//
// Created by matheus on 23/07/17.
//


#ifndef WHATSCOOKINGNAIVE_MAIN_H
#define WHATSCOOKINGNAIVE_MAIN_H

typedef struct recipe {
    int id;
    char* cuisine;
    char** ingredients;
    int *ingredientsFreq;
} Recipe;

#endif //WHATSCOOKINGNAIVE_MAIN_H
