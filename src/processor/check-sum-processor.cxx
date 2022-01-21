#include <utility>

#include "check-sum-processor.h"

namespace Processor {

    CheckSumProcessor::CheckSumProcessor(std::string &&fileName) :
    fileName(fileName) {}

    const CRC32Type &CheckSumProcessor::getFileCheckSum() const {
        return fileCheckSum;
    }

    void CheckSumProcessor::setFileCheckSum(const CRC32Type &fileCheckSum) {
        CheckSumProcessor::fileCheckSum = fileCheckSum;
    }

    const std::string &CheckSumProcessor::getFileName() const {
        return fileName;
    }

    void CheckSumProcessor::setFileName(const std::string &fileName) {
        CheckSumProcessor::fileName = fileName;
    }
}
