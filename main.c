//
// Created by matheus on 23/07/17.
//

#include "main.h"
#include "recipe.h"
#include "naive_bayes.h"

int main() {
    List_Of_Recipes * train_dataset = read_file(1);
    List_Of_Recipes * test_dataset = read_file(2);

    train(train_dataset);

}
