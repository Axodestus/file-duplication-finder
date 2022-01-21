#include <utility>

#include "check-sum-processor.h"

namespace Processor {
    CheckSumProcessor::CheckSumProcessor(std::string &&fileName) : file(std::move(fileName)) {}

    void CheckSumProcessor::calculateChunkHash(std::streamsize size) {
        checkSumBuilder.process_bytes(fileChunkBuffer, size);
    }

    auto CheckSumProcessor::calculateCheckSum(){
        if (!file.getCurrentFileStream()) {
            std::cerr << "Could not open the file..." << file.getFileName() << std::endl;
            exit(1);
        }

        do {
            file.getCurrentFileStream().read(fileChunkBuffer, buffer_size);

            calculateChunkHash(file.getCurrentFileStream().gcount());

        } while (file.getCurrentFileStream());
        return checkSumBuilder.checksum();
    }
}
