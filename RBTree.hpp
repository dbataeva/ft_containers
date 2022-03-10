#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "iterators/bidirectional_iterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include "relational_operators.hpp"
#include "my_pair.hpp"
#include <iostream>

namespace ft {

	template <typename K, typename Pr, typename Ax>
	struct tree_traits {
		typedef K												key_type;
		typedef K												value_type;
		typedef Pr												key_compare;
		typedef typename Ax::template rebind<key_type>::other	allocator_type;

		typedef key_compare										value_compare;

		tree_traits() : comp() {}
		tree_traits(Pr Parg) : comp(Parg) {}

		Pr comp;	 
	};

	template <typename Tr>
	class Tree_node : public Tr {
		protected:
			typedef typename Tr::allocator_type											allocator_type;
			typedef typename Tr::key_compare											key_compare;
			typedef typename Tr::value_type												value_type;
			typedef typename Tr::allocator_type::template rebind<void>::other::pointer	Genptr;

			struct Node {
				value_type	Value;
				Genptr		*left;
				Genptr		*right;
				Genptr		*parent;
				bool		is_red;
				bool		is_null;
			};

			typename allocator_type::template rebind<Node>::other	Alnode;

			Tree_node(const key_compare &Parg, allocator_type Al) : Tr(Parg), Alnode(Al) {}
	};
	
	template <typename Tr>
	class Tree_ptr : public Tree_node<Tr> {
		protected:
			typedef typename Tree_node<Tr>::Node									Node;
			typedef typename Tr::allocator_type										allocator_type;
			typedef typename Tr::key_compare										key_compare;
			typedef typename allocator_type::template rebind<Node>::other::pointer	Nodeptr;

			typename allocator_type::template rebind<Nodeptr>::other				Alptr;

			Tree_ptr(const key_compare &Parg, allocator_type Al) : Tree_node<Tr>(Parg, Al), Alptr(Al) {}

	};

	template <typename Tr>
	class Tree_val : public Tree_ptr<Tr> {
		protected:
			typedef typename Tr::allocator_type	allocator_type;
			typedef typename Tr::key_compare	key_compare;

			allocator_type						Alval;
			
			Tree_val(const key_compare &Parg, allocator_type Al) : Tree_ptr<Tr>(Parg, Al), Alval(Al) {}
	};
	
	template <typename Tr>
	class Tree : public Tree_val<Tr> {
		public:
			typedef Tree<Tr>					Myt;
			typedef Tree_val<Tr>				Mybase;
			typedef typename Tr::key_type		key_type;
			typedef typename Tr::key_compare	key_compare;
			typedef typename Tr::value_compare	value_comp;
			typedef typename Tr::value_type		value_type;
			typedef typename Tr::allocator_type	allocator_type;

		protected:
			typedef typename Tree_node<Tr>::Genptr												Genptr;
			typedef typename Tree_node<Tr>::Node												node;
			typedef typename allocator_type::template rebind<node>::other::pointer				Nodeptr;
			typedef typename allocator_type::template rebind<Nodeptr>::other::reference			Nodepref;
			typedef typename allocator_type::template rebind<key_type>::other::const_reference	Keyref;
			typedef typename allocator_type::template rebind<bool>::other::reference			boolref;
			typedef typename allocator_type::template rebind<value_type>::other::reference		Vref;

			static boolref Color(Nodeptr p) {
				return (p->is_red);
			}

			static boolref isNull(Nodeptr p) {
				return (p->is_null);
			}

			static Nodepref Left(Nodeptr p) {
				return ((Nodepref)p->left);
			}

			static Nodepref Right(Nodeptr p) {
				return ((Nodepref)p->right);
			}

			static Nodepref Parent(Nodeptr p) {
				return ((Nodepref)p->parent);
			}

			static Vref Value(Nodeptr p) {
				return (p->Value);
			}

			static Keyref Key(Nodeptr p) {
				return (Value(p));
			}

