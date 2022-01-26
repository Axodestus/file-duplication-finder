#include "duplication-finder.h"

namespace Duplication {

    DuplicationFinder::DuplicationFinder(Path &&firstFolderPath, Path &&secondFolderPath) :
            firstFolderPath(std::move(firstFolderPath)), secondFolderPath(std::move(secondFolderPath)) {
        if (firstFolderPath == secondFolderPath) {
            std::cerr << "[Warning]: The same paths was chosen..." << std::endl;
        }
        putFileBundles();
    }

    void DuplicationFinder::putFileBundles() {
        fsProcessor.setDirectoryPath(firstFolderPath);
        fsProcessor.putFiles();
        fsProcessor.setDirectoryPath(secondFolderPath);
        fsProcessor.putFiles();

        //NOTE: Collapse may be...
        auto &&files = fsProcessor.takeFileList();

        csProcessor.setListOfFiles(std::move(files));

        fileHashBundle = std::move(csProcessor.takeCheckSumFileBundle());
    }

    // NOTE: Raw realization...it is not good for me...
    void DuplicationFinder::findDuplicates() {
        auto begin = fileHashBundle.begin();
        auto end = fileHashBundle.end();

        for (auto &it = begin; it != end; ++it) {
            auto range = fileHashBundle.equal_range(it->first);
            auto countOfDuplicates = std::distance(range.first, range.second);

            if (countOfDuplicates > 1) {
                std::cout << "==================" << std::endl;
                for (auto &itr = range.first; itr != range.second; ++itr) {
                    std::cout << itr->first << " -> " << itr->second << std::endl;
                }

                std::advance(it, countOfDuplicates - 1);
                std::cout << "Found " << countOfDuplicates << " duplicates of files" << std::endl;
            }

        }
    }

}