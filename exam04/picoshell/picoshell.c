#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int	fd[2];
	int	fd_stdin = 0;
	pid_t pid;
	int	i = 0;
	int	status = 0;

	while (cmds[i])
	{
		if (cmds[i + 1])
		{
			if (pipe(fd) == -1)
			{
				if (fd_stdin != 0)
					close(fd_stdin);
				return (1);
			}
		}
		else
		{
			fd[0] = -1;
			fd[1] = -1;
		}
		pid = fork();
		if (pid == -1)
		{
			if (fd_stdin != 0)
				close(fd_stdin);
			if (fd[1] != -1)
			{
				close(fd[0]);
				close(fd[1]);
			}
			return (1);
		}
		if (pid == 0)
		{
			if (fd_stdin != 0)
			{
				dup2(fd_stdin, 0);
				close(fd_stdin);
			}
			if (fd[1] != -1)
			{
				dup2(fd[1], 1);
				close(fd[1]);
				close(fd[0]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (fd_stdin != 0)
			close(fd_stdin);
		if (fd[1] != -1)
			close(fd[1]);
		fd_stdin = fd[0];
		i++;
	}
	if (fd_stdin != 0)
		close(fd_stdin);
	while (wait(&status) > 0)
		;
	return (0);
}
