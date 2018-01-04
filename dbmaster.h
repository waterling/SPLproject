#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <direct.h>
#include <stdint.h>
#include "config.h"

#define PARAMS_COUNT 3
#define PATH_LIMIT 500
#define DB_NAME_LIMIT 30
#define DB_TYPE_LIMIT 10
#define DB_CONNECTION_LIMIT 60

#pragma pack(push, 1)

typedef struct db_block_t {
    size_t capacity;
    uint8_t isfree;
} db_block_t;

typedef struct db_column_t {
    char column_name[DB_NAME_LIMIT];
    char column_type[DB_TYPE_LIMIT];
//    char connection[DB_CONNECTION_LIMIT];
    uint8_t not_null;
    uint8_t unique;
} db_column_t;

typedef struct db_table_t {
    char table_name[DB_NAME_LIMIT];
    uint32_t column_counter;
    db_column_t *columns;
} db_table_t;

typedef struct db_table_info_t {
    char table_name[DB_NAME_LIMIT];
} db_table_info_t;

typedef struct db_control {
    char database_name[DB_NAME_LIMIT];
//    char* tables_path;
    db_table_info_t *tables_names;
} db_control;

typedef struct db_init {
    char database_name[DB_NAME_LIMIT];
//    char path_control_file[PATH_LIMIT];
} db_init;

#pragma pack(pop)

int create_table(char *string);

int create_database(char *string);

int save_init(char *filename, struct db_init *db_init);

int load_init(char *filename, struct db_init *db_init);



