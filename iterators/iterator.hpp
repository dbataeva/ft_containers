#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iterator>
#include <uchar.h>

namespace ft {

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	template <class Iter>
	struct iterator_traits {
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef typename std::ptrdiff_t			differense_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T         						value_type;

	};

	template <class T>
	struct iterator_traits<const T*> {
		typedef typename std::ptrdiff_t			differense_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T         						value_type;

	};

	template <bool A, typename B, typename C>
	struct conditional {
		typedef C	type;
	};

	template <typename B, typename C>
	struct conditional <true, B, C> {
		typedef B	type;
	};

	struct input_iterator_tag {};												//iterator_category

	struct forward_iterator_tag : public input_iterator_tag {};

	struct bidirectional_iterator_tag : public forward_iterator_tag {};

	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <typename T>
	struct is_integral {
		static const bool value = false;
	};

	template <>
	struct is_integral <char> {
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned short int> {
		static const bool value = true;
	};

	// template <>
	// struct is_integral <char16_t> {
	// 	static const bool value = true;
	// };

	// template <>
	// struct is_integral <char32_t> {
	// 	static const bool value = true;
	// };

	template <>
	struct is_integral <wchar_t> {
		static const bool value = true;
	};

	template <>
	struct is_integral <signed char> {
		static const bool value = true;
	};

	template <>
	struct is_integral <short int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <long int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <long long int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned char> {
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned long int> {
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned long long int> {
		static const bool value = true;
	};

	template <bool Cond, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if <true, T> {
		typedef T type;
	};
}

#endif
