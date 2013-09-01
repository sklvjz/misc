/*
* =====================================================================================
*
*       Filename:  check.h
*
*    Description:  
*
*        Version:  1.0
*        Created:  08/31/2013 01:02:29 PM
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  sunke (), sunke@sunniwell.net
*        Company:  Sunniwell
*
* =====================================================================================
*/
#ifndef _CHECK_H
#define _CHECK_H
/* headers used by a majority of the example program */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static void checkResults(char *string, int rc) {
    if (rc) {
        printf("Error on : %s, rc=%d\n",
               string, rc);
        exit(EXIT_FAILURE);
    }
    return;
}

#endif
