#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{

	template <typename T1, typename T2, bool is_map = false>
	class pair {
		public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type	first;
			second_type	second;

			pair() : first(T1()), second(T2()) {}

			template<class U, class V>
			pair (const pair<U, V>& to_copy) : first(to_copy.first), second(to_copy.second) {}

			pair (const first_type& a, const second_type& b) : first(a), second(b) {}

			~pair() {}

			pair<T1, T2, false>& operator=(const pair<T1, T2, false>& to_assignation) {
				if (this == &to_assignation)
					return (*this);
				this->first = to_assignation.first;
				this->second = to_assignation.second;
				return (*this);
			}
	};

	template <class T1, class T2>
  	pair<T1, T2> make_pair (T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	}

	template <class T1, class T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return ((lhs.first < rhs.first) || (!(rhs.first < lhs.first) && (lhs.second < rhs.second)));
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) { 
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs < rhs);
	}

}

#endif
