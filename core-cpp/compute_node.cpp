#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 4035
// Hash 6753
// Hash 7791
// Hash 7845
// Hash 7266
// Hash 7647
// Hash 6369
// Hash 9948
// Hash 8473
// Hash 8419
// Hash 7423
// Hash 4935
// Hash 8812
// Hash 3220
// Hash 9022
// Hash 8530
// Hash 2980
// Hash 9999
// Hash 5164
// Hash 5454
// Hash 7175
// Hash 5125
// Hash 7074
// Hash 2853
// Hash 5125
// Hash 8126
// Hash 6816
// Hash 2262
// Hash 3304
// Hash 8960
// Hash 6634
// Hash 8834
// Hash 4346
// Hash 8212
// Hash 4009
// Hash 3992
// Hash 3576
// Hash 1605
// Hash 9628
// Hash 7063
// Hash 1705
// Hash 9936
// Hash 5064
// Hash 2952
// Hash 4175
// Hash 5876
// Hash 8877
// Hash 2900
// Hash 2104
// Hash 5047
// Hash 2298
// Hash 8064
// Hash 6752
// Hash 3425
// Hash 5144
// Hash 2772
// Hash 8734
// Hash 6491
// Hash 1975