#include "cuisine.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

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

typedef struct result{
    char name[50];
    int id;
}result_t;




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

// calculate P( ingredient X | cuisine)
// amountX = total of X in this cuisine type
// total_ingredients = total of ingredients in this cuisine
// distintic_ingredients = total of distintic ingredients in this cuisine
double getIngredientProb(int amountX, int total_ingredients, int distintic_ingredients);

// finds the frequency of an element in a cuisine type
int findFrequency(cuisine_t *cuisines, int size_cuisines, char *cuisineName, char *ingredient);

// size_cuisines: how many cuisine types
// cuisines: array with all cuisine types
// recipe: recipe to be used
// return a list with size = size_cuisines, which stores the probability of a recipe for all cuisine types
double *getRecipeProb(cuisine_t *cuisines, int size_cuisines, recipe_t *recipe);

//read a vector of probabilities and return the index from the biggest
int findBiggest(double *recipeProbs, int size_cuisines);

result_t reading(cuisine_t *cuisines, int size_cuisines, recipe_t *recipe){

result_t *readAll(List_Of_Recipes *recipes, cuisine_t *cuisines, int size_cuisines);

void writeCSV(int *ids, char **cuisinesName, int number);
