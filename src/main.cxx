#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "duplication-finder.h"

#define DEBUG

int main() {

    Duplication::DuplicationFinder finder("/home/duckway/folder1", "/home/duckway/folder2");
    finder.findDuplicates();

    return 0;
}
