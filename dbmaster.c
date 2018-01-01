
#include <stdint.h>
#include "dbmaster.h"

int create_table(char *string) {
    printf("Creating table: %s \n", string);

    uint32_t table_name_length =  strstr(strstr(string, "\"")+1,"\"")-strstr(string, "\"")+1;
    printf("Table name size: %u \n", table_name_length);

    char table_name[table_name_length];
    strncpy(table_name, string, table_name_length);
    table_name[table_name_length]=0;
    printf("Table name: %s \n", table_name);


    uint32_t table_arguments_length = strstr(string, ")")-2 - string - table_name_length;
    printf("Table arguments size: %u \n", table_arguments_length);

    char table_arguments[table_arguments_length];
    strncpy(table_arguments, strstr(string, "(")+1, table_arguments_length);
    table_arguments[table_arguments_length]=0;
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
        printf("Column #%d\n",k);
        while (p != NULL) {
            column_info[k][counter++] = p;
            p = strtok(NULL, delim_info);
            if ((p==NULL || !strcmp(p,"NULL"))){
                column_info[k][counter++] ="0";
                p = strtok(NULL, delim_info);
            }
            if (p!=NULL && !strcmp(p,"NOT")){
                column_info[k][counter++] ="1";
                p = strtok(NULL, delim_info);
            }
        }
        printf("Name: %s\n",column_info[k][0]);
        printf("Type: %s\n",column_info[k][1]);
        printf("NOtNull: %s\n",column_info[k][2]);
    }


    return 1;
}




