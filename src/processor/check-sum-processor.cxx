#include <utility>

#include "check-sum-processor.h"

namespace Processor {

    CheckSumProcessor::CheckSumProcessor(std::vector<std::unique_ptr<File>> &&listOfFiles) :
            listOfFiles(std::move(listOfFiles)) {
    }

    void CheckSumProcessor::calculateChunkHash(std::streamsize size) {
        checkSumBuilder.process_bytes(fileChunkBuffer, size);
    }

    uMultiMap CheckSumProcessor::getCheckSumFileBundle() {
        for (auto & file : listOfFiles) {
            if (!file->getCurrentFileStream()) {
                std::cerr << "Could not open the file..." << file->getFileName() << std::endl;
                exit(1);
            }

            do {
                file->getCurrentFileStream().read(fileChunkBuffer, buffer_size);

                calculateChunkHash(file->getCurrentFileStream().gcount());

            } while (file->getCurrentFileStream());
            fileHashBundle.emplace(std::make_pair(checkSumBuilder.checksum(), file->getFileName()));
            checkSumBuilder.reset();
        }
        return fileHashBundle;
    }
}
