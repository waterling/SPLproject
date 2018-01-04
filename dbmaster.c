
#include "dbmaster.h"

int create_table(char *string) {
    printf("Creating table: %s \n", string);

    uint32_t table_name_length = strstr(strstr(string, "\"") + 1, "\"") - strstr(string, "\"") + 1;
    printf("Table name size: %u \n", table_name_length);

    char table_name[table_name_length];
    strncpy(table_name, string, table_name_length);
    table_name[table_name_length] = 0;
    printf("Table name: %s \n", table_name);


    uint32_t table_arguments_length = strstr(string, ")") - 2 - string - table_name_length;
    printf("Table arguments size: %u \n", table_arguments_length);

    char table_arguments[table_arguments_length];
    strncpy(table_arguments, strstr(string, "(") + 1, table_arguments_length);
    table_arguments[table_arguments_length] = 0;
    printf("Table arguments: %s \n", table_arguments);

    size_t column_count = 1;
    for (int i = table_arguments_length; i > 0; --i) {
        if (table_arguments[i] == ',') {
            column_count++;
        }
    }
    char *columns[column_count];

    char delim[] = ",";
    char *p = strtok(table_arguments, delim);
    size_t counter = 0;
    while (p != NULL) {
        columns[counter++] = p;
        p = strtok(NULL, delim);
    }
    for (int j = 0; j < column_count; ++j) {
        printf("Column %d: %s\n", j, columns[j]);
    }

    char *column_info[column_count][PARAMS_COUNT];
    for (int k = 0; k < column_count; ++k) {
        char delim_info[] = " ";
        p = strtok(columns[k], delim_info);
        counter = 0;
        printf("Column #%d\n", k);
        while (p != NULL) {
            column_info[k][counter++] = p;
            p = strtok(NULL, delim_info);
            if ((p == NULL || !strcmp(p, "NULL"))) {
                column_info[k][counter++] = "0";
                p = strtok(NULL, delim_info);
            }
            if (p != NULL && !strcmp(p, "NOT")) {
                column_info[k][counter++] = "1";
                p = strtok(NULL, delim_info);
            }
        }
        printf("Name: %s\n", column_info[k][0]);
        printf("Type: %s\n", column_info[k][1]);
        printf("NOtNull: %s\n", column_info[k][2]);
    }
    db_init db_init;
    load_init(INIT_FILE, &db_init);
    return 0;
}

int without_quotes(char *result, char *string) {
    strncpy(result, string - 1, strlen(string) - 2);
    printf("\n%s\n", result);
    return 0;
}

int create_database(char *string) {
    uint32_t database_name_length = strstr(strstr(string, "\"") + 1, "\"") - strstr(string, "\"") - 1;
    printf("Database name size: %u \n", database_name_length);

    char database_name[database_name_length];
    strncpy(database_name, strstr(string, "\"") + 1, database_name_length);
    database_name[database_name_length] = 0;
    printf("Database name: %s \n", database_name);


    char control_fn[database_name_length + strlen(CONTROL_PATH) + strlen(DATABASE_FILE_EXTENSION)];
    strcpy(control_fn, CONTROL_PATH);
    strcat(control_fn, database_name);
    strcat(control_fn, DATABASE_FILE_EXTENSION);


    db_init temp_db_init;
    strcpy(temp_db_init.database_name, database_name);
    if ((load_init(INIT_FILE, &temp_db_init))) {
        return 1;
    } else {
        save_init(INIT_FILE, &temp_db_init);
    }
}

int save_init(char *filename, struct db_init *db_init) {
    FILE *init_file;
    char *c;
    int size = sizeof(struct db_init);
    init_file = fopen(INIT_FILE, "wb");

    if (!init_file) {
        mkdir("db");
        mkdir("./db/control");
        mkdir("./db/bin");
        if (!(init_file = fopen(INIT_FILE, "wb+")))
            return (1);

    }

    c = (char *) db_init;
    for (int i = 0; i < size; i++) {
        putc(*c++, init_file);
    }
    fclose(init_file);
    printf("Saved name:%-30s\n", db_init->database_name);
    return 0;
}

int load_init(char *filename, struct db_init *db_init) {
    FILE *fp;
    char *c;
    int i;
    size_t size = sizeof(struct db_init);
    struct db_init *ptr = (struct db_init *) malloc(size);

    if ((fp = fopen(filename, "rb")) == NULL) {
        return 1;
    }

    c = (char *) ptr;
    while ((i = getc(fp)) != EOF) {
        *c = (char) i;
        c++;
    }

    fclose(fp);
    printf("Loaded: %-30s\n", ptr->database_name);
    free(ptr);
    return 0;
}