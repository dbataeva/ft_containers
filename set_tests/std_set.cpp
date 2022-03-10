#include <iostream>
#include <set>

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main () {

	unsigned int start_time =  clock();
	std::cout << "### constructor\n";
	{
		std::set<int> first;                           // empty set of ints

		int myints[]= {10,20,30,40,50};
		std::set<int> second (myints,myints+5);        // range

		std::set<int> third (second);                  // a copy of second

		std::set<int> fourth (second.begin(), second.end());  // iterator ctor.

		std::set<int,classcomp> fifth;                 // class as Compare

		bool(*fn_pt)(int,int) = fncomp;
		std::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare

	}
	std::cout << "### operator=\n";
	{
		int myints[]={ 12,82,37,64,15 };
		std::set<int> first (myints,myints+5);   // set with 5 ints

		std::cout << "Size of first: " << int (first.size()) << '\n';

		std::set<int> second;                    // empty set

		std::cout << "Size of second: " << int (second.size()) << '\n';

		second = first;                          // now second contains the 5 ints

		std::cout << "Size of second: " << int (second.size()) << '\n';
		
		first = std::set<int>();                 // and first is empty

		std::cout << "Size of first: " << int (first.size()) << '\n';
	}
	std::cout << "### bedin && end\n";
	{
		int myints[] = {75,23,65,42,13};
		std::set<int> myset (myints,myints+5);

		std::cout << "myset contains:";
		for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}
	std::cout << "### rbegin && rend\n";
	{
		int myints[] = {21,64,17,78,49};
		std::set<int> myset (myints,myints+5);

		std::set<int>::reverse_iterator rit;

		std::cout << "myset contains:";
		for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
			std::cout << ' ' << *rit;

		std::cout << '\n';
	}
	std::cout << "### empty\n";
	{
		std::set<int> myset;

		myset.insert(20);
		myset.insert(30);
		myset.insert(10);

		std::cout << "myset contains:";
		while (!myset.empty())
		{
			std::cout << ' ' << *myset.begin();
			myset.erase(myset.begin());
		}
		std::cout << '\n';
	}
	std::cout << "### size\n";
	{
		std::set<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; ++i) myints.insert(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.erase(5);
		std::cout << "3. size: " << myints.size() << '\n';
	}
	std::cout << "### max_size\n";
	{
		int i;
		std::set<int> myset;

		if (myset.max_size()>1000)
		{
			for (i=0; i<1000; i++) myset.insert(i);
			std::cout << "The set contains 1000 elements.\n";
		}
		else std::cout << "The set could not hold 1000 elements.\n";
	}
	std::cout << "### insert\n";
	{
		std::set<int> myset;
		std::set<int>::iterator it;
		std::pair<std::set<int>::iterator,bool> ret;

		// set some initial values:
		for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

		ret = myset.insert(20);               // no new element inserted

		if (ret.second==false) it=ret.first;  // "it" now points to element 20

		myset.insert (it,25);                 // max efficiency inserting
		myset.insert (it,24);                 // max efficiency inserting
		myset.insert (it,26);                 // no max efficiency inserting

		int myints[]= {5,10,15};              // 10 already in set, not inserted
		myset.insert (myints,myints+3);

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << "### erase\n";
	{
		std::set<int> myset;
		std::set<int>::iterator it;

		// insert some values:
		for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

		it = myset.begin();
		std::set<int>::iterator i_t = myset.end();
		
		std::cout << "myset contains:";
		for (; it!=i_t; ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		it = myset.begin();
		++it;  
		myset.erase (it);

		it = myset.begin();
		std::cout << "myset contains:";
		for (; it!=i_t; ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		myset.erase (40);

		it = myset.begin();
		std::cout << "myset contains:";
		for (; it!=i_t; ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		it = myset.find (60);
		myset.erase (it, myset.end());
		
		std::set<int>::iterator _it=myset.begin();
		std::cout << "myset contains:";
		for (; _it!=myset.end(); ++_it)
			std::cout << ' ' << *_it;
		std::cout << '\n';
	}
	std::cout << "### swap\n";
	{
		int myints[]={12,75,10,32,20,25};
		std::set<int> first (myints,myints+3);     // 10,12,75
		std::set<int> second (myints+3,myints+6);  // 20,25,32

		first.swap(second);

		std::cout << "first contains:";
		for (std::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (std::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << "### clear\n";
	{
		std::set<int> myset;

		myset.insert (100);
		myset.insert (200);
		myset.insert (300);

		std::cout << "myset contains:";
		for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		myset.clear();
		myset.insert (1101);
		myset.insert (2202);

		std::cout << "myset contains:";
		for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << "### key_compare\n";
	{
		std::set<int> myset;
		int highest;

		std::set<int>::key_compare mycomp = myset.key_comp();

		for (int i=0; i<=5; i++) myset.insert(i);

		std::cout << "myset contains:";

		highest=*myset.rbegin();
		std::set<int>::iterator it=myset.begin();
		do {
			std::cout << ' ' << *it;
		} while ( mycomp(*(++it),highest) );

		std::cout << '\n';
	}
	std::cout << "### value_compare\n";
	{
		std::set<int> myset;

		std::set<int>::value_compare mycomp = myset.value_comp();

		for (int i=0; i<=5; i++) myset.insert(i);

		std::cout << "myset contains:";

		int highest=*myset.rbegin();
		std::set<int>::iterator it=myset.begin();
		do {
			std::cout << ' ' << *it;
		} while ( mycomp(*(++it),highest) );

		std::cout << '\n';
	}
	std::cout << "### find\n";
	{
		std::set<int> myset;
		std::set<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

		it=myset.find(20);
		myset.erase (it);
		myset.erase (myset.find(40));

		std::cout << "myset contains:";
		for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << "### counst\n";
	{
		std::set<int> myset;

  // set some initial values:
		for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

		for (int i=0; i<10; ++i)
		{
			std::cout << i;
			if (myset.count(i)!=0)
			std::cout << " is an element of myset.\n";
			else
			std::cout << " is not an element of myset.\n";
		}
	}
	std::cout << "### lower_bound && upperbound\n";
	{
		std::set<int> myset;
		std::set<int>::iterator itlow,itup;

		for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

		itlow=myset.lower_bound (30);                //       ^
		itup=myset.upper_bound (60);                 //                   ^

		myset.erase(itlow,itup);                     // 10 20 70 80 90

		std::cout << "myset contains:";
		for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << "### equal_range\n";
	{
		std::set<int> myset;

		for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

		std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
		ret = myset.equal_range(30);

		std::cout << "the lower bound points to: " << *ret.first << '\n';
		std::cout << "the upper bound points to: " << *ret.second << '\n';
	}
	std::cout << "### get_allocator\n";
	{
		std::set<int> myset;
		int * p;
		unsigned int i;

		// allocate an array of 5 elements using myset's allocator:
		p=myset.get_allocator().allocate(5);

		// assign some values to array
		for (i=0; i<5; i++) p[i]=(i+1)*10;

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		myset.get_allocator().deallocate(p,5);
	}
  
	unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время

	std::cout << "std time of work = " << search_time << std::endl;
	return 0;
}