#ifndef DUPLICATION_FINDER_DUPLICATION_FINDER_H
#define DUPLICATION_FINDER_DUPLICATION_FINDER_H

#include <unordered_map>
#include <string>
#include <memory>
#include <filesystem>
#include <utility>

#include "processor/file-system-processor.h"
#include "processor/check-sum-processor.h"

namespace Duplication {

    using uMultiMap = std::unordered_multimap<unsigned int, std::string>;
    using CSProcessor = Processor::CheckSumProcessor;
    using FSProcessor = Processor::FileSystemProcessor;
    using Path = std::filesystem::path;

    class DuplicationFinder {
    private:
        CSProcessor csProcessor;
        FSProcessor fsProcessor;

        uMultiMap fileHashBundle;
        Path firstFolderPath;
        Path secondFolderPath;

        void putFileBundles();

    public:
        DuplicationFinder(Path &&firstFolderPath, Path &&secondFolderPath);

        void findDuplicates();
    };
}


#endif //DUPLICATION_FINDER_DUPLICATION_FINDER_H
