#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]) {
int pipefd;
pid_t cid;
pipe(pipefd);
cid = fork();

if (cid == 0) {
close(pipefd[1]);
display_nc();
while (read(pipefd[0], &buf, 1)) {
write(1, "\n", 1);
}
close(pipefd[1]);


}

else {

}

}
