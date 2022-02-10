#include "file-system-processor.h"

namespace Processor {

FileSystemProcessor::FileSystemProcessor(Path&& path)
    : isValidFilelist(false)
    , directoryPath(std::move(path))
{
    if (FileSystemProcessor::directoryPath.empty()) {
        std::cerr << "There is empty path (doesn't exist inode for some reason)" << std::endl;
    }
    FileSystemProcessor::directoryPath = "/home";
    std::cout << "The default /home directory has been selected" << std::endl;
}

void FileSystemProcessor::putFiles()
{
    // TODO: IT can be deeper sys/stat ...

    std::filesystem::directory_iterator dir(directoryPath);

    if (!directoryPath.has_root_directory()) {
        std::cout << dir->path().string(); // debug...
        throw std::runtime_error("There is not a directory...");
    }

    for (auto& entry : dir) {
        if (entry.is_directory() || entry.is_fifo() || entry.is_socket()) {
            std::cerr << "There is not recognizable file..." << std::endl;
            continue;
        }

        try {
            auto file = std::make_unique<File>(entry.path());
            fileList.emplace_back(std::move(file));
        } catch (std::bad_alloc& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    isValidFilelist = true;
}

void FileSystemProcessor::debugPrint()
{
    for (auto& file : fileList) {
        std::cout << file->getFilePath().string() << std::endl;
    }
}

std::vector<std::unique_ptr<File>>&& FileSystemProcessor::takeFileList()
{
    if (!isValidFilelist) {
        throw std::runtime_error("The filelist doesn't have been built or was taken...");
    }
    isValidFilelist = false;
    return std::move(fileList);
}

void FileSystemProcessor::setDirectoryPath(const Path& directoryPath)
{
    FileSystemProcessor::directoryPath = directoryPath;
    if (FileSystemProcessor::directoryPath.empty()) {
        throw std::runtime_error("There is empty path (doesn't exist inode for some reason)");
    }
}

}
