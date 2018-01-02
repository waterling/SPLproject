#pragma once

#include <stdio.h>          //Библиотека IO
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <direct.h>
#include <stdint.h>
#include "config.h"

#define PARAMS_COUNT 3
#define PATH_LIMIT 500
#define DB_NAME_LIMIT_LIMIT 30

typedef struct db_init {
    char database_name[DB_NAME_LIMIT_LIMIT];
    char path_control_file[PATH_LIMIT];
} db_init;

int create_table(char *string);

int create_database(char *string);

int save_init(char *filename, struct db_init *db_init);

int load_init(char *filename, struct db_init *db_init);



