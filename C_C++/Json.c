#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        int boolean;
        double number;
        char *string;
        struct {
            struct JsonValue *values;
            size_t count;
        } array;
        struct {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;


char *json_object = "{\"ten\":\"Nguyen A\", \"tuoi\": 19, \"diachi\": \"HCM\"}";


char *type_string(char **json_object){
    char *value = (char*)malloc(sizeof(char));
    int i = 0;
    if(**json_object == '\"') (*json_object)++;
        while (**json_object != '\"')
        {
            value[i] = *((*json_object)++);
            i++;
            value = (char*)realloc(value, (i+1)*sizeof(char));
        }
    if(**json_object == '\"') (*json_object)++;
    return value;
}

char *type_number(char **json_object) {
    char *value = (char*)malloc(sizeof(char));
    int i = 0;
    while (**json_object != '\0' && (**json_object == '.' || **json_object == '-' || (**json_object >= '0' && **json_object <= '9'))) {
        value[i] = *((*json_object)++);
        i++;
        value = (char*)realloc(value, (i+1)*sizeof(char));
    }
    value[i] = '\0';
    return value;
}

void parse_json(char *json_object){

    char key[10];

    char value[20];
   
    int index = 0;
    int i = 0;
    while (1)
    {
        if(*json_object == '{') 
            json_object++;
            strcpy(key, type_string(&json_object));
            if(*json_object == ':') json_object++;
            strcpy(value, type_string(&json_object));
            printf("Key: %s, value: %s\n", key, value);

        if(*json_object == ',') json_object++;
        if(*json_object == ' ') json_object++;
        strcpy(key, type_string(&json_object)); //{\"ten\":\"Nguyen A\", \"tuoi\": 19, \"diachi\": \"HCM\"}
        if(*json_object == ':') json_object++;
        if(*json_object == ' ') json_object++;
        strcpy(value, type_number(&json_object));
        printf("Key: %s, value: %s\n", key, value);
        
        if(*json_object == ',') json_object++;
        if(*json_object == ' ') json_object++;
        strcpy(key, type_string(&json_object));
        if(*json_object == ':') json_object++;
        if(*json_object == ' ') json_object++;
        strcpy(value, type_string(&json_object)); //{\"ten\":\"Nguyen A\", \"tuoi\": 19, \"diachi\": \"HCM\"}
        printf("Key: %s, value: %s\n", key, value);

        break;
        
    }
    
}


int main(int argc, char const *argv[])
{
    parse_json(json_object);
    return 0;
}