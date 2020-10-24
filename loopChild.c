#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
	for(int i=0; i<12; i++){
		pid_t pid = fork();

		if(pid == 0){
			printf("Child process => PPID=%d. PPID=%d \n",getppid(), getpid());
			exit(0);
		}
		else{
			printf("Parent process => PID=%d \n", getpid());
			printf("Waiting for child processes to finish...\n");
			wait(NULL);
			printf("Child process finished. \n");
		}
	}

	return EXIT_SUCCESS;
}
