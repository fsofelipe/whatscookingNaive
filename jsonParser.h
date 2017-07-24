//
// Created by matheus on 24/07/17.
//

#ifndef WHATSCOOKINGNAIVE_JSONPARSER_H
#define WHATSCOOKINGNAIVE_JSONPARSER_H
#include <json/json.h>
#include <stdio.h>

void print_json_value(json_object *jobj);
void json_parse_array( json_object *jobj, char *key);
void json_parse(json_object * jobj);
#endif //WHATSCOOKINGNAIVE_JSONPARSER_H
