#!/bin/bash

# c++ -Wall -Wextra -Werror -std=c++98 -g std_set.cpp && \
# ./a.out > 1 && \
# c++ -Wall -Wextra -Werror -std=c++98 -g ft_set.cpp  && \
# ./a.out > 2 && \
# diff 1 2
c++ -Wall -Wextra -Werror -std=c++98 -g std_set_my_tests.cpp && \
./a.out > 1 && \
c++ -Wall -Wextra -Werror -std=c++98 -g ft_set_my_tests.cpp  && \
./a.out > 2 && \
diff 1 2