#ifndef DUPLICATION_FINDER_THREAD_POOL_H
#define DUPLICATION_FINDER_THREAD_POOL_H

#include "boost/asio/thread_pool.hpp"


//NOTE: boost asio entry....
namespace Processor::Concurrency {
    using TP = boost::asio::thread_pool;

    class ThreadPool {
    private:
        TP threadPool;
    public:
        ThreadPool() noexcept = default;
    };
}


#endif //DUPLICATION_FINDER_THREAD_POOL_H
