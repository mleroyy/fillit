/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:25:48 by mleroy            #+#    #+#             */
/*   Updated: 2016/11/21 13:45:11 by mleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_vector
{
	int				x;
	int				y;
}					t_vector;

typedef struct		s_tetra
{
	t_vector		shape[4];
	char			print;
	int				ci;
	int				cj;
}					t_tetra;

typedef struct		s_info
{
	int				nb;
	int				size;
	int				count;
	int				i;
	int				j;
	int				fries;
}					t_info;

void				ft_putchar(char c);

void				ft_putchar_error(char c);

void				ft_putstr_error(char *str);

void				ft_print_usage(void);

void				ft_print_error(void);

void				ft_print_square(char **square, t_info *info);

char				*ft_read_tetra(char *files);

size_t				ft_count_tetra(char *s);

t_tetra				**ft_generate(char *s, unsigned long nbr);

int					ft_check_all(char *s);

int					ft_only_fries(t_tetra **tetra, t_info *info);

void				ft_min_size(t_tetra **tetra, t_info *info);

char				**ft_square(t_info *info);

int					ft_solve(char **square, t_tetra **tetra, t_info *info);

int					ft_can_i_put(char **square, t_tetra **tetra, t_info *info);

void				ft_put_it(char **square, t_tetra **tetra, t_info *info);

void				ft_erase_it(char **square, t_tetra **tetra, t_info *info);

void				ft_del_square(char **square, t_info *info);

int					ft_is_in_square(t_tetra **tetra, t_info *info);

#endif
