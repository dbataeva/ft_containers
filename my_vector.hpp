#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <iostream>
#include <sstream>

#include "iterators/reverse_iterator.hpp"
#include "relational_operators.hpp"


namespace ft {

	template <typename T, typename Alloc = std::allocator<T> >
	class vector {
		private:
			T		*array;
			size_t	siz;
			size_t 	cap;
			Alloc	allocator;

		public:
			typedef T																	value_type;
			typedef Alloc																allocator_type;
			typedef typename Alloc::reference											reference;
			typedef typename Alloc::const_reference										const_reference;
			typedef typename Alloc::pointer												pointer;
			typedef typename Alloc::const_pointer										const_pointer;
			typedef typename ft::iterator_traits<ft::iterator<ft::random_access_iterator_tag, T> >::difference_type	
																						difference_type;

			typedef _ft::random_iterator<T, difference_type, pointer, reference, true>	const_iterator;
			typedef _ft::random_iterator<T, difference_type, pointer, reference> 		iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
			typedef size_t																size_type;
			
			vector(const Alloc& = Alloc()) : array(0), siz(0), cap(0) {}

			vector(size_t n, const value_type& val = value_type(), const Alloc& = Alloc()) : siz(n), cap(n) {
				if (n == 0) {
					this->array = 0;
					return ;
				}
				this->array = allocator.allocate(n);
				size_t i = 0;
				try {
					for (; i < n; ++i) {
						allocator.construct(&this->array[i], val);
					}
				}
				catch (...) {
					for (size_t j = 0; j < i; ++j) {
						allocator.destroy(&this->array[j]);
					}
					allocator.deallocate(this->array, this->cap);
					this->siz = 0;
					this->cap = 0;
					throw ;
				}
				return ;
			}

			vector(const vector &to_copy) {
				this->siz = 0;
				this->cap = 0;
				this->allocator = to_copy.get_allocator();
				*this = to_copy;
				return ;
			}

			template <typename InputIterator>
			vector(InputIterator first, InputIterator last, const Alloc& = Alloc(), \
				typename enable_if<!is_integral<InputIterator>::value, void**>::type = NULL) {
					size_t i = last - first;
					if (i > this->max_size())
						throw std::length_error("cannot create ft::vector larger than max_size()");
					this->siz = i;
					this->cap = i;
					if (i == 0) {
						this->array = 0;
						return ;
					}
					this->array = this->allocator.allocate(i);
					try {
						for (i = 0; first != last; ++first, ++i) {
							this->allocator.construct(&this->array[i], *first);
						}
					}
					catch (...) {
						for (size_t j = 0; j < i; ++j) {
							this->allocator.destroy(&this->array[j]);
						}
						allocator.deallocate(this->array, this->cap);
						this->siz = 0;
						this->cap = 0;
						throw ;
					}
					return ;
			}

			~vector() {
				for (size_t i = 0; i < this->siz; ++i) {
					allocator.destroy(&this->array[i]);
				}
				if (this->cap)
					allocator.deallocate(this->array, this->cap);
				this->siz = 0;
				this->cap = 0;
				return ;
			}

			const vector &operator=(const vector &to_assignation) {
				if (this == &to_assignation)
					return *this;
				value_type *new_arr = 0;
				size_t i;
				if (to_assignation.cap != 0) {
					new_arr = allocator.allocate(to_assignation.cap);
					try {
						for (i = 0; i < to_assignation.siz; ++i) {
							allocator.construct(&new_arr[i], to_assignation.array[i]);
						}
					} catch (...) {
						for (size_t j = 0; j < i; ++j) {
							allocator.destroy(&new_arr[j]);
						}
						allocator.deallocate(new_arr, to_assignation.cap);
						throw ;
					}
				}
				for (i = 0; i < this->siz; ++i) {
					allocator.destroy(&this->array[i]);
				}
				if (this->cap)
					allocator.deallocate(this->array, this->cap);
				this->siz = to_assignation.siz;
				this->cap = to_assignation.cap;
				this->array = new_arr;
				return (*this);
			}

			iterator begin() {
				if (this->siz)
					return(allocator.address(this->array[0]));
				return (0);
			};

			const_iterator begin() const {
				if (this->siz)
					return(allocator.address(this->array[0]));
				return (0);
			}

			iterator end() {
				if (this->empty())
					return (0);
				return(allocator.address(this->array[this->siz]));
			}

			const_iterator end() const {
				if (this->empty())
					return (0);
				return(allocator.address(this->array[this->siz]));
			}

			reverse_iterator rbegin() {
				return (this->end());
			}

			const_reverse_iterator rbegin() const {
				return (this->end());
			}

			reverse_iterator rend() {
				return (this->begin());
			};

			const_reverse_iterator rend() const {
				return (this->begin());
			}

			size_t size() const {
				return (this->siz);
			}

