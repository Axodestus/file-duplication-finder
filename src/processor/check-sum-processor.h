#ifndef DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H
#define DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H

#include <boost/crc.hpp>

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "entity/file.h"

// NOTE: boost entry...
namespace Processor {

    // NOTE: Here we could discover OS and available optimal buffer for the faster stream block reading.
    constexpr int BUFFER_SIZE = 512;

    constexpr std::streamsize buffer_size = BUFFER_SIZE;

    using CRC32Type = boost::crc_32_type;
    using File = Processor::Entity::File;
    using uMultiMap = std::unordered_multimap<unsigned int, std::string>;

    class CheckSumProcessor {
    private:
        CRC32Type checkSumBuilder;

        char fileChunkBuffer[BUFFER_SIZE];

        std::vector<std::unique_ptr<File>> listOfFiles;

        uMultiMap fileHashBundle;

        void calculateChunkHash(std::streamsize size);

    public:
        explicit CheckSumProcessor(std::vector<std::unique_ptr<File>> &&listOfFiles);

        explicit CheckSumProcessor() noexcept;

        uMultiMap &&takeCheckSumFileBundle();

        void setListOfFiles(std::vector<std::unique_ptr<File>> &&listOfFiles);
    };
}

#endif //DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H
