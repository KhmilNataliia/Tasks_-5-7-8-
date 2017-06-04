#include<iostream>
#include"stack.h"

using namespace std;

int main()
{
	Stack<char>* stack = new Stack<char>();
	stack->add('e');
	stack->add('l');
	stack->add('p');
	stack->add('m');
	stack->add('a');
	stack->add('x');
	stack->add('e');
	stack->add(' ');
	stack->add('k');
	stack->add('c');
	stack->add('a');
	stack->add('t');
	stack->add('s');
	int col = stack->size_of_stack();
	for (int i = 0; i < col; i++)
	{
		cout << stack->on_top();
		stack->del();
	}
	cout << endl;
	cout << "stack empty? ==";
	if (stack->is_empty())
    cout << "true" << endl;
	else cout << "false" << endl;
	stack->~Stack();
	system("pause");
}