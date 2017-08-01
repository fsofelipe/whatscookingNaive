#include "cuisine.h"
#include <string.h>
#include <stdlib.h>

typedef struct ingredient{
    char name[100];
    int amount;
}ingredient_t;

typedef struct cuisine{
  char name[50]; //name of culinary type
  int total; //amount of recipes that are part of this culinary type
  ingredient_t *ingredient_list;
  int distintic_ingredients;
}cuisine_t;



// read all recipes on the list and counts the elements
// receipes: a list with all recipes
// size: pass by reference to return the total of different cuisines
// return an array of cuisines type
cuisine_t *getCuisines(List_Of_Recipes *recipes, int *size);


// recipes:  list of all recipes
// cuisine_list: list of all cuisines types
// cuisine_size: size of the list of cuisines
void getIngredients(List_Of_Recipes *recipes, cuisine_t *cuisine_list, int cuisine_size);
