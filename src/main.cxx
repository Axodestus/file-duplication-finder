#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "duplication-finder.h"

#define DEBUG

int main() {

    Duplication::DuplicationFinder finder("/home/duckway/folder1", "/home/duckway/folder2");
    finder.findDuplicates();

//    Processor::FileSystemProcessor proc("/home/duckway");
//    proc.putFiles();
//    Processor::CheckSumProcessor check(proc.getFileList());
//    //proc.debugPrint();
//    for (auto &fileName : check.getCheckSumFileBundle()) {
//        std::cout << fileName.first << " -> " << fileName.second << std::endl;
//    }

    return 0;
}
