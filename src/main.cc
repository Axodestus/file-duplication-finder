#include "duplication-finder.h"

#define DEBUG

int main()
{

    try {
        Duplication::DuplicationFinder finder("/home/duckway/folder1", "/home/duckway/folder2");
        finder.findDuplicates();
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
