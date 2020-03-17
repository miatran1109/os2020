#include <stdio.h>
#include <unistd.h>

int main ()
{
    printf("New c program");
    int pid = fork();
	if (pid == 0) 
	{
		int pid1 = fork(); 
		if (pid1 == 0) 
		{
			printf("I am child after fork(), launching ps -ef\n");
			char *args[] = {"/bin/ps", "-ef", NULL};
			execvp("/bin/ps", args); 
		}
		else {
			printf("I am parent after fork(), child is %d\n", pid1);
		}
		printf("I am child after fork(), launching free -h\n");
		char *args[] = {"free", "-h", NULL};
		execvp("free", args); 
	}
	else {
		printf("I am parent after fork(), child is %d\n", pid);
	}
	return 0;
}

