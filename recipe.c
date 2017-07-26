//
// Created by matheus on 25/07/17.
//

#include <stdio.h>
#include "recipe.h"
#include "jsonParser.h"

void print_recipe(Recipe *recipe, int withCuisine){
    if(withCuisine == 1){
        printf("ID: %d, Cuisine: %s, Ingredients:\n", recipe->id, recipe->cuisine);
    }else{
        printf("ID: %d, Ingredients:\n", recipe->id);
    }

    for(int z = 0; z < recipe->number_ingredients; z++){
        printf("Ingredient: %s \n", recipe->ingredients[z].name);
    }
    printf("\n");
}

void print_recipe_list(List_Of_Recipes *list, int withCuisine){
    for(int i = 0; i < list->number; i++){
        print_recipe(list->list[i], withCuisine);
    }
}

List_Of_Recipes * read_file(int type){
    //Type 1 = Train
    //Type 2 = Test

    int c;
    FILE *file;

    if(type == 1){
        file = fopen("train.json", "r");
    }else{
        file = fopen("test.json", "r");
    }

    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    List_Of_Recipes * recipe_list = (List_Of_Recipes *) malloc(sizeof(List_Of_Recipes));
    recipe_list->number = 0;

    recipe_list->list = (Recipe *) malloc(sizeof(Recipe));

    if (file) {
        char *file_contents;
        long input_file_size;
        fseek(file, 0, SEEK_END);
        input_file_size = ftell(file);
        rewind(file);
        file_contents = malloc(input_file_size * (sizeof(char)));
        fread(file_contents, sizeof(char), input_file_size, file);
        fclose(file);

        int i = 0;
        int found_first_bracket = 0;
        char *object = malloc(1);
        int size = 0;
        for (i = 0; file_contents[i] != 0; i++){
            //printf("%c", file_contents[i]);

            if(file_contents[i] == '{'){
                // printf("FOUND FIRST");
                found_first_bracket = i;
                size = 0;
            }

            if(found_first_bracket > 0){
                size++;
                //char * willBeAdded = malloc(1);
                //char * hold = object;
                // object = (char*) malloc(size * sizeof(char));
                //object = hold;
                //object[size] = 'a';
                //printf("%d", sizeof(object));
                //strncat(willBeAdded, &file_contents[i], 1);
                // strcat(object, willBeAdded);
                //printf("%s\n", object);
                // size++;
            }

            if(file_contents[i] == '}'){
                char object[size];
                memcpy(object, &file_contents[found_first_bracket], size);
                object[size] = '\0';
                //printf("%s\n", object);

                json_object * jobj = json_tokener_parse(object);
                Recipe *r = (Recipe *) malloc(sizeof(Recipe));
                json_parse(jobj, r);
                //object = malloc(size);
                //print_recipe(r);
                recipe_list->list[recipe_list->number] = r;
                recipe_list->number++;
                recipe_list->list = realloc(recipe_list->list, recipe_list->number * sizeof(Recipe));
                // strcpy(object, "0");
                // SALVA NO OBJETO
            }
            // Pega objeto por objeto.

            // Usar o json parse nele

            // Salva numa struct e adiciona no array.
        }
        //printf("%d", input_file_size);
        //printf("%s", file_contents);
        return recipe_list;
    }

    /* char * string = "{\"id\": 3731,\n"
             "    \"cuisine\": \"mexican\",\n"
             "    \"ingredients\": [\n"
             "      \"tomatoes\",\n"
             "      \"green onions\",\n"
             "      \"garlic\",\n"
             "      \"dried oregano\",\n"
             "      \"ground black pepper\",\n"
             "      \"red wine vinegar\",\n"
             "      \"salsa\",\n"
             "      \"flour tortillas\",\n"
             "      \"shredded lettuce\",\n"
             "      \"white sugar\",\n"
             "      \"lime\",\n"
             "      \"boneless skinless chicken breasts\",\n"
             "      \"salt\",\n"
             "      \"shredded Monterey Jack cheese\"\n"
             "    ]}";
     printf("JSON string: %sn", string);
     json_object * jobj = json_tokener_parse(string);
     json_parse(jobj);*/
}

Recipe * copyRecipe(Recipe * recipe){
    Recipe * r = (Recipe *) malloc(sizeof(Recipe));
    r->id = recipe->cuisine;
    strcpy(r->cuisine, recipe->cuisine);
    r->counter = recipe->counter;
    return r;
}

Ingredient * copyIngredients(Ingredient * ingredients, int number){
    Ingredient ** ings = (Ingredient *) malloc(sizeof(Ingredient));
    for(int i = 0; i < number; i++){
        Ingredient * ing = (Ingredient *) malloc(sizeof(Ingredient));
        strcpy(ing->name, ingredients[i].name);
        ings[i] = ing;

    }

    return ings;
}