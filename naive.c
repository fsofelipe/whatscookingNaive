#include "naive.h"
cuisine_t *getCuisines(List_Of_Recipes *recipes, int *size){
    cuisine_t *cuisines =(cuisine_t *) malloc (sizeof(cuisine_t) * 1);
    *size = 1;

    strcpy (cuisines[0].name, recipes->list[0]->cuisine);

    cuisines[0].total = 0;
    cuisines[0].distintic_ingredients = 1;
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
                }
                if (strcmp(cuisines[j].ingredient_list[l].name, recipes->list[i]->ingredients[k]) == 0)
                    break;
            }
            if (l < cuisines[j].distintic_ingredients){
                //ingredient already exist in this cuisine
                cuisines[j].ingredient_list[l].amount = cuisines[j].ingredient_list[l].amount + 1;
            }else{
                //new ingredient
                cuisines[j].distintic_ingredients = cuisines[j].distintic_ingredients + 1;
                cuisines[j].ingredient_list = (ingredient_t *) realloc (cuisines[j].ingredient_list, (l+1) * sizeof(ingredient_t));

                strcpy(cuisines[j].ingredient_list[l].name, recipes->list[i]->ingredients[k]);
                cuisines[j].ingredient_list[l].amount = 1;
            }


        }

        //printf("\n");






    }

    return cuisines;
}

void getIngredients(List_Of_Recipes *recipes, cuisine_t *cuisine_list, int cuisine_size){
    int i = 0, j = 0;
    //access each recipes
    for (i = 0; i < recipes->total_recipes; i++){
        for (j=0; j < cuisine_size; j++){
            //recipe belongs to a cuisine_list[j] type
            if (strcmp(recipes->list[i]->cuisine, cuisine_list[j].name) == 0){
                printf("%s - %s\n", recipes->list[i]->cuisine, cuisine_list[j].name);


            }

        }

    }

}
