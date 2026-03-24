char	*get_env_value(char **envp, char *key)
{
	int		i;
	size_t	key_len;
	key_len = ft_strlen(key);

    if (*envp == NULL)
        return NULL;
    if(key == NULL)
        return NULL;
    i = 0;
	while (envp[i] != '\0')
	{
		if (ft_strncmp(*envp, key, key_len) == 0)
        {
            i++;
			return ();
        }
		i++;
	}
	return (NULL);
}