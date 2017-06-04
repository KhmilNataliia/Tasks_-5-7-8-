#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

class Semaphore 
{
private:
	int max_count_;
	int count_ = 0;
	std::mutex mut_;
	std::condition_variable cv_;

public:
	explicit Semaphore(int max_count);
	void acquire();
	void release();
};