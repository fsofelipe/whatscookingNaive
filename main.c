//
// Created by matheus on 23/07/17.
//

#include <stdio.h>
#include "main.h"

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
        while ((getline(&line, &len, file)) != -1) {
            printf("%s", line);
        }
        fclose(file);
    }
}
int main(){
    Recipe * entry;
    Recipe * test;

    read_file(1);

    printf("Hello world!");
}