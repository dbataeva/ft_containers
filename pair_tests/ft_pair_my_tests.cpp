#include "../my_pair.hpp"

#include <iostream>

int main () {

	unsigned int start_time =  clock();

	std::cout << "### empty constructor\n";
	ft::pair<int, char> a;

	std::cout << "### constructor with arguments\n";
	ft::pair<int, char> b(0, 'a');
	std::cout << b.first << " " << b.second << std::endl;

	std::cout << "### construction by copy\n";
	ft::pair<int, char> c(b);
	std::cout << c.first << " " << c.second << std::endl;

	std::cout << "### operator=\n";
	a = b;
	std::cout << a.first << " " << a.second << std::endl;

	std::cout << "### operator==\n";
	std::cout << (a == b) << std::endl;

	std::cout << "### operator!=\n";
	std::cout << (a != c) << std::endl;

	std::cout << "### operator<\n";
	std::cout << (b < c) << std::endl;

	std::cout << "### operator<=\n";
	ft::pair<int, char> d(1, 'b');
	std::cout << (a <= d) << std::endl;

	std::cout << "### operator>\n";
	std::cout << (b > d) << std::endl;

	std::cout << "### operator>=\n";
	std::cout << (c > d) << std::endl;

	std::cout << "### make_pair\n";
	ft::pair<int, char> e = ft::make_pair<int, char>(2, 'c');
	std::cout << e.first << " " << e.second << std::endl;

	unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

	std::cout << "ft time of work = " << search_time << std::endl;
	return 0;
}