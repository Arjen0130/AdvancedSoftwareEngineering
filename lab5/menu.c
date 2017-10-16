
/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Mengning                                                             */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/08/31                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning, 2014/08/31
 * Changed the SearchCondition and FindCmd function to make the program to be more Modularized, by ZhangRunjie, 2017/10/16
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"

int Help();
int Quit();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

//char cmd[CMD_MAX_LEN];

/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

/*
 * find the node is matched with the cmd or not.
 * @pLinkTableNode: a pointer to the node to be tested.
 * @cmd: a pointer to a string used to test the node.
 * @return: if matched
 */
int SearchCondition(tLinkTableNode * pLinkTableNode, char * cmd)
{
    if((NULL == pLinkTableNode) || (NULL == cmd))
    {
        return FAILURE;
    }
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;  
    }
    return FAILURE;	       
}

/* 
 * find a cmd in the linklist and return the datanode pointer.
 * @head: a pointer to the head of a LinkTable.
 * @cmd: a poiner to a string which indicates the name of the command.
 * @return: a pointer to a tDataNode that matched the cmd.
 */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition, cmd);
}

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int InitMenuData(tLinkTable ** ppLinktable)
{
    *ppLinktable = CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "Menu List:";
    pNode->handler = Help;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "version";
    pNode->desc = "Menu Program V1.0";
    pNode->handler = NULL; 
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "Quit from Menu Program V1.0";
    pNode->handler = Quit; 
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
 
    return 0; 
}

/* menu program */

tLinkTable * head = NULL;

int main()
{
    InitMenuData(&head); 
    /* cmd line begins */
    char cmd[CMD_MAX_LEN];
    while(1)
    {
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler();
        }
   
    }
}

int Help()
{
    ShowAllCmd(head);
    return 0; 
}

int Quit()
{
    exit(0);
}
