#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class Read_Write_Lock
{
private:
	mutex mutex_;	
	condition_variable allowed_read, allowed_write;
	bool locked_for_writing = false;
	int locked_for_reading = 0;
public:
	void lock_reader();
	void unlock_reader();
	void lock_writer();
	void unlock_writer();
};