char	*get_env_value(char **envp, char *key)
{
	int		i;
	size_t	key_len;

    if (envp == NULL)
        return NULL;
    if(key == NULL)
        return NULL;
    if (*key == '\0')
        return NULL;
	key_len = ft_strlen(key);
    i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], key, key_len) == 0 
            && (envp[i][key_len] == '='))
			return (envp[i] + key_len + 1);
		i++;
	}
	return (NULL);
}

char	*get_var_name(char *str, int i)
{
    char *var_name;
    int var_len;
    int i;

    i = 0;
    var_len = ft_strlen(str);
    var_name = (char *)malloc(sizeof(char) * (var_len + 1));
    if (!var_name)
        return NULL;
    if (var_name[i] != '$')
        re
}
