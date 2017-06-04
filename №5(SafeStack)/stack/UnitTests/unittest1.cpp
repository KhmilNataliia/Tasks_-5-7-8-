#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CASE("stack")
	{
		Stack<char>* stack = new Stack<char>();
		stack->add('d');
		stack->add('N');
		REQUIRE(stack->on_top() == 'N');
	};
	TEST_CASE("stack_del")
	{
		Stack<char>* stack = new Stack<char>();
		stack->add('d');
		stack->add('N');
		stack->del();
		REQUIRE(stack->on_top() == 'd');
	};
	TEST_CASE("stack_del_empt")
	{
		Stack<char>* stack = new Stack<char>();
		stack->add('d');
		stack->del();
		REQUIRE(stack->is_empty() == true);
	};
	TEST_CASE("stack_del_not_empt")
	{
		Stack<char>* stack = new Stack<char>();
		stack->add('d');
		REQUIRE(stack->is_empty() == false);
	};

	TEST_CASE("stack_size")
	{
		Stack<char>* stack = new Stack<char>();
		stack->add('d');
		stack->add('N');
		REQUIRE(stack->size_of_stack() == 2);
	};

	TEST_CASE("stack_exep_del")
	{
		Stack<char>* stack = new Stack<char>();
		stack->add('d');
		stack->del();
		REQUIRE_THROWS(stack->del());
	};

	TEST_CASE("stack_exep_read")
	{
		Stack<char>* stack = new Stack<char>();
		stack->add('d');
		stack->del();
		REQUIRE_THROWS(stack->on_top());
	};


	TEST_CASE("stack_destr")
	{
		Stack<char>* stack = new Stack<char>();
		stack->add('d');
		stack->add('g');
		stack->add('v');
		stack->add('b');
		stack->~Stack();
		REQUIRE(stack->is_empty()==true);
	};
}