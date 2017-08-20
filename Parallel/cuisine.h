#ifndef CUISINE_H
#define CUISINE_H

#include <json/json.h>
#include <memory.h>
#include <omp.h>

typedef struct recipes{
  int id;
  char *cuisine;
  char **ingredients;
  int number_ingredients;
} recipe_t;

typedef struct list_of_recipes{
    int total_recipes; //how many recipes exists
    recipe_t **list;
} List_Of_Recipes;

List_Of_Recipes readFile(char *name);

List_Of_Recipes * read_file(int type, List_Of_Recipes * recipe_list);

void print_recipe(recipe_t *recipe, int withCuisine);

void print_recipe_list(List_Of_Recipes *list, int withCuisine);


#endif
