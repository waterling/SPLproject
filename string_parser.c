//
// Created by vadim on 01.01.2018.
//

#include "string_parser.h"


void parse_string(char *query){
    char temp_query[strlen(query)];
    strcpy(temp_query,query);
    size_t i =0;
    while (temp_query[i]){
        if(islower(temp_query[i])){
            temp_query[i] = (char) toupper(temp_query[i]);
        }

        i++;
    }
    if(!(temp_query-strstr(temp_query,"CREATE TABLE"))){
        create_table(temp_query+strlen("CREATE TABLE "));
    }

    if(!(temp_query-strstr(temp_query,"CREATE DATABASE"))){
        if (!(temp_query-strstr(temp_query,"CREATE DATABASE IF NOT EXIST"))){
            create_database(temp_query+strlen("CREATE DATABASE IF NOT EXIST "));
        }else{
            create_database(temp_query+strlen("CREATE DATABASE "));
        }

    }

}

char* read_string( size_t size){
    char* sequenceArray[size];
    signed char currentLetter = 0;
    unsigned char counter;

    puts( "Enter query:" );
    fflush( stdout );

    for ( counter = 0; ( currentLetter = getchar()) != ';'&& counter < size; ++counter ) {

        sequenceArray[counter] = currentLetter;
    }
    sequenceArray[counter] = ';';

    return ( EXIT_SUCCESS );
}

