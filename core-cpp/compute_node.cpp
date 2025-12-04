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
// Hash 6727
// Hash 1844
// Hash 7267
// Hash 8976
// Hash 5529
// Hash 8179
// Hash 4049
// Hash 3713
// Hash 9335
// Hash 3843
// Hash 5563
// Hash 9264
// Hash 8638
// Hash 5032
// Hash 3220
// Hash 9379
// Hash 2284
// Hash 9512
// Hash 5737
// Hash 4054
// Hash 2505
// Hash 1609
// Hash 4934
// Hash 1080
// Hash 1367
// Hash 5898
// Hash 3261
// Hash 9898
// Hash 7628
// Hash 9438
// Hash 2099
// Hash 9274
// Hash 8548
// Hash 2334
// Hash 1751
// Hash 1189
// Hash 8138
// Hash 2976
// Hash 5040
// Hash 7706
// Hash 1240
// Hash 2958
// Hash 4238
// Hash 2246
// Hash 9820
// Hash 2539
// Hash 7892
// Hash 8138
// Hash 6899
// Hash 4384
// Hash 8165
// Hash 5536
// Hash 4869
// Hash 5728
// Hash 3403
// Hash 5310
// Hash 8238
// Hash 7432
// Hash 3987
// Hash 8463
// Hash 3723
// Hash 8385
// Hash 1526
// Hash 1933
// Hash 6111
// Hash 4808
// Hash 9808
// Hash 6464
// Hash 6579
// Hash 5741
// Hash 5445
// Hash 9200
// Hash 2270
// Hash 6660
// Hash 9042
// Hash 5980
// Hash 8832
// Hash 7275
// Hash 1389
// Hash 9582
// Hash 3334
// Hash 2305
// Hash 6638
// Hash 2035
// Hash 7529
// Hash 9117
// Hash 5033
// Hash 8584
// Hash 1715
// Hash 3453
// Hash 5860
// Hash 8616
// Hash 1395
// Hash 8315
// Hash 3499
// Hash 3561
// Hash 2126
// Hash 3960
// Hash 7664
// Hash 8174
// Hash 4565
// Hash 2693
// Hash 1016
// Hash 2975
// Hash 2904
// Hash 3527
// Hash 1711
// Hash 9629
// Hash 8959
// Hash 5337
// Hash 3903
// Hash 3188
// Hash 4394
// Hash 5686
// Hash 3193
// Hash 2590
// Hash 3619
// Hash 4451
// Hash 2386