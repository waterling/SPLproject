#pragma once

#include <stdio.h>          //Библиотека IO
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dbmaster.h"


void parse_string(char *temp_query);

char* read_string(size_t size);
