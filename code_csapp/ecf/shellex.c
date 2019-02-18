#include "csapp.h"
#define MAXARGS 128


void eval(char* cmdline);
int parseline(char* buf, char** argv);
int builtin_command(char** argv);

int main() 
{
    char cmdline[MAXLINE];

    while (1) {
        //Read
        printf("> ");
        Fgets(cmdline, MAXLINE, stdin);
        if (frof(stdin))
            exit(0);
        
        // evaluate
        eval(cmdline);
    }
}

// eval
void eval(char* cmdline)
{
    char *argv[MAXARGS]; // Argument list execve()
    char buf[MAXLINE];    // Holds modified command line
    int bg;              // should the job run in bg or fg?
    pid_t pid;

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
        return; // Ignore empty lines
    
    if (!builtin_command(argv)) {
        if ((pid = Fork()) == 0) {
            if (execve(argv[0], argv, environ) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }

        // Parent waits for foreground job to terminate
        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0) <0)
                unix_error("waitfg: waitpid error");
        } 
        else
            printf("%d %s", pid, cmdline);
    }
    return;
}

//
int builtin_command(char** argv) 
{
    if (!strcmp(argv[0], "quit"))
        exit(0);
    if (!strcmp(argv[0], "&"))
        return 1;
    return 0;
}

int parseline(char* buf, char** argv)
{
    char *delim;
    int argc;
    int bg;

    buf[strlen(buf) - 1] = ' ';
    while (*buf && (*buf == ' '))
        buf++;

    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))
        buf++;
    }
    argv[argc] = NULL;

    if (argc == 0)
        return 1;

    if ((bg = (*argv[argv - 1] == '&')) != 0)
        argv[--argc] = NULL;

    return bg;
}