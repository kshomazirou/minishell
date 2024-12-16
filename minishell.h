/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:34:07 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/09 21:49:54 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SKIP 1
# define NOSKIP 0

# define BUFF_SIZE 4096
# define EXPANSION -36
# define ERROR 1
# define SUCCESS 0
# define IS_DIRECTORY 126
# define UNKNOWN_COMMAND 127

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}				t_token;

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_mini
{
	t_token			*start;
	t_env			*env;
	t_env			*secret_env;
	int				in;
	int				out;
	int				fdin;
	int				fdout;
	int				pipin;
	int				pipout;
	int				pid;
	int				charge;
	int				parent;
	int				last;
	int				ret;
	int				exit;
	int				no_exec;
}				t_mini;

typedef struct s_sig
{
	int				sigint;
	int				sigquit;
	int				exit_status;
	pid_t			pid;
}				t_sig;

typedef struct s_expansions
{
	char			*new_arg;
	int				i;
	int				j;
}				t_expansions;

extern t_sig	g_sig;

void	sig_int(int code);
void	sig_quit(int code);
char	*ft_strdup(const char *string);
int		env_init(t_mini *mini, char **env_s);
char	*ft_strdup(const char *string);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(const char *str);
int		env_value_len(const char *env);
int		ft_strcmp(const char *s1, const char *s2);
void	shell_level(t_env *env);
void	sig_int(int code);
void	sig_quit(int code);
int		quote_check(t_mini *mini, char **line);
char	*ft_strchr(const char *s, int c);
int		is_sep(char *line, int i);
void	ft_skip_space(const char *str, int *i);
int		ignore_sep(char *line, int i);
int		next_alloc(char *line, int *i);
char	*space_line(char *line);
t_token	*next_token(char *line, int *i);
int		is_type(t_token *token, int type);
int		is_types(t_token *token, char *types);
void	squish_args(t_mini *mini);
void	parse(t_mini *mini, char *line);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_memdel(void *ptr);
char	*space_alloc(char *line);
int		quotes(char *line, int index);
t_token	*prev_sep(t_token *token, int skip);
char	*ft_itoa(int n);
char	*ft_strjoin(const char *s1, const char *s2);
int			get_lvl(const char *str);
t_token	*next_run(t_token *token, int skip);
int		minipipe(t_mini *mini);
void	ft_close(int fd);
void	reset_std(t_mini *mini);
void	close_fds(t_mini *mini);
void	reset_fds(t_mini *mini);
char	*get_var_value(const char *arg, int pos, t_env *env, int ret);
char	*expansions(char *arg, t_env *env, int ret);
void	redir_and_exec(t_mini *mini, t_token *token);
void	exec_cmd(t_mini *mini, t_token *token);
int		arg_alloc_len(const char *arg, t_env *env, int ret);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
void	mini_exit(t_mini *mini, char **cmd);
void	free_tab(char **tab);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		has_pipe(t_token *token);
int		exec_builtin(char **args, t_mini *mini);
int		is_env_char(int c);
int		is_valid_env(const char *env);
int		env_value_len(const char *env);
char	*env_value(char *env);
void	print_error(char **args);
int		env_add(const char *value, t_env *env);
void	print_sorted_env(t_env *env);
char	*env_to_str(t_env *lst);


#endif