			size_t max_size() const {
				return (allocator.max_size());
			}
			
			void resize(size_t n, value_type val = value_type()) {
				if (n <= this->siz) {
					for (size_t j = n; j < this->siz; ++j) {
						allocator.destroy(&this->array[j]);
					}
					this->siz = n;
					return ;
				}
				size_t to_allocate;
				if (n > this->cap)
					to_allocate = n;
				else
					to_allocate = this->cap;
				value_type *new_arr = allocator.allocate(to_allocate);
				size_t i = 0;
				try {
					for (; i < n && i < this->siz; ++i) {
						allocator.construct(&new_arr[i], this->array[i]);
					}
					for (; i < n; ++i) {
						allocator.construct(&new_arr[i], val);
					}
				}
				catch (...) {
					for (size_t j = 0; j < i; ++j) {
						allocator.destroy(&new_arr[j]);
					}
					allocator.deallocate(new_arr, to_allocate);
					throw ;
				}
				for (i = 0; i < this->siz; ++i) {
					allocator.destroy(&this->array[i]);
				}
				allocator.deallocate(this->array, this->cap);
				this->cap = to_allocate;
				this->siz = n;
				this->array = new_arr;
				return ;
			}

			size_t capacity() const {
				return (this->cap);
			}

			bool empty() const {
				return (!this->siz);
			}

			void reserve(size_t n) {
				if (n > this->max_size())
					throw std::length_error("vector::reserve");
				if (n <= this->cap)
					return ;
				value_type *new_arr = allocator.allocate(n);
				size_t i = 0;
				try {
					for (; i < this->siz; ++i) {
						allocator.construct(&new_arr[i], this->array[i]);
					}
				}
				catch (...) {
					for (size_t j = 0; j < i; ++j) {
						allocator.destroy(&new_arr[j]);
					}
					allocator.deallocate(new_arr, n);
					throw ;
				}
				for (i = 0; i < this->siz; ++i) {
					allocator.destroy(&this->array[i]);
				}
				allocator.deallocate(this->array, this->cap);
				this->cap = n;
				this->array = new_arr;
			}

			reference operator[](size_t n) {
				return (this->array[n]);
			}

			const_reference operator[](size_t n) const {
				return (this->array[n]);
			}

			reference at(size_t n) {
				if (n >= this->siz) {
					std::string error("vector::_M_range_check: __n (which is ");
					std::ostringstream size;
					std::ostringstream num;
					num << n;
					error += num.str();
					error += ") >= this->size() (which is ";
					size << this->siz;
					error += size.str();
					error += ")";
					throw std::out_of_range(error);	
				}
				return (this->array[n]);
			}
			const_reference at(size_t n) const {
				if (n >= this->siz) {
					std::string error("vector::_M_range_check: __n (which is ");
					std::ostringstream size;
					std::ostringstream num;
					num << n;
					error += num.str();
					error += ") >= this->size() (which is ";
					size << this->siz;
					error += size.str();
					error += ")";
					throw std::out_of_range(error);
				}
				return (this->array[n]);
			}

			reference front() {
				return (this->array[0]);
			}

			const_reference front() const {
				return (this->array[0]);
			}

			reference back() {
				return (this->array[this->siz - 1]);
			}

			const_reference back() const {
				return (this->array[this->siz - 1]);
			}

			template <typename InputIterator>
			void assign(InputIterator first, InputIterator last, \
				typename enable_if<!is_integral<InputIterator>::value, void**>::type = NULL) {
					try {
						vector<T, Alloc> v(first, last);
						v.reserve(this->cap);
						this->swap(v);
					}
					catch (...) {
						throw ;
					}
					return ;
			}

			void assign(size_t n, const value_type & val) {
				try {
					vector<T, Alloc> v(n, val);
					v.reserve(this->cap);
					this->swap(v);
				}
				catch (...) {
					throw ;
				}
				return ;
			}

			void push_back(const value_type &val) {
				if (this->siz + 1 > this->cap) {
					try {
						if (this->cap)
							this->reserve(this->cap * 2);
						else
							this->reserve(1);
					}
					catch (...) {
						throw ;
					}
				}
				try {
					allocator.construct(&this->array[this->siz], val);
				}
				catch (...) {
					throw ;
				}
				this->siz++;
				return ;
			}

			void pop_back() {
				this->allocator.destroy(&this->array[this->siz - 1]);
				this->siz--;
				return ;
			}

			template <typename InputIterator>
			iterator insert(InputIterator pos, const T &val) {
				if (pos == this->end()) {
					try {
						this->push_back(val);
					} catch (...) {
						throw ;
					}
					return (this->end() - 1);
				}
				vector<T, Alloc> tmp;
				try {
					tmp.assign(this->begin(), pos);
				} catch (...) {
					throw ;
				}
				size_t i = pos - this->begin();
				if (this->cap < this->siz + 1) {
					try {
						tmp.reserve(this->cap * 2);
					} catch (...) {
						throw ;
					}
				}
				else
					tmp.reserve(this->cap);
				try {
					tmp.push_back(val);
					for (; pos != this->end(); ++pos) {
						tmp.push_back(*pos);
					}
				} catch (...) {
					throw ;
				}
				this->swap(tmp);
				return (iterator(this->allocator.address(this->array[i])));
			}

