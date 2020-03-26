/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:25:09 by amartino          #+#    #+#             */
/*   Updated: 2020/03/11 20:58:13 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define ON						1
# define OFF					0

# define DEFAULT_VCT_SIZE 		64
# define DEFAULT_VCT_SCALE 		16
# define FIRST					1
# define SECOND					2
# define BOTH					3
# define NB_OF_APPLY_FUNC		3
# define NB_OF_TEST_FUNC		4
# define NB_TOTAL_OF_FUNC		7
# define START					0

/*
*****************************************************************************
**	size  is the total lenght of str (including the '\0')
**	len	  is the number of characters of the string
**	scale is the number by which the string will be increase for each memory
**	      allocation
**
**	WARNING : 	you should NEVER dereference a vector directly. Use the
**				appropriate function or create it.
*****************************************************************************
*/

typedef struct	s_vector
{
	char		*str;
	size_t		size;
	size_t		len;
	size_t		scale;
}				t_vector;

typedef int		(*t_int_func)(char *);
typedef char	*(*t_char_ptr_func)(char *);

enum	e_apply
{
	UPCASE,
	LOWCASE,
	CAPITALIZE,
	IS_UPCASE,
	IS_LOWCASE,
	IS_BLANK,
	IS_ZERO,
	EMPTY
};

/*
**********************
**  	 BASE	    **
**********************
*/
t_vector		*vct_new(size_t size);
t_vector		*vct_newstr(char *str);
size_t			vct_len(t_vector *vector);
int8_t			vct_increase_scale(t_vector *vector, size_t scale);
void			vct_bzero(t_vector *vector);
void			vct_del(t_vector **vector);
void			vct_del_tab(t_vector ***vct_tab);
void			vct_del_tab_content(t_vector **vct_tab);
char			*vct_getstr(t_vector *vector);
char			vct_getchar_at(t_vector *vector, size_t index);
void			vct_print(t_vector *vector);
void			vct_print_nl(t_vector *vector);
void			vct_print_tab(t_vector **vector);
int8_t			vct_read_line(const int fd, t_vector **line);
int8_t			vct_read_line_for_push_swap(const int fd, t_vector **line);
t_vector		**vct_split(t_vector *input, char c);

/*
**********************
**  	 ADD	    **
**********************
*/
int8_t			vct_addchar(t_vector *vector, char c);
int8_t			vct_addchar_at(t_vector *vector, char c, size_t index);
void			vct_replace_char_at(t_vector *vector, char c, size_t index);
int8_t			vct_addstr(t_vector *vector, char *str);
int8_t			vct_addnstr(t_vector *vector, char *str, size_t len);
int8_t			vct_pushstr(t_vector *vector, char *str);
int8_t			vct_addstr_at(t_vector *vector, char *str, size_t index);
int8_t			vct_addnb(t_vector *vector, int64_t nb);

/*
**********************
**  	REMOVE	    **
**********************
*/
void			vct_pop(t_vector *vector, size_t len);
int8_t			vct_pop_from(t_vector *vector, size_t len, size_t index);

/*
**********************
**  	 JOIN	    **
**********************
*/
t_vector 		*vct_sub(t_vector *vector, size_t start, size_t len);
t_vector		*vct_dup(t_vector *vector);
t_vector		*vct_ndup(t_vector *vector, size_t len);
t_vector		*vct_dup_from(t_vector *vector, size_t index);
t_vector		*vct_ndup_from(t_vector *vector, size_t len, size_t index);
int8_t			vct_cat(t_vector *dest, t_vector *src);
t_vector		*vct_join(t_vector *dest, t_vector *src);
t_vector		*vct_joinfree(t_vector **dest, t_vector **src, int first_or_second_or_both);

/*
**********************
**  	 FILL	    **
**********************
*/
int8_t			vct_fill_after(t_vector *vector, char c, size_t nbr);
int8_t			vct_fill_before(t_vector *vector, char c, size_t nbr);

/*
**********************
**  	SEARCH	    **
**********************
*/
uint8_t			vct_strequ(t_vector const *vector, char const *str);
uint8_t			vct_strnequ(t_vector const *vector, char const *str, size_t n);
ssize_t			vct_chr(t_vector *vector, char c);
size_t			vct_chr_count(t_vector *vector, char c);
ssize_t			vct_chr_str(t_vector *vector, char *find);
size_t			vct_chr_str_count(t_vector *vector, char *find);
ssize_t			vct_replace_char(t_vector *vector, char c, char replace);
ssize_t			vct_replace_str(t_vector *vector, char *str, char *replace);

/*
**********************
**  	APPLY	    **
**********************
*/
int				vct_apply(t_vector *vector, enum e_apply type);

/*
**********************
**  	CONV	    **
**********************
*/
t_vector		*ft_ftoa(double value, uint64_t precision, uint32_t option);
t_vector		*ft_fldtoa(long double val, uint64_t preci, uint32_t opt);

/*
** vct_print
** vct_trim
** vct_split
** vct_splitchr
** vct_read_line
*/

# include "libft.h"

#endif
