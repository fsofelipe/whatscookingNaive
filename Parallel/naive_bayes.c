//
// Created by matheus on 25/07/17.
//

#include "naive_bayes.h"

void train(List_Of_Recipes * recipes){
    // Mount list_likelihood_table.
    mount_tables(recipes);
}

List_likelihood_table * mount_tables(List_Of_Recipes * recipes){
    // Count number of ingredients with amount. Monta uma lista com todos os ingredientes com quantidade.
    List_Of_Ingredients * ingredients = mount_ingredient_list(recipes);
    //print_list_of_ingredients(ingredients);

    // Mount likelihood_tables

    // Travel json.
    List_likelihood_table * tables = (List_likelihood_table *) malloc(sizeof(List_likelihood_table));
    tables->count = 0;

    #pragma omp parallel num_threads(THREADS)
    {
        // Populate tables.
        #pragma omp for
        for(int i = 0; i < recipes->total_recipes; i++){
            //int tid = omp_get_thread_num();
            //printf("Hello World from thread = %d\n", tid);
            int found = 0;
            for(int x = 0; x < tables->count; x++){
                if(strcmp(recipes->list[i]->cuisine, tables->list[x]->name)==0){
                    found = 1;
                }
            }

            // Adicionar a cozinha na lista de tabelas.
            // Atualizar os ingredientes na cozinha.
            if(found == 0){
                Likelihood_Table * table = (Likelihood_Table *) malloc(sizeof(Likelihood_Table));
                strcpy(table->name, recipes->list[i]->cuisine);
                table->ingredients = (List_Of_Ingredients *) malloc(sizeof(List_Of_Ingredients));
                table->ingredients->number_of_ingredients = 0;
                table->ingredients->list = (Ingredient *) malloc(sizeof(Ingredient));
                table->n_ing_no = 0;
                table->n_ing_yes = 0;
                table->p_c_n = 0;
                table->p_c_y = 0;
                table->id = recipes->list[i]->id;
                tables->list[tables->count] = table;
                tables->count++;
                // Adicionar os ingredientes com a quantidade de vezes que aparece nessa cozinha.
                update_ingredients_on_table(recipes->list[i], table->ingredients);
            }
        }
    };

    #pragma omp parallel num_threads(THREADS)
        {
        #pragma omp for
        for (int i = 0; i < tables->count; i++) {
            update_tables(tables->list[i], ingredients, i);
        }
    };
    return tables;
}

