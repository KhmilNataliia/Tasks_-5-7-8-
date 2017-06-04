#include "stdafx.h"
#include "semaphore.h"

Semaphore::Semaphore(int max_count)
{
	if (max_count < 0) 
	{
		throw std::runtime_error("The counter can't be negative!!!");
	}
	max_count_ = max_count;
}

void Semaphore::acquire()
{
	std::unique_lock<std::mutex> lock(mut_);
	while (count_ == max_count_) 
	{ cv_.wait(lock); }
	count_++;
}

void Semaphore::release()
{
	std::lock_guard<std::mutex> lock(mut_);
	if (count_ > 0)
	{
		count_--;
		cv_.notify_one();
	}
}