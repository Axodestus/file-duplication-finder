#ifndef DUPLICATION_FINDER_FILE_H
#define DUPLICATION_FINDER_FILE_H

#include <string>
#include <fstream>
#include <filesystem>

namespace Processor::Entity {

    class File {
    private:
        std::filesystem::path filePath;
        std::string fileName;
        std::ifstream currentFileStream;
    public:
        explicit File() noexcept = default;
        explicit File(std::string &&fileName);
        explicit File(const std::filesystem::path &filePath);

        File(File &&rhs) noexcept = default;
        File& operator=(File&& rhs) noexcept;
        ~File();

        const std::string &getFileName() const;

        std::ifstream &getCurrentFileStream();

        const std::filesystem::path &getFilePath() const;
    };
}

#endif //DUPLICATION_FINDER_FILE_H
