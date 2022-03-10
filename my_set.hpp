#ifndef MY_SET_HPP
#define MY_SET_HPP

#include "RBTree.hpp"

namespace ft {
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
		private:
			Tree<tree_traits<T, Compare, Alloc> > tree;			

		public:
			typedef T																		key_type;
			typedef typename Tree<tree_traits<T, Compare, Alloc> >::value_type				value_type;
			typedef Compare																	key_compare;
			typedef Compare																	value_compare;
			typedef Alloc																	allocator_type;
			typedef typename allocator_type::reference										reference;
			typedef typename allocator_type::const_reference								const_reference;
			typedef typename allocator_type::pointer										pointer;
			typedef typename allocator_type::const_pointer									const_pointer;

			typedef typename Tree<tree_traits<T, Compare, Alloc> >::const_iterator			iterator;
			typedef typename Tree<tree_traits<T, Compare, Alloc> >::const_iterator			const_iterator;
			typedef typename Tree<tree_traits<T, Compare, Alloc> >::const_reverse_iterator	reverse_iterator;
			typedef typename Tree<tree_traits<T, Compare, Alloc> >::const_reverse_iterator	const_reverse_iterator;

			typedef typename iterator_traits<iterator>::difference_type							difference_type;
			typedef size_t																		size_type;
			

			set(const Compare& C = Compare(), const Alloc& A = Alloc()) : tree(C, A) {}

			template <class InputIterator>
  			set(InputIterator first, InputIterator last, const Compare& C = Compare(), const Alloc& A = Alloc()) \
			  	: tree(C, A) {
					try {
						this->tree.insert(first, last);
					}
					catch (...) {
						throw ;
					}
					return ;
			  }

			set(const set& to_copy) : tree(to_copy.key_comp(), to_copy.get_allocator()) {
				try {
					this->tree = to_copy.tree;
				}
				catch (...) {
					throw ;
				}
				return ;
			}

			~set() {}

			set& operator=(const set& to_assignation) {
				this->tree = to_assignation.tree;
				return (*this);
			}

			iterator begin() { //min value
				return (this->tree.begin());
			}

			const_iterator begin() const {
				return (this->tree.begin());
			}

			iterator end() { //head
				return (this->tree.end());
			}
			
			const_iterator end() const {
				return (this->tree.end());
			}

			reverse_iterator rbegin() { //max value
				return (this->tree.rbegin());
			}
			
			const_reverse_iterator rbegin() const {
				return (this->tree.rbegin());
			}

			reverse_iterator rend() { //head
				return (this->tree.rend());
			}
	
			const_reverse_iterator rend() const {
				return (this->tree.rend());
			}

			bool empty() const {
				return (this->tree.empty());
			}

			size_type size() const {
				return (this->tree.size());
			}

			size_type max_size() const {
				return (this->tree.max_size());
			}

			ft::pair<iterator, bool> insert (const value_type& val) {
				ft::pair<iterator, bool> p;
				try {
					p = this->tree.insert(val);
				}
				catch (...) {
					throw ;
				}
				return (p);
			}

			iterator insert (iterator position, const value_type& val) {
				iterator it;
				try {
					it = this->tree.insert(position.Mynode(), val);
				}
				catch (...) {
					throw ;
				}
				return (it);
			}

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last) {
				try {
					for (; first != last; ++first) {
						this->insert(*first);
					}
				}
				catch (...) {
					throw ;
				}
				return ;
			}

			void erase (iterator position) {
				this->tree.erase(position.Mynode());
				return ;
			}

			size_type erase (const value_type& val) {
				return (this->tree.erase(val));
			}

			void erase (iterator first, iterator last) {
				this->tree.erase(first.Mynode(), last.Mynode());
				return ;
			}

			void swap (set& to_swap) {
				this->tree.swap(to_swap.tree);
				return ;
			}

			void clear() {
				this->tree.clear();
				return ;
			}

			Compare key_comp() const {
				key_compare c;
				return (c);
			}

			value_compare value_comp() const {
				value_compare v;
				return (v);
			}

			iterator find(const value_type& val) const {
				const_iterator it = this->tree.find(val);
				return (it.Mynode());
			}

			size_type count(const value_type& val) const {
				if (this->tree.find(val) != this->end())
					return (1);
				return (0);
			}

			iterator lower_bound(const value_type& val) const {
				const_iterator it = this->tree.lower_bound(val);
				return (it.Mynode());
			}

			iterator upper_bound(const value_type& val) const {
				const_iterator it = this->tree.upper_bound(val);
				return (it.Mynode());
			}

			ft::pair<iterator,iterator> equal_range(const value_type& val) const {
				return (ft::pair<iterator,iterator>(this->lower_bound(val), this->upper_bound(val)));
			}

			Alloc get_allocator() const {
				allocator_type a;
				return (a);
			}
	};

	template <class T, class Compare, class Alloc>
	bool operator==(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Compare, class Alloc>
	bool operator!=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Compare, class Alloc>
	bool operator<(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), Compare()));
	}

	template <class T, class Compare, class Alloc>
	bool operator>=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return !(lhs < rhs);
	}

	template <class T, class Compare, class Alloc>
	bool operator>(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return (rhs < lhs);
	}

	template <class T, class Compare, class Alloc>
	bool operator<=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return !(lhs > rhs);
	}

	template <class T, class Compare, class Alloc>
	void swap(set<T, Compare, Alloc> &lhs, set<T, Compare, Alloc> &rhs) {
		lhs.swap(rhs);
		return ;
	}
}

#endif