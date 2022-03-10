#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "random_iterator.hpp"

namespace ft {

	//может быть использован для map && set - в этом случае нельзя вызывать operator+=, operator+, operator-, operator-=, operator[]
	template <typename Iterator>
	class reverse_iterator : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category, \
		typename ft::iterator_traits<Iterator>::value_type, typename ft::iterator_traits<Iterator>::difference_type,\
		typename ft::iterator_traits<Iterator>::pointer, typename ft::iterator_traits<Iterator>::reference> { 
		
		protected:
			Iterator										current;

		public:
			typedef Iterator								iterator_type;
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;

			reverse_iterator() {}

			reverse_iterator(iterator_type it) : current(it) {}

			template <typename Iter>
			reverse_iterator(const reverse_iterator<Iter> &rev_it) : current(rev_it.base()) {}

			reverse_iterator operator=(reverse_iterator to_assignation) {
				if (this == &to_assignation)
					return (*this);
				this->current = to_assignation.current;
				return (*this);
			}

			Iterator base() const {
				return (this->current);
			}

			reference operator*() const {
				reverse_iterator copy(*this);
				copy++;
				return (*(copy.current));
			}

			pointer operator->() const {
				return &(operator*());
			}

			reverse_iterator &operator++() {
				--this->current;
				return (*this);
			}

			reverse_iterator operator++(int) {
				reverse_iterator copy(*this);
				--this->current;
				return (copy);
			}

			reverse_iterator &operator--() {
				++this->current;
				return (*this);
			}

			reverse_iterator operator--(int) {
				reverse_iterator copy(*this);
				++this->current;
				return (copy);
			}

			reverse_iterator &operator+=(difference_type n) {
				this->current -= n;
				return (*this);
			}

			reverse_iterator operator+(difference_type n) const {
				return (this->base() - n);
			}

			reverse_iterator &operator-=(difference_type n) {
				this->current += n;
				return (*this);
			}

			reverse_iterator operator-(difference_type n) const {
				return (this->base() + n);
			}
			
			reference operator[](difference_type n) const {
				return (this->current[-n - 1]);
			}

			~reverse_iterator() {}

			template <typename It1, typename It2>
			friend bool operator==(const reverse_iterator<It1> &left, const reverse_iterator<It2> &right);

			template <typename It1, typename It2>
			friend bool operator<(const reverse_iterator<It1> &left, const reverse_iterator<It2> &right);

			template <typename It1, typename It2>
			friend typename reverse_iterator<It1>::difference_type operator-(const reverse_iterator<It1> &left, \
				const reverse_iterator<It2> &right);

			template <typename It>
			friend reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type n, \
				const reverse_iterator<It>& rev_it);
	};

	template <typename Iterator1, typename Iterator2>
	bool operator==(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) {
		return (left.current == right.current);
	}

	template <typename Iterator1, typename Iterator2>
	bool operator!=(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) {
		return (!(left == right));
	}

	template <typename Iterator1, typename Iterator2>
	bool operator<(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) {
		return (left.current > right.current);
	}

	template <typename Iterator1, typename Iterator2>
	bool operator<=(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) {
		return ((left < right) || (left == right));
	}

	template <typename Iterator1, typename Iterator2>
	bool operator>(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) {
		return (!(left <= right));
	}

	template <typename Iterator1, typename Iterator2>
	bool operator>=(const reverse_iterator<Iterator1> &left, const reverse_iterator<Iterator2> &right) {
		return (!(left < right));
	}

	template <typename Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, \
		const reverse_iterator<Iterator>& rev_it) {
			return (rev_it + n);
	}

	template <typename Iterator1, typename Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& left, \
    	const reverse_iterator<Iterator2>& right) {
			return (right.current - left.current);
	}
}


#endif