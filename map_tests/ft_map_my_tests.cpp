#include "../my_map.hpp"
#include <iostream>

int main () {
	unsigned int start_time =  clock();

	std::cout << "### empty constructor\n";
	ft::map<std::string, double> a;

	std::cout << "### operator[] to change value\n";
	a["qwertyuiop"] = 0.0;
	a["wertyuiop"] = 0.1;
	a["ertyuiop"] = 0.2;
	a["rtyuiop"] = 0.3;
	a["tyuiop"] = 0.4;
	a["yuiop"] = 0.5;
	a["uiop"] = 0.6;
	a["iop"] = 0.7;
	a["op"] = 0.8;
	a["p"] = 0.9;
	a["asdfghjkl"] = 1.0;
	a["sdfghjkl"] = 1.1;
	a["dfghjkl"] = 1.2;
	a["fghjkl"] = 1.3;
	a["ghjkl"] = 1.4;
	a["hjkl"] = 1.5;
	a["jkl"] = 1.6;
	a["kl"] = 1.7;
	a["l"] = 1.8;
	a["zxcvbnm"] = 1.9;
	a["xcvbnm"] = 2.0;
	a["cvbnm"] = 2.1;
	a["vbnm"] = 2.2;
	a["bnm"] = 2.3;
	a["nm"] = 2.4;
	a["m"] = 2.5;

	std::cout << "### constructor for range\n";
	ft::map<std::string, double> b(++a.begin(), --a.end());

	std::cout << "### construction by copy\n";
	ft::map<std::string, double> c(a);

	std::cout << "### operator=\n";
	c = b;

	std::cout << "### begin for iterator\n";
	ft::map<std::string, double>::iterator d = b.begin();
	std::cout << d->first << " " << d->second << std::endl;

	std::cout << "### begin for const_iterator\n";
	ft::map<std::string, double>::const_iterator e = c.begin();
	std::cout << e->first << " " << e->second << std::endl;

	std::cout << "### construction by copy for iterators\n";
	ft::map<std::string, double>::iterator g(d);
	std::cout << g->first << " " << g->second << std::endl;

	std::cout << "### construction by copy for const_iterators\n";
	ft::map<std::string, double>::const_iterator h(e);
	std::cout << h->first << " " << h->second << std::endl;

	std::cout << "### construction by copy for const_iterator(iterator)\n";
	ft::map<std::string, double>::const_iterator f(d);
	std::cout << f->first << " " << f->second << std::endl;

	std::cout << "### operator= for iterators\n";
	ft::map<std::string, double>::iterator i;
	i = d;
	std::cout << i->first << " " << i->second << std::endl;

	std::cout << "### operator= for const_iterators\n";
	ft::map<std::string, double>::const_iterator j;
	j = e;
	std::cout << j->first << " " << j->second << std::endl;

	std::cout << "### operator= for const_iterator and iterator\n";
	j = i;
	std::cout << j->first << " " << j->second << std::endl;

	std::cout << "### operator* for iterator\n";
	ft::pair<const std::string, double> k = *i;
	std::cout << k.first << " " << k.second << std::endl;

	std::cout << "### operator* for const_iterator\n";
	ft::pair<const std::string, double> l = *j;
	std::cout << l.first << " " << l.second << std::endl;

	std::cout << "### operator-> for iterator to change value\n";
	std::cout << i->second << std::endl;
	i->second = 9.9;
	std::cout << i->second << std::endl;

	std::cout << "### operator++ for iterator\n";
	std::cout << i->first << " " << i->second << std::endl;
	++i;
	std::cout << i->first << " " << i->second << std::endl;

	std::cout << "### operator++(int) for iterator\n";
	std::cout << i->first << " " << i->second << std::endl;
	i++;
	std::cout << i->first << " " << i->second << std::endl;

	std::cout << "### operator-- for iterator\n";
	std::cout << i->first << " " << i->second << std::endl;
	--i;
	std::cout << i->first << " " << i->second << std::endl;

	std::cout << "### operator(int) for iterator\n";
	std::cout << i->first << " " << i->second << std::endl;
	i--;
	std::cout << i->first << " " << i->second << std::endl;

	std::cout << "### operator++ for const_iterator\n";
	std::cout << j->first << " " << j->second << std::endl;
	++j;
	std::cout << j->first << " " << j->second << std::endl;

	std::cout << "### operator++(int) for const_iterator\n";
	std::cout << j->first << " " << j->second << std::endl;
	j++;
	std::cout << j->first << " " << j->second << std::endl;

	std::cout << "### operator-- for const_iterator\n";
	std::cout << j->first << " " << j->second << std::endl;
	--j;
	std::cout << j->first << " " << j->second << std::endl;

	std::cout << "### operator(int) for const_iterator\n";
	std::cout << j->first << " " << j->second << std::endl;
	j--;
	std::cout << j->first << " " << j->second << std::endl;

	std::cout << "### operator== for iterators if they are equal\n";
	std::cout << (i == i) << std::endl;

	std::cout << "### operator== for const_iterators if the are equal\n";
	std::cout << (j == j) << std::endl;
	
	std::cout << "### end for iterator\n";
	ft::map<std::string, double>::iterator m = a.end();

	std::cout << "### operator== for iterators if they aren't equal\n";
	std::cout << (i == m) << std::endl;

	std::cout << "### end for const_iterator\n";
	ft::map<std::string, double>::const_iterator n = a.end();

	std::cout << "### operator== for const_iterators if the aren't equal\n";
	std::cout << (j == n) << std::endl;

	std::cout << "### rend for reverse_iterator\n";
	ft::map<std::string, double>::reverse_iterator o = a.rend();
	
	std::cout << "### operator-- for reverse_iterator\n";
	--o;
	std::cout << o->first << " " << o->second << std::endl;

	std::cout << "### operator--(int) for reverse_iterator\n";
	o--;
	std::cout << o->first << " " << o->second << std::endl;

	std::cout << "### rbegin() for reverce_iterstor\n";
	ft::map<std::string, double>::reverse_iterator p = a.rbegin();
	std::cout << p->first << " " << p->second << std::endl;

	std::cout << "### operator++ for reverse_iterator\n";
	++p;
	std::cout << p->first << " " << p->second << std::endl;

	std::cout << "### operator++(int) for reverse_iterator\n";
	p++;
	std::cout << p->first << " " << p->second << std::endl;

	std::cout << "### operator-> to change value for reverse_iterator\n";
	p->second = 7.7;
	std::cout << p->first << " " << p->second << std::endl;

	std::cout << "### operator== for reverse_iterators\n";
	std::cout << (p == o) << std::endl;

	std::cout << "### rend for const_reverse_iterator\n";
	ft::map<std::string, double>::const_reverse_iterator r = a.rend();

	std::cout << "### operator-- for const_reverse_iterator\n";
	--r;
	std::cout << r->first << " " << r->second << std::endl;

	std::cout << "### operator--(int) for const_reverse_iterator\n";
	r--;
	std::cout << r->first << " " << r->second << std::endl;

	std::cout << "### construction by copy for reverse_iterstor\n";
	ft::map<std::string, double>::reverse_iterator q(p);
	std::cout << q->first << " " << q->second << std::endl;

	std::cout << "### construction by copy for const_reverse_iterator\n";
	ft::map<std::string, double>::const_reverse_iterator s(r);
	std::cout << s->first << " " << s->second << std::endl;

	std::cout << "### operator== for const_reverse_iterator\n";
	std::cout << (s == r) << std::endl;

	std::cout << "### operator= for const_reverse_iterator and reverse_iterator\n";
	std::cout << s->first << " " << s->second << std::endl;
	s = p;
	std::cout << s->first << " " << s->second << std::endl;

	std::cout << "### empty if map isn't empty\n";
	std::cout << a.empty() << std::endl;

	std::cout << "### empty if map isempty\n";
	ft::map<std::string, double> t;
	std::cout << t.empty() << std::endl;

	std::cout << "### size for empty map\n";
	std::cout << t.size() << std::endl;

	std::cout << "### size for not empty map\n";
	std::cout << a.size() << std::endl;

	std::cout << "### max_size\n";
	std::cout << a.max_size() << std::endl;

	std::cout << "### operator[] to show value\n";
	std::cout << a["qwertyuiop"] << std::endl;

	std::cout << "### insert new value\n";
	ft::map<std::string, double>::iterator zz = a.begin();
	ft::map<std::string, double>::const_iterator xx = --a.end();
	ft::map<std::string, double>::reverse_iterator yy = a.rbegin();
	ft::map<std::string, double>::const_reverse_iterator ww = --a.rend();
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;
	ft::pair<ft::map<std::string, double>::iterator, bool> u = a.insert(ft::pair<std::string, double>("999", 6.6));
	std::cout << (u.first)->first << " " << (u.first)->second << " " << u.second << std::endl;
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;

	std::cout << "### insert already existing value\n";
	u = a.insert(ft::pair<std::string, double>("qwertyuiop", 5.5));
	std::cout << (u.first)->first << " " << (u.first)->second << " " << u.second << std::endl;
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;

	std::cout << "### insert in definite position new value\n";
	d = a.insert(a.begin(), ft::pair<std::string, double>("a", 5.5));
	std::cout << d->first << " " << d->second << std::endl;
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;

	std::cout << "### insert in definite position already existing value\n";
	d = a.insert(a.begin(), ft::pair<std::string, double>("a", 5.5));
	std::cout << d->first << " " << d->second << std::endl;
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;

	std::cout << "### insert for range already existing values\n";
	for (d = a.begin(); d != a.end(); ++d) {
		std::cout << d->first << " " << d->second << std::endl;
	}
	a.insert(a.begin(), a.end());
	for (d = a.begin(); d != a.end(); ++d) {
		std::cout << d->first << " " << d->second << std::endl;
	}
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;

	std::cout << "### insert for range new values\n";
	t["poiuytrewq"] = 4.4;
	t["lkjhgfdsa"] = 3.3;
	t["mnbvcxz"] = 2.2;
	a.insert(t.begin(), t.end());
	for (d = a.begin(); d != a.end(); ++d) {
		std::cout << d->first << " " << d->second << std::endl;
	}
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;

	std::cout << "### erase for iterator\n";
	a.erase(++a.begin());
	for (d = a.begin(); d != a.end(); ++d) {
		std::cout << d->first << " " << d->second << std::endl;
	}
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;

	std::cout << "### erase for exist key\n";
	std::cout << a.erase("lkjhgfdsa") << std::endl;
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;

	std::cout << "### erase for unfamiliar key\n";
	std::cout << a.erase("plm") << std::endl;
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;

	std::cout << "### erase for range\n";
	for (d = a.begin(); d != a.end(); ++d) {
		std::cout << d->first << " " << d->second << std::endl;
	}
	std::cout << "\n";
	zz = a.begin();
	a.erase(++a.begin(), --a.end());
	for (d = a.begin(); d != a.end(); ++d) {
		std::cout << d->first << " " << d->second << std::endl;
	}
	std::cout << "\n";
	std::cout << zz->first << " " << zz->second << std::endl;
	std::cout << xx->first << " " << xx->second << std::endl;
	std::cout << yy->first << " " << yy->second << std::endl;
	std::cout << ww->first << " " << ww->second << std::endl;

	std::cout << "### swap\n";
	for (d = t.begin(); d != t.end(); ++d) {
		std::cout << d->first << " " << d->second << std::endl;
	}
	std::cout << "\n";
	a.swap(t);
	for (d = t.begin(); d != t.end(); ++d) {
		std::cout << d->first << " " << d->second << std::endl;
	}

	std::cout << "### clear\n";
	std::cout << a.size() << std::endl;
	a.clear();
	std::cout << a.size() << std::endl;

	std::cout << "### key_comp\n";
	ft::map<std::string, double>::key_compare v = a.key_comp();
	std::cout << v("okn", "ijn") << std::endl;

	std::cout << "### value_comp\n";
	ft::map<std::string, double>::value_compare w = a.value_comp();
	std::cout << w(ft::pair<std::string, double>("uhb", 1.1), ft::pair<std::string, double>("ygv", 0.0)) << std::endl;

	std::cout << "### find familiar value for iterator\n";
	d = t.find("999");
	std::cout << d->first << " " << d->second << std::endl;

	std::cout << "### find unfamiliar value for iterator\n";
	std::cout << (t.end() == t.find("9")) << std::endl;

	std::cout << "### find familiar value for const_iterator\n";
	ft::map<std::string, double>::const_iterator x = t.find("zxcvbnm");
	std::cout << x->first << " " << x->second << std::endl;

	std::cout << "### find unfamiliar value for const_iterator\n";
	std::cout << (t.end() == t.find("8")) << std::endl;

	std::cout << "### count familiar value\n";
	std::cout << t.count("a") << std::endl;

	std::cout << "### count unfamiliar value\n";
	std::cout << t.count("aa") << std::endl;

	std::cout << "### lower_bound for iterator\n";
	t["qwertyuiop"] = 0.1;
	d = t.lower_bound("qwertyuiop");
	std::cout << d->first << " " << d->second << std::endl;

	std::cout << "### lower_bound for const_iterator\n";
	x = t.lower_bound("pl");
	std::cout << x->first << " " << x->second << std::endl;

	std::cout << "### upper_bound for iterator\n";
	d = t.upper_bound("a");
	std::cout << d->first << " " << d->second << std::endl;

	std::cout << "### upper_bound for const_iterator\n";
	x = t.upper_bound("z");
	std::cout << x->first << " " << x->second << std::endl;

	std::cout << "### equal_range for iterators\n";
	ft::pair<ft::map<std::string, double>::iterator, ft::map<std::string, double>::iterator> y = t.equal_range("a");
	std::cout << y.first->first << " " << y.first->second << " " << y.second->first << " " << y.second->second << std::endl;

	std::cout << "### equal_range for const_iterators\n";
	ft::pair<ft::map<std::string, double>::const_iterator, ft::map<std::string, double>::const_iterator> z;
	z = t.equal_range("qwertyuiop");
	std::cout << z.first->first << " " << z.first->second << " " << z.second->first << " " << z.second->second << std::endl;

	std::cout << "### get_allocator\n";
	ft::map<std::string, double>::allocator_type aa = t.get_allocator();
	ft::pair<const std::string, double, true> *bb = aa.allocate(1);
	const std::string cc("0147");
	aa.construct(bb, ft::pair<const std::string, double, true>(cc, 5.0));
	std::cout << bb->first << " " << bb->second << std::endl;
	aa.destroy(bb);
	aa.deallocate(bb, 1);

	std::cout << "### operator== for map\n";
	std::cout << (a == b) << std::endl;

	std::cout << "### operator!= for map\n";
	std::cout << (a != c) << std::endl;

	std::cout << "### operator< for map\n";
	std::cout << (b < c) << std::endl;

	std::cout << "### operator>= for map\n";
	std::cout << (a >= t) << std::endl;

	std::cout << "### operator> for map\n";
	std::cout << (b > t) << std::endl;

	std::cout << "### operator<= for map\n";
	std::cout << (c <= t) << std::endl;

	std::cout << "### swap (not a member)\n";
	for (d = b.begin(); d !=  b.end(); ++d) {
		std::cout << d->first << " " << d->second << std::endl;
	}
	ft::swap(b, c);
	for (d = b.begin(); d !=  b.end(); ++d) {
		std::cout << d->first << " " << d->second << std::endl;
	}

	std::cout << "### operator== for reverse_iterator and const_reverse_iterator\n";
	std::cout << (q == s) << std::endl; 

	std::cout << "### operator== for iterator and const_iterator\n";
	std::cout << (j == i) << std::endl; 

	unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

	std::cout << "ft time of work = " << search_time << std::endl;
	return 0;
}