SDIR			= src
ODIR			= obj
_SRCS			=	malloc.c show_alloc_mem.c \
					memory_bucket.c memory_pointer.c \
					get_available_pointer.c \
					init.c utils.c
_OBJS			= ${_SRCS:.c=.o}
SRCS			= ${_SRCS:%=${SDIR}/%}
OBJS			= ${_OBJS:%=${ODIR}/%}
SRCS_TEST		= ${_SRCS_TEST:%=${SDIR}/%}
_SRCS_TEST		= test.c test_*.c
_OBJS_TEST		= ${_SRCS_TEST:.c=.o}
SRCS_TEST		= ${_SRCS_TEST:%=${SDIR}/%}
OBJS_TEST		= ${_OBJS_TEST:%=${ODIR}/%}
INC				= -Ilibft -Iinc
LIB				= libft/libft.a
CC				= clang
CFLAGS			= -Wall -Wextra -Werror -g -ggdb
RM				= rm -f

ifndef HOSTTYPE
HOSTTYPE = $(shell uname -m)_$(shell uname -s)
endif

NAME_LIB	= libft_malloc.so
NAME_BLANK	= libblank.so
NAME_TEST	= test.out
NAME		= libft_malloc_${HOSTTYPE}.so

PWD			= $(shell pwd)

${ODIR}/%.o :	${SDIR}/%.c
				${CC} ${CFLAGS} -fpic ${INC} -c $< -o $@
all :
				cd libft && make EXCLUDE=alloc
				make ${NAME}
				make ${NAME_TEST}
${NAME} :		${OBJS}
				${CC} -shared -o ${NAME} ${OBJS}
				${RM} ${NAME_LIB}
				ln -s ${NAME} ${NAME_LIB}
${NAME_BLANK} :	${ODIR}/blank.o
				${CC} -shared -o ${NAME_BLANK} ${ODIR}/blank.o
${NAME_TEST} :	${NAME} ${NAME_BLANK} ${OBJS_TEST}
				${CC} -o ${NAME_TEST} ${OBJS_TEST} -lft_malloc -Wl,-rpath=${PWD} -L${PWD} ${LIB} ${CFLAGS} ${INC}
clean :
				${RM} ${OBJS} ${ODIR}/blank.o
fclean :		clean
				${RM} ${NAME} ${NAME_LIB} ${NAME_BLANK} ${NAME_TEST} test_output_*.txt
re :			fclean all
.PHONY :
				all ${NAME} ${NAME_BLANK} ${NAME_TEST} clean fclean re