		public:
			typedef typename allocator_type::size_type												size_type;
			typedef typename allocator_type::template rebind<value_type>::other::pointer			Tptr;
			typedef typename _ft::bidirectional_iterator<node, value_type, allocator_type>			iterator;
			typedef typename _ft::bidirectional_iterator<node, value_type, allocator_type, true>	const_iterator;
			typedef ft::reverse_iterator<iterator>													reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;
			typedef ft::pair<iterator, bool>													Pairib;
			typedef ft::pair<iterator, iterator>												Pairii;
			typedef ft::pair<const_iterator, const_iterator>									Paircc;

			Tree(const key_compare &Parg, const allocator_type &Al) : Mybase(Parg, Al) {
				Init();
				return ;
			}

			Tree(const value_type *F, const value_type *L, const key_compare &Parg, const allocator_type &Al) \
				: Mybase(Parg, Al) {
					Init();
					insert(F, L);
					return ;
				}

			Tree(const Myt &X) : Mybase(X.key_comp(), X.get_allocator()) {
					Init();
					Copy(X);
					return ;
			}

			~Tree() {
				erase(begin(), end());
				Freenode(this->Head);
				this->Head = 0;
				this->Size = 0;
				return ;
			}

			Myt &operator=(const Myt &X) {
				if (this == &X)
					return (*this);
				this->erase(begin(), end());
				this->comp = X.comp;
				Copy(X);
				return (*this);
			}

			iterator begin() {
				return (Lmost());
			}

			const_iterator begin() const {
				return (Lmost());
			}

			iterator end() {
				return (this->Head);
			}

			const_iterator end() const {
				return (this->Head);
			}

			reverse_iterator rbegin() {
				return (this->end());
			}

			const_reverse_iterator rbegin() const {
				return (this->end());
			}

			reverse_iterator rend() {
				return (this->begin());
			}

			const reverse_iterator rend() const {
				return (this->begin());
			}

			size_type size() const {
				return (this->Size);
			}

			size_type max_size() const {
				return (this->Alnode.max_size());
			}

			bool empty() const {
				return (this->Size == 0);
			}

			allocator_type get_allocator() const {
				return (this->Alval);
			}

			key_compare key_comp() const {
				return (this->comp);
			}

			value_comp value_compare() const {
				return (this->comp);
			}

			Pairib insert(const value_type &V) {
				Nodeptr X = Root();
				Nodeptr Y = this->Head;
				bool Addleft = true;
				while (!this->isNull(X)) { //спускается вниз по дереву, пока не будет обнаружен подходящий узел У для
					Y = X; //присоединения нового узла в качестве листа дерева
					Addleft = this->comp(V, Key(X)); //если Addleft == true, лист будет добавлен в качестве левого  
					X = Addleft ? Left(X) : Right(X); //потомка, если нет - в качестве правого
				}
				iterator P = iterator(Y); 
				if (!Addleft) 
					;
				else if (P == begin()) 
					return (Pairib(Insert(true, Y, V), true));
				else 
					--P;
				if (this->comp(Key(P.Mynode()), V))
					return (Pairib(Insert(Addleft, Y, V), true));
				else if (this->comp(V, Key(P.Mynode())))
					return (Pairib(Insert(false, Y, V), true)); 
				return (Pairib(P, false));
			}

			iterator insert(iterator P, const value_type &V) {
				if (this->Size == 0)
					return (Insert(true, Head, V));
				else if (P == begin()) {
					if (this->comp(V, Value(P.Mynode())))
						return (Insert(true, P.Mynode(), V)); //вставка в качестве левого потомка
				}
				else if (P == end()) {
					if (this->comp(Value(Rmost()), V))
						return (Insert(false, Rmost(), V)); //вставка в качестве правого потомка
				}
				iterator Pb = P;
				if (this->comp(Value((--Pb).Mynode()), V) && this->comp(V, Value(P.Mynode()))) {
					if (this->isNull(Right(Pb.Mynode())))
						return (Insert(false, Pb.Mynode(), V)); //вставка в качестве правого потомка
					return (Insert(true, P.Mynode(), V)); //вставка в качестве левого потомка
				}
				return (insert(V).first); 
			}

