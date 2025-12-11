#include "ft_printf.h"
#include "libft/libft.h"

static void reset_template(t_template *tpl) {
  if (!tpl)
    return;
  tpl->start = 0;
  tpl->left_justify = 0;
  tpl->sign = 0;
  tpl->space = 0;
  tpl->hash = 0;
  tpl->zero = 0;
  tpl->width = 0;
  tpl->dot = 0;
  tpl->precision = 0;
  tpl->specifier = 0;
  tpl->end = 0;
}

int next_template(char *str, t_template *tpl) {
  size_t i = 0;

  if (ft_index(str, "%") > -1) {
    tpl->start = ft_index(str, "%");

    i = tpl->start + 1;
    while (str[i] && ft_is_member(str[i], "-+ #0")){
      if (str[i] == '-')
        tpl->left_justify = 1;
      else if (str[i] == '+')
        tpl->sign = 1;
      else if (str[i] == ' ')
        tpl->space = 1;
      else if (str[i] == '#')
        tpl->hash = 1;
      else if (str[i] == '0')
        tpl->zero = 1;
      i++;
    }
    while (str[i] && ft_isdigit(str[i]))
      tpl->width  = tpl->width* 10 + str[i++] - '0';
    if (str[i] == '.'){
      tpl->dot = 1;
      i++;
    }
    while (str[i] && ft_isdigit(str[i]))
      tpl->precision = tpl->precision * 10 + str[i++] - '0';
    if (str[i] && ft_is_member(str[i], "cspdiuxX%"))
      tpl->specifier = str[i++];
    tpl->end = i;    
    return 1;
  }
  return 0;
}
