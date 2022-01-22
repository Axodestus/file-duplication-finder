#ifndef DUPLICATION_FINDER_FILE_SYSTEM_PROCESSOR_H
#define DUPLICATION_FINDER_FILE_SYSTEM_PROCESSOR_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "entity/file.h"

namespace Processor {

    using File = Processor::Entity::File;

    class FileSystemProcessor {
    private:
        std::vector<std::shared_ptr<File>> fileList;         // too many may be
        const std::string directoryPath;
    public:
        explicit FileSystemProcessor(std::string &&directoryPath);
        void fillListOfFiles();
        void debugPrint();

        const std::vector<std::shared_ptr<File>> &getFileList() const;
    };
}


#endif //DUPLICATION_FINDER_FILE_SYSTEM_PROCESSOR_H
