/**************************************************************************************************/
/* Copyright (C) 2017 ZhangRunjie. All rights reserved.                                           */
/*                                                                                                */
/*  FILE NAME              :   menu.c                                                             */
/*  PRINCIPAL AUTHOR       :   ZhangRunjie                                                        */
/*  SUBSYSTEM NAME         :   menu                                                               */
/*  MODULE NAME            :   menu                                                               */
/*  LANGUAGE               :   C                                                                  */
/*  TARGET ENVIRONMENT     :   ANY                                                                */
/*  DATE OF FIRST RELEASE  :   2017/09/20                                                         */
/*  DESCRIPTION            :   This is a menu program                                             */
/**************************************************************************************************/

/*
 * Revision log:
 *    2017/10/05, make the program to be modularization.
 *
 * Created by ZhangRunjie, 2017/09/20
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linklist.h"
#include "help.h"
#include "read.h"
#include "write.h"
#include "get.h"
#include "pull.h"
#include "push.h"
#include "compare.h"
#include "put.h"
#include "quit.h"


#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

tDataNode head[] =
{
    {"help", "this is help cmd.", help, &head[1]},
    {"read", "this is read cmd.", read, &head[2]},
    {"write", "this is write cmd", write, &head[3]},
    {"get", "this is get cmd", get, &head[4]},
    {"pull", "this is pull cmd", pull, &head[5]},
    {"push", "this is push cmd", push, &head[6]},
    {"compare", "this is compare cmd", compare, &head[7]},
    {"put", "this is put cmd", put, &head[8]},
    {"quit", "this is quit cmd", quit, NULL}
};


int main()
{
    char cCmd[CMD_MAX_LEN];
    
    while(1)
    {
        printf("Input a cmd > ");
        scanf("%s", cCmd);
        tDataNode *p = FindCmd(head, cCmd);
        if (NULL == p)
        {
            printf("Undefined command...\n");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc);
        if(NULL != p->handler)
        {
            p->handler();
        }
    }
    return 0;
}