void update_tables(Likelihood_Table * table, List_Of_Ingredients * ingredients, int i){
    //int tid = omp_get_thread_num();
    //printf("Table %d happening on thread %d\n", i, tid);
    int sum_yes = 0;
    int sum_no = 0;
    // Put the ingredients that dont belong on the recipe and sum.
    // Conta a quantidade que os ingredientes nao apareceram na cozinha.
    for (int x = 0; x < ingredients->number_of_ingredients; x++) {
        int found = 0;
        int z;
        for (z = 0; z < table->ingredients->number_of_ingredients; z++) {
            if (strcmp(table->ingredients->list[z]->name, ingredients->list[x]->name) == 0) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            Ingredient *new_ingredient = (Ingredient *) malloc(sizeof(Ingredient));
            strcpy(new_ingredient->name, ingredients->list[x]->name);
            new_ingredient->amount_yes = 1;
            new_ingredient->amount_no = ingredients->list[x]->amount_yes +
                                        1; // Number of times that this ingredient dont belong to this recipe.
            new_ingredient->p_x_c = 0;
            new_ingredient->p_x = 0;
            table->ingredients->list[table->ingredients->number_of_ingredients] = new_ingredient;
            table->ingredients->number_of_ingredients++;
            table->ingredients->list = realloc(table->ingredients->list,
                                               table->ingredients->number_of_ingredients * sizeof(Ingredient));
        } else {
            table->ingredients->list[z]->amount_no =
                    ingredients->list[x]->amount_yes - table->ingredients->list[z]->amount_yes +
                    1; // Number of ingredients in list of ingredients - number of times that this ingredient belong to this recipe. + 1 that is Naive Bayes Factor.
        }
    }

    // Update amount_yes and amount_no with of Naive Bayes, and calculate n_ing_yes.
    // Conta o numero de ingredientes que tem na cozinha e o numero de ingredientes que nao tem na cozinha.
    for (int x = 0; x < table->ingredients->number_of_ingredients; x++) {
        sum_no = sum_no + table->ingredients->list[x]->amount_no;
        sum_yes = sum_yes + table->ingredients->list[x]->amount_yes;
    }
    table->n_ing_yes = sum_yes;
    table->n_ing_no = sum_no;

    // Calcula o P(x|c) de cada ingrediente e o P(x) de cada ingrediente.
    for (int x = 0; x < table->ingredients->number_of_ingredients; x++) {
        double result = ((double) table->ingredients->list[x]->amount_yes) / ((double) sum_yes);
        table->ingredients->list[x]->p_x_c = result;

        double p_x = ((double) table->ingredients->list[x]->amount_yes +
                      (double) table->ingredients->list[x]->amount_no) / ((double) sum_no + (
                double) sum_yes);
        table->ingredients->list[x]->p_x = p_x;
        //printf("%d %d = %f\n", table->ingredients->list[x]->amount_yes, sum_yes, result);
    }

    // Calcula o P(c|yes) e o P(c|no) da cozinha.
    table->p_c_y = (double) sum_yes / ((double) sum_yes + (double) sum_no);
    table->p_c_n = (double) sum_no / ((double) sum_yes + (double) sum_no);
    //print_table(table, 0);
}
result_t ** calculate_probabilities(List_Of_Recipes * recipes, List_likelihood_table * tables) {
    // Travel the recipes.
     /*for(int i = 0; i < recipes->total_recipes; i++){
        // For each recipe:
        // For each likelihood table, calculate the Likelihood of yes = P(x|c) * P(x|c) of each ingredient.
        // Store the biggest and save on result_t.
        double max_probability = 0;
        int id = 0;
        char name[100];

        //#pragma omp parallel num_threads(THREADS) // Com esse for paralelizado, o tempo vai de 20s pra 40s.Entao nao vale a pena.
        //{
          //  #pragma omp for
            for (int j = 0; j < tables->count; j++) {
                probabilities[j] = calculate_table_probability(tables->list[j], recipes->list[j]);
            }
        //};

        //#pragma omp parallel num_threads(THREADS)
        //{
          //  #pragma omp parallel for reduction(max:max_probability) // Ficou bem mais lento.
            for (int j = 0; j < tables->count; j++)
                if(max_probability < probabilities[j]){
                    max_probability = probabilities[j];
                    strcpy(name, tables->list[j]);
                }
        //};


        result_t * r = (result_t *) malloc(sizeof(result_t));
        strcpy(r->name, name);
        r->id = recipes->list[i]->id;
        results[number_of_results] = r;
        number_of_results++;
    }*/

    result_t **results = (result_t *) malloc(sizeof(result_t) * recipes->total_recipes);

    FILE *fp;

    fp=fopen("output.csv","w+");

    fprintf(fp,"id,cuisine");

    #pragma omp parallel num_threads(THREADS)// Com esse for paralelizado, o tempo vai de 20s pra 40s.Entao nao vale a pena.
    {
        int number_of_results = 0;
        double probabilities[tables->count];

        #pragma omp for
        for (int i = 0; i < recipes->total_recipes; i++) {
            int found = 0;
            // For each recipe:
            // For each likelihood table, calculate the Likelihood of yes = P(x|c) * P(x|c) of each ingredient.
            // Store the biggest and save on result_t.
            double max_probability = 0;
            int id = 0;
            char name[100];
            //printf("%d\n", omp_get_thread_num());

            // Percorre todas as cozinhas.
            for (int j = 0; j < tables->count; j++) {
                double probability = 1;

                // Calcula a probabilidade da receita pertencer a essa cozinha.
                for (int z = 0; z < recipes->list[i]->number_ingredients; z++) {
                    double result = 1;
                    Ingredient *found;
                    for (int x = 0; x < tables->list[j]->ingredients->number_of_ingredients; x++) {
                        if (strcmp(recipes->list[i]->ingredients[z], tables->list[j]->ingredients->list[x]->name) ==
                            0) {
                            found = tables->list[j]->ingredients->list[x];
                            break;
                        }
                    }
                    if (found != NULL) {
                        // Pega o P(x|c) do ingrediente * P(c|yes) da tabela e divide pelo P(x).
                        // Formula do Naive Bayes.
                        // Probabilidade desse ingrediente fazer parte da cozinha.
                        result = found->p_x_c * tables->list[j]->p_c_y / found->p_x;
                    }
                    // Probabilidades dos outros ingredientes.
                    probability = probability * result;
                    //probability = probability * get_ingredient_probability(tables->list[j], recipes->list[i]->ingredients[z]);
                }

                // Multiplica P(c|yes) -> Formula Naive Bayes
                probability = probability * tables->list[j]->p_c_y;
                if (probability > max_probability) {
                    max_probability = probability;
                    id = tables->list[j]->id;
                    strcpy(name, tables->list[j]);
                }
                fprintf(fp,"\n%d,%s", recipes->list[i]->id, name);
            }


                //printf("%d\n", i);
                /*result_t *r = (result_t *) malloc(sizeof(result_t));
                strcpy(r->name, name);
                r->id = recipes->list[i]->id;
                results[number_of_results] = r;
                number_of_results++;*/
            //fprintf(fp,"\n%d,%s", recipes->list[i]->id, name);
        }
    };
    fclose(fp);
    return results;
}

double calculate_table_probability(Likelihood_Table * table, recipe_t * recipe){
    double probability = 1;

    for(int z = 0; z < recipe->number_ingredients; z++){
        probability = probability * get_ingredient_probability(table, recipe->ingredients[z]);
    }

    probability = probability * table->p_c_y;

    return probability;
}

