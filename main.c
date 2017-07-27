//
// Created by matheus on 23/07/17.
//

#include "main.h"
#include "cuisine.h"
#include "jsonParser.h"

int main() {
    List_Of_Recipes * train_dataset = read_file(1);
    //List_Of_Recipes * test_dataset = read_file(2);

    print_recipe_list(train_dataset, 1);

    printf("%d\n", train_dataset->number);

    //train(train_dataset);

}
