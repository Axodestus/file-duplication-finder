#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "processor/file-system-processor.h"
#include "processor/check-sum-processor.h"

#define BUF_SIZE 1024

void cout_checksum(const std::string& file_path) {
    boost::crc_32_type result;
    std::streamsize buffer_size = BUF_SIZE;
    char buffer[buffer_size];

    std::ifstream current_file_stream(file_path, std::ios_base::binary);
    if (!current_file_stream) {
        std::cerr << "Could not open the file..." << std::endl;
        exit(1);
    }

    do {
        current_file_stream.read(buffer, buffer_size);
        result.process_bytes(buffer, current_file_stream.gcount());
    } while (current_file_stream);
    current_file_stream.close();

    std::cout << std::hex << std::uppercase << result.checksum() << std::endl;
}

void cout_directory_content(const std::string& folder) {
    std::filesystem::directory_iterator dir(folder);
    for (auto& entry : dir) {
        std::cout << entry.path() << std::endl;
        cout_checksum(entry.path());
    }
}

int main() {
    std::string folder1("/home/duckway/folder1");
    std::string folder2("/home/duckway/folder2");

    cout_directory_content(folder1);
    std::cout << "========================" << std::endl;
    cout_directory_content(folder2);
    std::cout << "=======================" << std::endl;

    Processor::FileSystemProcessor proc("/home/duckway");
    proc.fillListOfFiles();
    Processor::CheckSumProcessor check(proc.getFileList());
    //proc.debugPrint();
    for (auto &fileName : check.getCheckSumFileBundle()) {
        std::cout << fileName.first << " -> " << fileName.second << std::endl;
    }

    return 0;
}
