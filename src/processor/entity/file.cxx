#include "file.h"

namespace Processor::Entity {

    File::File(std::string &&fileName) : fileName(fileName),
                                         currentFileStream(fileName, std::ios_base::binary) {
    }

    File::File(const std::filesystem::path &filePath) : filePath(filePath), fileName(filePath.string()),
                                                   currentFileStream(fileName, std::ios_base::binary) {
    }

    File::~File() {
        currentFileStream.close();
    }

    const std::string &File::getFileName() const {
        return fileName;
    }

    std::ifstream &File::getCurrentFileStream() {
        return currentFileStream;
    }

    const std::filesystem::path &File::getFilePath() const {
        return filePath;
    }

    File &File::operator=(File &&rhs) noexcept {
        std::swap(fileName, rhs.fileName);
        std::swap(filePath, rhs.filePath);
        std::swap(currentFileStream, rhs.currentFileStream);
        return *this;
    }

}