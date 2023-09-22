/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:19:06 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/22 13:46:20 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include "include/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int				n;
	int				index;
	struct t_stack	*next;
}					t_stack;

typedef struct t_bigstack
{
	char			**argv;
	int				argc;
	int				splited;
	struct t_stack	*a;
	struct t_stack	*b;
}					t_bigstack;

//++++++++ Function ++++++++++++

//*************** utils
int					ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
char				**insert_to(char **tab, char const *s, char c);
char				*get_word(char const *s, char c);
int					count_word(char const *s, char sep);
int					ft_is_number(char *s);
int					ft_isspace(char c);
char				*ft_getsign(char *str, int *is_neg);
long int			ft_long_atoi(char *str, t_bigstack *b);
void				arg_char(t_bigstack *b);
int					ft_isdigit(int c);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);

//*************** utils_error
void				ft_error(t_bigstack *b);
void				ft_freedom(t_bigstack *b);

//*************** utils list
t_stack				*getlast(t_stack *a);
t_stack				*addlast_list(t_bigstack *big, t_stack *new, char *s);
int					stack_size(t_stack **a);
void				init_stack(t_bigstack *big);
void				single_arg(t_bigstack *b, char **argv);
void				ft_clear_stack(t_stack **a);

//*************** utils_index
int					find_index(t_bigstack *b, t_stack *a);
void				init_index(t_bigstack *b);
int					get_min_index(t_stack **a);
int					get_max_index(t_stack **a);

//************** operations
void				ft_pa(t_stack **a, t_stack **b);
void				ft_pb(t_stack **a, t_stack **b);
void				ft_sa(t_stack **a);
void				ft_ra(t_stack **a);
void				ft_rra(t_stack **a);

//************* mouvements
void				ft_sx_move(t_stack **a);
void				ft_rx_move(t_stack **a);
void				ft_rrx(t_stack **a);

//************* utils_sort
int					is_order(t_bigstack *b);
void				init_sort(t_bigstack *b);
void				tri_sort(t_bigstack *b);
void				ft_five_sort(t_bigstack *b);

//************* utils_args
void				init_arg(t_bigstack *b);
void				arg_type(t_bigstack *b);
void				arg_double(t_bigstack *b);
void				arg_limit(t_bigstack *b);
void				init_struct(t_bigstack *b, int argc, char **argv);
void				multi_arg(t_bigstack *b, char **argv, int argc);

//************ radix
void				ft_radix(t_bigstack *b, int byte);

#endif