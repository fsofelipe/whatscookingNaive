//
// Created by matheus on 24/07/17.
//
#include "jsonParser.h"

/*printing the value corresponding to boolean, double, integer and strings*/
void print_json_value(json_object *jobj, Recipe * recipe, int cuisine){
    enum json_type type;
    //printf("type: ",type);
    type = json_object_get_type(jobj); /*Getting the type of the json object*/
    switch (type) {
        case json_type_boolean: //printf("json_type_booleann");
            //printf("value: %sn", json_object_get_boolean(jobj)? "true": "false");
            break;
        case json_type_double: //printf("json_type_doublen");
            //printf("          value: %lfn", json_object_get_double(jobj));
            break;
        case json_type_int: //printf("json_type_intn");
            recipe->id = json_object_get_int(jobj);
            //printf("          value: %dn", json_object_get_int(jobj));
            break;
        case json_type_string: //printf("json_type_stringn");
            if(cuisine == 1){
                recipe->cuisine = json_object_get_string(jobj);
                //printf("CUISINE: %s\n", json_object_get_string(jobj));
            }
            //printf("          value: %sn", json_object_get_string(jobj));
            break;
    }

}

void json_parse_array( json_object *jobj, char *key, Recipe * recipe) {
    void json_parse(json_object * jobj, Recipe * recipe); /*Forward Declaration*/
    enum json_type type;

    json_object *jarray = jobj; /*Simply get the array*/
    if(key) {
        jarray = json_object_object_get(jobj, key); /*Getting the array if it is a key value pair*/
    }

    int arraylen = json_object_array_length(jarray); /*Getting the length of the array*/
    //printf("Array Length: %dn",arraylen);
    int i;
    json_object * jvalue;
    recipe->ingredients = (Ingredient*) malloc(arraylen * sizeof(Ingredient));
    recipe->number_ingredients = arraylen;
    //recipe->ingredients = malloc(arraylen);
    for (i=0; i< arraylen; i++){
        //recipe->ingredients[i] = (Ingredient *) malloc(sizeof(Ingredient));
        //recipe->ingredients[i] = malloc(20);
        jvalue = json_object_array_get_idx(jarray, i); /*Getting the array element at position i*/
        type = json_object_get_type(jvalue);
        if (type == json_type_array) {
            json_parse_array(jvalue, NULL, recipe);
        }
        else if (type != json_type_object) {
            //printf("value[%d]: ",i);
            print_json_value(jvalue, recipe, 0);
            recipe->ingredients[i] = (Ingredient *) malloc(sizeof(Ingredient));
            recipe->ingredients[i]->name = json_object_get_string(jvalue);
            //printf("Ingredient: %s\n", recipe->ingredients[i]);

        }
        else {
            json_parse(jvalue, recipe);
        }
    }
}

/*Parsing the json object*/
void json_parse(json_object * jobj, Recipe *recipe) {
    recipe->id = 1;
    enum json_type type;
    json_object_object_foreach(jobj, key, val) { /*Passing through every array element*/
        //printf("type: ",type);
        type = json_object_get_type(val);
        switch (type) {
            case json_type_boolean:
            case json_type_double:
            case json_type_int:
            case json_type_string:
                //printf("", val);
                print_json_value(val, recipe, 1);
                break;
            case json_type_object: //printf("json_type_objectn");
                jobj = json_object_object_get(jobj, key);
                json_parse(jobj, recipe);
                break;
            case json_type_array: //printf("type: json_type_array, ");
                json_parse_array(jobj, key, recipe);
                break;
        }
    }
}