			template <typename It>
			void insert(It F, It L) {
				for (; F != L; ++F) {
					Pairib p = insert(*F);
				}
				return ;
			}

			iterator erase(iterator P) {
				if (this->isNull(P.Mynode()))
					throw std::out_of_range("iterator");
				Nodeptr X;
				Nodeptr Xpar;
				Nodeptr Y = P.Mynode();
				++P;
				Nodeptr Z = Y;
				if (this->isNull(Left(Y)))
					X = Right(Y);
				else if (isNull(Right(Y)))
					X = Left(Y);
				else {
					Y = Min(Right(Y));
					X = Right(Y);
				}
				if (Y == Z) {
					Xpar = Parent(Z);
					if (!this->isNull(X))
						Parent(X) = Xpar;
					if (Root() == Z)
						Root() = X;
					else if (Left(Xpar) == Z)
						Left(Xpar) = X;
					else
						Right(Xpar) = X;
					if (Lmost() != Z)
						; 
					else if (this->isNull(Right(Z)))
						Lmost() = Xpar;
					else
						Lmost() = Min(X);
					if (Rmost() != Z)
						; 
					else if (this->isNull(Left(Z)))
						Rmost() = Xpar;
					else
						Rmost() = Max(X);
				}
				else {
					Parent(Left(Z)) = Y;
					Left(Y) = Left(Z);
					if (Y == Right(Z))
						Xpar = Y;
					else {
						Xpar = Parent (Y);
						if (!isNull(X))
							Parent(X) = Xpar;
						Left(Xpar) = X;
						Right(Y) = Right(Z);
						Parent(Right(Z)) = Y;
					}
					if (Root() == Z)
						Root() = Y;
					else if (Left(Parent(Z)) == Z)
						Left(Parent(Z)) = Y;
					else
						Right(Parent(Z)) = Y;
					Parent(Y) = Parent(Z);
					std::swap(Color(Y), Color(Z));
				}
				if (Color(Z) == 0) {//black 
					for (; X != Root() && (Color(X) == 0); Xpar = Parent(X)) {
						if (X == Left(Xpar)) {
							Nodeptr W = Right(Xpar);
							if (Color(W) == 1) {//red
								Color(W) = 0;
								Color(Xpar) = 1;
								Lrotate(Xpar);
								W = Right(Xpar);
							}
							if (this->isNull(W))
								X = Xpar; // shouldn't happen
							else if ((Color(Left(W)) == 0) && (Color(Right(W)) == 0)) {//black
								Color(W) = 1; //red
								X = Xpar;
							}
							else {
								if (Color(Right(W)) == 0) { //black
									Color(Left(W)) = 0; //black
									Color(W) = 1; //red
									Rrotate(W);
									W = Right(Xpar);
								}
								Color(W) = Color(Xpar);
								Color(Xpar) = 0; //black
								Color(Right(W)) = 0; //black
								Lrotate(Xpar);
								break ;
							}
						}
						else {
							Nodeptr W = Left(Xpar);
							if (Color(W) == 1) {// red
								Color(W) = 0; //black
								Color(Xpar) = 1; //red
								Rrotate(Xpar);
								W = Left(Xpar);
							}
							if (isNull(W))
								X = Xpar; // shouldn't happen
							else if ((Color(Right(W)) == 0) && (Color(Left(W)) == 0)) { //black
								Color(W) = 1; //red
								X = Xpar;
							}
							else {
								if (Color(Left(W)) == 0) {// black
									Color(Right(W)) = 0; //black
									Color(W) = 1; //red
									Lrotate(W);
									W = Left(Xpar);
								}
								Color(W) = Color(Xpar);
								Color(Xpar) = 0; //black
								Color(Left(W)) = 0; //black
								Rrotate(Xpar);
								break ;
							}
						}
					}
					Color(X) = 0; //black
				}
				Destval(&Value(Z));
				Freenode(Z);
				if (Size > 0)
					--Size;
				return (P);
			}

