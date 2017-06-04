#include "read_write_lock.h"


void Read_Write_Lock::lock_reader()
{
	unique_lock<mutex> monitor(mutex_);
	while (locked_for_writing)
	{
		allowed_read.wait(monitor);
	}
	locked_for_reading++;
}

void Read_Write_Lock::unlock_reader()
{
	unique_lock<mutex> monitor(mutex_);
	locked_for_reading--;
	if (locked_for_reading == 0)
	{
		allowed_write.notify_all();
	}
}

void Read_Write_Lock::lock_writer()
{
	unique_lock<mutex> monitor(mutex_);
	while (locked_for_writing && locked_for_reading != 0)
	{
		allowed_write.wait(monitor);
	}
	locked_for_writing = true;
}

void Read_Write_Lock::unlock_writer()
{
	unique_lock<mutex> monitor(mutex_);
	locked_for_writing = false;
	allowed_read.notify_all();
}