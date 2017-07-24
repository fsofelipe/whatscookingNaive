//
// Created by matheus on 23/07/17.
//

#include <stdio.h>
#include "main.h"
#include <json/json.h>
#include "jsonParser.h"

void read_file(int type){
    //Type 1 = Train
    //Type 2 = Test

    int c;
    FILE *file;

    if(type == 1){
        file = fopen("train.json", "r");
    }else{
        file = fopen("test.json", "r");
    }

    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    if (file) {
        char *file_contents;
        long input_file_size;
        fseek(file, 0, SEEK_END);
        input_file_size = ftell(file);
        rewind(file);
        file_contents = malloc(input_file_size * (sizeof(char)));
        fread(file_contents, sizeof(char), input_file_size, file);
        fclose(file);

        int i = 0;
        for (i = 0; file_contents[i] != 0; i++){
            printf("%c", file_contents[i]);
            // Pega objeto por objeto.

            // Usar o json parse nele

            // Salva numa struct e adiciona no array.
        }
        //printf("%d", input_file_size);
        //printf("%s", file_contents);
    }

   /* char * string = "{\"id\": 3731,\n"
            "    \"cuisine\": \"mexican\",\n"
            "    \"ingredients\": [\n"
            "      \"tomatoes\",\n"
            "      \"green onions\",\n"
            "      \"garlic\",\n"
            "      \"dried oregano\",\n"
            "      \"ground black pepper\",\n"
            "      \"red wine vinegar\",\n"
            "      \"salsa\",\n"
            "      \"flour tortillas\",\n"
            "      \"shredded lettuce\",\n"
            "      \"white sugar\",\n"
            "      \"lime\",\n"
            "      \"boneless skinless chicken breasts\",\n"
            "      \"salt\",\n"
            "      \"shredded Monterey Jack cheese\"\n"
            "    ]}";
    printf("JSON string: %sn", string);
    json_object * jobj = json_tokener_parse(string);
    json_parse(jobj);*/
}

int main() {
    read_file(1);
}
