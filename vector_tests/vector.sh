#!/bin/bash

# c++ -Wall -Wextra -Werror -std=c++98 std_vector_my_examples.cpp && \
# ./a.out > 1 && \
# c++ -Wall -Wextra -Werror -g -std=c++98 ft_vector_my_examples.cpp && \
# ./a.out > 2 && \
# diff 1 2 
# c++ -Wall -Wextra -Werror -std=c++98 std_vector.cpp && \
# ./a.out > 1 && \
# c++ -Wall -Wextra -Werror -g -std=c++98 ft_vector.cpp && \
# ./a.out > 2 && \
# diff 1 2
c++ -Wall -Wextra -Werror -std=c++98 std_vector_test_itertor.cpp && \
./a.out > 1 && \
c++ -Wall -Wextra -Werror -g -std=c++98 ft_vector_test_itertor.cpp && \
./a.out > 2 && \
diff 1 2