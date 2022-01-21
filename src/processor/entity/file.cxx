#include "file.h"

namespace Processor::Entity {

    File::File(std::string &&fileName) : fileName(fileName),
                                         currentFileStream(fileName, std::ios_base::binary) {
    }

    File::File(std::filesystem::path &&filePath) : filePath(filePath), fileName(filePath.string()),
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

}