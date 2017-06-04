#include<iostream>
#include<exception>

using namespace std;

template <class T>
class Stack
{
	class Item
	{
		T dat;
		Item *next;
	public:
		Item(const T &ndat);
		~Item();
		const T &get_dat();
		Item *get_next();
		void set_next(Item *el_next);
	};
	Item *top_item;
	int num_of_items;
public:
	Stack();
	~Stack();
	T on_top();
	const int size_of_stack();
	bool is_empty();
	void add(const T &dat);
	void del();

	class case_del_from_empty_stack:public exception
	{ 
		void *source;
	public:
		case_del_from_empty_stack(void *_src):source(_src){};
		void output_error_messege();
	};

	class case_read_from_empty_stack: public exception
	{
		void *source;
	public:
		case_read_from_empty_stack(void *_src) :source(_src){};
		void output_error_messege();
	};
};

//for class "Item"

template<class T>
Stack<T>::Item::Item(const T &ndat)
{
	dat = T(ndat);
	next = NULL;
}

template<class T>
Stack<T>::Item::~Item()
{
	dat.~T();
	next = NULL;
}

template<class T>
void Stack<T>::Item::set_next(Item *el_next)
{
	next = el_next;
}

template<class T>
const T &Stack<T>::Item::get_dat()
{
	return dat;
}

template<class T>
typename Stack<T>::Item *Stack<T>::Item::get_next()
{
	return next;
}

//for class "Stack"

template<class T>
Stack<T>::Stack()
{
	top_item = NULL;
	num_of_items = 0;
}

template<class T>
Stack<T>::~Stack()
{
	while (num_of_items > 0) { del(); }
}

template<class T>
void Stack<T>::add(const T &dat)
{
	Item *prev = top_item;
	top_item = new Item(dat);
	top_item->set_next(prev);
	num_of_items++;
}

template<class T>
bool Stack<T>::is_empty()
{
	if (num_of_items > 0) 
		return false;
	else return true;
}

template<class T>
const int Stack<T>::size_of_stack()
{
	return num_of_items;
}

template<class T>
void Stack<T>::del() throw(case_del_from_empty_stack)
{
	if (num_of_items > 0)
	{
		Item *be_deleted = top_item;
		top_item = top_item->get_next();
		be_deleted->~Item();
		num_of_items--;
	}
	else
	{
		throw case_del_from_empty_stack(this);
	}
}

template<class T>
T Stack<T>::on_top() throw(case_read_from_empty_stack)
{
	if (num_of_items > 0)
	{
		return T(top_item->get_dat());
	}
	else throw case_read_from_empty_stack(this);
}

template<class T>
void Stack<T>::case_read_from_empty_stack::output_error_messege()
{
	cout << "reading data from top of empty stack" << source << endl;
}

template<class T>
void Stack<T>::case_del_from_empty_stack::output_error_messege()
{
	cout << "deleting Item from empty stack" << source << endl;
}

