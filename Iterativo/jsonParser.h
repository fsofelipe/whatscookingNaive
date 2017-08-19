#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <json/json_object.h>
#include "cuisine.h"

void print_json_value(json_object *jobj, recipe_t * recipe, int cuisine);
void json_parse_array( json_object *jobj, char *key, recipe_t * recipe);
void json_parse(json_object * jobj, recipe_t * recipe);
#endif //WHATSCOOKINGNAIVE_JSONPARSER_H
