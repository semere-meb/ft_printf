#include "ft_printf.h"
#include "libft/libft.h"

void sanitize_template(t_template *tpl) {
  if (tpl->precision){
    tpl->zero = 0;
    if(tpl->specifier == 's')
      tpl->width = 0;
  }
  if (tpl->left_justify)
    tpl->zero = 0;
}

void handler(char *val, t_template *tpl) {
  size_t size = ft_strlen(val);

  char *res = ft_strdup(val);
  if (tpl->precision)

  
}
