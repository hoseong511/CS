
void	ft_squeeze(char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			s[j++] = s[i];
		i++;
	}
	s[j] = '\0';
}
