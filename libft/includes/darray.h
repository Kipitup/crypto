/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:27:45 by fkante            #+#    #+#             */
/*   Updated: 2020/03/09 10:39:40 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DARRAY_H
# define DARRAY_H

# include <stdlib.h>

# define DEFAULT_EXPAND_RATE	20
# define DEFAULT_ARRAY_SIZE		10
/*
**	WARNING: the dynamic array is agnostic of what is in content. However you'll
**	need to give it the appropriate clean function. NO LEAKS MAY BE TOLERATED.
**	You'll need to go in the del_function.c file and add the appropriate del
**	function. Then, when calling darray_clear_content or darray_clear_destroy
**	pass the del function you created.
**
**	'max' is the number of block initially malloc
**	'end' is index that define the last assigned element
**	'sizeof_elem' is the byte' size of each element in content
**	'expand_rate' when end >= max, then we expand the array by the expand_rate
*/

typedef	void (*t_del_func)(void *);

typedef struct	s_darray {
	size_t		end;
	size_t		max;
	size_t		sizeof_elem;
	size_t		expand_rate;
	void		**contents;
}				t_darray;


int8_t		darray_set(t_darray *array, size_t i, void *element);
void		*darray_get(t_darray *array, size_t i);
void		*darray_remove(t_darray *array, size_t i);
void		*darray_new(t_darray *array);
t_darray	*darray_create(size_t sizeof_elem, size_t initial_max);
int8_t		darray_expand(t_darray *array);
int8_t		darray_contract(t_darray *array);
int8_t		darray_push(t_darray *array, void *element);
void		*darray_pop(t_darray *array);
void		darray_destroy(t_darray **array);
void		darray_clear_content(t_darray **array, t_del_func del_func);
void		darray_clear_destroy(t_darray **array, t_del_func del_func);
void		**ft_realloc(t_darray *array, size_t size, size_t old_size);
void		del_hashmap_node(void *content);
void		del_vector(void *content);

/*
** ********************************  ERRORS ************************************
*/
# define ARRAY_IS_NULL			"Array is null"
# define CLEAR_NULL				"Trying to clear null array"
# define SET_ABOVE_MAX			"darray attempt to set past max"
# define GET_ABOVE_MAX			"darray attempt to get past max"
# define ARRAY_SIZE_ZERO		"Can't use darray_new on 0 size darrays"
# define INITIAL_MAX_ZERO		"You must set an initial_max > 0"
# define NEWSIZE_ZERO			"To resize Darray, the newsize must be > 0"
# define FAILED_TO_EXPAND		"Failed to expand array to new size"
# define FAILED_TO_POP			"Attempt to pop from empty array"
# define CONTENT_FAIL			"Failed to allocated memory for content"
# define REALLOC_FAIL			"Reallocation failed"

#endif
