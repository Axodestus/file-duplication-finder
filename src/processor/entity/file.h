#ifndef DUPLICATION_FINDER_FILE_H
#define DUPLICATION_FINDER_FILE_H

#include <string>
#include <fstream>
#include <filesystem>

namespace Processor::Entity {

    class File {
    private:
        const std::filesystem::path filePath;
        const std::string fileName;
        std::ifstream currentFileStream;
    public:
        File();
        File(File &file) = delete;
        File(File &&file) = default;
        File(std::string &&fileName);
        File(const std::filesystem::path &filePath);
        ~File();
        const std::string &getFileName() const;
        std::ifstream &getCurrentFileStream();
        const std::filesystem::path &getFilePath() const;
    };
}

#endif //DUPLICATION_FINDER_FILE_H
