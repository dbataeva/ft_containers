#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <ctime>

bool my_pred(const std::string &first, const std::string &second) {
	return(first == second);
}

int main () {

	unsigned int start_time =  clock();
	{
		std::cout << "=== TEST VECTOR ===" << std::endl;
		std::cout << "=== test vector() ===" << std::endl;
		std::vector<std::string> a;
		std::cout << a.size() << " " << a.capacity() << std::endl;
		
		std::cout << "ok\n=== test vector(args) ===" << std::endl;
		std::vector<std::string> b(100, "qwerty");
		std::cout << b.size() << " " << b.capacity() << std::endl;

		std::cout << "ok\n=== test construction by copy ===" << std::endl;
		std::vector<std::string> c(b);
		std::cout << c.size() << " " << c.capacity() << std::endl;

		std::cout << "ok\n=== test destruction ===" << std::endl;
		std::vector<std::string> *d = new std::vector<std::string> (100, "asdfg") ;
		std::cout << d->size() << " " << d->capacity() << std::endl;
		delete d;

		std::cout << "ok\n=== test operator= ===" << std::endl;
		a = b;
		std::cout << a.size() << " " << a.capacity() << std::endl;

		std::cout << "ok\n=== test size() ===" << std::endl;
		std::cout << a.size() << std::endl;

		std::cout << "ok\n=== test max_size() ===" << std::endl;
		std::cout << b.max_size() << std::endl;

		std::cout << "ok\n=== test resize ===" << std::endl;
		std::cout << "before: " << c.size() << " " << c.capacity() << std::endl;
		c.resize(1000, "asdfg");
		std::cout << "after: " << c.size() << " " << c.capacity() << std::endl;

		std::cout <<  "ok\n=== test capacity ===" << std::endl;
		std::cout << c.capacity() << std::endl;

		std::cout << "=== test empty with empty vector ===" << std::endl;
		std::vector<std::string> f;
		std::cout << f.empty() << std::endl;

		std::cout << "=== test empty with empty vector after reserve ===" << std::endl;
		f.reserve(10);
		std::cout << f.empty() << std::endl;

		std::cout << "=== test reserve with n > max_size ===" << std::endl;
		try {
			c.reserve(768614336404564650 + 1);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "=== test reserve with valid n ===" << std::endl;
		std::cout << "before: " << c.size() << " " << c.capacity() << std::endl;
		c.reserve(1001);
		std::cout << "after: " << c.size() << " " << c.capacity() << std::endl;
		
		std::cout << "=== test operator[] to access ===" << std::endl;
		std::cout << "|" << c[1] << "|"  << " |" << c[999] << "|" << std::endl;

		std::cout << "=== test operator[] to change value ===" << std::endl;
		c[999] = "zxcvb";
		std::cout << "|" << c[999] << "|" << std::endl;

		std::cout << "ok\n=== test empty with not empty vector ===" << std::endl;
		std::cout << c.empty() << std::endl;

		std::cout << "=== test operator[] with const ===" << std::endl;
		const std::vector<std::string> e(c);
		std::cout << "|" << e[1] << "|" << std::endl;

		std::cout << "=== test at with valid n ===" << std::endl;
		std::cout << c.at(20) << std::endl;

		std::cout << "=== test at with invalid n===" << std::endl;
		try {
			std::cout << c.at(2000) << std::endl;
		}
		catch (std::out_of_range &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "=== test front to access ===" << std::endl;
		std::cout << c.front() << std::endl;

		std::cout << "=== test front to change value ===" << std::endl;
		c.front() = "poiuy";
		std::cout << c.front() << std::endl;

		std::cout << "=== test front to access with const vector ===" << std::endl;
		std::cout << e.front() << std::endl;

		std::cout << "=== test back to access ===" << std::endl;
		c.reserve(1002);
		std::cout << c.back() << std::endl;

		std::cout << "=== test back to change value ===" << std::endl;
		c.back() = "mnbvc";
		std::cout << c.back() << std::endl;

		std::cout << "=== test back to access with const vector ===" << std::endl;
		std::cout << e.back() << std::endl;

		std::cout << "=== test push_back ===" << std::endl;
		std::cout << "before: " << c.size() << " " << c.capacity() << std::endl;
		c.push_back("Dasha");
		std::cout << "after: " << c.size() << " " << c.capacity() << std::endl;

		std::cout << "=== test pop_back ===" << std::endl;
		std::cout << "before: " << a.size() << " " << a.capacity() << std::endl;
		a.pop_back();
		std::cout << "after: " << a.size() << " " << a.capacity() << std::endl;

		try {
			std::cout << a.at(99) << std::endl;
		}
		catch (std::out_of_range &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "=== test clear ===" << std::endl;
		std::cout << "before: " << c.size() << " " << c.capacity() << std::endl;
		c.clear();
		std::cout << "after: " << c.size() << " " << c.capacity() << std::endl;

		std::cout << "=== test assing(size_t n, const T &val) ===" << std::endl;
		std::cout << "before: " << c.size() << " " << c.capacity() << std::endl;
		c.assign(100, "0123456789");
		std::cout << "after: " << c.size() << " " << c.capacity() << std::endl;
		std::cout << c[99] << std::endl;

		std::cout << "=== test get_allocator ===" << std::endl;
		std::string *str;
		str = c.get_allocator().allocate(5);
		int i = 0;
		while (i < 5) {
			c.get_allocator().construct(&str[i], c[i]);
			i++;
		}
		i = 0;
		while (i < 5) {
			std::cout << str[i] << std::endl;
			i++;
		}
		i = 0;
		while (i < 5) {
			c.get_allocator().destroy(&str[i]);
			i++;
		}
		c.get_allocator().deallocate(str, 5);

		std::cout << "=== TEST ITERATOR ===" << std::endl;
		c[0] = "0";
		c[1] = "11";
		c[2] = "222";
		c[3] = "3333";
		c[4] = "44444";
		c[5] = "555555";

		std::cout << "=== test iterator && begin() && operator* with not const string ===" << std::endl;
		std::vector<std::string>::iterator start = c.begin();
		std::cout << *start << std::endl;
		std::cout << c[0] << std::endl;

		std::cout << "=== test const_iterator && begin() && operator* ===" << std::endl;
		std::vector<std::string>::const_iterator st = c.begin();
		std::cout << *st << std::endl;

		std::cout << "=== test iterator && end() && operator* ===" << std::endl;
		std::vector<std::string>::iterator finish = c.end();
		(void)finish;

		std::cout << "ok\n=== test const_iterator && end() && operator*  ===" << std::endl;
		std::vector<std::string>::const_iterator finis = c.end();
		(void)finis;

		std::cout << "ok\n=== test operator-- for iterator ===" << std::endl;
		finish--;
		std::cout << "finish after: " << *finish << std::endl;

		std::cout << "=== test operator= && operator* for iterator ===" << std::endl;
		std::cout << "start before: " << *start << "; finish before: " << *finish << std::endl;
		finish = start;
		std::cout << "start after: " << *start << "; finish after: " << *finish << std::endl;

		std::cout << "ok\n=== test construction by copy && operator* for iterator ===" << std::endl;
		std::vector<std::string>::iterator i_copy(start);
		std::cout << "original iterator = " << *start << "; copy iterator = " << *i_copy << std::endl;

		std::cout << "=== test construction by copy && operator* for iterator to make const_iterator ===" << std::endl;
		std::vector<std::string>::const_iterator c_i_cop(start);
		std::cout << "original iterator = " << *start << "; copy const_iterator = " << *c_i_cop << std::endl;

		std::cout << "=== test operator== for iterator if they are equal===" << std::endl;
		std::cout << (start == finish) << std::endl;

		std::cout << "=== test operator== for iterator if they aren't equal===" << std::endl;
		std::vector<std::string>::iterator fi = c.end();
		std::cout << (start == fi) << std::endl;

		std::cout << "=== test operator== for const_iterator if they aren't equal===" << std::endl;
		std::cout << (st == finis) << std::endl;	

		std::cout << "=== test operator!= for iterator if they are equal===" << std::endl;
		std::cout << (start != finish) << std::endl;

		std::cout << "=== test operator!= for iterator if they aren't equal===" << std::endl;
		std::cout << (start != fi) << std::endl;

		std::cout << "=== test operator!= for const_iterator if they aren't equal===" << std::endl;
		std::cout << (st != finis) << std::endl;	

		std::cout << "=== test operator* to change for iterator ===" << std::endl;
		std::cout << "start before: " << *start << std::endl;
		*start = "00000";
		std::cout << "start after: " << *start << std::endl;

		std::cout << "=== test operator-> for iterator ===" << std::endl;
		std::cout << start->npos << std::endl;

		std::cout << "=== test operator-> for const_iterator ===" << std::endl;
		std::cout << st->npos << std::endl;

		std::cout << "=== test operator++ for iterator ===" << std::endl;
		std::cout << "start before: " << *start << std::endl;
		start++;
		std::cout << "start after: " << *start << std::endl;

		std::cout << "=== test operator++ for const_iterator ===" << std::endl;
		std::cout << "st before: " << *st << std::endl;
		st++;
		std::cout << "st after: " << *st << std::endl;

		std::cout << "=== test operator++(int) for iterator ===" << std::endl;
		std::cout << "start before: " << *start << std::endl;
		++start;
		std::cout << "start after: " << *start << std::endl;

		std::cout << "=== test operator++(int) for const_iterator ===" << std::endl;
		std::cout << "st before: " << *st << std::endl;
		++st;
		std::cout << "st after: " << *st << std::endl;

		std::cout << "=== test operator--(int) for iterator ===" << std::endl;
		std::cout << "start before: " << *start << std::endl;
		--start;
		std::cout << "start after: " << *start << std::endl;

		std::cout << "=== test operator--(int) for const_iterator ===" << std::endl;
		std::cout << "st before: " << *st << std::endl;
		--st;
		std::cout << "st after: " << *st << std::endl;

		std::cout << "=== test operator+ for iterator ===" << std::endl;
		std::cout << "start: " << *start << std::endl;
		std::vector<std::string>::iterator z = start + 3;
		std::cout << "start + 3: " << *z << std::endl;
		
		std::cout << "=== test operator+ for const_iterator ===" << std::endl;
		std::cout << "st: " << *st << std::endl;
		std::vector<std::string>::const_iterator y = st + 2;
		std::cout << "st + 1: " << *y << std::endl;

		std::cout << "=== test operator-(int) for iterator ===" << std::endl;
		std::cout << "z: " << *z << std::endl;
		z = z - 1;
		std::cout << "z - 1: " << *z << std::endl;
		
		std::cout << "=== test operator-(int) for const_iterator ===" << std::endl;
		std::cout << "y: " << *y << std::endl;
		std::cout << "y - 1: " << *(y - 1) << std::endl;

		std::cout << "=== test operator-(iterator) for iterator if first bigger ===" << std::endl;
		std::cout << "z - start = " << z - start << std::endl;
		
		std::cout << "=== test operator-(const_iterator) for const_iterator if first bigger ===" << std::endl;
		std::cout << "y - st: " << y - st << std::endl;

		std::cout << "=== test operator-(iterator) for iterator if first is lower ===" << std::endl;
		std::cout << "start - z = " << start - z << std::endl;

		std::cout << "=== test operator-(const_iterator) for const_iterator if first is lower===" << std::endl;
		std::cout << "st - finis = " << st - finis << std::endl;

		std::cout << "=== test operator< for iterator ===" << std::endl;
		std::cout << "z < finish ? : " << (z < finish) << std::endl;

		std::cout << "=== test operator> for iterator ===" << std::endl;
		std::cout << "z > finish ? : " << (z > finish) << std::endl;

		std::cout << "=== test operator<= for iterator ===" << std::endl;
		std::cout << "start <= finish ? : " << (start <= finish) << std::endl;

		std::cout << "=== test operator>= for iterator ===" << std::endl;
		std::cout << "start >= finish ? : " << (start >= finish) << std::endl;

		start = finish;

		std::cout << "=== test operator< for iterator after assignation ===" << std::endl;
		std::cout << "start < finish ? : " << (start < finish) << std::endl;

		std::cout << "=== test operator> for iterator ===" << std::endl;
		std::cout << "start > finish ? : " << (start > finish) << std::endl;

		std::cout << "=== test operator<= for iterator ===" << std::endl;
		std::cout << "start <= finish ? : " << (start <= finish) << std::endl;

		std::cout << "=== test operator>= for iterator ===" << std::endl;
		std::cout << "start >= finish ? : " << (start >= finish) << std::endl;
		
		std::cout << "=== test operator< for const_iterator ===" << std::endl;
		std::cout << "y < finis ? : " << (y < finis) << std::endl;

		std::cout << "=== test operator> for const_iterator ===" << std::endl;
		std::cout << "y > finis ? : " << (y > finis) << std::endl;
		
		st = finis;
		
		std::cout << "=== test operator< for const_iterator after assignation ===" << std::endl;
		std::cout << "st < finis ? : " << (st < finis) << std::endl;

		std::cout << "=== test operator> for const_iterator ===" << std::endl;
		std::cout << "st > finis ? : " << (st > finis) << std::endl;

		std::cout << "=== test operator>= for const_iterator ===" << std::endl;
		std::cout << "st >= finis ? : " << (st >= finis) << std::endl;

		std::cout << "=== test operator<= for const_iterator ===" << std::endl;
		std::cout << "st <= finis ? : " << (st <= finis) << std::endl;

		std::cout << "=== test operator+= for iterator ===" << std::endl;
		std::cout << "start: " << *start << std::endl;
		start += 3;
		std::cout << "start + 3: " << *start << std::endl;

		std::cout << "=== test operator-= for iterator ===" << std::endl;
		std::cout << "start: " << *start << std::endl;
		start -= 2;
		std::cout << "start - 2: " << *start << std::endl;

		std::cout << "=== test operator[] for iterator ===" << std::endl;
		std::cout << "start[1] = " << start[1] << std::endl;

		st = c.begin();

		std::cout << "=== test operator[] for const_iterator ===" << std::endl;
		std::cout << "st[2] = " << st[2] << std::endl;

		const std::vector<std::string> t(40, "skjdnf");
		std::vector<std::string>::const_iterator j = t.begin();
		(void)j;

		std::cout << "=== test operator== for iterator and const_iterator ===" << std::endl;
		std::cout << (start == st) << std::endl;
		std::cout << (st == start) << std::endl;

		std::cout << "=== test operator< for iterator and const_iterator ===" << std::endl;
		std::cout << (start == st) << std::endl;
		std::cout << (st == start) << std::endl;

		std::cout << "=== test operator- for iterator and const_iterator ===" << std::endl;
		std::cout << (start - st) << std::endl;
		std::cout << (st - start) << std::endl;

		std::cout << *j.base() << std::endl;

	}
	std::cout << "### reverse_iterator constructors\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
																// ? 0 1 2 3 4 5 6 7 8 9 ?
		iter_type from (myvector.begin());                     //   ^
																//         ------>
		iter_type until (myvector.end());                      //                       ^
																//
		std::reverse_iterator<iter_type> rev_until (from);     // ^
																//         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
	std::cout << "### base\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_end (myvector.begin());
		std::reverse_iterator<iter_type> rev_begin (myvector.end());

		std::cout << "myvector:";
		for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << "### operator*\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
																// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
																//         ------>
		iter_type until (myvector.end());                      //                       ^
																//
		std::reverse_iterator<iter_type> rev_until (from);     // ^
																//         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
	std::cout << "### operator+\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_it;

		rev_it = myvector.rbegin() +3;

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}
	std::cout << "### operator++\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
																// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
																//         ------>
		iter_type until (myvector.end());                      //                       ^
																//
		std::reverse_iterator<iter_type> rev_until (from);     // ^
																//         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until) {
			std::cout << ' ' << *rev_from;
			++rev_from;
		}
		std::cout << '\n';
	}
	std::cout << "### operator+=\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		rev_iterator += 2;

		std::cout << "The third element from the end is: " << *rev_iterator << '\n';
	}
	std::cout << "### operator-\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_iterator;

		rev_iterator = myvector.rend() - 3;

		std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
	}
	std::cout << "### operator--\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_begin (myvector.end());
		std::reverse_iterator<iter_type> rev_end (myvector.begin());

		std::reverse_iterator<iter_type> rev_iterator = rev_begin;
		while ( rev_iterator != rev_end )
			std::cout << *rev_iterator++ << ' ';
		std::cout << '\n';

		while ( rev_iterator != rev_begin )
			std::cout << *(--rev_iterator) << ' ';
		std::cout << '\n';
	}
	std::cout << "### operator-=\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_iterator = myvector.rend();

		rev_iterator -= 4;

		std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';
	}
	std::cout << "### operator[]\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
	}
	std::cout << "### relational operations (== != > < >= <=)\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
																// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
																//         ------>
		iter_type until (myvector.end());                      //                       ^
																//
		std::reverse_iterator<iter_type> rev_until (from);     // ^
																//         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
	std::cout << "### operator+ (not a member)\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_it;

		rev_it = 3 + myvector.rbegin();

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}
	std::cout << "### operator- (not a member)\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		std::reverse_iterator<std::vector<int>::iterator> from,until;

		from = myvector.rbegin();
		until = myvector.rend();

		std::cout << "myvector has " << (until-from) << " elements.\n";
	}

	std::vector<int> p(5, 5);

	unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

	std::cout << "std time of work = " << search_time << std::endl;

	return (0);
}