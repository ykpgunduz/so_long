/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   get_next_line.h                                       :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/09/11 09:37:24 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:21:10 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_and_free(char *s1, char const *s2);

#endif