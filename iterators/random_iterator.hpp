#ifndef RANDOM_ITERATOR_HPP
#define RANDOM_ITERATOR_HPP

#include "iterator.hpp"

namespace _ft {

	template <typename T, typename Dist, typename Ptr, typename Ref, bool is_const = false>
	class random_iterator : public ft::iterator<ft::random_access_iterator_tag, T, Dist, Ptr, Ref> {

		private:
			T* ptr;

		public:
			typedef				Dist											difference_type;
			typedef 			ft::random_access_iterator_tag					iterator_category;
			typedef typename	ft::conditional<is_const, const T, T>::type		value_type;
			typedef typename	ft::conditional<is_const, const Ptr, Ptr>::type	pointer;
			typedef typename	ft::conditional<is_const, const Ref, Ref>::type	reference;

			random_iterator() : ptr(0) {}

			random_iterator(T *x) : ptr(x) {}

			random_iterator(const random_iterator &to_copy) : ptr(to_copy.ptr) {}

			template <typename t, typename dist, typename pointer, typename ref>
			random_iterator(random_iterator<t, dist, pointer, ref, false> const &to_copy) {
				this->ptr = &(*to_copy);
			}

			pointer base() {
				return (this->ptr);
			}
			
			reference operator*() const {
				return (*(this->ptr));
			}

			pointer operator->() const {
				return (this->ptr);
			}

			random_iterator &operator++() {
				++this->ptr;
				return (*this);
			}

			random_iterator operator++(int) {
				random_iterator copy(*this);
				++this->ptr;
				return (copy);
			}

			random_iterator & operator--() {
				--this->ptr;
				return (*this);
			}

			random_iterator operator--(int) {
				random_iterator copy(*this);
				--this->ptr;
				return (copy);
			}

			random_iterator &operator+=(difference_type n) {
				this->ptr += n;
				return (*this);
			}

			random_iterator operator+(difference_type n) const {
				random_iterator copy(*this);
				copy.ptr += n;
				return (copy);
			}

			random_iterator &operator-=(difference_type n) {
				this->ptr -= n;
				return (*this);
			}

			random_iterator operator-(difference_type n) const {
				random_iterator copy(*this);
				copy.ptr -= n;
				return (copy);
			}

			difference_type operator-(random_iterator &to_substruct) const {
				return (this->ptr - to_substruct.ptr);
			}

			reference operator[](difference_type n) const {
				return (*(this->ptr + n));
			}

			~random_iterator() {}

			template <typename t, typename dist, typename pointer, typename ref, bool isConst>
			friend bool operator==(const random_iterator<t, dist, pointer, ref, isConst> &left, \
				const random_iterator<t, dist, pointer, ref, isConst> &right);

			template <typename t, typename dist, typename pointer, typename ref>
			friend bool operator==(const random_iterator<t, dist, pointer, ref, true> &left, \
				const random_iterator<t, dist, pointer, ref, false> &right);

			template <typename t, typename dist, typename pointer, typename ref>
			friend bool operator==(const random_iterator<t, dist, pointer, ref, false> &left, \
				const random_iterator<t, dist, pointer, ref, true> &right);

			template <typename t, typename dist, typename pointer, typename ref, bool isConst>
			friend bool operator<(const random_iterator<t, dist, pointer, ref, isConst> &left, \
				const random_iterator<t, dist, pointer, ref, isConst> &right);

			template <typename t, typename dist, typename pointer, typename ref>
			friend bool operator<(const random_iterator<t, dist, pointer, ref, true> &left, \
				const random_iterator<t, dist, pointer, ref, false> &right);

			template <typename t, typename dist, typename pointer, typename ref>
			friend bool operator<(const random_iterator<t, dist, pointer, ref, false> &left, \
				const random_iterator<t, dist, pointer, ref, true> &right);
				
			template <typename t, typename dist, typename pointer, typename ref, bool isConst>
			friend typename random_iterator<t, dist, pointer, ref, isConst>::difference_type operator-(const 
				random_iterator<t, dist, pointer, ref, isConst> &left, const random_iterator<t, dist, pointer, ref, 
				isConst> &right);

			template <typename t, typename dist, typename pointer, typename ref>
			friend typename random_iterator<t, dist, pointer, ref, true>::difference_type operator-(const 
				random_iterator<t, dist, pointer, ref, true> &left, const random_iterator<t, dist, pointer, ref, 
				false> &right);

			template <typename t, typename dist, typename pointer, typename ref>
			friend typename random_iterator<t, dist, pointer, ref, false>::difference_type operator-(const 
				random_iterator<t, dist, pointer, ref, false> &left, const random_iterator<t, dist, pointer, ref, 
				true> &right);
	};

