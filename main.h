#ifndef WHATSCOOKINGNAIVE_MAIN_H
#define WHATSCOOKINGNAIVE_MAIN_H

typedef struct recipe {
    int id; //cuisine id
    char* cuisine; //cuisine name
    int counter; //cuisine counter
    char** ingredients; //list of ingredients that are part of the cuisine
    int *ingredientsFreq; //list of the frequency for each ingredient on the cuisine
    int number_ingredients;
} Recipe;

typedef struct list_of_recipes{
    int number;
    Recipe **list;
} List_Of_Recipes;

void print_recipe(Recipe *recipe);

#endif //WHATSCOOKINGNAIVE_MAIN_H
