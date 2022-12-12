#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set);

int main () 
{
//   const char str[] = "This is just a String"; 
//   const char ch = 'u'; 
//   char *p;
//   char *q;

// p = strchr(str, ch);
//  printf("With strch, string starting from %c is: %s", ch, p);
// q = ft_strchr(str, ch);
// printf("With ft_strchr, string starting from %c is: %s\n\n"), ch, q);

   const char s1[] = "dddddddd12345ddddddddddddddd"; 
   const char set[] = "d";
   printf("In the string ------> %s    we need to trim the set: %s\n", s1, set);
   printf("The trimmed string is %s\n\n", ft_strtrim(s1, set));
}