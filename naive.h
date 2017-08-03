#include "cuisine.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct ingredient{
    char name[100];
    int amount;
}ingredient_t;

typedef struct cuisine{
  char name[50]; //name of culinary type
  int total; //amount of recipes that are part of this culinary type
  ingredient_t *ingredient_list;
  int distintic_ingredients;
  int total_ingredients;
  double probability;
}cuisine_t;


// read all recipes on the list and counts the elements
// receipes: a list with all recipes
// size: pass by reference to return the total of different cuisines
// return an array of cuisines type
cuisine_t *getCuisines(List_Of_Recipes *recipes, int *size);


// recipes:  list of all recipes
// cuisine_list: list of all cuisines types
// cuisine_size: size of the list of cuisines
ingredient_t *getIngredients(cuisine_t *cuisine_list, int cuisine_size, int *ingredient_size);


// calculate each cuisine probability and stores in the cuisine array
// cuisines_list: list of all types of cuisine
// size of the list cuisines_list
// total_recipes: all recipes in the dataset
void getClassProb(cuisine_t *cuisine_list, int cuisine_size, int total_recipes);

// calculate the probability of X ingredient in the list of all ingredient
// name: the name of the ingredient
// frequency: frequency of this ingredient in a cuisine typedef
// global_ingredients: list of all ingredients from all recipes
// ingredient_size: size of the list of global_ingredients
// return: the probability
double getIngredientProb(char *name, int frequency, ingredient_t *global_ingredients, int ingredient_size);

void getIngredients(List_Of_Recipes *recipes, cuisine_t *cuisine_list, int cuisine_size);

void writeCSV(int *ids, char ** cuisines, int number);
