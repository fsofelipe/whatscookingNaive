//
// Created by matheus on 25/07/17.
//

#include "naive_bayes.h"

void train(List_Of_Recipes * recipes){
    // Mount list_likelihood_table.
    mount_tables(recipes);
}

Likelihood_Table * mount_tables(List_Of_Recipes * recipes){
    printf("%d\n", recipes->number);

    // Travel all entry creating a list of different ingredients.
    Ingredient ** ingredients = (Ingredient *) malloc(sizeof(Ingredient));
    int number_ingredients = 0;

    for(int i = 0; i < recipes->number; i++){
        Recipe * recipe = recipes->list[i];
        for(int j = 0; j < recipe->number_ingredients; j++){
            int found = 0;
            Ingredient * ingredient_to_be_added = recipe->ingredients[j];
            for(int z = 0; z < number_ingredients; z++){
                if(strcmp(ingredient_to_be_added->name, recipe->ingredients[z]->name) == 0){
                    found = 1;
                    break;
                }
            }
            if(found == 0){
                ingredients[number_ingredients] = (Ingredient *) malloc(sizeof(Ingredient));
                ingredients[number_ingredients] = ingredient_to_be_added;
                number_ingredients++;
            }
        }
    }

    // Create a list of different cuisines and add the ingredients on it.
    List_likelihood_table * cuisines = (List_likelihood_table *) malloc(sizeof(List_likelihood_table));
    cuisines->list = (Likelihood_Table *) malloc(sizeof(Likelihood_Table) * recipes->number);

    cuisines->count = 0;

    // Create the likelihood table and update values.
    for(int i = 0; i < recipes->number; i++){
        Likelihood_Table * cuisine = (Likelihood_Table *) malloc(sizeof(Likelihood_Table));
        Recipe * recipe = (Recipe *) malloc(sizeof(Recipe));
        copyRecipe(recipe, recipes->list[i]);
        copyIngredientsToRecipe(recipes->list[i]->ingredients, recipes->list[i]->number_ingredients, recipe, number_ingredients);

        // Pensei que as cozinhas repetiam no dataset de treino, mas nao repetem.
        /*int found = 0;
        for(int j = 0; j < cuisines->count; j++){
            if(recipe->id == cuisines->list[j]->recipe->id){
                found = 1;
            }
        }

        if(found == 0){*/
        cuisine->recipe = recipe;
        cuisine->likelihood_yes = recipe->number_ingredients;
        cuisine->likelihood_no = number_ingredients - recipe->number_ingredients;
        //cuisines->list[cuisines->count] = (Likelihood_Table *) malloc(sizeof(Likelihood_Table));
        cuisines->list[cuisines->count] = cuisine;
        cuisines->count++;
        //}
    }

    print_likelihood_tables(cuisines);

    // Clean memory.
    free_list(recipes);
}

void print_likelihood_tables(List_likelihood_table * table){
    for(int i = 0; i < table->count; i++){
        Likelihood_Table * likelihood = table->list[i];
        printf("Yes = %d No = %d\n", likelihood->likelihood_yes, likelihood->likelihood_no);
        print_recipe(likelihood->recipe, 1);
    }
}

// TODO: Function that calculate a chance to be on of the recipe.
double calculate_frequency(){
    // Naive bayes frequency calculus.
}

// TODO: Function that return the most likely recipe that the list of ingredients belong.
Recipe * most_likely_recipe(){
    // Travel all the recipes.

    // For each recipe calculate the frequency and hold the most likely recipe to return.
}

// TODO: Function that test with the test dataset and generate the csv file.
void test(List_Of_Recipes * recipes){
    // Travel all the test dataset.

    // For each test in test dataset calculate the most_likely_recipe and save on CSV.
}