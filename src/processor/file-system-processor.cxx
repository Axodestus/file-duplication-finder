#include "file-system-processor.h"


namespace Processor {

    FileSystemProcessor::FileSystemProcessor(std::string &&directoryPath) : directoryPath(directoryPath) {}

    void FileSystemProcessor::fillListOfFiles() {
        std::filesystem::directory_iterator dir(directoryPath);

        for (auto& entry: dir) {
//            if (entry.is_directory() || entry.is_fifo()) {
//                continue;
//            }
            auto file = std::make_unique<File>(entry.path().string());
            fileList.push_back(std::move(file));
        }

        //return std::move(fileList);
    }

    void FileSystemProcessor::debugPrint() {
        for (auto &file: fileList) {
            std::cout << file->getFileName() << std::endl;
        }
    }
}