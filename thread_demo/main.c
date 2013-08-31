/*
* =====================================================================================
*
*       Filename:  main.c
*
*    Description:  
*
*        Version:  1.0
*        Created:  08/31/2013 12:32:49 PM
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  sunke (), sunke@sunniwell.net
*        Company:  Sunniwell
*
* =====================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *cb_foo()
{
    int i;

    for( i = 0 ; i < 10 ; i++ )
    {
        printf("I am in cb_foo,i = %d\n",i);
        sleep(1);
    }
    
    return NULL;
}


int main(int argc, char *argv[])
{
    pthread_t tid;
    int i;

    pthread_create(&tid,NULL,cb_foo,0);

    for( i = 0 ; i < 10 ; i++ )
    {
        printf("I am i main,i = %d\n",i);
        sleep(1);
    }
    
    pthread_join(tid,NULL);

    return 0;
}
