#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator.hpp"

namespace _ft {

	template <typename node, typename Value_type, typename allocator_type, bool is_const = false>
	class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, \
		typename allocator_type::template rebind<node>::other::pointer, typename allocator_type::difference_type, \
		typename allocator_type::template rebind<Value_type>::other::pointer, \
		typename allocator_type::template rebind<Value_type>::other::reference> {

		private:
			typedef typename allocator_type::template rebind<node>::other::pointer		Nodeptr;
			typedef typename allocator_type::template rebind<Nodeptr>::other::reference	Nodepref;

			Nodeptr	ptr;

			static Nodeptr Max(Nodeptr P) {
				while (1) {
					Nodeptr tmp = (Nodepref)P->right;
					if (tmp->is_null)
						break ;
					P = tmp;
				}
				return (P);
			}

			static Nodeptr Min(Nodeptr P) {
				while (1) {
					Nodeptr tmp = (Nodepref)P->left;
					if (tmp->is_null)
						break ;
					P = tmp;
				}
				return (P);	
			}

			void Dec() {
				Nodeptr tmp = (Nodepref)this->ptr->left;
				if (this->ptr->is_null)
					this->ptr = (Nodepref)this->ptr->right;
				else if (!tmp->is_null) //если есть левое поддерево
					this->ptr = Max(tmp); //перейди на максимальное значение в этом поддереве
				else {
					Nodeptr P;
					while (1) {
						P = (Nodepref)this->ptr->parent; //если правого поддерева нет, то иди вверх по дереву до 
						Nodeptr L = (Nodepref)P->left; //родителя, имеющего левого потомка, который не является корнем 
						if (!P->is_null && (this->ptr == L)) //родительского левого поддерева; если в процессе поиска 
							this->ptr = P; //достигнут begin, то оставайся на нем
						else
							break ;
					}
					this->ptr = P;					
				}
				return ;
			}

			void Inc() {
				Nodeptr tmp = (Nodepref)this->ptr->right;
				if (this->ptr->is_null) //итератор указывает на end
					return ;
				else if (!tmp->is_null) //если есть правое поддерево
					this->ptr = Min(tmp); //перейди на минимальное значение в этом поддереве
				else {
					Nodeptr P;
					while (1) {
						P = (Nodepref)this->ptr->parent; //если правого поддерева нет, то иди вверх по дереву до 
						Nodeptr R = (Nodepref)P->right; //родителя, имеющего правого потомка, который не является корнем 
						if (!P->is_null && (this->ptr == R)) //родительского правого поддерева; если в процессе поиска 
							this->ptr = P; //достигнут головной узел == достигнут end, то итератор указывал на 
						else //предпоследний (наибольший - крайний правый) элемент
							break ;
					}
					this->ptr = P;
				}
				return ;
			}

		public:
			typedef typename allocator_type::difference_type									difference_type;
			typedef ft::bidirectional_iterator_tag												iterator_category;
			typedef Nodeptr																		value_type;
			typedef typename ft::conditional<is_const, \
				typename allocator_type::template rebind<Value_type>::other::const_pointer, \
				typename allocator_type::template rebind<Value_type>::other::pointer>::type		pointer;
			typedef typename ft::conditional<is_const, \
				typename allocator_type::template rebind<Value_type>::other::const_reference, \
				typename allocator_type::template rebind<Value_type>::other::reference>::type	reference;

			bidirectional_iterator() : ptr(0) {}

			bidirectional_iterator(Nodeptr P) : ptr(P) {}

			bidirectional_iterator(const bidirectional_iterator &to_copy) {
				this->ptr = to_copy.Mynode();
			}

			template <typename Node, typename ValueType, typename Allocator_type>
			bidirectional_iterator(bidirectional_iterator<Node, ValueType, Allocator_type, false> const &to_copy) {
				this->ptr = to_copy.Mynode();
			}

			reference operator*() const {
				return (this->ptr->Value);
			}
			
			pointer operator->() const {
				return (&**this);
			}

			bidirectional_iterator &operator++() {
				Inc();
				return (*this);
			}

			bidirectional_iterator operator++(int) {
				bidirectional_iterator tmp = *this;
				Inc();
				return (tmp);
			}

			bidirectional_iterator &operator--() {
				Dec();
				return (*this);
			}

			bidirectional_iterator operator--(int) {
				bidirectional_iterator tmp = *this;
				Dec();
				return (tmp);
			}

			Nodeptr Mynode() const {
				return (this->ptr);
			}
			
			~bidirectional_iterator() {}

	};

	template <typename node, typename Value_type, typename allocator_type, bool is_const>
	bool operator==(const bidirectional_iterator<node, Value_type, allocator_type, is_const> &left, \
		const bidirectional_iterator<node, Value_type, allocator_type, is_const> &right) {
			return (left.Mynode() == right.Mynode());
	}

	template <typename node, typename Value_type, typename allocator_type>
	bool operator==(const bidirectional_iterator<node, Value_type, allocator_type, true> &left, \
		const bidirectional_iterator<node, Value_type, allocator_type, false> &right) {
			return (left.Mynode() == right.Mynode());
	}

	template <typename node, typename Value_type, typename allocator_type>
	bool operator==(const bidirectional_iterator<node, Value_type, allocator_type, false> &left, \
		const bidirectional_iterator<node, Value_type, allocator_type, true> &right) {
			return (left.Mynode() == right.Mynode());
	}

	template <typename node, typename Value_type, typename allocator_type, bool is_const>
	bool operator!=(const bidirectional_iterator<node, Value_type, allocator_type, is_const> &left, \
		const bidirectional_iterator<node, Value_type, allocator_type, is_const> &right) {
			return !(left == right);
	}

	template <typename node, typename Value_type, typename allocator_type>
	bool operator!=(const bidirectional_iterator<node, Value_type, allocator_type, false> &left, \
		const bidirectional_iterator<node, Value_type, allocator_type, true> &right) {
			return !(left == right);
	}

	template <typename node, typename Value_type, typename allocator_type>
	bool operator!=(const bidirectional_iterator<node, Value_type, allocator_type, true> &left, \
		const bidirectional_iterator<node, Value_type, allocator_type, false> &right) {
			return !(left == right);
	}

}

#endif