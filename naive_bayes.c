//
// Created by matheus on 25/07/17.
//

#include "naive_bayes.h"

void train(){
    // Mount list_likelihood_table.

}

Likelihood_Table * mount_tables(List_Of_Recipes * recipes){


    // Travel all entry creating a list of different ingredients.
    //printf("%d", recipes->number);
    Ingredient * ingredients = (Ingredient *) malloc(sizeof(Ingredient));
    int number_ingredients = 0;

    for(int i = 0; i < recipes->number; i++){
        Recipe * recipe = recipes->list[i];
        for(int j = 0; j < recipe->number_ingredients; j++){
            int found = 0;
            Ingredient ingredient_to_be_added = recipe->ingredients[j];
            for(int z = 0; z < number_ingredients; z++){
                if(strcmp(ingredient_to_be_added.name, recipe->ingredients[z].name) == 0){
                    found = 1;
                    break;
                }
            }
            if(found == 0){
                ingredients[number_ingredients] = ingredient_to_be_added;
                number_ingredients++;
            }
        }
    }

    // Create a list of different cuisines and add the ingredients on it.
    List_likelihood_table * cuisines = (List_likelihood_table *) malloc(sizeof(List_likelihood_table));
    cuisines->count = 0;

    for(int i = 0; i < recipes->number; i++){
        Likelihood_Table * cuisine = (Likelihood_Table *) malloc(sizeof(Likelihood_Table));
        Recipe * recipe = copyRecipe(recipes->list[i]);

        int found = 0;
        for(int j = 0; j < cuisines->count; j++){
            if(recipe->id == cuisines->list[i].recipe->id){
                found = 1;
            }
        }

        if(found == 0){
            recipe->ingredients = copyIngredients(ingredients, number_ingredients);
            recipe->number_ingredients = number_ingredients;

            for(int z = 0; z < number_ingredients; z++){
                printf("%s\n", recipe->ingredients[z]);
            }
            cuisine->recipe = recipe;
            cuisines->count++;
        }
    }

    // Travel all the list of recipes updating list likelihood table.


}