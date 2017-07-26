//
// Created by matheus on 25/07/17.
//

#ifndef WHATSCOOKINGNAIVE_NAIVE_BAYES_H
#define WHATSCOOKINGNAIVE_NAIVE_BAYES_H
#include <stdio.h>
#include "main.h"
#include "recipe.h"

typedef struct likelihood_table{
    Recipe * recipe;
    int no_total;
    int yes_total;
} Likelihood_Table;

typedef struct list_likelihood_table{
    int count;
    Likelihood_Table * list;
} List_likelihood_table;

//                                      Recipe
//                                Yes            No
//            -> Ingredient 1      A             B
// Outlook    -> Ingredient 2      A             B
//            -> Ingredient 3      A             B
//                                 C             D
//
// A = Ing.yes/likelihood_yes
// B = Ing.no/likelihood_no
// C = SUM(Ing.yes)/(likelihood_yes+likelihood_no)
// D = SUM(Ing.no)/(likelihood_yes+likelihood_no)
// P(x) = P(Ingredien   t 1) = (Ing.yes+Ing.no) / likelihood_yes+likelihood.no
// P(x|c) = P(Ingredient 1|Yes) = A
// P(c) = P(Yes) = C
// P(c|x) = P(Yes | Sunny) =  P(x|c) * P(c) / P(x) --> GOAL

void train();
Likelihood_Table * mount_tables(List_Of_Recipes * recipes);

#endif //WHATSCOOKINGNAIVE_NAIVE_BAYES_H
