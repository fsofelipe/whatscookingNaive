#ifndef WHATSCOOKINGNAIVE_MAIN_H
#define WHATSCOOKINGNAIVE_MAIN_H

typedef struct ingredient{
    char * name;
    long double frequency;
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

#endif //WHATSCOOKINGNAIVE_MAIN_H
