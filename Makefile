NAME			= containers_test

CONTAINERS_SRC	= ../ft_containers

# MY FILES TEST
FILES			= hello_test.cpp
INC_FILES		= .
INC_PATH		= .
INC				= $(addprefix ${INC_PATH}/, ${INC_FILES})
SRC_PATH		= .
SRC				= $(addprefix ${SRC_PATH}/, ${FILES})
#version$(grep -m 1 OBJS $ | sed 's/^.*= //g')


# THE BINARY FOLDER
BIN_PATH		= bin
BIN 			= $(SRC:%.cpp=$(BIN_PATH)/%.o)


# GOOGLE TEST LIBRARY
GTEST_SRC 		= googletest
GTEST_INC 		= googletest/googletest/include/
GTEST_LIB		= $(addprefix build/lib/, libgtest.a libgtest_main.a)


# COMMAND LINE
CXX				= clang++
RM				= rm -rf
FLAGS			= -Wall -Wextra  -Werror --std=c++11
AR				= ar rcs


all: 			${NAME}
				clear
				@./${NAME}


# CREATE CONTAINERS INTO A LIBRARY
initContainers:
			#IF HAVE A .A => COPY THEM ELSE ASK

# CREATE GOOGLE TEST INTO A LIBRARY
initGtest:
				@cmake -S ${GTEST_SRC} -B build
				@cmake --build build

# INIT
init: initGtest
				@$(shell mkdir -p $(BIN_PATH))


# CREATE BINARY FILES
$(BIN): $(BIN_PATH)/%.o: %.cpp ${INC}
				@mkdir -p $(@D)
				@$(CXX) $(FLAGS) -I ${INC_PATH} -I ${GTEST_INC} -o $@ -c $<
				@printf "\e[?25l\e[JGTEST  : \e[92m$(notdir $<)\e[0m\r"

# MAIN
${NAME}: 		init ${BIN}
				@${CXX} ${FLAGS} ${BIN} -o ${NAME} -I ${INC_PATH} -I ${GTEST_INC} ${GTEST_LIB}
				@printf '\033[?25l\033[JGTEST CREATED \033[92m✔ \033[0m\033[?25h\n'


# CLEAN GOOGLE TEST AND MY BINARY FILES
clean:
				@${RM} ${BIN_PATH}
				@${RM} build
				@printf '\033[?25l\033[JGTEST DELETED \033[92m✔ \033[0m\033[?25h\n'

fclean:	clean
				@${RM} ${NAME}

re:				fclean all

.PHONY: all clean fclean re
