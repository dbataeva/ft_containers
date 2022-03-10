#ifndef RELATIONAL_OPERATORS_HPP
#define RELATIONAL_OPERATORS_HPP

namespace ft {

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		for (; first1 != last1; ++first1, ++first2) {
			if (*first1 != *first2)
				return (false);
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		for (; first1 != last1; ++first1, ++first2) {
			if (!pred(*first1, *first2))
				return (false);
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, \
		InputIterator2 first2, InputIterator2 last2) {
			for (; first1 != last1; ++first1, ++first2) {
			if (*first1 < *first2)
				return (true);
			else if ((*first2 < *first1) || (first2 == last2))
				return (false);
			}
			return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, \
		InputIterator2 last2, Compare comp) {
			for (; first1 != last1; ++first1, ++first2) {
			if (comp(*first1, *first2))
				return (true);
			else if (comp(*first2, *first1) || (first2 == last2))
				return (false);
			}
			return (first2 != last2);
	}
}

#endif