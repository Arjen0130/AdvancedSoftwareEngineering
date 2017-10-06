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
 *    2017/10/06, make the program to be modularization with using the linktable
 *
 * Created by ZhangRunjie, 2017/09/20
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linklist.h"
#include "linktable.h"
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
#define CMD_NUM     9

typedef struct CmdInfo
{
    char * cmd;
    char * desc;
    void (*handler)();
}tCmdInfo;

tLinkTable * pLinkTable = NULL;
tDataNode * head = NULL;

tCmdInfo cmdInfo[CMD_NUM] =
{
    {"help", "this is help cmd", help},
    {"read", "this is read cmd", read},
    {"write", "this is write cmd", write},
    {"get", "this is get cmd", get},
    {"pull", "this is pull cmd", pull},
    {"push", "this is push cmd", push},
    {"compare", "this is compare cmd", compare},
    {"put", "this is put cmd", put},
    {"quit", "this is quit cmd", quit}
};


/*
 *  Initialize the pLinkTable with the menu command
 */
void InitMenuTable(tLinkTable * pLinkTable);


int main()
{
    pLinkTable = CreateLinkTable();
    if(NULL == pLinkTable)
    {
        printf("CreateLinkTable Error...\n");
        exit(1);
    }
    InitMenuTable(pLinkTable);
    head = (tDataNode *)pLinkTable->pHead;

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


/*
 *  Initialize the pLinkTable with the menu command
 */
void InitMenuTable(tLinkTable * pLinkTable)
{
    for(int i = 0; i < CMD_NUM; i++)
    {
        tDataNode * pNode = (tDataNode *)malloc(sizeof(tDataNode));
        if(NULL == pNode)
        {
            printf("malloc Error...\n");
            exit(1);
        }
        pNode->cmd = (cmdInfo[i]).cmd;
        pNode->desc = (cmdInfo[i]).desc;
        pNode->handler = (cmdInfo[i]).handler;
        if(1 == AddLinkTableNode(pLinkTable, (tLinkTableNode *) pNode))
        {
            printf("AddLinkTableNode Error...\n");
            exit(1);
        }
    }
}

