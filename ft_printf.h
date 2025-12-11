/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:20 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/09 17:24:34 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

//%[flags][width][.precision][length]specifier
 // ’-0.’ 
 // minimum field width
 // ’# +’

typedef struct s_template {
  size_t start;
  size_t end;

  int left_justify; // Left-justify within the given field width; Right justification is the default (see width sub-specifier).
  int sign;// Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.
  int space; // If no sign is going to be written, a blank space is inserted before the value.
  int hash; // Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.  char zero;
  int zero; // Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
  size_t width; // Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.
  int dot; //  For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.  char specifier;
  size_t precision;
  char specifier;
} t_template;

int next_template(char *str, t_template *tpl);

ssize_t	ft_index(const char *s, char *chars);

int ft_is_member(char c, char *chars);

char			*ft_convert_base(int n, char *base_to);

char * ft_append(char *s1, char *s2, size_t size);

void			ft_printf(const char *f, ...);

#endif