			template <typename InputIterator>
			void insert(InputIterator pos, size_t n, const T &val) {
				if (pos == this->end() && (this->siz + n) <= this->cap) {
					try {
						for (size_t j = 0; j < n; ++j) {
							this->push_back(val);
						}
					} catch (...) {
						throw ;
					}
					return ;
				}
				vector<T, Alloc> tmp;
				try {
					tmp.assign(this->begin(), pos);
				} catch (...) {
					throw ;
				}
				if (this->cap < this->siz + n) {
					try {
						tmp.reserve(this->cap * 2);
						while (tmp.cap < (this->siz + n)) {
							tmp.reserve(tmp.cap * 2);
						}
					} catch (...) {
						throw ;
					}
				}
				else
					tmp.reserve(this->cap);
				try {
					for (size_t j = 0; j < n; ++j) {
						tmp.push_back(val);
					}
					for (; pos != this->end(); ++pos) {
						tmp.push_back(*pos);
					}
				} catch (...) {
					throw ;
				}
				this->swap(tmp);
				return ;
			}

			template <typename InputIterator>
			void insert(iterator pos, InputIterator first, InputIterator last, \
				typename enable_if<!is_integral<InputIterator>::value, void**>::type = NULL) {
					if (pos == this->end() && (this->siz + (last - first)) <= this->cap) {
						try {
							for (; first != last; ++first) {
								this->push_back(*first);
							}
						} catch (...) {
							throw ;
						}
						return ;
					}
					vector<T, Alloc> tmp;
					try {
						tmp.assign(this->begin(), pos);
					} catch (...) {
						throw ;
					}
					if (this->cap < (this->siz + (last - first))) {
						try {
							tmp.reserve(this->cap * 2);
							while (tmp.cap < (this->siz + (last - first))) {
								tmp.reserve(tmp.cap * 2);
							}
						} catch (...) {
							throw ;
						}
					}
					else
						tmp.reserve(this->cap);
					try {
						for (; first != last; ++first) {
							tmp.push_back(*first);
						}
						for (; pos != this->end(); ++pos) {
							tmp.push_back(*pos);
						}
					} catch (...) {
						throw ;
					}
					this->swap(tmp);
					return ;
				}
			
			template <typename InputIterator>
			iterator erase(InputIterator pos) {
				if (pos == this->end() - 1) {
					this->pop_back();
					return (this->end());
				}
				vector<T, Alloc> tmp(this->begin(), pos);
				try {
					tmp.reserve(this->cap);
				}
				catch (...) {
					throw ;
				}
				size_t i = pos++ - this->begin();
				try {
					for (; pos != this->end(); ++pos) {
						tmp.push_back(*pos);
					}
				}
				catch (...) {
					throw ;
				}
				this->swap(tmp);
				return (iterator(this->allocator.address(this->array[i])));
			}

			template <typename InputIterator>
			iterator erase(InputIterator first, InputIterator last) {
				if (last == this->end()) {
					for (size_t i = last - first; i; --i) {
						this->pop_back();
					}
					return (this->end());
				}
				vector<T, Alloc> tmp(this->begin(), first);
				try {
					tmp.reserve(this->cap);
				}
				catch (...) {
					throw ;
				}
				size_t i = first - this->begin();
				try {
					for (; last != this->end(); ++last) {
						tmp.push_back(*last);
					}
				}
				catch (...) {
					throw ;
				}
				this->swap(tmp);
				return (iterator(this->allocator.address(this->array[i])));
			}

			void swap(vector &to_swap) {
				if (this->allocator == to_swap.allocator) {
					value_type *store = this->array;
					this->array = to_swap.array;
					to_swap.array = store;
					size_t stor = this->siz;
					this->siz = to_swap.siz;
					to_swap.siz = stor;
					stor = this->cap;
					this->cap = to_swap.cap;
					to_swap.cap = stor;
					return ;
				}
				vector<T, Alloc> tmp = *this;
				*this = to_swap;
				to_swap = tmp;
			}

			void clear() {
				for (size_t i = 0; i < this->siz; ++i) {
					allocator.destroy(&this->array[i]);
				}
				this->siz = 0;
				return ;
			}

			Alloc get_allocator() const {
				return (this->allocator);
			}
	};

	template <typename T, typename Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
		x.swap(y);
		return ;
	}

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (!(lhs == rhs));
	}
	
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (!(lhs < rhs));
	}
}

#endif