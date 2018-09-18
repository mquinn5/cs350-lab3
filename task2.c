#include <unistd.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char**argv){
	pid_t p_id = getpid();
	pid_t c_id = fork();
	if(c_id==0){ //if child
		c_id=getpid();
		printf(">>> IN CHILD: pid=%d\n", c_id);
		char * args[argc];
		for(int i=0; i<argc-1; i++)
			args[i]=argv[i+1];
		args[argc]=NULL;
		execvp(argv[1], args);
	} else { //if parent
		c_id = wait(NULL);
		printf(">>> In PARENT: successfully waited child (pid=%d)\n", c_id);
	}
	return 0;
}
