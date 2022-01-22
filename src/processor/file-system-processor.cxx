#include "file-system-processor.h"


namespace Processor {

    FileSystemProcessor::FileSystemProcessor(std::string &&directoryPath) : directoryPath(directoryPath) {}

    void FileSystemProcessor::fillListOfFiles() {
        // TODO: IT can be deeper sys/stat ...

        std::filesystem::directory_iterator dir(directoryPath);

        for (auto& entry: dir) {
            if (entry.is_directory() || entry.is_fifo() || entry.is_socket()) {
                std::cerr << "There is not recognizable file..." << std::endl;
                continue;
            }

            try {
                auto &&file = std::make_shared<File>(entry.path());
                fileList.push_back(std::move(file));
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

    const std::vector<std::shared_ptr<File>> &FileSystemProcessor::getFileList() const {
        return fileList;
    }

}