			iterator erase(iterator F, iterator L) {
				if ((Size == 0) || (F != begin()) || (L != end())) {
					while (F != L) {
						F = erase(F);
					}
					return (F);
				}
				Erase(Root());
				Root() = Head;
				Size = 0;
				Lmost() = Head;
				Rmost() = Head;
				return (begin());
			}

			size_type erase(const key_type &X) {
				iterator P = find(X);
				if (P == end())
					return (0);
				erase(P);
				return (1);
			}

			void erase(const key_type *F, const key_type *L) {
				while (F != L)
					erase(F++);
				return ;
			}

			void clear() {
				erase(begin(), end());
			}

			iterator find(const key_type &Kv) {
				iterator P = lower_bound(Kv);
				return (this->comp(Kv, Value(P.Mynode())) ? end() : P);
			}

			const_iterator find(const key_type &Kv) const {
				const_iterator P = lower_bound(Kv);
				return (this->comp(Kv, Value(P.Mynode())) ? end() : P);
			}

			size_type count(const key_type &Kv) const {
				Paircc Ans = equal_range(Kv);
				size_type N = 0;
				Distance(Ans.first, Ans.second, N);
				return (N);
			}

			iterator lower_bound(const key_type &Kv) {
				return (Lbound(Kv));
			}

			const_iterator lower_bound(const key_type &Kv) const {
				return (Lbound(Kv));
			}

			iterator upper_bound(const key_type &Kv) {
				return (Ubound(Kv));
			}

			const_iterator upper_bound(const key_type &Kv) const {
				return (Ubound(Kv));
			}

			Pairii equal_range(const key_type &Kv) {
				return (Pairii(lower_bound(Kv), upper_bound(Kv)));
			}

			Paircc equal_range(const key_type &Kv) const {
				return (Paircc(lower_bound(Kv), upper_bound(Kv)));
			}

			void swap(Myt &X) {
				if (get_allocator() == X.get_allocator()) {
					std::swap(this->comp, X.comp);
					std::swap(Head, X.Head);
					std::swap(Size, X.Size);
					return ;
				}
				Myt Ts = *this;
				*this = X;
				X = Ts;
				return ;
			}

			protected:
				void Copy(const Myt &X) {
					Root() = Copy(X.Root(), Head);
					Size = X.Size;
					if (!this->isNull(Root())) {
						Lmost() = Min(Root());
						Rmost() = Max(Root());
						return ;
					}
					Lmost() = Head;
					Rmost() = Head;
					return ;
				}

				Nodeptr Copy(Nodeptr X, Nodeptr P) {
					Nodeptr R = Head;
					if (!this->isNull(X)) {
						Nodeptr Y = Buynode(P, Color(X));
						try {
							Consval(&Value(Y), Value(X));
						}
						catch (...) {
							Freenode(Y);
							Freenode(R);
							throw ;
						}
						Left(Y) = Head;
						Right(Y) = Head;
						if (isNull(R))
							R = Y;
						try {
							Left(Y) = Copy(Left(X), Y);
							Right(Y) = Copy(Right(X), Y);
						}
						catch (...) {
							Erase(R);
							throw ;
						}
					}
					return (R);
				}

				void Erase(Nodeptr &X) {
					for (Nodeptr Y = X; !this->isNull(Y); X = Y) {
						Erase(Right(Y));
						Y = Left(Y);
						Destval(&Value(X));
						Freenode(X);
					}
					return ;
				}

				void Init() {
					Head = Buynode(0, false); // black
					this->isNull(Head) = true;
					Root() = Head;
					Lmost() = Head;
					Rmost() = Head;
					Size = 0;
					return ;
				}

