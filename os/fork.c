#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    printf("hehe,from %d\n",getpid());

    char* p = malloc(sizeof(char));
    int rc = fork();

    if(rc < 0) printf("forkfail!\n");
    else if (rc == 0) printf("iamchild,pid=%d,%d\n",getpid(),(int)p);
    else printf("iamfather,pid=%d,%d\n",getpid(),(int)p);

    return 0;
}
