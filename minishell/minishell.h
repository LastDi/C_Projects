/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalvera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:35:24 by oalvera           #+#    #+#             */
/*   Updated: 2022/04/30 14:35:26 by oalvera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include <errno.h>

# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_pipes {
	int		pipe_count;
	int		fd_in;
	int		fd_out;
	int		*flags;
}				t_pipes;

typedef struct s_shell {
	char	**str;
	int		pipe_count;
	int		pipe_count_max;
	int		func_count;
	int		i;
	int		j;
	int		n;
	int		error;
	int		flags_count;
	int		longs;
	int		error_code;
	int		preflag;
	int		lenght;
	int		*flags;
	int		**flags_for_prog;
	int		tmp_split_p;
	int		tmp_split_on_off;
	int		*start_flag_prog;
	int		*count_flag_prog;
	int		cycle;
	char	tmp_split;
	int		tmp_split2;
	int		free;
	char	**env;
	t_pipes	*pipes;
}				t_shell;

typedef struct command
{
	char			*name;
	char			**flags;
	struct command	*next;
	int				fd_in;
	int				fd_out;
	char			*path;
}				t_com;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	minishell(t_shell *shell, t_com *com, t_list **evl);

//parser
char	*parser(char *s, t_shell *shell);
int		preparser(char *str);
void	multiple_free(void *s1, void *s2, void *s3, void *s4);
char	*find_key(t_shell *shell, char *str1);

//signals
void	handler_ctrl_c(int val);
void	handler_ctrl_d(void);
void	handler_ctrl_backslash(int val);

//errors
int		error_checker(char *str, t_shell *shell);

char	**ft_split_shell(char const *s, char c, int i, t_shell *shell);

// DELETE IT
void	show_struct(t_shell *shell, char *s);
void	set_point(char *s);

// LIBA
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_bzero(void *b, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_lstcount(t_com **com);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
t_com	*ft_lstgive(t_com **com, int i);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strlen_sym(char *str, char c);
int		ft_isdigit(int c);
void	ft_lstclear(t_list **lst, void (*del)(void*));
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

// Redirect
int		fd_redirect(t_shell *shell);
int		fd_redirect_output(t_shell *shell);
int		fd_redirect_output_one(t_shell *shell);
int		fd_redirect_output_two(t_shell *shell);
int		fd_redirect_input(t_shell *shell);
int		fd_redirect_input_one(t_shell *shell);
int		fd_redirect_input_two(t_shell *shell);
int		fd_file_not_exist(char *str, int j, int n);
char	*ft_find_file_name(char *str, t_shell *shell, int l);
int		read_for_redirect(t_shell *shell, char *str, int j, int x);
int		gnl_light(char **str);

// Exec command
void	init_com(t_shell *shell, t_com *com);
int		ft_exec_start(char **ev, t_com *com, t_list **evl);
int		ft_exec_one_com(t_com *com, char **ev, t_list **evl);
void	ft_duplicate_fd(t_com *com);
int		directory_access(t_com *com);
int		ft_exec_errors(char *s1, char *s2);
char	*make_name_after_slash(char *str);
char	*delete_slash_from_name(char *str);
void	ft_exec_full_path(t_com *com, char **ev, t_list **evl);
int		ft_choose_exec_com(t_com *com, t_list **evl);
int		parsing_export(char *str);
int		ft_exec_pipe(t_com **com, char **ev, t_list **evl);

// system commands
int		ft_pwd(void);
int		ft_cd(t_com *com, t_list **evl);
int		ft_echo(t_com *com);
int		ft_export(t_com *com, t_list **evl);
int		ft_unset(t_com *com, t_list **evl);
int		ft_env(t_com *com, t_list **evl);
int		ft_exit(t_com *com, t_list **evl);

// utils for command
void	ft_sort_easy(t_list **evl);
int		check_arg_unset(char *str);
int		unset_help1(t_com *com, int i);
void	env_help(char *help);
int		sort_count(t_list **evl);
int		who_is_more(char *s1, char *s2);

//UTILS
void	tmp_changer(t_shell *shell);
void	malloc_part(t_shell *shell, int i);
void	tmp_write(t_shell *shell, char c, int i);
void	set_count(int count, t_shell *shell, char c);

// CHANGE THIS TODO
int		export_unset2(char *arg, t_list **l1, t_list **l3, t_list **l2);
int		export_unset1(char *arg, t_list **l1, t_list **l2, t_list **evl);
int		export_unset_help_1(char *arg, t_list **evl, char *help, t_list *l1);
int		export_unset_help_2(char *arg, char *help);
char	*arg_tipo_unset(char *arg);

// free
int		free_com_list(t_com *com);
void	free_split_str(char **str, int j);
void	ft_freesplit_2(char **x);
#endif
