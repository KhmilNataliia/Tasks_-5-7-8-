#include <string>

#include "semaphore.h"

using namespace std;

void control_func(string number, Semaphore &sem);


int main() 
{
	cout << "first example: semaphore max_count=1" << endl;
	cout << endl;
	Semaphore semaphore(1);
	thread th1(control_func, "first", ref(semaphore));
	thread th2(control_func, "second", ref(semaphore));
	thread th3(control_func, "third", ref(semaphore));
	thread th4(control_func, "fourth", ref(semaphore));
	thread th5(control_func, "fifth", ref(semaphore));
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();
	cout << endl;
	cout << "second example: semaphore max_count=2" << endl;
	cout << endl;
	Semaphore semaphore2(2);
	thread th2_1(control_func, "first", ref(semaphore2));
	thread th2_2(control_func, "second", ref(semaphore2));
	thread th2_3(control_func, "third", ref(semaphore2));
	thread th2_4(control_func, "fourth", ref(semaphore2));
	thread th2_5(control_func, "fifth", ref(semaphore2));
	th2_1.join();
	th2_2.join();
	th2_3.join();
	th2_4.join();
	th2_5.join();

	system("pause");
	return 0;
}


void control_func(string number, Semaphore &sem)
{
	sem.acquire();
	cout << "the thread N=" << number << endl;
	sem.release();
}