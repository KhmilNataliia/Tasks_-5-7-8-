#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "read_write_lock.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{	

	Read_Write_Lock r_w_l;
	string res;
	void read()
	{
		r_w_l.lock_writer();
		res+= "r";
		Sleep(10);
		r_w_l.unlock_writer();
	}
	void write()
	{
		r_w_l.lock_reader();
		res += "w";
		Sleep(10);
		r_w_l.unlock_reader();
	}
	TEST_CASE("read->write")
	{
		res = "";
		thread t1(read);
		thread t2(read);
		thread t3(write);
		t1.join();
		t2.join();
		t3.join();
		REQUIRE(res == "rrw");
	};
	TEST_CASE("write->read")
	{
		res = "";
		thread t1(write);
		thread t2(read);
		t1.join();
		t2.join();
		REQUIRE(res == "wr");
	};
}