#include "cuisine.h"
#include "naive.h"
#include "main.h"

int main() {
    List_Of_Recipes *train_dataset = read_file(1);
    List_Of_Recipes *test_dataset = read_file(2);
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


    printf("total_recipes: %d\n", train_dataset->total_recipes);

    getClassProb(cuisines_list, size_cuisines, train_dataset->total_recipes);
    double teste;
    for (int i = 0; i < size_cuisines; i++){
        printf("%s, %lg\n", cuisines_list[i].name, cuisines_list[i].probability);
        teste += cuisines_list[i].probability;
    }

    printf("prova real das probabilidades das classes: %lf\n", teste);


    printf(":= %d\n", findFrequency(cuisines_list, size_cuisines, "southern_us", "plain flour"));



    double *a = getRecipeProb(size_cuisines, cuisines_list, train_dataset->list[0]);

    for (int i = 0; i < size_cuisines; i++)
        printf("%s, %lg\n", cuisines_list[i].name, a[i]);


    printf("%d\n", findBiggest(a, size_cuisines));




}
