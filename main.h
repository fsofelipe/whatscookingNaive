#ifndef WHATSCOOKINGNAIVE_MAIN_H
#define WHATSCOOKINGNAIVE_MAIN_H

typedef struct recipe {
    char* ingredients; //ingredients that are part of the cuisine
    int ingredientsFreq; //requency for each ingredient on the cuisine
} recipe_t;

typedef struct cuisine{
  int id; //cuisine id
  char* name; //cuisine name
  int counter; //cuisine counter; how many times the cuisine appears on the dataset
  recipe_t *ingredient; //list of ingredients for each recipe
  int totalIngredients;
} cuisine_t;

#endif //WHATSCOOKINGNAIVE_MAIN_H
