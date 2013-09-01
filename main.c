/*
* =====================================================================================
*
*       Filename:  main.c
*
*    Description:  
*
*        Version:  1.0
*        Created:  09/01/2013 08:46:55 AM
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  sunke (), sunke@sunniwell.net
*        Company:  Sunniwell
*
* =====================================================================================
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    printf("argc = %d\n",argc);

    for( i = 0 ; i < argc ; i++ )
    {
        printf("argv[%d]:%s\n",i,argv[i]);
    }
    
    return 0;
}
