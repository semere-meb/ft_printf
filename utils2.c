#include "ft_printf.h"
#include "libft/libft.h"

char *handle_precision(t_template *tpl, char *str) {
	char *str_gen;
	
	if (tpl->precision > -1) {
		if (tpl->specifier == 's' && tpl->precision < (int) ft_strlen(str))
			str[tpl->precision] = '\0';
		else if (ft_is_member(tpl->specifier, "diuxX") && tpl->precision > (int) ft_strlen(str)){
			str_gen = strgen('0', tpl->precision - ft_strlen(str));
			str = append(str_gen, str, ft_strlen(str), 1);
		}
	}
	return str;
}

char *handle_width(t_template *tpl, int size, char c) {
	if(tpl->width > 0 && tpl->width > size)
		return strgen(c, tpl->width - size);
	else
		return  ft_strdup("");
}

char *handle_left(t_template *tpl, char *str, char *str_gen, size_t str_size, size_t str_gen_size){
	if (tpl->left)
		return  append(str, str_gen, str_size, str_gen_size);
	else
		return append(str_gen, str, str_gen_size, str_size);
}

char *handle_alt(t_template *tpl, char *str) {
	if (tpl->alt && ft_strncmp(str, "0", ft_strlen(str)))
		return append(ft_strdup("0x"), str, 2, ft_strlen(str));
	return str;
}

char *handle_sign(t_template *tpl, char *str) {
	if (tpl->sign && str[0] != '-')
		return append(ft_strdup("+"), str, -1, -1);
	return str;
}

char *handle_space(t_template *tpl, char *str) {
	if (tpl->space && str[0] != '-')
		return append(ft_strdup("+"), str, -1, -1);
	return str;
}

char handle_zero(t_template *tpl) {
	if (tpl->zero && !tpl->left && !tpl->precision)
		return '0';
	return ' ';
}

void print(char *str, t_template *tpl, size_t size) {
	tpl->len += size;
	write(1, str, size);
	free(str);
}
