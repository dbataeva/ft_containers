#include <iostream>
#include <string>
#include <ctime>
#include <list>
#include <vector>

#include "../my_stack.hpp"

int main() {

	unsigned int start_time =  clock();

	std::cout << "=== TEST STACK ===" << std::endl;
	std::cout << "=== test stack() && size() ===" << std::endl;
	ft::stack<std::string> st_a;
	std::cout << st_a.size() << std::endl;

	std::cout << "=== test empty() with empty stack ===" << std::endl;
	std::cout << st_a.empty() << std::endl;

	std::cout << "=== test push() with empty stack ===" << std::endl;
	std::cout << "before : " << st_a.size() << std::endl;
	st_a.push("aaa");
	std::cout << "after : " << st_a.size() << std::endl;

	std::cout << "=== test top() ===" << std::endl;
	std::cout << st_a.top() << std::endl;

	std::cout << "=== test push() with not empty stack ===" << std::endl;
	std::cout << "before : " << st_a.size() << std::endl;
	st_a.push("bbb");
	std::cout << "after : " << st_a.size() << std::endl;

	std::cout << "=== test top() ===" << std::endl;
	std::cout << st_a.top() << std::endl;

	std::cout << "=== test pop() ===" << std::endl;
	st_a.pop();
	std::cout << "after : " << st_a.size() << std::endl;

	std::cout << "=== test top() ===" << std::endl;
	std::cout << st_a.top() << std::endl;

	ft::stack<std::string> st_c;
	st_c.push("ccc");

	std::cout << "=== TEST CONST STACK ===" << std::endl;
	std::cout << "=== test stack() && size() ===" << std::endl;
	const ft::stack<std::string> st_b;
	std::cout << st_b.size() << std::endl;

	std::cout << "=== test empty() with empty stack ===" << std::endl;
	std::cout << st_b.empty() << std::endl;

	std::cout << "=== TEST RELATIONAL OPERATORS ===" << std::endl;
	std::cout << "=== test operator== for stack if they are equal===" << std::endl;
	std::cout << (st_a == st_a) << std::endl;

	std::cout << "=== test operator== for stack if they aren't equal===" << std::endl;
	std::cout << (st_a == st_c) << std::endl;

	std::cout << "=== test operator!= for stack if they are equal===" << std::endl;
	std::cout << (st_a == st_c) << std::endl;

	std::cout << "=== test operator!= for stack if they aren't equal===" << std::endl;
	std::cout << (st_a == st_c) << std::endl;

	std::cout << "=== test operator< for stack if they are equal===" << std::endl;
	std::cout << (st_a < st_a) << std::endl;

	std::cout << "=== test operator< for stack if they aren't equal===" << std::endl;
	std::cout << (st_a < st_c) << std::endl;

	std::cout << "=== test operator> for stack if they are equal===" << std::endl;
	std::cout << (st_a > st_a) << std::endl;

	std::cout << "=== test operator> for stack if they aren't equal===" << std::endl;
	std::cout << (st_a > st_c) << std::endl;

	std::cout << "=== test operator<= for stack if they are equal===" << std::endl;
	std::cout << (st_a <= st_a) << std::endl;

	std::cout << "=== test operator<= for stack if they aren't equal===" << std::endl;
	std::cout << (st_a <= st_c) << std::endl;

	std::cout << "=== test operator>= for stack if they are equal===" << std::endl;
	std::cout << (st_a >= st_a) << std::endl;

	std::cout << "=== test operator>= for stack if they aren't equal===" << std::endl;
	std::cout << (st_a >= st_c) << std::endl;

	std::cout << "### constructor with list\n";
	std::list<std::string> zz;
	zz.push_back("qwertyuiop");
	zz.push_back("asdfghjkl");
	zz.push_back("zxcvbnm");
	ft::stack<std::string, std::list<std::string> > yy(zz);
	std::cout << yy.size() << std::endl;
	std::cout << yy.top() << std::endl;

	std::cout << "### constructor with std::vector\n";
	std::vector<std::string> xx(zz.begin(), zz.end());
	ft::stack<std::string, std::vector<std::string> > ww(xx);
	std::cout << ww.size() << " " << ww.top() << std::endl;

	unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

	std::cout << "ft time of work = " << search_time << std::endl;

	return (0);
}