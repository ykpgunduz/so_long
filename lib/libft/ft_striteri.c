/* ************************************************************************** */
/*                                                                            */
/*                                                           :::      ::::::: */
/*   ft_striteri.c                                         :+:      :+:    :+ */
/*                                                       +:+ +:+         +:+  */
/*   By: yagunduz <yagunduz@student.42istanbul.com.tr> +#+  +:+       +#+     */
/*                                                   +#+#+#+#+#+   +#+        */
/*   Created: 2025/06/28 13:45:19 by yagunduz             #+#    #+#          */
/*   Updated: 2026/01/16 23:21:58 by yagunduz            ###   ########.tr    */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
