#include "main.h"

int main(int argc, char **argv) {
    parse_string("CREATE database IF NOT EXIST \"MY DATABASE\"");
    parse_string("create TABLE \"TABLE_NAME\" (\"name\" text NOT NULL, \"num\" int NULL, \"age\" int);");
//    parse_string("create");

    return 0;
}