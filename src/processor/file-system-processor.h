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

        //NOTE: Too much io syscalls at now. So, we'll should... can make the threadpool.
        std::vector<std::unique_ptr<File>> fileList;
        Path directoryPath;
    public:
        void setDirectoryPath(const Path &directoryPath);

        explicit FileSystemProcessor(Path &&path);

        explicit FileSystemProcessor() noexcept = default;

        void putFiles();

        void debugPrint();

        std::vector<std::unique_ptr<File>> &&takeFileList();
    };
}


#endif //DUPLICATION_FINDER_FILE_SYSTEM_PROCESSOR_H
