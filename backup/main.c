#include "cuisine.h"
#include "naive.h"
#include "main.h"
#include "cronometro.h"
int main() {
    inicia_cronometro();
    //List_Of_Recipes * train_dataset = read_file(1);
    //List_Of_Recipes * test_dataset = read_file(2);
    List_Of_Recipes train_dataset;
    List_Of_Recipes  test_dataset;
    read_file(1, &train_dataset);
    read_file(2, &test_dataset);

    int size_cuisines = 0;

    cuisine_t *cuisines_list = getCuisines(&train_dataset, &size_cuisines);

    //printf("total_recipes: %d\n", train_dataset.total_recipes);

    getClassProb(cuisines_list, size_cuisines, train_dataset.total_recipes);

    double teste = 0;



    result_t *a = (result_t *) malloc (sizeof(result_t) * test_dataset.total_recipes);

    a = readAll(test_dataset, cuisines_list, size_cuisines);

    writeCSV(a, test_dataset.total_recipes);
    printf("%f\n", para_cronometro());
}
