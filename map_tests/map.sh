#!/bin/bash

c++ -Wall -Wextra -Werror -std=c++98 -g std_map.cpp && \
./a.out > 1 && \
c++ -Wall -Wextra -Werror -std=c++98 -g ft_map.cpp  && \
./a.out > 2 && \
diff 1 2
# c++ -Wall -Wextra -Werror -std=c++98 -g std_map_my_tests.cpp && \
# ./a.out > 1 && \
# c++ -Wall -Wextra -Werror -std=c++98 -g ft_map_my_tests.cpp  && \
# ./a.out > 2 && \
# diff 1 2