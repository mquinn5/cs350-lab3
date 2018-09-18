#include <unistd.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(){
	pid_t p_id = getpid();
	pid_t c_id = fork();
	if(c_id==0){ //if child
		c_id=getpid();
		printf(">>> IN CHILD: pid=%d\n", c_id);
		char * args[4];
		args[0]="ls";
		args[1]="-l";
		args[2]="-a";
		args[3]=NULL;
		execv("/bin/ls", args);
	} else { //if parent
		c_id = wait(NULL);
		printf(">>> In PARENT: successfully waited child (pid=%d)\n", c_id);
	}
	return 0;
}