				iterator Insert(bool Addleft, Nodeptr Y, const value_type &V) {
					if (Size >= max_size())
						throw std::length_error("tpp long");
					Nodeptr Z = Buynode(Y, true); // новый узел - red, является потомком У
					Left(Z) = Head; //его правый и левый указатели - пустые
					Right(Z) = Head;
					try {
						Consval(&Value(Z), V); //пробуем в этом узле consturct для хранимого значения
					}
					catch (...) {
						Freenode(Z); //если construct не удался с этим значением, то осовбождаем память и кидаем
						throw ; //исключение дальше
					}
					++Size; //если construct удался, увеличиваем размер дерева
					if (Y == Head) { //если до этого в дерево было пустое, то теперь корень дерева - только что
						Root() = Z; //добавленный узел
						Lmost() = Z;
						Rmost() = Z;
					}
					else if (Addleft) { //если узел надо добавить в качестве левого потомка, то соответствующим образом
						Left(Y) = Z; //устанавливаем левый указатель У на новый узел
						if (Y == Lmost())
							Lmost() = Z;
					}
					else { //иначе добавляем узел в качестве правого потомка, соответствующим образом устанавливаем
						Right(Y) = Z; //правый указатель У на новый узел
						if (Y == Rmost())
							Rmost() = Z;
					}
					for (Nodeptr X = Z; Color(Parent(X)) == true;) {//если у нового красного узла красный родитель, то
						if (Parent(X) == Left(Parent(Parent(X)))) { //необходимо подняться вверх по дереву, пока не 
							Y = Right(Parent(Parent(X))); //будет найдено место, где можно корректно вставить 
							if (Color(Y) == true) {//дополнительную черную связь
								Color(Parent(X)) = false; //black
								Color(Y) = false; //black
								Color(Parent(Parent(X))) = true; //red
								X = Parent(Parent(X));
							}
							else {
								if (X == Right(Parent(X))) {
									X = Parent(X);
									Lrotate(X);
								}
								Color(Parent(X)) = false; //black
								Color(Parent(Parent(X))) = true; //red
								Rrotate(Parent(Parent(X)));
							}
						}
						else {
							Y = Left(Parent(Parent(X)));
							if (Color(Y) == true) { // red
								Color(Parent(X)) = false; //black
								Color(Y) = false; //black
								Color(Parent(Parent(X))) = true; //red
								X = Parent(Parent(X));
							}
							else {
								if (X == Left(Parent(X))) {
									X = Parent(X);
									Rrotate(X);
								}
								Color(Parent(X)) = false; //black
								Color(Parent(Parent(X))) = true; //red
								Lrotate(Parent(Parent(X)));
							}
						}
					}
					Color(Root()) = false; //black
					return (Z);
				}

				Nodeptr Lbound(const key_type &Kv) const {
					Nodeptr X = Root();
					Nodeptr Y = Head;
					while (!isNull(X)) {
						if (this->comp(Value(X), Kv))
							X = Right(X);
						else {
							Y = X;
							X = Left(X);
						}
					}
					return (Y);
				}

				Nodeptr &Lmost() {
					return (Left(Head));
				}
				
				Nodeptr &Lmost() const {
					return (Left(Head));
				}

				void Lrotate(Nodeptr X) { //метод берет правое поддерево Х и подставляет его вместо Х, а Х становится
					Nodeptr Y = Right(X); //левым поддеревом
					Right(X) = Left(Y);
					if (!this->isNull(Left(Y)))
						Parent(Left(Y)) = X;
					Parent(Y) = Parent(X);
					if (X == Root())
						Root() = Y;
					else if (X == Left(Parent(X)))
						Left(Parent(X)) = Y;
					else
						Right(Parent(X)) = Y;
					Left(Y) = X;
					Parent(X) = Y;
					return ;
				}

				static Nodeptr Max(Nodeptr P) {
					while (!isNull(Right(P)))
						P = Right(P);
					return (P);
				}

