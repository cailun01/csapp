#ifndef __CSAPP__
#define __CSAPP__

#include <sys/types.h>
// fork() 函数

#include <sys/wait.h>
// waitpid, WNOHANG, WIFEXITED

#include <errno.h>
// ECHILD, EINTER

#include <stdio.h>
// fprintf() 函数

#include <stdlib.h>
// exit() 函数

#include <unistd.h>
// execve

void unix_error(char *msg);
pid_t Fork(void);

extern char **environ; /* Defined by libc */

#define	MAXLINE	 8192  /* Max text line length */
#define MAXBUF   8192  /* Max I/O buffer size */

#endif