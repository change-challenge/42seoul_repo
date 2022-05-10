#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
char	*get_next_line(int fd);
char	*ft_strlen_chr_init(const char *s, int c, size_t *len, int init);
size_t	ft_strlcat_dstlen(char *dst, size_t dst_len, char const *src,
			size_t dstsize);
char	*ft_strdup(const char *s1);

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;
t_list	*ft_lstadd_back_last(t_list **lst, t_list *new);
t_list	*ft_lstnew_str(char *content);
#endif