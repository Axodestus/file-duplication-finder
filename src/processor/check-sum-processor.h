#ifndef DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H
#define DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H

#include <boost/crc.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "entity/file.h"

namespace Processor {
    constexpr int BUFFER_SIZE = 1024;

    constexpr std::streamsize buffer_size = BUFFER_SIZE;

    using CRC32Type = boost::crc_32_type;
    using File = Processor::Entity::File;

    class CheckSumProcessor {
    private:
        CRC32Type checkSumBuilder;
        File file;
        char fileChunkBuffer[BUFFER_SIZE];

        void calculateChunkHash(std::streamsize size);
    public:
        explicit CheckSumProcessor(std::string &&fileName);
        auto calculateCheckSum();
    };
}

#endif //DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H
