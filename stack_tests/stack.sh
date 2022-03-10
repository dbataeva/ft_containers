#!/bin/bash

c++ -Wall -Wextra -Werror -std=c++98 std_stack_my_example.cpp && \
./a.out > 1 && \
c++ -Wall -Wextra -Werror -std=c++98 ft_stack_my_example.cpp  && \
./a.out > 2 && \
diff 1 2
# c++ -Wall -Wextra -Werror -std=c++98 std_stack.cpp && \
# ./a.out > 1 && \
# c++ -Wall -Wextra -Werror -std=c++98 ft_stack.cpp  && \
# ./a.out > 2 && \
# diff 1 2