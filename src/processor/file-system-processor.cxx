#include "file-system-processor.h"


namespace Processor {

    FileSystemProcessor::FileSystemProcessor(Path &&path) : directoryPath(std::move(path)) {}

    void FileSystemProcessor::putFiles() {
        // TODO: IT can be deeper sys/stat ...

        std::filesystem::directory_iterator dir(directoryPath);

        if (!dir->is_directory()) {
            throw std::runtime_error("There is not a directory");
        }

        for (auto &entry: dir) {
            if (entry.is_directory() || entry.is_fifo() || entry.is_socket()) {
                std::cerr << "There is not recognizable file..." << std::endl;
                continue;
            }

            try {
                auto file = std::make_unique<File>(entry.path());
                fileList.emplace_back(std::move(file));
            } catch (std::bad_alloc &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    void FileSystemProcessor::debugPrint() {
        for (auto &file: fileList) {
            std::cout << file->getFilePath().string() << std::endl;
        }
    }

    std::vector<std::unique_ptr<File>> &&FileSystemProcessor::takeFileList() {
        return std::move(fileList);
    }

    void FileSystemProcessor::setDirectoryPath(const Path &directoryPath) {
        FileSystemProcessor::directoryPath = directoryPath;
    }

}