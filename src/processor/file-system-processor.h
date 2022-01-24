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
    using Path = std::filesystem::path;

    class FileSystemProcessor {
    private:
        std::vector<std::unique_ptr<File>> fileList;         // too many may be
        Path directoryPath;
    public:
        void setDirectoryPath(const Path &directoryPath);

    public:
        explicit FileSystemProcessor(Path &&path);

        explicit FileSystemProcessor() noexcept = default;

        void putFiles();

        void debugPrint();

        std::vector<std::unique_ptr<File>> &&takeFileList();
    };
}


#endif //DUPLICATION_FINDER_FILE_SYSTEM_PROCESSOR_H
