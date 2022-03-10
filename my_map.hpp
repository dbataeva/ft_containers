#ifndef MY_MAP_HPP
#define MY_MAP_HPP

#include "RBTree.hpp"
#include "my_pair.hpp"

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T, true> > > 
	class map {

		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, T>					value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			class value_compare : public std::binary_function<value_type, value_type, bool> {
				friend class map;
				
				protected:
					key_compare comp;
					value_compare (key_compare c) : comp(c) {}  // constructed with map's comparison object
				
				public:
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};

			typedef typename Tree<tree_traits<ft::pair<const Key, T>, \
										value_compare, Alloc> >::iterator				iterator;
			typedef typename Tree<tree_traits<ft::pair<const Key, T>, \
										value_compare, Alloc> >::const_iterator			const_iterator;
			typedef typename Tree<tree_traits<ft::pair<const Key, T>, \
										value_compare, Alloc> >::reverse_iterator		reverse_iterator;
			typedef typename Tree<tree_traits<ft::pair<const Key, T>, \
										value_compare, Alloc> >::const_reverse_iterator	const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type					difference_type;
			typedef size_t																size_type;

		private:
			Tree<tree_traits<ft::pair<const Key, T>, value_compare, Alloc> > tree;

		public:
			map(const key_compare& c = key_compare(), const allocator_type& a = allocator_type()) : tree(c, a) {}

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), \
				const allocator_type& alloc = allocator_type()) : tree(comp, alloc) {
					try {
						this->tree.insert(first, last);
					}
					catch (...) {
						throw ;
					}
					return ;
				}

			map(const map& to_copy) : tree(to_copy.key_comp(), to_copy.get_allocator()) {
				try {
					this->tree = to_copy.tree;
				}
				catch (...) {
					throw ;
				}
				return ;
			}

			~map() {}

			map& operator=(const map& to_assignation) {
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
				if (this->tree.size() == 0)
					return (true);
				return (false);
			}

			size_type size() const {
				return (this->tree.size());
			}

			size_type max_size() const {
				return (this->tree.max_size());
			}

			mapped_type& operator[](const key_type& k) {
				ft::pair<iterator, bool> it;
				try {
					ft::pair<Key, T> p(k, T());
					it = this->tree.insert(p);
				}
				catch (...) {
					throw ;
				}
				return (it.first->second);
			}

			pair<iterator, bool> insert(const value_type& val) {
				ft::pair<iterator, bool> p;
				try {
					p = this->tree.insert(val);
				}
				catch (...) {
					throw ;
				}
				return (p);
			}

			iterator insert(iterator position, const value_type& val) {
				iterator it;
				try {
					it = this->tree.insert(position, val);
				}
				catch (...) {
					throw ;
				}
				return (it);
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				try {
					this->tree.insert(first, last);
				}
				catch (...) {
					throw ;
				}
				return ;
			}

			void erase(iterator position) {
				this->tree.erase(position);
				return ;
			}

			size_type erase(const key_type& k) {
				ft::pair<iterator, bool> it;
				try {
					ft::pair<Key, T> p(k, T());
					it = this->tree.insert(p);
				}
				catch (...) {
					throw ;
				}
				if (it.second) {
					this->erase(it.first);
					return (0);
				}
				this->erase(it.first);
				return (1);
			}

			void erase(iterator first, iterator last) {
				this->tree.erase(first, last);
				return ;
			}

			void swap(map& x) {
				this->tree.swap(x.tree);
			}

			void clear() {
				this->tree.clear();
				return ;
			}

			key_compare key_comp() const {
				key_compare k;
				return (k);
			}

			value_compare value_comp() const {
				value_compare v(this->key_comp());
				return (v);
			}

			iterator find(const key_type& k) {
				ft::pair<iterator, bool> it;
				try {
					ft::pair<Key, T> p(k, T());
					it = this->tree.insert(p);
				}
				catch (...) {
					throw ;
				}
				if (it.second) {
					this->erase(it.first);
					return (this->end());
				}
				return (it.first);
			}

			const_iterator find(const key_type& k) const {
				ft::pair<Key, T> p(k, T());
				const_iterator it = this->tree.find(p);
				return (it.Mynode());
			}

			size_type count(const key_type& k) const {
				if (this->find(k) == this->end())
					return (0);
				return (1);
			}

			iterator lower_bound(const key_type& k) {
				ft::pair<Key, T> p(k, T());
				const_iterator it = this->tree.lower_bound(p);
				return (it.Mynode());
			}

			const_iterator lower_bound(const key_type& k) const {
				ft::pair<Key, T> p(k, T());
				const_iterator it = this->tree.lower_bound(p);
				return (it.Mynode());
			}

			iterator upper_bound(const key_type& k) {
				ft::pair<Key, T> p(k, T());
				const_iterator it = this->tree.upper_bound(p);
				return (it.Mynode());
			}

			const_iterator upper_bound(const key_type& k) const {
				ft::pair<Key, T> p(k, T());
				const_iterator it = this->tree.upper_bound(p);
				return (it.Mynode());
			}

			pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
				return (ft::pair<iterator,iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

			pair<iterator,iterator> equal_range(const key_type& k) {
				return (ft::pair<iterator,iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

			allocator_type get_allocator() const {
				allocator_type a;
				return (a);
			}

	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) {
		return !(lhs > rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &lhs, map<Key, T, Compare, Alloc>  &rhs) {
		lhs.swap(rhs);
		return ;
	}
}

#endif
