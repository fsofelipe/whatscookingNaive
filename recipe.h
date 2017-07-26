//
// Created by matheus on 25/07/17.
//

#ifndef WHATSCOOKINGNAIVE_RECIPE_H
#define WHATSCOOKINGNAIVE_RECIPE_H

#include <json/json.h>
#include <memory.h>

typedef struct ingredient{
    char * name;
    int yes_times;
    int no_times;
} Ingredient;

typedef struct recipe {
    int id; //cuisine id
    char* cuisine; //cuisine name
    int counter; //cuisine counter
    Ingredient * ingredients; //list of ingredients that are part of the cuisine
    int number_ingredients;
} Recipe;

typedef struct list_of_recipes{
    int number;
    Recipe **list;
} List_Of_Recipes;

void print_recipe(Recipe *recipe, int withCuisine);

void print_recipe_list(List_Of_Recipes *list, int withCuisine);

List_Of_Recipes * read_file(int type);

Recipe * copyRecipe(Recipe * recipe);

Ingredient * copyIngredients(Ingredient * ingredients, int number);
#endif //WHATSCOOKINGNAIVE_RECIPE_H
