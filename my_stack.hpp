#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include "my_vector.hpp"

namespace ft {

	template <typename T, typename Container = vector<T> >
	class stack {

		protected:
			Container c;
		
		public:
			typedef typename Container::value_type	value_type;
			typedef Container						container_type;
			typedef	size_t							size_type;

			stack(const Container& ctnr = Container()) : c(ctnr) {}

			~stack() {}

			bool empty() const {
				return c.empty();
			}

			size_t size() const {
				return c.size();
			}

			value_type &top() {
				return c.back();
			}

			const value_type &top() const {
				return c.back();
			}

			void push(const value_type &val) {
				c.push_back(val);
				return ;
			}

			void pop() {
				c.pop_back();
				return ;
			}

			template <typename T1, typename container>
			friend bool operator==(const stack<T1, container> &left, const stack<T1, container> &right);
			template <typename T1, typename container>
			friend bool operator<(const stack<T1, container> &left, const stack<T1, container> &right);
	};

	template <typename T, typename Container>
	bool operator==(const stack<T, Container> &left, const stack<T, Container> &right) {
		return (left.c == right.c);
	}

	template <typename T, typename Container>
	bool operator!=(const stack<T, Container> &left, const stack<T, Container> &right) {
		return (!(left == right));
	}

	template <typename T, typename Container>
	bool operator<(const stack<T, Container> &left, const stack<T, Container> &right) {
		return (left.c < right.c);
	}

	template <typename T, typename Container>
	bool operator>(const stack<T, Container> &left, const stack<T, Container> &right) {
		return (!(left < right) && !(left == right));
	}

	template <typename T, typename Container>
	bool operator<=(const stack<T, Container> &left, const stack<T, Container> &right) {
		return (!(left > right));
	}

	template <typename T, typename Container>
	bool operator>=(const stack<T, Container> &left, const stack<T, Container> &right) {
		return (!(left < right));
	}
}

#endif
