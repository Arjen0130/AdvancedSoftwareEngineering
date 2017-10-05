/**************************************************************************************************/
/* Copyright (C) 2017 ZhangRunjie. All rights reserved.                                           */
/*                                                                                                */
/*  FILE NAME              :   linklist.c                                                         */
/*  PRINCIPAL AUTHOR       :   ZhangRunjie                                                        */
/*  SUBSYSTEM NAME         :   linklist                                                           */
/*  MODULE NAME            :   linklist                                                           */
/*  LANGUAGE               :   C                                                                  */
/*  TARGET ENVIRONMENT     :   ANY                                                                */
/*  DATE OF FIRST RELEASE  :   2017/10/05                                                         */
/*  DESCRIPTION            :   This is a module of menu                                           */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by ZhangRunjie, 2017/10/05
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"


/*
 * This function is used to find a cmd in the linklist and return the datanode pointer
 * @head: the header of linklist
 * @cmd: the command to be searched
 * return value: if matched, return pointer of the command; or else return NULL
 */
tDataNode * FindCmd(tDataNode * head, char * cmd)
{
    if((NULL == head) || (NULL == cmd))
    {
        return NULL;
    }
    
    tDataNode *p = head;

    while(NULL != p)
    {
        if(0 == strcmp(p->cmd, cmd))
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}


/*
 *This function is used to show all cmd in listlist
 * @head: the header of linklist
 * return value: always zero
 */
int ShowAllCmd(tDataNode * head)
{
    printf("Menu List:\n");

    tDataNode *p = head;

    while(NULL != p)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}
