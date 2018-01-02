#include "main.h"

int main() {
    parse_string("create TABLE \"TABLE_NAME\" (\"name\" text NOT NULL, \"num\" int NULL, \"age\" int);");
    parse_string("CREATE database IF NOT EXIST \"MY DATABASE\"");
    parse_string("CREATE DATABASE \"your DATABASE\"");
    parse_string("create");

    return 0;
}