#include "duplication-finder.h"

#define DEBUG

int main() {

    // we have a 3 sys calls
    // open() read() clos()
    // open() => O(n) -> read() => O(n^2) -> clos() => O(N^2 + n)
    // O(N^2 + n)


    //Some experiments




    //================
    try {
        Duplication::DuplicationFinder finder("/home/duckway/folder1", "/home/duckway/folder2");
        finder.findDuplicates();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
