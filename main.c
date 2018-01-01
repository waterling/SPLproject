#include "main.h"

int main() {
    parse_string("CREATE TABLE \"TABLE_NAME\" (\"name\" text NOT NULL, \"num\" int NULL, \"age\" int);");

    return 0;
}