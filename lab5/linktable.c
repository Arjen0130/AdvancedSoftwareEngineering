
/********************************************************************/
/* Copyright (C) SSE-USTC, 2012-2013                                */
/*                                                                  */
/*  FILE NAME             :  linktabe.c                             */
/*  PRINCIPAL AUTHOR      :  Mengning                               */
/*  SUBSYSTEM NAME        :  LinkTable                              */
/*  MODULE NAME           :  LinkTable                              */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2012/12/30                             */
/*  DESCRIPTION           :  interface of Link Table                */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Mengning,2012/12/30
 * Provide right Callback interface by Mengning,2012/09/17
 * Changed the SearchLinkTableNode function and make the interface to be more independabel, by ZhangRunjie, 2017/10/16
 *
 */

#include<stdio.h>
#include<stdlib.h>

#include"linktable.h"

/*
 * LinkTable Node Type
 */
typedef struct LinkTableNode
{
    struct LinkTableNode * pNext;
}tLinkTableNode;

/*
 * LinkTable Type
 */
typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int			SumOfNode;
    pthread_mutex_t mutex;
}tLinkTable;

/*
 * Create a LinkTable
 */
tLinkTable * CreateLinkTable()
{
    tLinkTable * pLinkTable = (tLinkTable *)malloc(sizeof(tLinkTable));
    if(pLinkTable == NULL)
    {
        return NULL;
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = 0;
    pthread_mutex_init(&(pLinkTable->mutex), NULL);
    return pLinkTable;
}
/*
 * Delete a LinkTable
 */
int DeleteLinkTable(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
    {
        return FAILURE;
    }
    while(pLinkTable->pHead != NULL)
    {
        tLinkTableNode * p = pLinkTable->pHead;
        pthread_mutex_lock(&(pLinkTable->mutex));
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        pLinkTable->SumOfNode -= 1 ;
        pthread_mutex_unlock(&(pLinkTable->mutex));
        free(p);
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = 0;
    pthread_mutex_destroy(&(pLinkTable->mutex));
    free(pLinkTable);
    return SUCCESS;		
}
/*
 * Add a LinkTableNode to LinkTable
 */
int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return FAILURE;
    }
    pNode->pNext = NULL;
    pthread_mutex_lock(&(pLinkTable->mutex));
    if(pLinkTable->pHead == NULL)
    {
        pLinkTable->pHead = pNode;
    }
    if(pLinkTable->pTail == NULL)
    {
        pLinkTable->pTail = pNode;
    }
    else
    {
        pLinkTable->pTail->pNext = pNode;
        pLinkTable->pTail = pNode;
    }
    pLinkTable->SumOfNode += 1 ;
    pthread_mutex_unlock(&(pLinkTable->mutex));
    return SUCCESS;		
}
/*
 * Delete a LinkTableNode from LinkTable
 */
int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return FAILURE;
    }
    pthread_mutex_lock(&(pLinkTable->mutex));
    if(pLinkTable->pHead == pNode)
    {
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        pLinkTable->SumOfNode -= 1 ;
        if(pLinkTable->SumOfNode == 0)
        {
            pLinkTable->pTail = NULL;	
        }
        pthread_mutex_unlock(&(pLinkTable->mutex));
        return SUCCESS;
    }
    tLinkTableNode * pTempNode = pLinkTable->pHead;
    while(pTempNode != NULL)
    {    
        if(pTempNode->pNext == pNode)
        {
            pTempNode->pNext = pTempNode->pNext->pNext;
            pLinkTable->SumOfNode -= 1 ;
            if(pLinkTable->SumOfNode == 0)
            {
                pLinkTable->pTail = NULL;	
            }
            pthread_mutex_unlock(&(pLinkTable->mutex));
            return SUCCESS;				    
        }
        pTempNode = pTempNode->pNext;
    }
    pthread_mutex_unlock(&(pLinkTable->mutex));
    return FAILURE;		
}

/*
 * Search a LinkTableNode from LinkTable
 * @pLinkTable: a pointer to the linkTable to be searched.
 * @int Conditon(tLinkTableNode * pNode): a pointer to a function used as judging condition.
 * @cmd: a pointer to a string used to test the node of the LinkTable.
 * @return: if find the matched node, then return it, else return NULL.
 */
tLinkTableNode * SearchLinkTableNode(tLinkTable *pLinkTable, int Conditon(tLinkTableNode * pNode, char * cmd), char * cmd)
{
    if((NULL == pLinkTable) || (NULL == Conditon) || (NULL == cmd))
    {
        return NULL;
    }
    tLinkTableNode * pNode = pLinkTable->pHead;
    //while(pNode != pLinkTable->pTail)  //This test condition will stop the loop when reaching the tail node.
    while(NULL != pNode)
    {    
        if(Conditon(pNode, cmd) == SUCCESS)
        {
            return pNode;				    
        }
        pNode = pNode->pNext;
    }
    return NULL;
}

/*
 * get LinkTableHead
 */
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    if(pLinkTable == NULL)
    {
        return NULL;
    }    
    return pLinkTable->pHead;
}

/*
 * get next LinkTableNode
 */
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
    if(pLinkTable == NULL || pNode == NULL)
    {
        return NULL;
    }
    tLinkTableNode * pTempNode = pLinkTable->pHead;
    while(pTempNode != NULL)
    {    
        if(pTempNode == pNode)
        {
            return pTempNode->pNext;				    
        }
        pTempNode = pTempNode->pNext;
    }
    return NULL;
}

