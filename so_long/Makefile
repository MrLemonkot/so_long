# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 14:49:37 by akayle            #+#    #+#              #
#    Updated: 2022/06/28 13:54:04 by akayle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEAD = so_long.h
BHEAD = so_long_bonus.h

LIB			=	-L ./liba/libft -lft
LIBFT		=	libft.a
MLX			=	-L ./liba/mlx -lmlx -framework OpenGL -framework Appkit
MLXLIB		=	mlx

MDIR		= 	./man/
BDIR		=	./bonus/

MFLS		=	main.c error_end.c init_map.c \
				hook.c read_map.c valid_map.c \
				count.c pic.c wasd.c
BFLS		=	main_b.c error_end_b.c init_map_bonus.c \
				hook_b.c read_map_b.c valid_map_b.c \
				count_b.c pic_bonus.c wasd_b.c \
				patrool_move.c patrool.c

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MD 
RM			=	rm -rf

MSRC		=	$(addprefix $(MDIR), $(MFLS))
BSRC		=	$(addprefix $(BDIR), $(BFLS))

MOBJS		=	$(patsubst %.c,%.o,$(MSRC))
BOBJS		=	$(patsubst %.c,%.o,$(BSRC))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MD 
RM			=	rm -rf

OBJS_ALL ?= $(MOBJS)
DEP_ALL ?= $(DEPS)

$(MDIR)%.o:		$(MDIR)%.c Makefile liba/libft/libft.a so_long.h
				$(CC) $(CFLAGS) -Imlx -I $(HEAD) -c $< -o ${<:.c=.o}
$(BDIR)%.o:		$(BDIR)%.c Makefile liba/libft/libft.a so_long_bonus.h
				$(CC) $(CFLAGS) -Imlx -I $(BHEAD) -c $< -o ${<:.c=.o}

all:			$(LIBFT) $(MLXLIB) $(NAME)

$(LIBFT):
				@make -C ./liba/libft

$(MLXLIB):
				@make -C ./liba/mlx

$(NAME):		$(MLXLIB) $(LIBFT) $(MOBJS)
				@make -s -C ./liba/mlx
				@$(CC) $(MOBJS) $(LIB) $(MLX) -o $@

bonus:			$(MLXLIB) $(LIBFT) $(BOBJS)
				@make -s -C ./liba/mlx
				@$(CC) $(BOBJS) $(LIB) $(MLX) -o so_long

clean:
				@make clean -s -C ./liba/libft
				@make clean -s -C ./liba/mlx
				$(RM) $(MOBJS) $(BOBJS)

fclean:			clean
				@make fclean -s -C ./liba/libft
				@make re -s -C ./liba/mlx
				$(RM) $(NAME) so_long_bonus

re:				fclean all

.PHONY:		all clean fclean re bonus