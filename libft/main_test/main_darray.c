/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_darray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 09:58:13 by fkante            #+#    #+#             */
/*   Updated: 2020/03/05 11:37:44 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darray.h"
#include "libft.h"

int8_t	test_push_pop(t_darray *array)
{
    int32_t i;
	int32_t	*val;

	i = 0;
	while (i < 50)
	{
		val = darray_new(array);
		*val = i;
		darray_push(array, val);
		i++;
	}
	ft_printf("max value index %d\n", array->end);
	for (i = 0; i <= array->end; i++)
		ft_printf("content = %d\n", *((int*)array->contents[i]));
	ft_printf("------------ pop -----------\n");
	i = 40;
	while (i > 0)
	{
        val = darray_pop(array);
		ft_printf("popped = %d\n", *val);
		if (val == NULL)
			return (ft_perror_failure("pop shouldn't be NULL", __FILE__, __LINE__));
        ft_memdel((void**)&val);
		i--;
    }
   return (TRUE);
}

int8_t	test_expand_contract(t_darray *array, int *val1, int *val2)
{
    darray_expand(array);
	for (int i = 0; i <= array->end; i++)
		ft_printf("content = %d\n", *((int*)array->contents[i]));
     darray_expand(array);
	 ft_printf("newsize after both expand = %d\n", array->max);
   	 darray_contract(array);
	 ft_printf("newsize after contract = %d\n", array->max);
	return (TRUE);

}

int8_t	test_remove(t_darray *array, int *val1, int *val2)
{
    int *val_removed = darray_remove(array, 0);

	if (val_removed == NULL)
		return (ft_perror_failure("removed should not be NULL", __FILE__, __LINE__));
    if (*val_removed != *val1)
		return (ft_perror_failure("val_removed should be == to val1", __FILE__, __LINE__));
	if (darray_get(array, 0) != NULL)
		return (ft_perror_failure("array->content[0] should be NULL", __FILE__, __LINE__));
	ft_memdel((void**)&val_removed);

	val_removed = darray_remove(array, 1);
	if (val_removed == NULL)
		return (ft_perror_failure("removed should not be NULL", __FILE__, __LINE__));
    if (*val_removed != *val2)
		return (ft_perror_failure("val_removed should be == to val2", __FILE__, __LINE__));
	if (darray_get(array, 1) != NULL)
		return (ft_perror_failure("array->content[1] should be NULL", __FILE__, __LINE__));
	ft_memdel((void**)&val_removed);
	return (TRUE);
}

int8_t	test_get(t_darray *array, int *val1, int *val2)
{
	ft_printf("darray get 0 = %d\n", *((int*)darray_get(array, 0)));
	if (darray_get(array, 0) != val1)
		return (ft_perror_failure("Wrong first value.", __FILE__, __LINE__));
	ft_printf("darray get 1 = %d\n\n", *((int*)darray_get(array, 1)));
	if (darray_get(array, 1) != val2)
		return (ft_perror_failure("Wrong second value.", __FILE__, __LINE__));
	return (TRUE);
}

int8_t	test_new_and_set(t_darray *array, int *val1, int *val2)
{
	int8_t	ret;

	val1 = darray_new(array);
	val2 = darray_new(array);
	*val1 = 50;
	*val2 = 76;
	ret = darray_set(array, 0, val1);
	ret = darray_set(array, 1, val2);
	test_get(array, val1, val2);
//	test_expand_contract(array, val1, val2);
	test_push_pop(array);

	return (TRUE);
}

int8_t	test_create(void)
{
	t_darray	*array = NULL;
	int	*val1 = NULL;
	int	*val2 = NULL;
	array = darray_create(sizeof(int), DEFAULT_ARRAY_SIZE, NULL);

	if (array == NULL)
		return (ft_perror_failure("darray_create failed.", __FILE__, __LINE__));

	ft_printf("\n{c_green}Dynamic array created{c_end}\n");

	ft_printf("\n--- make and set new elements ---\n");
	test_new_and_set(array, val1, val2);
	darray_clear_destroy(&array);
	return (TRUE);
}

int	main(void)
{
	ft_printf("------ Dynamic array tests ------\n");
	test_create();
	ft_printf("--------------- END -------------\n");
	return (0);
}
