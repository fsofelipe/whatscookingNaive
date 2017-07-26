//
// Created by matheus on 23/07/17.
//

#include "main.h"
#include "recipe.h"

int main() {
    List_Of_Recipes * train = read_file(1);
    List_Of_Recipes * test = read_file(2);
    print_recipe_list(train, 1);

}
