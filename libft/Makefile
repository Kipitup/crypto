# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkante <fkante@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 17:11:38 by fkante            #+#    #+#              #
#    Updated: 2020/03/12 16:26:29 by amartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
AR = ar -rcs
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
BUILD_DIR = objs/

INCLUDES = ./includes
I_INCLUDES = $(addprefix -I, $(INCLUDES))
HEAD += libft.h
HEAD += vector.h
HEAD += btree.h
HEAD += ft_printf.h
HEAD += define_pf.h
HEAD += darray.h
HEAD += hashmap.h
HEAD += graph.h

vpath %.h $(INCLUDES)

                     ####################################
                     #                   				#
                     #       	  	IFEQ	   			#
                     #                   				#
                     ####################################

# FLAGS
ifeq ($(debug), 0)
	CFLAGS += -g3
else ifeq ($(debug), 1)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
else ifeq ($(debug), 2)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	#CFLAGS += -ansi
	CFLAGS += -pedantic
else ifeq ($(debug), 3)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	#CFLAGS += -ansi
	CFLAGS += -pedantic
	CFLAGS += -Wpadded
else ifeq ($(debug), 4)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	#CFLAGS += -ansi
	CFLAGS += -pedantic
	CFLAGS += -Wpadded
	CFLAGS += -Weverything
endif

SRCS += ft_memalloc.c
# SRCS += ft_malloc_debug.c
SRCS += ft_atoi.c
SRCS += ft_bzero.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_itoa.c
SRCS += ft_itoa_base.c
SRCS += ft_lstadd.c
SRCS += ft_lstdel.c
SRCS += ft_lstdelone.c
SRCS += ft_lstiter.c
SRCS += ft_lstnew.c
SRCS += ft_lstmap.c
SRCS += ft_lstfindone.c
SRCS += ft_memccpy.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memdel.c
SRCS += ft_memmove.c
SRCS += ft_memset.c
SRCS += ft_putchar.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr.c
SRCS += ft_putstr_fd.c
SRCS += ft_strcat.c
SRCS += ft_strchr.c
SRCS += ft_strclr.c
SRCS += ft_strcmp.c
SRCS += ft_strcpy.c
SRCS += ft_strdel.c
SRCS += ft_strdup.c
SRCS += ft_strequ.c
SRCS += ft_striter.c
SRCS += ft_striteri.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlen.c
SRCS += ft_strmap.c
SRCS += ft_strmapi.c
SRCS += ft_strndup.c
SRCS += ft_strncat.c
SRCS += ft_strncmp.c
SRCS += ft_strncpy.c
SRCS += ft_strnequ.c
SRCS += ft_strnew.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strsplit.c
SRCS += ft_strstr.c
SRCS += ft_strsub.c
SRCS += ft_strtrim.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c
SRCS += ft_swap.c
SRCS += ft_nb_unitlen.c
SRCS += ft_absolute.c
SRCS += ft_fibonacci.c
SRCS += ft_sqrt.c
SRCS += ft_pow.c
SRCS += ft_pow_positive.c
SRCS += ft_uint64_t_len.c
SRCS += ft_int64_t_len.c
SRCS += ft_strcapitalize.c
SRCS += ft_strupcase.c
SRCS += ft_strlowcase.c
SRCS += ft_strisupcase.c
SRCS += ft_strislowcase.c
SRCS += ft_strchr_str.c
SRCS += ft_strisblank.c
SRCS += ft_striszero.c
SRCS += ft_len_printf.c
SRCS += ft_ftoa.c
SRCS += ft_fldtoa.c
SRCS += get_next_line.c
SRCS += ft_atol.c
SRCS += ft_log2_n.c
SRCS += ft_check_int_len.c
SRCS += ft_is_prime.c
SRCS += ft_find_next_prime.c

#------------------------------------ STAT ------------------------------------#
SRCS += ft_get_high.c
SRCS += ft_get_low.c
SRCS += ft_get_low_in_range.c
SRCS += ft_get_high_in_range.c
SRCS += ft_high.c
SRCS += ft_low.c
SRCS += ft_mean.c
SRCS += ft_median.c
SRCS += ft_range.c
SRCS += ft_get_median.c
SRCS += ft_get_n_highest.c
SRCS += ft_get_n_smallest.c
SRCS += ft_sort.c

