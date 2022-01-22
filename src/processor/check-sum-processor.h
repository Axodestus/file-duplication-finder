#ifndef DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H
#define DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H

#include <boost/crc.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "entity/file.h"

namespace Processor {
    constexpr int BUFFER_SIZE = 1024;

    constexpr std::streamsize buffer_size = BUFFER_SIZE;

    using CRC32Type = boost::crc_32_type;
    using File = Processor::Entity::File;

    class CheckSumProcessor {
    private:
        CRC32Type checkSumBuilder;
        std::shared_ptr<File> file;
        std::vector<std::shared_ptr<File>> listOfFiles;

        char fileChunkBuffer[BUFFER_SIZE];


        std::unordered_multimap<std::string, unsigned int> fileHashBundle;

        void calculateChunkHash(std::streamsize size);
    public:
        explicit CheckSumProcessor(std::string &&fileName);
        CheckSumProcessor(std::vector<std::shared_ptr<File>> listOfFiles);
        auto calculateCheckSum();
        auto getCheckSumFileBundle();
    };
}

#endif //DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H
