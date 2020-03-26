/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:14:27 by amartino          #+#    #+#             */
/*   Updated: 2020/03/12 11:47:28 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "define_pf.h"

enum	e_main_states
{
	ST_STRING,
	ST_FLAGS,
	ST_CONVERSION,
	ST_BUFFER,
	ST_COLOR,
	ST_ERROR,
	ST_END
};

typedef struct	s_state_machine
{
	t_vector			*output;
	uint64_t			width;
	uint64_t			precision;
	uint32_t			option;
	enum e_main_states	state;
	int8_t				fd;
	char				padding[7];
}				t_state_machine;

typedef struct	s_flag
{
	uint64_t			width;
	uint64_t			precision;
	uint32_t			option;
	char				padding[4];
}				t_flag;

typedef int8_t		(*t_statefunc)(t_state_machine *self, char *input,
									va_list *arg_pf);
typedef t_vector	*(*t_convfunc)(va_list *arg_pf, t_flag *flag);

/*
**********************
**     FT_PRINTF    **
**********************
*/
int				ft_printf(const char *input, ...);

/*
** __attribute__((format(printf, 1, 2)));
*/

int				ft_dprintf(int fd, const char *input, ...);
int				ft_asprintf(char **str, const char *input, ...);

/*
**********************
**  STATE MACHINE	**
**********************
*/
ssize_t			parser(t_state_machine *ptf, char *input, va_list *arg_pf);
ssize_t			parser_aspf(t_state_machine *ptf, char *input, va_list *arg_pf);
int8_t			string(t_state_machine *ptf, char *input, va_list *arg_pf);
int8_t			conversion(t_state_machine *ptf, char *input, va_list *arg_pf);
int8_t			flags(t_state_machine *ptf, char *input, va_list *arg_pf);
int8_t			buffer(t_state_machine *mahcine, char *input, va_list *arg_pf);
int8_t			buffer_as_pf(t_state_machine *ptf, char *inpt, va_list *arg_pf);
int8_t			color(t_state_machine *ptf, char *input, va_list *arg_pf);
int8_t			error(t_state_machine *ptf, char *input, va_list *arg_pf);
int8_t			end(t_state_machine *ptf, char *input, va_list *arg_pf);
uint8_t			is_width(t_state_machine *ptf, char *input, va_list *arg_pf);
uint8_t			is_precision(t_state_machine *ptf, char *input,
								va_list *arg_pf);
uint64_t		get_numbers(t_state_machine *ptf, char *input, size_t *count);

/*
**********************
**  	 INIT	    **
**********************
*/
int8_t			init_state_machine(t_state_machine *ptf, int fd);
void			init_flags(t_state_machine *ptf, t_flag *flags);
t_vector		*init_colors(void);

/*
**********************
**    CONVERSION	**
**********************
*/
t_vector		*conv_to_c(va_list *arg_pf, t_flag *flag);
t_vector		*conv_to_str(va_list *arg_pf, t_flag *flag);
t_vector		*conv_to_ptr(va_list *arg_pf, t_flag *flag);
t_vector		*conv_to_ox(va_list *arg_pf, t_flag *flag);
t_vector		*conv_to_di(va_list *arg_pf, t_flag *flag);
t_vector		*conv_to_u(va_list *arg_pf, t_flag *flag);
t_vector		*conv_to_hexa_maj(va_list *arg_pf, t_flag *flag);
t_vector		*conv_to_f(va_list *arg_pf, t_flag *flag);
t_vector		*conv_to_b(va_list *arg_pf, t_flag *flag);
t_vector		*conv_to_none(char input, t_flag *flag);

int64_t			apply_modifier_di(int64_t nbr_conv, uint32_t flag);
uint64_t		apply_modifier_oxx_maj(int64_t nbr_conv, uint32_t flag);
uint64_t		apply_modifier_u(uint64_t nbr_conv, uint32_t flag);
uint64_t		apply_modifier_s(uint64_t str, uint64_t flag);
uint64_t		apply_modifier_p(uint64_t str, uint64_t flag);
int64_t			apply_modifier_zj(int64_t nbr_conv, uint32_t flag);
long double		apply_modifier_f(long double nbr, int32_t flag);
int8_t			apply_precision(t_vector *vector, t_flag *flag);
int8_t			apply_width(t_vector *vector, t_flag *flag);
int8_t			apply_padding_flag(t_vector *vector, t_flag *flag,
		t_vector *nb_itoa);
t_vector		*handle_sign(t_vector *nb_itoa, t_flag *flag);
int8_t			apply_hash(t_vector *vector, t_flag *flag);
void			apply_hash_flag_zero(t_vector *vector, t_flag *flag);
void			apply_hash_special_case(t_vector *vector, t_flag *flag);
int8_t			apply_hash_float(t_vector *vector, t_flag *flag);

t_vector		*get_converted_number(t_vector	*vector, t_flag *flag,
										uint8_t base, int64_t nbr);

int8_t			convert(t_state_machine *ptf, t_flag *flag, char *input,
							va_list *arg_pf);
void			check_and_cancel_flag(t_state_machine *ptf);
void			cancel_flag_for_numeric_conv(t_flag *flag);
void			cancel_flag_for_other_conv(t_flag *flag);
void			cancel_flag_for_ptr_conv(t_flag *flag);
void			cancel_flag_for_none_conv(t_flag *flag);

void			search_color(t_state_machine *ptf, t_vector *vector,
							char *input, int i);

enum	e_type_flag
{
	E_TYPE_FLAG_FLAG_HH,
	E_TYPE_FLAG_LL,
	E_TYPE_FLAG_H,
	E_TYPE_FLAG_L,
	E_TYPE_FLAG_L_MAJ,
	E_TYPE_FLAG_PLUS,
	E_TYPE_FLAG_MINUS,
	E_TYPE_FLAG_HASH,
	E_TYPE_FLAG_ZERO,
	E_TYPE_FLAG_SPACE,
	E_TYPE_FLAG_POINT
};

enum	e_type_conv
{
	E_TYPE_CONV_C,
	E_TYPE_CONV_S,
	E_TYPE_CONV_P,
	E_TYPE_CONV_D,
	E_TYPE_CONV_I,
	E_TYPE_CONV_O,
	E_TYPE_CONV_U,
	E_TYPE_CONV_X,
	E_TYPE_CONV_X_MAJ,
	E_TYPE_CONV_F,
	E_TYPE_CONV_NONE
};

#endif
