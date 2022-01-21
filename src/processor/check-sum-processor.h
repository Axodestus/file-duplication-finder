#ifndef DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H
#define DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H

#include <boost/crc.hpp>
#include <fstream>
#include <iostream>
#include <string>

namespace Processor {
    constexpr int BUFFER_SIZE = 1024;

    constexpr std::streamsize buffer_size = BUFFER_SIZE;

    using CRC32Type = boost::crc_32_type;

    class CheckSumProcessor {
    private:
        CRC32Type fileCheckSum;

        std::string fileName;

        char fileChunkBuffer[BUFFER_SIZE];

    public:
        explicit CheckSumProcessor(std::string &&fileName);

        const CRC32Type &getFileCheckSum() const;

        void setFileCheckSum(const CRC32Type &fileCheckSum);

        const std::string &getFileName() const;

        void setFileName(const std::string &fileName);
    };
}

#endif //DUPLICATION_FINDER_CHECK_SUM_PROCESSOR_H