				static Nodeptr Min(Nodeptr P) {
					while (!isNull(Left(P)))
						P = Left(P);
					return (P);	
				}

				Nodeptr &Rmost() {
					return (Right(Head));
				}

				Nodeptr &Rmost() const {
					return (Right(Head));
				}

				Nodeptr &Root() {
					return (Parent(Head));
				}

				Nodeptr &Root() const {
					return (Parent(Head));
				}

				void Rrotate(Nodeptr X) { //метод берет левое поддерево Х и подставляет его вместо Х, а Х становится
					Nodeptr Y = Left(X); //правым поддеревом
					Left(X) = Right(Y);
					if (!isNull(Right(Y)))
						Parent(Right(Y)) = X;
					Parent(Y) = Parent(X);
					if (X == Root())
						Root() = Y;
					else if (X == Right(Parent(X)))
						Right(Parent(X)) = Y;
					else
						Left(Parent(X)) = Y;
					Right(Y) = X;
					Parent(X) = Y;
					return ;
				}

				Nodeptr Ubound(const key_type &Kv) const {
					Nodeptr X = Root();
					Nodeptr Y = Head;
					while (!isNull(X)) {
						if (this->comp(Kv, Value(X))) {
							Y = X;
							X = Left(X);
						}
						else
							X = Right(X);
					}
					return (Y);
				}

				Nodeptr Buynode(Nodeptr Parg, bool Carg) { //выделяет память под узел
					Nodeptr S = this->Alnode.allocate(1, (void*)0);
					this->Alptr.construct(&Left(S), 0); //инициализирует указатель на родителский элемент и цвет узла 
					this->Alptr.construct(&Right(S), 0); //в соответствии с пришедшими параметрами, а конструирование 
					this->Alptr.construct(&Parent(S), Parg); //хранимого значения и установка правого и левого 
					Color(S) = Carg; //указателей при необходимости выполняется в других методах
					this->isNull(S) = false; 
					return (S);
				}

				void Consval(Tptr P, const value_type &V) {
					this->Alval.construct(P, V);
					return ;
				}

				void Destval(Tptr P) {
					this->Alval.destroy(P);
					return ;
				}

				void Freenode(Nodeptr S) {
					this->Alptr.destroy(&Parent(S)); //уничтожение хранимого значения, сохранение правого и левого 
					this->Alptr.destroy(&Right(S)); //указателей при необходимости выполняется в других методах
					this->Alptr.destroy(&Left(S));
					this->Alnode.deallocate(S, 1);
					return ;
				}

				Nodeptr Head; //указатель на фиктивный гловной узел; Head->left - первый элемент; Head->right - последний элемент; Head->parent - корень дерева; если дерево пустое, все указатели указывают на Head
				size_type Size;
	};

	template <typename Tr>
	void swap(Tree<Tr> &X, Tree<Tr> &Y) {
		X.swap(Y);
		return ;
	}

	template <typename Tr>
	bool operator==(const Tree<Tr> &X, const Tree<Tr> &Y) {
		return ((X.size() == Y.size()) && ft::equal(X.begin(), X.end(), Y.begin()));
	}

	template <typename Tr>
	bool operator!=(const Tree<Tr> &X, const Tree<Tr> &Y) {
		return (!(X == Y));
	}

	template <typename Tr>
	bool operator<(const Tree<Tr> &X, const Tree<Tr> &Y) {
		return (lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end(), X.value_compare()));
	}

	template <typename Tr>
	bool operator>(const Tree<Tr> &X, const Tree<Tr> &Y) {
		return (Y < X);
	}

	template <typename Tr>
	bool operator<=(const Tree<Tr> &X, const Tree<Tr> &Y) {
		return (!(Y < X));
	}

	template <typename Tr>
	bool operator>=(const Tree<Tr> &X, const Tree<Tr> &Y) {
		return (!(X < Y));
	}	

}

#endif