double get_ingredient_probability(Likelihood_Table * table, char * ingredient){

    Ingredient * found;
    for(int i = 0; i < table->ingredients->number_of_ingredients; i++){
        if(strcmp(ingredient, table->ingredients->list[i]->name) == 0){
            found = table->ingredients->list[i];
            break;
        }
    }
    if(found == NULL){
        return 1;
    }
    double result = found->p_x_c * table->p_c_y / found->p_x;

    //printf("%f %f %f %f\n", found->p_x_c, table->p_c_y, found->p_x, result);

    return result;
}
void print_tables(List_likelihood_table * tables, int withIngredients){
    for(int i = 0; i < tables->count; i++){
        print_table(tables->list[i], withIngredients);
    }
}
void print_table(Likelihood_Table * table, int withIngredients){
    printf("Name: %s, n_ing_yes: %d, n_ing_no: %d, p_c_y: %lF, p_c_n: %lF\n Ingredients:\n", table->name, table->n_ing_yes, table->n_ing_no, table->p_c_y, table->p_c_n);
    if(withIngredients == 1){
        print_list_of_ingredients(table->ingredients);
    }
}
void update_ingredients_on_table(recipe_t * recipe, List_Of_Ingredients * list){
    for(int v = 0; v < recipe->number_ingredients; v++){
        Ingredient * ingredient = recipe->ingredients[v];
        int found = 0;
        int i;

        for(i = 0; i < list->number_of_ingredients; i++){
            if(strcmp(ingredient->name, list->list[i]->name) == 0){
                found = 1;
                break;
            }
        }
        if(found == 0){
            Ingredient * new_ingredient = (Ingredient *) malloc(sizeof(Ingredient));
            strcpy(new_ingredient, ingredient->name);
            new_ingredient->p_x = 0;
            new_ingredient->amount_no = 0;
            new_ingredient->amount_yes = 1;
            new_ingredient->p_x_c = 0;
            list->list[list->number_of_ingredients] = new_ingredient;
            list->number_of_ingredients++;
            list->list = realloc(list->list, list->number_of_ingredients * sizeof(Ingredient));
        }else{
            list->list[i]->amount_yes++;
        }
    }
}
List_Of_Ingredients * mount_ingredient_list(List_Of_Recipes * recipes){
    List_Of_Ingredients * list = (List_Of_Ingredients *) malloc(sizeof(List_Of_Ingredients));
    //ingredients->number_of_ingredients = 0;
    list->list = (Ingredient *) malloc(sizeof(Ingredient));
    int number_of_ingredients = 0;
    int total_ingredients = 0;

        // Populate tables.
        for (int i = 0; i < recipes->total_recipes; i++) {
            recipe_t *recipe = recipes->list[i];
            for (int j = 0; j < recipe->number_ingredients; j++) {
                int found = 0;
                int x = 0;
                //TODO: Dar pra paralelizar a pesquisa nos ingredientes, divide em chunks e dar um join depois para ver se foi encontrado.
                for (x = 0; x < number_of_ingredients; x++) {
                    if (strcmp(list->list[x]->name, recipe->ingredients[j]) == 0) {
                        found = 1;
                        break;
                    }
                }

                // If not found, add.
                if (found == 0) {
                    Ingredient *ingredient = (Ingredient *) malloc(sizeof(Ingredient));
                    strcpy(ingredient->name, recipe->ingredients[j]);
                    ingredient->amount_yes = 1;
                    ingredient->amount_no = 0;
                    ingredient->p_x = 0;
                    ingredient->p_x_c = 0;
                    ingredient->next = NULL;
                    list->list[number_of_ingredients] = ingredient;
                    number_of_ingredients++;
                    list->list = realloc(list->list, number_of_ingredients * sizeof(Ingredient));
                    //add(hash, ingredient);
                } else {
                    list->list[x]->amount_yes++; // Quantidade de ingredientes.
                }
                total_ingredients++;
            }
        }

    list->number_of_ingredients = number_of_ingredients;
    list->total_ingredients = total_ingredients;
    return list;
}

void print_list_of_ingredients(List_Of_Ingredients * ingredients){
    for(int i = 0; i < ingredients->number_of_ingredients; i++){
        print_ingredient(ingredients->list[i]);
    }
}

void print_ingredient(Ingredient * ingredient){
    printf("Name: %s, Amount_yes:  %d, Amount_no: %d, p_x_c: %lF, p_x %lF\n", ingredient->name, ingredient->amount_yes, ingredient->amount_no, ingredient->p_x_c, ingredient->p_x);
}


void writeCSV(result_t **receipes, int number){
    FILE *fp;

    fp=fopen("output.csv","w+");

    fprintf(fp,"id,cuisine");

    for(int i =0; i < number; i++){
        printf("%s, %d\n", receipes[i]->name, receipes[i]->id);
        fprintf(fp,"\n%d,%s", receipes[i]->id, receipes[i]->name);
    }

    fclose(fp);
}