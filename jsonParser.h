//
// Created by matheus on 24/07/17.
//


#ifndef WHATSCOOKINGNAIVE_JSONPARSER_H
#define WHATSCOOKINGNAIVE_JSONPARSER_H

#include <json/json_object.h>
#include "cuisine.h"

void print_json_value(json_object *jobj, recipe_t * recipe, int cuisine);
void json_parse_array( json_object *jobj, char *key, recipe_t * recipe); 
void json_parse(json_object * jobj, recipe_t * recipe);
#endif //WHATSCOOKINGNAIVE_JSONPARSER_H
