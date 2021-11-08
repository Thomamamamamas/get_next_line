NAME = get_next_line.a
SRCS	= get_next_line.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f
AR		= ar rcs
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c {CFLAGS} -o $@ $<

all :	$(NAME)

$(NAME):	$(OBJS)
			$(AR) $@ $^

clean :	${RM} ${OBJ}

fclean :	clean
		rm $(NAME)

re: fclean all

.PHONY:	all clean fclean re
