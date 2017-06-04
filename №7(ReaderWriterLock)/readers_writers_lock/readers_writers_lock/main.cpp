#include <iostream>
#include "read_write_lock.h"
#include <fstream>
#include <vector>
#include <string>

Read_Write_Lock r_w_lock;

vector<string> txt = { "hello", "world","!!!"};

void write(string file) 
{
	r_w_lock.lock_reader();

	fstream f(file);
	for (int i(0); i < txt.size(); i++) 
	{
		f << txt[i] << " ";
	}

	r_w_lock.unlock_reader();
}

void print() 
{
	r_w_lock.lock_reader();

	for (int i(0); i < txt.size(); i++) {
		cout << txt[i] << " ";
	}

	r_w_lock.unlock_reader();
}

void read(string file)
{
	r_w_lock.lock_writer();
	txt.clear();
	fstream f(file);
	string s;
	while (!f.eof())
	{
		getline(f, s);
		txt.push_back(s);
	}
	r_w_lock.unlock_writer();
}

void add(string s)
{
	r_w_lock.lock_reader();
	txt.push_back(s);
	r_w_lock.unlock_reader();
}

int main()
{
	thread thr2(write, "thr2.txt");
	thread thr3(add, "very nice day=)");
	thread thr1(read, "thr1.txt");
	thread thr4(print);

	thr1.join();
	thr2.join();
	thr3.join();
	thr4.join();

	system("pause");
}