#ifndef DUPLICATION_FINDER_FILE_H
#define DUPLICATION_FINDER_FILE_H

#include <string>
#include <fstream>
#include <filesystem>

namespace Processor::Entity {

    class File {
    private:
        std::filesystem::path filePath;
    public:
        const std::filesystem::path &getFilePath() const;

    private:

        std::string fileName;
        std::ifstream currentFileStream;
    public:
        File(std::string &&fileName);
        File(std::filesystem::path &&fileName);
        ~File();
        const std::string &getFileName() const;
        std::ifstream &getCurrentFileStream();
    };
}

#endif //DUPLICATION_FINDER_FILE_H
