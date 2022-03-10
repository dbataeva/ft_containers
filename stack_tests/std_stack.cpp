#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque

int main ()
{
	unsigned int start_time =  clock();

	std::cout << "### constructor ###\n";
	{
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		std::vector<int> myvector (2,200);        // vector with 2 elements

		std::stack<int, std::vector<int> > first;                    // empty stack
		std::stack<int> second (mydeque);         // stack initialized to copy of deque

		std::stack<int,std::vector<int> > third;  // empty stack using vector
		std::stack<int,std::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	std::cout << "### empty ###\n";
	{
		std::stack<int, std::vector<int> > mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}
	std::cout << "### size ###\n";
	{
		std::stack<int, std::vector<int> > myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	std::cout << "### top ###\n";
	{
		std::stack<int, std::vector<int> > mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	std::cout << "### push ###\n";
	{
		std::stack<int, std::vector<int> > mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	std::cout << "### pop ###\n";
	{
		std::stack<int, std::vector<int> > mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	std::cout << "### relational operators ###\n";
	{
		std::vector<int> myvector (2,200);        // vector with 2 elements

		std::stack<int, std::vector<int> > first;                    // empty stack

		std::stack<int,std::vector<int> > second;  // empty stack using vector
		std::stack<int,std::vector<int> > third (myvector);

		std::cout << "operator== " << (first == second) << '\n';
		std::cout << "operator!= " << (third != second) << '\n';
		std::cout << "operator< " << (third < first) << '\n';
		std::cout << "operator<= " << (first <= second) << '\n';
		std::cout << "operator>= " << (second >= third) << '\n';
		std::cout << "operator> " << (first > third) << '\n';
		std::cout << "operator> " << (second > third) << '\n';
		std::cout << "operator== " << (second == third) << '\n';
	}

	unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

	std::cout << "std time of work = " << search_time << std::endl;

	return 0;
}