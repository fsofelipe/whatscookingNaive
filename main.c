#include "cuisine.h"
#include "naive.h"
#include "main.h"

int main() {

    List_Of_Recipes * train_dataset = read_file(1);
    //List_Of_Recipes * test_dataset = read_file(2);

    //print_recipe_list(train_dataset, 1);

    //printf("%d\n", train_dataset->total_ingredients);
    int size_of_resultado = 0;
    cuisine_t *cuisines_list = getCuisines(train_dataset, &size_of_resultado);

    //TEST PRINTS
    printf("\nsize_of_resultado: %d\n", size_of_resultado);
    for (int i = 0; i < size_of_resultado; i++){
        printf("%s, %d\n", cuisines_list[i].name, cuisines_list[i].total);
        for (int j = 0; j < cuisines_list[i].distintic_ingredients; j++ ){
            printf("%s - %d\n", cuisines_list[i].ingredient_list[j].name,  cuisines_list[i].ingredient_list[j].amount);
        }
    }

    //getIngredients(train_dataset, cuisines_list, size_of_resultado);

    //printf("==%d\n", cuisines_list[0].distintic_ingredients);

    //printf("%s\n", resultado[0].name);

    //train(train_dataset);

    char * cuisines[2];
    cuisines[0] = malloc(5);
    cuisines[1] = malloc(7);
    strcpy(cuisines[0], "Teste");
    strcpy(cuisines[1], "Teste 2");

    int ids[2] = {0,1};

    writeCSV(ids, cuisines, 2);

}
