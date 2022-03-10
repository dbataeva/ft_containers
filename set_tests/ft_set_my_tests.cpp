#include "../my_set.hpp"
#include <iostream>

int main () {
	unsigned int start_time =  clock();

	std::cout << "### empty set constructor && size && insert for value\n";
	ft::set<std::string> a;
	std::cout << a.size() << std::endl;

	a.insert("qwerty");
	a.insert("asdfg");
	a.insert("zxcvb");
	a.insert("werty");
	a.insert("sdfgh");
	a.insert("xcvbn");
	a.insert("ertyu");
	a.insert("dfghj");
	a.insert("cvbnm");
	a.insert("rtyui");
	a.insert("fghjk");
	a.insert("bnm");
	a.insert("tyuio");
	a.insert("ghjkl");
	a.insert("nm");
	a.insert("yuiop");
	a.insert("hjkl");
	a.insert("m");
	a.insert("uiop");
	a.insert("jkl");
	a.insert("iop");
	a.insert("kl");
	a.insert("op");
	a.insert("l");
	a.insert("p");
	
	std::cout << "### iterator constructor && size\n";
	ft::set<std::string> b(a.begin(), a.end());
	std::cout << b.size() << std::endl;

	std::cout << "### copy constructor && size\n";
	ft::set<std::string> c(b);
	std::cout << c.size() << std::endl;

	std::cout << "### operator= && size\n";
	ft::set<std::string> d;
	b = d;
	std::cout << b.size() << std::endl;

	std::cout << "### befin (iterator)\n";
	ft::set<std::string>::iterator e = a.begin();
	std::cout << *e << std::endl;

	std::cout << "### operator++ for iterator\n";
	++e;
	std::cout << *e << std::endl;

	std::cout << "### operator++(int) for iterator\n";
	e++;
	std::cout << *e << std::endl;

	std::cout << "### operator--(int) for iterator\n";
	e--;
	std::cout << *e << std::endl;

	std::cout << "### operator-- for iterator\n";
	--e;
	std::cout << *e << std::endl;

	std::cout << "### operator-> for iterator\n";
	std::cout << e->c_str() << std::endl;

	std::cout << "### begin (const_iterator)\n";
	ft::set<std::string>::const_iterator f = a.begin();
	std::cout << *f << std::endl;

	std::cout << "### operator++ for const_iterator\n";
	++f;
	std::cout << *f << std::endl;

	std::cout << "### operator++(int) for const_iterator\n";
	f++;
	std::cout << *f << std::endl;

	std::cout << "### operator--(int) for const_iterator\n";
	f--;
	std::cout << *f << std::endl;

	std::cout << "### operator-- for const_iterator\n";
	--f;
	std::cout << *f << std::endl;

	std::cout << "### operator-> for const_iterator\n";
	std::cout << f->c_str() << std::endl;

	std::cout << "### end() itrerator\n";
	ft::set<std::string>::iterator g = a.end();

	std::cout << "### end() const_itrerator\n";
	ft::set<std::string>::const_iterator h = a.end();

	std::cout << "### operator== for iterators\n";
	std::cout << (e == g) << std::endl;

	std::cout << "### operator== for const_iterators\n";
	std::cout << (f == h) << std::endl;

	std::cout << "### operator== for iterator and const_iterator\n";
	std::cout << (e == f) << std::endl;

	std::cout << "### operator!= for iterators\n";
	std::cout << (e != g) << std::endl;

	std::cout << "### operator!= for const_iterators\n";
	std::cout << (f != h) << std::endl;

	std::cout << "### operator!= for iterator and const_iterator\n";
	std::cout << (e != f) << std::endl;

	std::cout << "### empty constructor for iterator\n";
	ft::set<std::string>::iterator i;

	std::cout << "### empty constructor for const_iterator\n";
	ft::set<std::string>::const_iterator j;

	std::cout << "### construction by copy for iterator(iterator)\n";
	ft::set<std::string>::iterator k(e);
	std::cout << *k << std::endl;

	std::cout << "### construction by copy for const_iterator(const_iterator)\n";
	ft::set<std::string>::const_iterator l(f);
	std::cout << *l << std::endl;

	std::cout << "### construction by copy for const_iterator(iterator)\n";
	ft::set<std::string>::const_iterator m(e);
	std::cout << *m << std::endl;

	std::cout << "### construction by copy for iterator(const_iterator)\n";
	ft::set<std::string>::iterator n(m);
	std::cout << *n << std::endl;

	std::cout << "### operator= for iterators\n";
	e = n;

	std::cout << "### operator= for const_iterators\n";
	f = m;

	std::cout << "### operator= for iterator and const_iterator\n";
	e = f;

	std::cout << "### operator= for const_iterator and iterator\n";
	f = e;

	std::cout << "### rend() reverse_itrerator\n";
	ft::set<std::string>::reverse_iterator o = a.rend();

	std::cout << "### operator--(int) for reverse_iterator\n";
	o--;
	std::cout << *o << std::endl;

	std::cout << "### operator-- for reverse_iterator\n";
	--o;
	std::cout << *o << std::endl;

	std::cout << "### operator++ for reverse_iterator\n";
	++o;
	std::cout << *o << std::endl;

	std::cout << "### operator++(int) for reverse_iterator\n";
	o++;	

	--o;
	std::cout << "### operator-> for const_iterator\n";
	std::cout << o->c_str() << std::endl;

	std::cout << "### rbegin() const_reverse_itrerator\n";
	ft::set<std::string>::const_reverse_iterator q = a.rbegin();

	std::cout << "### operator++ for const_reverse_iterator\n";
	++q;
	std::cout << *q << std::endl;

	std::cout << "### operator++(int) for const_reverse_iterator\n";
	q++;

	std::cout << "### operator--(int) for const_reverse_iterator\n";
	q--;
	std::cout << *q << std::endl;

	std::cout << "### operator-- for const_reverse_iterator\n";
	--q;
	std::cout << *q << std::endl;	

	++q;
	std::cout << "### operator-> for const_iterator\n";
	std::cout << q->c_str() << std::endl;

	std::cout << "### operator== for reverse_iterator and const_reverse_iterator\n";
	std::cout << (o == q) << std::endl;

	std::cout << "### operator!= for reverse_iterator and const_reverse_iterator\n";
	std::cout << (o != q) << std::endl;

	ft::set<std::string>::const_reverse_iterator r = a.rend();
	ft::set<std::string>::reverse_iterator s = a.rbegin();

	std::cout << "### operator== for reverse_iterators\n";
	std::cout << (o == s) << std::endl;

	std::cout << "### operator!= for reverse_iterators\n";
	std::cout << (o != s) << std::endl;

	std::cout << "### operator== for const_reverse_iterators\n";
	std::cout << (q == r) << std::endl;

	std::cout << "### operator!= for const_reverse_iterators\n";
	std::cout << (r != q) << std::endl;

	std::cout << "### empty constructor for reverse_iterator\n";
	ft::set<std::string>::reverse_iterator t;
	(void)t;

	std::cout << "### empty constructor for const_reverse_iterator\n";
	ft::set<std::string>::const_iterator u;

	std::cout << "### construction by copy for reverse_iterator(reverse_iterator)\n";
	ft::set<std::string>::reverse_iterator v(++s);
	std::cout << *v << std::endl;

	std::cout << "### construction by copy for const_reverse_iterator(const_reverse_iterator)\n";
	ft::set<std::string>::const_reverse_iterator w(--r);
	std::cout << *w << std::endl;

	std::cout << "### construction by copy for const_reverse_iterator(reverse_iterator)\n";
	ft::set<std::string>::const_reverse_iterator y(++s);
	std::cout << *y << std::endl;

	std::cout << "### construction by copy for const_reverse_iterator(reverse_iterator)\n";
	ft::set<std::string>::const_reverse_iterator x(++s);
	std::cout << *x << std::endl;

	std::cout << "### operator!= for reverse_iterator && const_reverse_iterator\n";
	std::cout << (x != v) << std::endl;

	std::cout << "### operator== for const_reverse_iterator && reverse_iterator\n";
	std::cout << (v == x) << std::endl;

	std::cout << "### empty with not empty set\n";
	std::cout << a.empty() << std::endl;

	std::cout << "### empty with empty set\n";
	std::cout << d.empty() << std::endl;

	std::cout << "### max_size\n";
	std::cout << a.max_size() << std::endl;

	std::cout << "### insert for value that is already in set\n";
	std::cout << a.size() << std::endl;
	a.insert("qwerty");
	std::cout << a.size() << std::endl;

	std::cout << "### insert for iterator position\n";
	ft::set<std::string>::iterator z = a.insert(++a.begin(), "qaz");
	std::cout << *z << std::endl;

	std::cout << "### insert for value\n";
	ft::pair<ft::set<std::string>::iterator, bool> aa = a.insert("wsx");
	std::cout << aa.second << std::endl;

	std::cout << "### insert for range\n";
	for (ft::set<std::string>::iterator bb = a.begin(); bb != a.end(); ++bb) {
		std::cout << *bb << std::endl;
	}
	ft::set<std::string> cc;
	cc.insert("edc");
	cc.insert("rfv");
	cc.insert("tgb");
	cc.insert("yhn");
	cc.insert("ujm");
	cc.insert("ik");
	cc.insert("ol");
	cc.insert("p");
	
	a.insert(cc.begin(), cc.end());
	for (ft::set<std::string>::iterator bb = a.begin(); bb != a.end(); ++bb) {
		std::cout << *bb << std::endl;
	}

	std::cout << "### erase for iterator position\n";
	std::cout << a.size() << std::endl;
	a.erase(a.begin());
	std::cout << a.size() << std::endl;

	std::cout << "### erase for exist value\n";
	std::cout << a.size() << std::endl;
	std::cout << a.erase("qwerty") << std::endl;
	std::cout << a.size() << std::endl;

	std::cout << "### erase for not exist value\n";
	std::cout << a.size() << std::endl;
	std::cout << a.erase("qwertyp") << std::endl;
	std::cout << a.size() << std::endl;

	std::cout << "### erase for iterator range\n";
	std::cout << a.size() << std::endl;
	a.erase(++a.begin(), --a.end());
	std::cout << a.size() << std::endl;

	std::cout << "### swap\n";
	std::cout << a.size() << std::endl;
	a.swap(cc);
	std::cout << a.size() << std::endl;

	std::cout << "### clear\n";
	std::cout << cc.size() << std::endl;
	cc.clear();
	std::cout << cc.size() << std::endl;

	std::cout << "### key_copm\n";
	ft::set<std::string>::key_compare bb = a.key_comp();
	std::cout << bb.operator()("aaa", "aaab") << std::endl;

	std::cout << "### value_copm\n";
	ft::set<std::string>::value_compare dd = a.value_comp();
	std::cout << dd.operator()("aab", "aaab") << std::endl;

	std::cout << "### find for not exist value\n";
	std::cout << (cc.find("qaz") == cc.end()) << std::endl;

	std::cout << "### find for exist value\n";
	std::cout << *(a.find("edc")) << std::endl;

	std::cout << "### count for exist value\n";
	std::cout << a.count("ik") << std::endl;

	std::cout << "### count for not exist value\n";
	std::cout << a.count("123") << std::endl;

	std::cout << "### lower_bound\n";
	std::cout << *(a.lower_bound("ol")) << std::endl;

	std::cout << "### upper_bound\n";
	std::cout << *(a.upper_bound("p")) << std::endl;

	std::cout << "### equal_range\n";
	ft::pair<ft::set<std::string>::iterator, ft::set<std::string>::iterator> ee = a.equal_range("rfv");
	for (; ee.first != ee.second; ++ee.first) {
		std::cout << *ee.first << std::endl;
	}

	std::cout << "### get_allocator\n";
	ft::set<std::string>::allocator_type ff = a.get_allocator();
	std::string *gg = ff.allocate(1);
	ff.construct(gg, "poiuytrewq");
	std::cout << *gg << std::endl;
	ff.destroy(gg);
	ff.deallocate(gg, 1);

	std::cout << "### operator== for sets if they are equal\n";
	std::cout << (a == a) << std::endl;

	std::cout << "### operator== for sets if they aren't equal\n";
	std::cout << (a == b) << std::endl;

	std::cout << "### operator!= for sets if they are equal\n";
	std::cout << (a != a) << std::endl;

	std::cout << "### operator!= for sets if they aren't equal\n";
	std::cout << (a != b) << std::endl;

	std::cout << "### operator> for sets if they are equal\n";
	std::cout << (a > a) << std::endl;

	std::cout << "### operator> for sets if they aren't equal\n";
	std::cout << (a > b) << std::endl;

	std::cout << "### operator>= for sets if they are equal\n";
	std::cout << (a >= a) << std::endl;

	std::cout << "### operator>= for sets if they aren't equal\n";
	std::cout << (a >= b) << std::endl;

	std::cout << "### operator<= for sets if they are equal\n";
	std::cout << (a <= a) << std::endl;

	std::cout << "### operator<= for sets if they aren't equal\n";
	std::cout << (a <= b) << std::endl;

	std::cout << "### operator< for sets if they are equal\n";
	std::cout << (a < a) << std::endl;

	std::cout << "### operator< for sets if they aren't equal\n";
	std::cout << (a < b) << std::endl;

	std::cout << "### swap (not a member)\n";
	for (ft::set<std::string>::iterator gg = a.begin(); gg != a.end(); ++gg) {
		std::cout << *gg << std::endl;
	}
	for (ft::set<std::string>::iterator gg = b.begin(); gg != b.end(); ++gg) {
		std::cout << *gg << std::endl;
	}
	ft::swap(a, b);
	for (ft::set<std::string>::iterator gg = a.begin(); gg != a.end(); ++gg) {
		std::cout << *gg << std::endl;
	}
	for (ft::set<std::string>::iterator gg = b.begin(); gg != b.end(); ++gg) {
		std::cout << *gg << std::endl;
	}

	unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

	std::cout << "ft time of work = " << search_time << std::endl;
}
