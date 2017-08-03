#include "naive.h"
cuisine_t *getCuisines(List_Of_Recipes *recipes, int *size){
    cuisine_t *cuisines =(cuisine_t *) malloc (sizeof(cuisine_t) * 1);
    *size = 1;

    strcpy (cuisines[0].name, recipes->list[0]->cuisine);

    cuisines[0].total = 0;
    cuisines[0].distintic_ingredients = 1;
    cuisines[0].total = 1;
    cuisines[0].ingredient_list = (ingredient_t *) malloc (sizeof(ingredient_t) * 1);
    strcpy (cuisines[0].ingredient_list[0].name, "-");
    cuisines[0].ingredient_list[0].amount = 0;

    // iterators:
    // i = all recipes
    // j = cuisines types
    // k = all ingredients
    // l = distintic_ingredients list
    int i = 0, j = 0, k = 0, l = 0;
    for (i = 0; i < recipes->total_recipes; i++){
        char cuisine_name[50];
        strcpy (cuisine_name, recipes->list[i]->cuisine);
        //search if there is different type of cuisine

        for (j = 0; j < *size; j++){
            if (strcmp(cuisine_name, cuisines[j].name) == 0)
                break;
        }

        if (j < *size){
            //cuisine already exist
            cuisines[j].total++;

        }else{
            //new cuisine
            cuisines = (cuisine_t *) realloc (cuisines, (j+1) * sizeof(cuisine_t));
            strcpy (cuisines[j].name, recipes->list[i]->cuisine);
            cuisines[j].total = 1;
            *size = *size + 1;
            cuisines[j].distintic_ingredients = 1;
            cuisines[j].ingredient_list = (ingredient_t *) malloc (sizeof(ingredient_t) * 1);
            strcpy (cuisines[j].ingredient_list[0].name, "-");
            cuisines[j].ingredient_list[0].amount = 0;

        }
        //printf("%d\n", j);
        //printf("cuisine type: %s\n", cuisines[j].name);
        for (k = 0; k < recipes->list[i]->number_ingredients; k++){
            //printf("reading INGREDIENT: %s\n", recipes->list[i]->ingredients[k]);
            for(l = 0; l < cuisines[j].distintic_ingredients;l++){

                //first ingredient
                if (strcmp(cuisines[j].ingredient_list[l].name, "-") == 0){
                    strcpy (cuisines[j].ingredient_list[l].name, recipes->list[i]->ingredients[k]);
                    cuisines[j].ingredient_list[l].amount = 1;
                    cuisines[j].total_ingredients = 1;

                }
                if (strcmp(cuisines[j].ingredient_list[l].name, recipes->list[i]->ingredients[k]) == 0)
                    break;
            }
            if (l < cuisines[j].distintic_ingredients){
                //ingredient already exist in this cuisine
                cuisines[j].ingredient_list[l].amount = cuisines[j].ingredient_list[l].amount + 1;
                cuisines[j].total_ingredients = cuisines[j].total_ingredients + 1;

            }else{
                //new ingredient
                cuisines[j].distintic_ingredients = cuisines[j].distintic_ingredients + 1;
                cuisines[j].ingredient_list = (ingredient_t *) realloc (cuisines[j].ingredient_list, (l+1) * sizeof(ingredient_t));

                strcpy(cuisines[j].ingredient_list[l].name, recipes->list[i]->ingredients[k]);
                cuisines[j].ingredient_list[l].amount = 1;
                cuisines[j].total_ingredients = cuisines[j].total_ingredients + 1;
            }


        }

        //printf("\n");


    }

    return cuisines;
}

ingredient_t *getIngredients(cuisine_t *cuisine_list, int cuisine_size, int *ingredient_size){
    ingredient_t *global = (ingredient_t *) malloc (sizeof(ingredient_t) * 1);

    *ingredient_size = 1;

    strcpy(global[0].name, cuisine_list[0].ingredient_list[0].name);
    global[0].amount = 0;

    //ITERATORS:
    // i = cuisines types
    // j = independents ingredients in the cuisines types
    // k = global ingredients
    int i = 0, j = 0, k =0;

    //access each cuisine
    for (i = 0; i < cuisine_size; i++){
        for (j = 0; j < cuisine_list[i].distintic_ingredients; j++){
            //printf("%s - %s\n", cuisine_list[i].name, cuisine_list[i].ingredient_list[j].name);

            for (k = 0; k < *ingredient_size; k++){
                if (strcmp(cuisine_list[i].ingredient_list[j].name, global[k].name) == 0)
                    break;

            }
            //not new
            if (k < *ingredient_size){
                global[k].amount = global[k].amount + cuisine_list[i].ingredient_list[j].amount;
            }else{
                //new
                global = (ingredient_t *) realloc (global, (k + 1) * sizeof(ingredient_t));
                strcpy(global[k].name, cuisine_list[i].ingredient_list[j].name);
                global[k].amount = cuisine_list[i].ingredient_list[j].amount;
                *ingredient_size= *ingredient_size + 1;
            }
        }

    }
    return global;
}

void getClassProb(cuisine_t *cuisine_list, int cuisine_size, int total_recipes){
    int i = 0;
    for (i = 0; i < cuisine_size; i++){
        cuisine_list[i].probability = (double)cuisine_list[i].total / (double)total_recipes;
    }
}

double getIngredientProb(char *name, int frequency, ingredient_t *global_ingredients, int ingredient_size){
    double prob;
    int i = 0;
    for (i = 0; i < ingredient_size; i++){
        if (strcmp(name, global_ingredients[i].name) == 0){
            prob = (double)frequency/(double)global_ingredients[i].amount;
            break;
        }

    }




    return prob;
}

void writeCSV(int *ids, char ** cuisines, int number){
    FILE *fp;

    fp=fopen("output.csv","w+");

    fprintf(fp,"id,cuisine");

    for(int i =0; i < number; i++){
        fprintf(fp,"\n%d,%s", ids[i], cuisines[i]);
    }

    fclose(fp);
}
