#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <ctime>

#include <vector>

bool my_pred(const std::string &first, const std::string &second) {
	return(first == second);
}

bool my_comp(const std::string &first, const std::string &second) {
	return(first < second);
}

int main () {

	unsigned int start_time =  clock();

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

	std::cout << "=== test operator[] to access ===" << std::endl;
	std::cout << "|" << c[1] << "|"  << " |" << c[999] << "|" << std::endl;

	std::cout << "=== test operator[] to change value ===" << std::endl;
	c[999] = "zxcvb";
	std::cout << "|" << c[999] << "|" << std::endl;

	std::cout << "ok\n=== test empty with not empty vector ===" << std::endl;
	std::cout << c.empty() << std::endl;

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

	std::cout << "=== test swap(to_swap) ===" << std::endl;
	std::cout << "a before: " << a.size() << " " << a.capacity() << std::endl;
	std::cout << "c before: " << c.size() << " " << c.capacity() << std::endl;
	std::vector<std::string>::iterator start_a = a.begin();
	std::vector<std::string>::iterator start_c = c.begin();
	std::cout << "start_a before: " << *start_a << std::endl;
	std::cout << "start_c before: " << *start_c << std::endl;
	a.swap(c);
	std::cout << "a after: " << a.size() << " " << a.capacity() << std::endl;
	std::cout << "c after: " << c.size() << " " << c.capacity() << std::endl;std::cout << "start_a after: " << *start_a << std::endl;
	std::cout << "start_c after: " << *start_c << std::endl;

	std::cout <<  "ok\n=== test swap(x, y) ===" << std::endl;
	std::cout << "a before: " << a.size() << " " << a.capacity() << std::endl;
	std::cout << "c before: " << c.size() << " " << c.capacity() << std::endl;
	start_a = a.begin();
	start_c = c.begin();
	std::cout << "start_a before: " << *start_a << std::endl;
	std::cout << "start_c before: " << *start_c << std::endl;
	std::swap(a, c);
	std::cout << "a after: " << a.size() << " " << a.capacity() << std::endl;
	std::cout << "c after: " << c.size() << " " << c.capacity() << std::endl;std::cout << "start_a after: " << *start_a << std::endl;
	std::cout << "start_c after: " << *start_c << std::endl;

	std::cout << "=== TEST REVERSE_ITERATOR ===" << std::endl;
	{
		std::cout << "=== test reverse_iterator && rbegin() && operator* ===" << std::endl;
		std::vector<std::string>::reverse_iterator start = c.rbegin();
		std::cout << *start << std::endl;

		std::cout << "=== test const_reverse_iterator && rbegin() && operator* with not const string ===" << std::endl;
		std::vector<std::string>::const_reverse_iterator st = c.rbegin();

		std::cout << "=== test reverse_iterator && rend() && operator* ===" << std::endl;
		std::vector<std::string>::reverse_iterator finish = c.rend();
		(void)finish;

		std::cout << "ok\n=== test const_reverse_iterator && rend() && operator* with not const string ===" << std::endl;
		std::vector<std::string>::const_reverse_iterator finis = c.rend();
		(void)finis;

		std::cout << "ok\n=== test operator-- for reverse_iterator ===" << std::endl;
		finish--;
		std::cout << "finish before: " << *finish << std::endl;
		finish--;
		std::cout << "finish after: " << *finish << std::endl;

		std::cout << "=== test operator= && operator* for reverse_iterator ===" << std::endl;
		std::cout << "start before: " << *start << std::endl;
		finish = start;
		std::cout << "finish after: " << *finish << std::endl;

		std::cout << "=== test operator-- for const_reverse_iterator ===" << std::endl;
		finis--;
		std::cout << "finis before: " << *finis<< std::endl;
		finis--;
		std::cout << "finis after: " << *finis << std::endl;

		std::cout << "=== test construction by copy && operator* for reverse_iterator ===" << std::endl;
		std::vector<std::string>::reverse_iterator i_copy(start);
		std::cout << "original iterator = " << *start << "; copy iterator = " << *i_copy << std::endl;

		std::cout << "=== test construction by copy && operator* for iterator to make const_iterator ===" << std::endl;
		std::vector<std::string>::const_reverse_iterator c_i_cop(start);
		std::cout << "original iterator = " << *start << "; copy const_iterator = " << *c_i_cop << std::endl;

		std::cout << "=== test operator== for reverse_iterator if they are equal===" << std::endl;
		std::cout << (start == finish) << std::endl;

		std::cout << "=== test operator== for reverse_iterator if they aren't equal===" << std::endl;
		std::vector<std::string>::reverse_iterator fi = c.rend();
		std::cout << (start == fi) << std::endl;

		std::cout << (start == finish) << std::endl;

		std::cout << "=== test operator== for const_reverse_iterator if they aren't equal===" << std::endl;
		std::cout << (st == finis) << std::endl;	

		std::cout << "=== test operator!= for reverse_iterator if they are equal===" << std::endl;
		std::cout << (start != finish) << std::endl;

		std::cout << "=== test operator!= for reverse_iterator if they aren't equal===" << std::endl;
		std::cout << (start != fi) << std::endl;

		std::cout << "=== test operator!= for const_reverse_iterator if they aren't equal===" << std::endl;
		std::cout << (st != finis) << std::endl;	

		std::cout << "=== test operator* to change for reverse_iterator ===" << std::endl;
		start++;
		std::cout << "start before: " << *start << std::endl;
		*start = "00000";
		std::cout << "start after: " << *start << std::endl;

		std::cout << "=== test operator-> for reverse_iterator ===" << std::endl;
		std::cout << start->npos << std::endl;

		std::cout << "=== test operator-> for const_reverse_iterator ===" << std::endl;
		std::cout << st->npos << std::endl;

		c[94] = "0";
		c[95] = "11";
		c[96] = "222";
		c[97] = "3333";
		c[98] = "44444";
		c[99] = "555555";

		std::cout << "=== test operator++ for reverse_iterator ===" << std::endl;
		std::cout << "start before: " << *start << std::endl;
		start++;
		std::cout << "start after: " << *start << std::endl;

		std::cout << "=== test operator++ for const_reverse_iterator ===" << std::endl;
		std::cout << "st before: " << *st << std::endl;
		st++;
		std::cout << "st after: " << *st << std::endl;

		std::cout << "=== test operator++(int) for reverse_iterator ===" << std::endl;
		std::cout << "start before: " << *start << std::endl;
		++start;
		std::cout << "start after: " << *start << std::endl;

		std::cout << "=== test operator++(int) for const_reverse_iterator ===" << std::endl;
		std::cout << "st before: " << *st << std::endl;
		++st;
		std::cout << "st after: " << *st << std::endl;

		std::cout << "=== test operator--(int) for reverse_iterator ===" << std::endl;
		std::cout << "start before: " << *start << std::endl;
		--start;
		std::cout << "start after: " << *start << std::endl;

		std::cout << "=== test operator--(int) for const_reverse_iterator ===" << std::endl;
		std::cout << "st before: " << *st << std::endl;
		--st;
		std::cout << "st after: " << *st << std::endl;

		std::cout << "=== test operator+ for reverse_iterator ===" << std::endl;
		std::cout << "start: " << *start << std::endl;
		start = start + 2;
		std::cout << "start + 2: " << *start << std::endl;
		
		std::cout << "=== test operator+ for const_reverse_iterator ===" << std::endl;
		std::cout << "st: " << *st << std::endl;
		std::cout << "st + 1: " << *(st + 1) << std::endl;

		std::vector<std::string>::const_reverse_iterator st_ = st + 1;
		std::cout << *st_ << std::endl;

		std::cout << "=== test operator-(int) for reverse_iterator ===" << std::endl;
		std::cout << "start: " << *start << std::endl;
		start = start - 1;
		std::cout << "start - 1: " << *start << std::endl;
		
		std::cout << "=== test operator-(int) for const_reverse_iterator ===" << std::endl;
		finis--;
		std::cout << "st: " << *finis << std::endl;
		std::cout << "st - 1: " << *(finis - 1) << std::endl;

		std::cout << "=== test operator-(iterator) for reverse_iterator if first bigger ===" << std::endl;
		std::cout << "finish - start = " << finish - start << std::endl;
		
		std::cout << "=== test operator-(const_iterator) for const_reverse_iterator if first bigger ===" << std::endl;
		std::cout << "finis - st: " << finis - st << std::endl;

		std::cout << "=== test operator-(iterator) for reverse_iterator if first lower ===" << std::endl;
		std::cout << "start - finish = " << start - finish << std::endl;

		std::cout << "=== test operator-(const_iterator) for const_reverse_iterator ===" << std::endl;
		std::cout << "st - finis = " << st - finis << std::endl;

		std::cout << "=== test operator< for reverse_iterator ===" << std::endl;
		std::cout << "start < finish ? : " << (start < finish) << std::endl;

		std::cout << "=== test operator> for reverse_iterator ===" << std::endl;
		std::cout << "start > finish ? : " << (start > finish) << std::endl;

		std::cout << "=== test operator<= for reverse_iterator ===" << std::endl;
		std::cout << "start <= finish ? : " << (start <= finish) << std::endl;

		std::cout << "=== test operator>= for reverse_iterator ===" << std::endl;
		std::cout << "start >= finish ? : " << (start >= finish) << std::endl;

		start = finish;

		std::cout << "=== test operator< for reverse_iterator after assignation ===" << std::endl;
		std::cout << "start < finish ? : " << (start < finish) << std::endl;

		std::cout << "=== test operator> for reverse_iterator ===" << std::endl;
		std::cout << "start > finish ? : " << (start > finish) << std::endl;

		std::cout << "=== test operator<= for reverse_iterator ===" << std::endl;
		std::cout << "start <= finish ? : " << (start <= finish) << std::endl;

		std::cout << "=== test operator>= for reverse_iterator ===" << std::endl;
		std::cout << "start >= finish ? : " << (start >= finish) << std::endl;
		
		std::cout << "=== test operator< for const_reverse_iterator ===" << std::endl;
		std::cout << "st < finis ? : " << (st < finis) << std::endl;

		std::cout << "=== test operator> for const_reverse_iterator ===" << std::endl;
		std::cout << "st > finis ? : " << (st > finis) << std::endl;

		st = finis;
		
		std::cout << "=== test operator< for const_reverse_iterator after assignation ===" << std::endl;
		std::cout << "st < finis ? : " << (st < finis) << std::endl;

		std::cout << "=== test operator> for const_reverse_iterator ===" << std::endl;
		std::cout << "st > finis ? : " << (st > finis) << std::endl;

		std::cout << "=== test operator>= for const_reverse_iterator ===" << std::endl;
		std::cout << "st >= finis ? : " << (st >= finis) << std::endl;

		std::cout << "=== test operator<= for const_reverse_iterator ===" << std::endl;
		std::cout << "st <= finis ? : " << (st <= finis) << std::endl;

		std::cout << "=== test operator+= for reverse_iterator ===" << std::endl;
		std::cout << "start: " << *start << std::endl;
		start += 3;
		std::cout << "start + 3: " << *start << std::endl;

		std::cout << "=== test operator-= for reverse_iterator ===" << std::endl;
		std::cout << "start: " << *start << std::endl;
		start -= 2;
		std::cout << "start - 2: " << *start << std::endl;

		std::cout << "=== test operator[] for reverse_iterator ===" << std::endl;
		std::cout << "start[1] = " << start[1] << std::endl;

		st = c.rbegin();

		std::cout << "=== test operator[] for const_reverse_iterator ===" << std::endl;
		std::cout << "st[2] = " << st[2] << std::endl;

		std::cout << st - start << std::endl;
		std::cout << start - st << std::endl;
	}

	std::cout << "=== test construction vector(size) ===" << std::endl;
	std::vector<std::string> j(29);
	std::cout << "ok\nsize = " << j.size() << "; capacity = " << j.capacity() <<  "; j[0] = |" << j[0] << "|" << std::endl;

	std::cout << "=== test operator== for vectors if they are equal===" << std::endl;
	std::cout << (c == c) << std::endl;

	std::cout << "=== test operator== for vectors if they aren't equal===" << std::endl;
	std::cout << (c == a) << std::endl;

	std::cout << "=== test operator!= for vectors if they are equal===" << std::endl;
	std::cout << (c == c) << std::endl;

	std::cout << "=== test operator!= for vectors if they aren't equal===" << std::endl;
	std::cout << (c == a) << std::endl;

	std::cout << "=== test operator< for vectors if they are equal===" << std::endl;
	std::cout << (c < c) << std::endl;

	std::cout << "=== test operator< for vectors if they aren't equal===" << std::endl;
	std::cout << (c < a) << std::endl;

	std::cout << "=== test operator> for vectors if they are equal===" << std::endl;
	std::cout << (c > c) << std::endl;

	std::cout << "=== test operator> for vectors if they aren't equal===" << std::endl;
	std::cout << (c > a) << std::endl;

	std::cout << "=== test operator<= for vectors if they are equal===" << std::endl;
	std::cout << (c <= c) << std::endl;

	std::cout << "=== test operator<= for vectors if they aren't equal===" << std::endl;
	std::cout << (c <= a) << std::endl;

	std::cout << "=== test operator>= for vectors if they are equal===" << std::endl;
	std::cout << (c >= c) << std::endl;

	std::cout << "=== test operator>= for vectors if they aren't equal===" << std::endl;
	std::cout << (c >= a) << std::endl;

	std::cout << "=== test equal(iterator1, iterator2, iterator3) ===" << std::endl;
	std::cout << std::equal(a.begin(), a.end(), c.begin()) << std::endl;

	std::cout << "=== test equal(iterator1, iterator2, iterator3) ===" << std::endl;
	std::cout << std::equal(a.begin(), a.end(), a.begin()) << std::endl;

	std::cout << "=== test equal(iterator1, iterator2, iterator3, pred) ===" << std::endl;
	std::cout << std::equal(a.begin(), a.end(), c.begin(), my_pred) << std::endl;

	std::cout << "=== test equal(iterator1, iterator2, iterator3, pred) ===" << std::endl;
	std::cout << std::equal(a.begin(), a.end(), a.begin(), my_pred) << std::endl;

	std::cout << "=== test lexicographical_compare (iterator1, iterator2, iterator3, itertor4) ===" << std::endl;
	std::cout << std::lexicographical_compare(a.begin(), a.end(), c.begin(), c.end()) << std::endl;

	std::cout << "=== test lexicographical_compare (iterator1, iterator2, iterator3, itertor4) ===" << std::endl;
	std::cout << std::lexicographical_compare(a.begin(), a.end(), a.begin(), a.end()) << std::endl;

	std::cout << "=== test construction vector(iteratot first, iterator last)" << std::endl;
	std::vector<std::string>::iterator start = c.begin();
	std::vector<std::string>::iterator finish = c.end();
	std::vector<std::string> k(start, finish);
	std::cout << c[0] << " " << c[99] << std::endl;
	std::cout << k[0] << " " << k[99] << std::endl;
	std::cout << "size = " << k.size() << " capacity = " << k.capacity() << std::endl;

	std::cout << "=== test construction vector(iteratot last, iterator first)" << std::endl;
	try{
		std::vector<std::string> k(finish, start);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "=== test construction vector(reverse_iteratot first, iterator last)" << std::endl;
	std::vector<std::string>::reverse_iterator star = c.rbegin();
	std::vector<std::string>::reverse_iterator finis = c.rend();
	std::vector<std::string> l(star, finis);
	std::cout << c[0] << " " << c[99] << std::endl;
	std::cout << l[0] << " " << l[99] << std::endl;
	std::cout << "size = " << l.size() << " capacity = " << l.capacity() << std::endl;

	std::cout << "=== test construction vector(reverse_iteratot last, reverse_iterator first)" << std::endl;
	try{
		std::vector<std::string> l(finis, star);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "=== test assign(iteratot first, iterator last) ===" << std::endl;
	std::cout << "a[0] before: " << b[0] << " size = " << b.size() << " capacity = " << b.capacity() << std::endl;
	b.assign(start, finish);
	std::cout << "b[0] after: " << b[0] << " size = " << b.size() << " capacity = " << b.capacity() << std::endl;

	std::cout << "=== test assign(reverse_iteratot first, reverse_iterator last) ===" << std::endl;
	std::cout << "c[0] before: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	c.assign(star, finis);
	std::cout << "c[0] after: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test insert(iterator, val) in begin ===" << std::endl;
	std::cout << "c[0] before: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	std::cout << *(c.insert(c.begin(), "bbb")) << std::endl;
	std::cout << "c[0] after: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test insert(iterator, val) in medium ===" << std::endl;
	std::cout << "c[10] before: " << c[10] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	std::vector<std::string>::iterator i_m = c.begin();
	i_m += 10;
	std::cout << *(c.insert(i_m, "bbb")) << std::endl;
	std::cout << "c[10] after: " << c[10] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test insert(iterator, val) in end ===" << std::endl;
	std::cout << "size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	std::vector<std::string>::iterator i_e = c.end();
	std::cout << *(c.insert(i_e, "bbb")) << std::endl;
	std::cout << "size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test insert(iterator, first, last) in begin ===" << std::endl;
	std::cout << "c[0] before: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	c.insert(c.begin(), c.begin() + 30, c.begin() + 35);
	std::cout << "c[0] after: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test insert(iterator, first, last) in medium ===" << std::endl;
	std::cout << "c[10] before: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	c.insert(c.begin() + 40, c.begin(), c.begin() + 6);
	std::cout << "c[10] after: " << c[10] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test insert(iterator, first, last) in end ===" << std::endl;
	std::cout << "c before: " << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	c.insert(c.end(), c.begin(), c.begin() + 7);
	std::cout << "c after: " << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test insert(iterator, n, val) in begin ===" << std::endl;
	std::cout << "c[0] before: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	c.insert(c.begin(), 2, "ccc");
	std::cout << "c[0] after: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test insert(iterator, n, val) in medium ===" << std::endl;
	std::cout << "c[20] before: " << c[20] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	i_m = c.begin() + 20;
	c.insert(i_m, 3, "ddd");
	std::cout << "c[20] after: " << c[20] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test insert(iterator, n, val) in end ===" << std::endl;
	std::cout << "size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	i_e = c.end();
	c.insert(i_e, 4, "eee");
	std::cout << "size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test erase(iterator) in begin ===" << std::endl;
	std::cout << "c[0] before: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	std::cout << *(c.erase(c.begin())) << std::endl;
	std::cout << "c[0] after: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test erase(iterator) in medium ===" << std::endl;
	std::cout << "c[10] before: " << c[10] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	std::cout << *(c.erase(c.begin() + 10)) << std::endl;
	std::cout << "c[10] after: " << c[10] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test erase(iterator) in end - 1 ===" << std::endl;
	std::cout << "c before: " << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	c.erase(c.end() - 1);
	std::cout << "c after: " << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test erase(first, last) in begin ===" << std::endl;
	std::cout << "c[0] before: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	std::cout << *(c.erase(c.begin(), c.begin() + 5)) << std::endl;
	std::cout << "c[0] after: " << c[0] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test erase(first, last) in medium ===" << std::endl;
	std::cout << "c[10] before: " << c[10] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	std::cout << *(c.erase(c.begin() + 10, c.begin() + 15)) << std::endl;
	std::cout << "c[10] after: " << c[10] << " size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	std::cout << "=== test erase(first, last) in end ===" << std::endl;
	std::cout << "c before: " << "size = " << c.size() << " capacity = " << c.capacity() << std::endl;
	c.erase(c.begin() + 100, c.end());
	std::cout << "c after: " << "size = " << c.size() << " capacity = " << c.capacity() << std::endl;

	unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

	std::cout << "std time of work = " << search_time << std::endl;

	return (0);
}