#----------------------------------- VECTOR -----------------------------------#
SRCS += vct_del.c
SRCS += vct_new.c
SRCS += vct_newstr.c
SRCS += vct_addstr.c
SRCS += vct_addnstr.c
SRCS += vct_pop.c
SRCS += vct_dup.c
SRCS += vct_ndup.c
SRCS += vct_dup_from.c
SRCS += vct_ndup_from.c
SRCS += vct_addchar.c
SRCS += vct_increase_scale.c
SRCS += vct_bzero.c
SRCS += vct_len.c
SRCS += vct_cat.c
SRCS += vct_getstr.c
SRCS += vct_join.c
SRCS += vct_joinfree.c
SRCS += vct_addchar_at.c
SRCS += vct_pop_from.c
SRCS += vct_fill_after.c
SRCS += vct_fill_before.c
SRCS += vct_pushstr.c
SRCS += vct_apply.c
SRCS += vct_replace_char_at.c
SRCS += vct_replace_char.c
SRCS += vct_replace_str.c
SRCS += vct_addstr_at.c
SRCS += vct_chr.c
SRCS += vct_chr_str.c
SRCS += vct_getchar_at.c
SRCS += vct_print.c
SRCS += vct_print_nl.c
SRCS += vct_addnb.c
SRCS += vct_chr_count.c
SRCS += vct_chr_str_count.c
SRCS += vct_read_line.c
SRCS +=	vct_read_line_for_push_swap.c
SRCS += vct_strequ.c
SRCS += vct_strnequ.c
SRCS += vct_sub.c
SRCS += vct_split.c
SRCS += vct_del_tab.c
SRCS += vct_print_tab.c

#----------------------------------- BTREE ------------------------------------#
SRCS += heap_build.c
SRCS += heap_order.c
SRCS += heap_print.c
SRCS += heap_tool.c
SRCS += red_black_build.c
SRCS += red_black_insert_order.c
SRCS += red_black_remove_order.c
SRCS += red_black_remove.c
SRCS += red_black_print.c
SRCS += red_black_tool.c
SRCS += red_black_rotation.c

#----------------------------------- ERROR ------------------------------------#
SRCS += ft_perror_null.c
SRCS += ft_perror_failure.c
SRCS += ft_perror_false.c
SRCS += ft_perror.c

#----------------------------------- HASH -------------------------------------#
SRCS += hash_function.c
SRCS += compare_function.c
SRCS += hashmap_create.c
SRCS += hashmap_set.c
SRCS += hashmap_get.c
SRCS += hashmap_clean.c
SRCS += hashmap_print.c
SRCS += hashmap_resize.c

#---------------------------------- DARRAY -------------------------------------#
SRCS += darray_clear.c
SRCS += darray_create.c
SRCS += darray_destroy.c
SRCS += darray_modify_size.c
SRCS += darray_pop.c
SRCS += darray_push.c
SRCS += darray_utilities.c
SRCS += ft_realloc.c
SRCS += del_function.c

#--------------------------------- FT_PRINTF ----------------------------------#
SRCS += ft_printf.c
SRCS += ft_asprintf.c
SRCS += ft_dprintf.c
SRCS += search_color.c
SRCS += apply_hash_flag.c
SRCS += apply_modifier.c
SRCS += apply_modifier_f.c
SRCS += apply_modifier_zj.c
SRCS += apply_padding_flag.c
SRCS += check_flag.c
SRCS += conv_to_b.c
SRCS += conv_to_c.c
SRCS += conv_to_di.c
SRCS += conv_to_f.c
SRCS += conv_to_hexa_maj.c
SRCS += conv_to_none.c
SRCS += conv_to_ox.c
SRCS += conv_to_ptr.c
SRCS += conv_to_str.c
SRCS += conv_to_u.c
SRCS += convert.c
SRCS += init_printf.c
SRCS += statemachine.c
SRCS += statemachine_asprintf.c
SRCS += states.c
SRCS += width_and_precision.c

#------------------------------- ADJACENCY LIST -------------------------------#
SRCS += adjacency_list.c
SRCS += graph_clean.c
SRCS += graph_print.c

PATH_SRCS += ./vector
PATH_SRCS += ./darray
PATH_SRCS += ./ft_printf/bonus
PATH_SRCS += ./ft_printf/init
PATH_SRCS += ./ft_printf/conversion
PATH_SRCS += ./ft_printf/statemachine
PATH_SRCS += ./ft_printf/
PATH_SRCS += ./btree
PATH_SRCS += ./stats
PATH_SRCS += ./error
PATH_SRCS += ./linked_list
PATH_SRCS += ./number
PATH_SRCS += ./string
PATH_SRCS += ./memory
PATH_SRCS += ./print
PATH_SRCS += ./math
PATH_SRCS += ./hashmap
PATH_SRCS += ./graph
PATH_SRCS += .

vpath %.c $(PATH_SRCS)

OBJS += $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	echo  "\n$(CYAN)Makefile libft$(END)\n"
	$(AR) $@ $(OBJS)

$(BUILD_DIR):
	mkdir $@

$(OBJS): $(BUILD_DIR)%.o: %.c $(HEAD) Makefile
	$(CC) $(CFLAGS) $(I_INCLUDES) -c $< -o $@
	echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"


clean:
	$(RM) -R $(BUILD_DIR)
	$(RM) -R a.out
	$(RM) -R hash_valgrind
	$(RM) -R hash_valgrind.dSYM

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: clean fclean re
.SILENT: $(NAME) $(OBJS) $(BUILD_DIR) clean fclean re

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
END = \033[0m
