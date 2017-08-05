#include "cuisine.h"
#include <stdio.h>
#include "jsonParser.h"

List_Of_Recipes * read_file(int type, List_Of_Recipes * recipe_list){
    //Type 1 = Train
    //Type 2 = Test

    int c;
    FILE *file;

    if(type == 1){
        file = fopen("Dataset/train.json", "r");
    }else{
        file = fopen("Dataset/test.json", "r");
    }

    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int total_recipes = 0;

    recipe_list->total_recipes = 0;

    recipe_list->list = (recipe_t *) malloc(sizeof(recipe_t));

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
            if(file_contents[i] == '{'){
                found_first_bracket = i;
                size = 0;

            }

            if(found_first_bracket > 0){
                size++;
            }

            if(file_contents[i] == '}'){
                char object[size+1];
                memcpy(object, &file_contents[found_first_bracket], size);
                printf("%s\n", object);
                object[size] = '\0';

                json_object * jobj = json_tokener_parse(object);
                recipe_t *r = (recipe_t *) malloc(sizeof(recipe_t));
                json_parse(jobj, r);

                //object = malloc(size);
                //print_recipe(r);
                recipe_list->list[recipe_list->total_recipes] = r;
                recipe_list->total_recipes++;
                recipe_list->list = realloc(recipe_list->list, recipe_list->total_recipes * sizeof(recipe_t));


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

void print_recipe(recipe_t *recipe, int withCuisine){
    if(withCuisine == 1){
        printf("ID: %d\nCuisine: %s\n---\nIngredients:\n", recipe->id, recipe->cuisine);
    }else{
        printf("ID: %d\nIngredients:\n", recipe->id);
    }
    for(int z = 0; z < recipe->number_ingredients; z++){
      printf("%s\n", recipe->ingredients[z]);
    }

    printf("\n===\n");
}

void print_recipe_list(List_Of_Recipes *list, int withCuisine){
    for(int i = 0; i < list->total_recipes; i++){
        print_recipe(list->list[i], withCuisine);
    }
}
