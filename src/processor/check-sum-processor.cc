#include <utility>

#include "check-sum-processor.h"

namespace Processor {

CheckSumProcessor::CheckSumProcessor(std::vector<std::unique_ptr<File>>&& listOfFiles)
    : listOfFiles(std::move(listOfFiles))
{
}

CheckSumProcessor::CheckSumProcessor() noexcept
{
}

void CheckSumProcessor::calculateChunkHash(std::streamsize size)
{
    checkSumBuilder.process_bytes(fileChunkBuffer, size);
}

// NOTE: It's not good for me. I'll must parse that shit...
uMultiMap&& CheckSumProcessor::takeCheckSumFileBundle()
{
    for (auto& file : listOfFiles) {
        if (!file->getCurrentFileStream()) {
            std::cerr << "Could not open the file..." << file->getFileName() << std::endl;
        }

        // NOTE: Problem with very big data.
        do {
            file->getCurrentFileStream().read(fileChunkBuffer, buffer_size);
            calculateChunkHash(file->getCurrentFileStream().gcount());

        } while (file->getCurrentFileStream());

        try {
            fileHashBundle.emplace(std::make_pair(checkSumBuilder.checksum(), file->getFileName()));
        } catch (std::bad_alloc& e) {
            std::cerr << e.what() << std::endl;
        }

        checkSumBuilder.reset();
    }
    return std::move(fileHashBundle);
}

void CheckSumProcessor::setListOfFiles(std::vector<std::unique_ptr<File>>&& listOfFiles)
{
    CheckSumProcessor::listOfFiles = std::move(listOfFiles);
}

}
