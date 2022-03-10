#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>

int main () {

	unsigned int start_time =  clock();

	std::cout << "### constructor\n";
	{
		std::pair <std::string,double> product1;                     // default constructor
		std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
		std::pair <std::string,double> product3 (product2);          // copy constructor

		product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

		product2.first = "shoes";                  // the type of first is string
		product2.second = 39.90;                   // the type of second is double

		std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
		std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
		std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
	}
	std::cout << "### operator=\n";
	{
		std::pair <std::string,int> planet, homeplanet;

		planet = std::make_pair("Earth",6371);

		homeplanet = planet;

		std::cout << "Home planet: " << homeplanet.first << '\n';
		std::cout << "Planet size: " << homeplanet.second << '\n';
	}
	std::cout << "### relational operators\n";
	{
		std::pair<int,char> foo (10,'z');
		std::pair<int,char> bar (90,'a');

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	std::cout << "### make pair\n";
	{
		std::pair <int,int> foo;
		std::pair <int,int> bar;

		foo = std::make_pair (10,20);
		bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

		std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
		std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
	}

	unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

	std::cout << "std time of work = " << search_time << std::endl;
	return 0;
}