#ifndef ENV_H
# define ENV_H

# include <unistd.h>

char	*get_env_value(char **envp, char *key);

#endif