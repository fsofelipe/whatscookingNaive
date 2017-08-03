#include "cuisine.h"
#include "naive.h"
#include "main.h"

int main() {
    List_Of_Recipes *train_dataset = read_file(1);

    int size_cuisines = 0;
    cuisine_t *cuisines_list = getCuisines(train_dataset, &size_cuisines);

    //TEST PRINTS
    /*
    printf("\nsize_of_resultado: %d\n", size_cuisines);
    for (int i = 0; i < size_cuisines; i++){
        printf("%s, %d\n", cuisines_list[i].name, cuisines_list[i].total);
        for (int j = 0; j < cuisines_list[i].distintic_ingredients; j++ ){
            printf("%s - %d\n", cuisines_list[i].ingredient_list[j].name,  cuisines_list[i].ingredient_list[j].amount);
        }
    }
    */
    int total_ingredients;
    ingredient_t *global_ingredients = getIngredients(cuisines_list, size_cuisines, &total_ingredients);

    //TEST PRINTS
    /*
    printf("total_ingredients: %d\n", total_ingredients);
    for (int i = 0; i < total_ingredients; i++){
        printf("%s - %d\n", global_ingredients[i].name,  global_ingredients[i].amount);
    }
    */

    printf("total_recipes: %d\n", train_dataset->total_recipes);

    getClassProb(cuisines_list, size_cuisines, train_dataset->total_recipes);
    double teste;
    for (int i = 0; i < size_cuisines; i++){
        printf("%s, %lf\n", cuisines_list[i].name, cuisines_list[i].probability);
        teste += cuisines_list[i].probability;
    }

    printf("%lf\n", teste);
    printf("%lf\n", getIngredientProb("2\% reduced-fat milk", 21, global_ingredients, total_ingredients));


}
