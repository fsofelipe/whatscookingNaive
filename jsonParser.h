//
// Created by matheus on 24/07/17.
//

#ifndef WHATSCOOKINGNAIVE_JSONPARSER_H
#define WHATSCOOKINGNAIVE_JSONPARSER_H
#include <json/json.h>
#include <stdio.h>
#include "main.h"

void print_json_value(json_object *jobj, Recipe * recipe, int cuisine);
void json_parse_array( json_object *jobj, char *key, Recipe * recipe);
void json_parse(json_object * jobj, Recipe * recipe);
#endif //WHATSCOOKINGNAIVE_JSONPARSER_H
