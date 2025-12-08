#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_str_append(char const *s1, char const *s2, size_t start, size_t end)
{
	ssize_t	i;
	size_t	s1_len;
	char	*new;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	new = malloc(s1_len + end - start + 1);
	if (!new)
		return (NULL);
	i = -1;
	while ((size_t)++i < s1_len)
		new[i] = s1[i];
	while (start < end)
		new[i++] = s2[start++];
	new[i] = '\0';
	return (new);
}

ssize_t	ft_index(const char *s, size_t start, char c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = start;
	while (s[i] != c)
		if (!s[i++])
			return -1;
	return (i);
}

void ft_printf(const char *format, ...){
  size_t index = 0;
  char *res = "";
  va_list args;
  char *temp;


  va_start(args, format);

  while (ft_index(format, index, '%') > -1){
    index = ft_index(format, index, '%');
    if (format[index + 1] == 's')
      temp = va_arg(args, char *);
    else if (format[index+1] == 'd')
      temp = ft_convert_d(va_arg(args, int));

      

  }

  
  
  va_end(args);
}


int main() {
}
