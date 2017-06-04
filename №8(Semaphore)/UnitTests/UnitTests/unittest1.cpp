#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "semaphore.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{	
	int res;

	void func(Semaphore &sem)
	{
		sem.acquire();
		res++;
		Sleep(10);
		sem.release();
	}

	TEST_CASE("waiting")
	{
		res = 0;
		Semaphore semaphore(1);
		thread th1(func, ref(semaphore));
		thread th2(func, ref(semaphore));
		thread th3(func, ref(semaphore));
		thread th4(func, ref(semaphore));
		th1.join();
		th2.join();
		th3.join();
		th4.join();
		REQUIRE(res == 4);
	};

	TEST_CASE("non_waiting")
	{
		res = 0;
		Semaphore semaphore(5);
		thread th1(func, ref(semaphore));
		thread th2(func, ref(semaphore));
		thread th3(func, ref(semaphore));
		thread th4(func, ref(semaphore));
		th1.join();
		th2.join();
		th3.join();
		th4.join();
		REQUIRE(res == 4);
	};

	TEST_CASE("negative_maXcount")
	{
		REQUIRE_THROWS(Semaphore semaphore(-4));
	};
}