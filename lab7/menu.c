
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
#include "menu.h"

int Help(int argc, char * argv[]);

#define CMD_MAX_LEN      128
#define CMD_MAX_ARGV_NUM 10
#define DESC_LEN         1024
#define CMD_NUM          10

//char cmd[CMD_MAX_LEN];

/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)(int argc, char * argv[]);
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
    pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}


/* menu program */

tLinkTable * head = NULL;


/*
 * Add cmd to menu.
 * @cmd: Name of the cmd to be added.
 * @desc: Description of the cmd to be added.
 * @handler: A function handler which executes the cmd.
 * @return: Number reflects function status.
 */
int MenuConfig(char * cmd, char * desc, int (*handler)(int argc, char * argv[]))
{
    tDataNode * pNode = NULL;
    if(NULL == head)
    {
        head = CreateLinkTable();
        pNode = (tDataNode *)malloc(sizeof(tDataNode));
        pNode->cmd = "help";
        pNode->desc = "Menu List:";
        pNode->handler = Help;
        AddLinkTableNode(head, (tLinkTableNode *)pNode);
    }
    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler;
    AddLinkTableNode(head, (tLinkTableNode *)pNode);
    return 0;
}


/*
 * Menu Engine Execute.
 * @return: Number reflects function status.
 */
int ExecuteMenu()
{
    /* cmd line begins */
    while(1)
    {
        int argc = 0;
        char *argv[CMD_MAX_ARGV_NUM];
        char cmd[CMD_MAX_LEN];
        char * pcmd = NULL;
        printf("Input a cmd > ");
        /* scanf("%s", cmd); */
        pcmd = fgets(cmd, CMD_MAX_LEN, stdin);
        if(NULL == pcmd)
        {
            continue;
        }
        /* convert cmd to argc/argv */
        pcmd = strtok(pcmd, " ");
        while((NULL != pcmd) && (CMD_MAX_ARGV_NUM > argc))
        {
            argv[argc++] = pcmd;
            pcmd = strtok(NULL, " ");
        }
        if(1 == argc)
        {
            int len = strlen(argv[0]);
            *(argv[0] + len - 1) = '\0';
        }
            
        tDataNode *p = FindCmd(head, argv[0]);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler(argc, argv);
        }
   
    }
}

int Help(int argc, char * argv[])
{
    ShowAllCmd(head);
    return 0; 
}
