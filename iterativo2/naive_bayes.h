//
// Created by matheus on 25/07/17.
//

#ifndef WHATSCOOKINGNAIVE_NAIVE_BAYES_H
#define WHATSCOOKINGNAIVE_NAIVE_BAYES_H
#include <stdio.h>
#include "main.h"
#include "cuisine.h"
#include <math.h>
#include <float.h>

#define THREADS 4


typedef struct ingredient{
    char name[100];
    int amount_yes;
    int amount_no;
    double p_x_c; // P(x|c)
    double p_x; // P(x)
    struct ingredient * next;
}Ingredient;

typedef struct list_of_ingredients{
    Ingredient ** list;
    int number_of_ingredients;
    int total_ingredients;
} List_Of_Ingredients;

typedef struct likelihood_table{
    char name[100];
    List_Of_Ingredients * ingredients;
    int n_ing_yes;
    int n_ing_no;
    double p_c_y; // P(yes)
    double p_c_n; // P(no)
    int id;
} Likelihood_Table;

typedef struct list_likelihood_table{
    int count;
    Likelihood_Table * list[20];
} List_likelihood_table;

typedef struct result{
    char name[50];
    int id;
}result_t;

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

// Frequencia do nao = nao vai ser salvo os ingredientes que nao tem na receita para nao desperdicar memoria nem trabalho, para calcular
// a frequencia de um ingrediente que nao ta na receita, vai ser 1 / (total_ingredients - number_ingredients) assim retornando a frequencia
// do nao. O likelihood_no é (total_ingredients - number_ingredients).

void train(List_Of_Recipes * recipes);

List_likelihood_table * mount_tables(List_Of_Recipes * recipes);
List_Of_Ingredients * mount_ingredient_list(List_Of_Recipes * recipes);
void print_list_of_ingredients(List_Of_Ingredients * ingredients);
void print_ingredient(Ingredient * ingredient);
void update_ingredients_on_table(recipe_t * recipe, List_Of_Ingredients * list);
void print_tables(List_likelihood_table * tables, int withIngredients);
void print_table(Likelihood_Table * table, int withIngredients);
result_t ** calculate_probabilities(List_Of_Recipes * recipes, List_likelihood_table * tables);
void print_likelihood_tables(List_likelihood_table * table);
double get_ingredient_probability(Likelihood_Table * table, char * ingredient);
void writeCSV(result_t **receipes, int number);
void calculate_ingredient_probability(Ingredient * ingredient, double p_c_y);
int found_ingredient_by_name(char * name, List_Of_Ingredients * ingredients);

#endif //WHATSCOOKINGNAIVE_NAIVE_BAYES_H