	template <typename t, typename dist, typename pointer, typename ref, bool isConst>
	bool operator==(const random_iterator<t, dist, pointer, ref, isConst> &left, \
		const random_iterator<t, dist, pointer, ref, isConst> &right) {
			return (left.ptr == right.ptr);
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator==(const random_iterator<t, dist, pointer, ref, true> &left, \
		const random_iterator<t, dist, pointer, ref, false> &right) {
			return (left.ptr == right.ptr);
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator==(const random_iterator<t, dist, pointer, ref, false> &left, \
		const random_iterator<t, dist, pointer, ref, true> &right) {
			return (left.ptr == right.ptr);
		}

	template <typename t, typename dist, typename pointer, typename ref, bool isConst>
	bool operator<(const random_iterator<t, dist, pointer, ref, isConst> &left, \
		const random_iterator<t, dist, pointer, ref, isConst> &right) {
			return (left.ptr < right.ptr);
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator<(const random_iterator<t, dist, pointer, ref, true> &left, \
		const random_iterator<t, dist, pointer, ref, false> &right) {
			return (left.ptr < right.ptr);
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator<(const random_iterator<t, dist, pointer, ref, false> &left, \
		const random_iterator<t, dist, pointer, ref, true> &right) {
			return (left.ptr < right.ptr);
		}

	template <typename t, typename dist, typename pointer, typename ref, bool isConst>
	bool operator!=(const random_iterator<t, dist, pointer, ref, isConst> &left, \
		const random_iterator<t, dist, pointer, ref, isConst> &right) {
			return (!(left == right));
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator!=(const random_iterator<t, dist, pointer, ref, true> &left, \
		const random_iterator<t, dist, pointer, ref, false> &right) {
			return (!(left == right));
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator!=(const random_iterator<t, dist, pointer, ref, false> &left, \
		const random_iterator<t, dist, pointer, ref, true> &right) {
			return (!(left == right));
		}

	template <typename t, typename dist, typename pointer, typename ref, bool isConst>
	bool operator<=(const random_iterator<t, dist, pointer, ref, isConst> &left, \
		const random_iterator<t, dist, pointer, ref, isConst> &right) {
			return ((left < right) || (left == right));
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator<=(const random_iterator<t, dist, pointer, ref, true> &left, \
		const random_iterator<t, dist, pointer, ref, false> &right) {
			return ((left < right) || (left == right));
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator<=(const random_iterator<t, dist, pointer, ref, false> &left, \
		const random_iterator<t, dist, pointer, ref, true> &right) {
			return ((left < right) || (left == right));
		}
	
	template <typename t, typename dist, typename pointer, typename ref, bool isConst>
	bool operator>(const random_iterator<t, dist, pointer, ref, isConst> &left, \
		const random_iterator<t, dist, pointer, ref, isConst> &right) {
			return (!(left <= right));
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator>(const random_iterator<t, dist, pointer, ref, true> &left, \
		const random_iterator<t, dist, pointer, ref, false> &right) {
			return (!(left <= right));
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator>(const random_iterator<t, dist, pointer, ref, false> &left, \
		const random_iterator<t, dist, pointer, ref, true> &right) {
			return (!(left <= right));
		}

	template <typename t, typename dist, typename pointer, typename ref, bool isConst>
	bool operator>=(const random_iterator<t, dist, pointer, ref, isConst> &left, \
		const random_iterator<t, dist, pointer, ref, isConst> &right) {
			return (!(left < right));
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator>=(const random_iterator<t, dist, pointer, ref, true> &left, \
		const random_iterator<t, dist, pointer, ref, false> &right) {
			return (!(left < right));
		}

	template <typename t, typename dist, typename pointer, typename ref>
	bool operator>=(const random_iterator<t, dist, pointer, ref, false> &left, \
		const random_iterator<t, dist, pointer, ref, true> &right) {
			return (!(left < right));
		}

	template <typename t, typename dist, typename pointer, typename ref, bool isConst>
	typename random_iterator<t, dist, pointer, ref, isConst>::difference_type operator-(const random_iterator<t, dist, 
		pointer, ref, isConst> &left, const random_iterator<t, dist, pointer, ref, isConst> &right) {
			return (left.ptr - right.ptr);
	}

	template <typename t, typename dist, typename pointer, typename ref>
	typename random_iterator<t, dist, pointer, ref, true>::difference_type operator-(const random_iterator<t, dist, 
		pointer, ref, true> &left, const random_iterator<t, dist, pointer, ref, false> &right) {
			return (left.ptr - right.ptr);
	}

	template <typename t, typename dist, typename pointer, typename ref>
	typename random_iterator<t, dist, pointer, ref, false>::difference_type operator-(const random_iterator<t, dist, 
		pointer, ref, false> &left, const random_iterator<t, dist, pointer, ref, true> &right) {
			return (left.ptr - right.ptr);
	}
}

#endif
