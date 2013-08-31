#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sfd,cfd;
    struct sockaddr_in s_add,c_add;
    int sin_size;
    unsigned short portnum = 8888;
    char message[1024];

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sfd)
    {
        printf("socket fail !\n");
        return -1;
    }

    bzero(&s_add,sizeof(struct sockaddr_in));
    s_add.sin_family = AF_INET;
    s_add.sin_addr.s_addr = htonl(INADDR_ANY);
    s_add.sin_port = htons(portnum);

    if(-1 == bind(sfd,(struct sockaddr *)(&s_add), sizeof(struct sockaddr)))
    {
        printf("bind fail !\r\n");
        return -1;
    }

    if(-1 == listen(sfd,5))
    {
        printf("listen fail !\r\n");
        return -1;
    }

    sin_size = sizeof(struct sockaddr_in);

    while(1)
    {
        cfd = accept(sfd, (struct sockaddr *)(&c_add), (socklen_t *)&sin_size);
        if(-1 == cfd)
        {
            printf("accept fail !\r\n");
            return -1;
        }
        printf("accept ok!\r\nServer start get connect from %#x : %#x\r\n",ntohl(c_add.sin_addr.s_addr),ntohs(c_add.sin_port));

        memset(message,0,sizeof(message));
        snprintf(message,sizeof(message)-1,"Hello,Server pid is %d",getpid());
        if(-1 == write(cfd,message,strlen(message)))
        {
            printf("write fail!\r\n");
            return -1;
        }
        printf("write ok!\r\n");
        close(cfd);
    }
    close(sfd);
    return 0;
}
