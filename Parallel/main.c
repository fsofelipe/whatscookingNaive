#include "cuisine.h"
#include "naive_bayes.h"
#include "main.h"
#include "cronometro.h"
#include <omp.h>
int main() {
    omp_set_num_threads(THREADS);
    inicia_cronometro();
    //List_Of_Recipes * train_dataset = read_file(1);
    //List_Of_Recipes * test_dataset = read_file(2);
    List_Of_Recipes train_dataset;
    List_Of_Recipes  test_dataset;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            read_file(1, &train_dataset);
        }

        #pragma omp section
        {
            read_file(2, &test_dataset);
        }
    }

    List_likelihood_table * tables = mount_tables(&train_dataset);
    result_t ** results = calculate_probabilities(&test_dataset, tables);
    writeCSV(results, test_dataset.total_recipes);
    /*int size_cuisines = 0;

    cuisine_t *cuisines_list = getCuisines(&train_dataset, &size_cuisines);

    //printf("total_recipes: %d\n", train_dataset.total_recipes);

    getClassProb(cuisines_list, size_cuisines, train_dataset.total_recipes);

    double teste = 0;



    result_t *a = (result_t *) malloc (sizeof(result_t) * test_dataset.total_recipes);

    a = readAll(test_dataset, cuisines_list, size_cuisines);

    writeCSV(a, test_dataset.total_recipes);*/
    printf("%f\n", para_cronometro());
}
