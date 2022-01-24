#include <utility>

#include "duplication-finder.h"

namespace Duplication {

    DuplicationFinder::DuplicationFinder(Path &&firstFolderPath, Path &&secondFolderPath) :
            firstFolderPath(std::move(firstFolderPath)), secondFolderPath(std::move(secondFolderPath)) {
        putFileBundles();
    }

    void DuplicationFinder::putFileBundles() {
        fsProcessor.setDirectoryPath(firstFolderPath);
        fsProcessor.putFiles();
        fsProcessor.setDirectoryPath(secondFolderPath);
        fsProcessor.putFiles();

        auto &&files = fsProcessor.takeFileList();

        csProcessor.setListOfFiles(std::move(files));

        fileHashBundle = std::move(csProcessor.takeCheckSumFileBundle());
    }

    void DuplicationFinder::findDuplicates() {
        for (auto &file_bundle: fileHashBundle) {
            std::cout << file_bundle.first << " -> " << file_bundle.second << std::endl;
        }
    }

}