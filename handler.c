/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:36:54 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:33 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char *handle_c(int c, t_template *tpl) {
	(void) tpl;
	printf("DEBUG: [%c]\n", (char) c);
	return ft_strdup((char []) {(unsigned char) c});	
}

char *handle_s(char *str, t_template *tpl) {
	(void ) tpl;
	return ft_strdup(str);	
}

char *handle_p(char *str, t_template *tpl) {
	(void ) tpl;
	return ft_strdup(str);	
}

char *handle_d(char *str, t_template *tpl) {
	(void ) tpl;
	return ft_strdup(str);	
}

char *handle_u(char *str, t_template *tpl) {
	(void ) tpl;
	return ft_strdup(str);	
}

char *handle_x(char *str, t_template *tpl) {
	(void ) tpl;
	return ft_strdup(str);	
}
