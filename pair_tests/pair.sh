#!/bin/bash

# c++ -Wall -Wextra -Werror -std=c++98 std_pair.cpp && \
# ./a.out > 1 && \
# c++ -Wall -Wextra -Werror -std=c++98 -g ft_pair.cpp  && \
# ./a.out > 2 && \
# diff 1 2
c++ -Wall -Wextra -Werror -std=c++98 std_pair_my_tests.cpp && \
./a.out > 1 && \
c++ -Wall -Wextra -Werror -std=c++98 -g ft_pair_my_tests.cpp  && \
./a.out > 2 && \
diff 1 2