NAME		=	Base
CC			=	c++
EXT			=	.cpp
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98
DEPFLAGS	=	-MMD -MP
HEADER		=	inc/
INC			=	-I$(HEADER)
FILES		=	main Base
FILES_CPP	=	$(addsuffix $(EXT),$(FILES))
SRC_DIR		=	src/
SRCS		=	$(addprefix $(SRC_DIR),$(FILES_CPP))
OBJ_DIR		=	obj/
OBJS		=	$(addprefix $(OBJ_DIR),$(subst $(EXT),.o,$(FILES_CPP)))
DEPS		=	$(subst .o,.d,$(OBJS))
RM			=	rm -rf
MKD			=	mkdir -p
MK			=	Makefile

$(OBJ_DIR)%.o: $(SRC_DIR)%$(EXT) $(MK)
	@$(MKD) $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(DEPFLAGS) $(INC) -c $< -o $@

$(NAME)	:	$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

all		:	$(NAME)

clean	:
	$(RM) $(OBJ_DIR)

fclean	:
	$(MAKE) clean
	$(RM) $(NAME)

re		:	all fclean
	$(MAKE) fclean
	$(MAKE) all

.PHONY	: all clean fclean re