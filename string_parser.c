//
// Created by vadim on 01.01.2018.
//

#include <stdint-gcc.h>
#include "string_parser.h"


void parse_string(char * query){
    if(!(query-strstr(query,"CREATE TABLE"))){
        create_table(query+strlen("CREATE TABLE "));
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

