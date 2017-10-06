/**************************************************************************************************/
/* Copyright (C) 2017 ZhangRunjie. All rights reserved.                                           */
/*                                                                                                */
/*  FILE NAME              :   linktable.c                                                        */
/*  PRINCIPAL AUTHOR       :   ZhangRunjie                                                        */
/*  SUBSYSTEM NAME         :   linktable                                                          */
/*  MODULE NAME            :   linktable                                                          */
/*  LANGUAGE               :   C                                                                  */
/*  TARGET ENVIRONMENT     :   ANY                                                                */
/*  DATE OF FIRST RELEASE  :   2017/10/06                                                         */
/*  DESCRIPTION            :   This is a module of menu                                           */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by ZhangRunjie, 2017/10/06
 *
 */


#include <stdlib.h>

#include "linktable.h"

/*
 *  Create a LinkTable
 *  return value: If success, return the poiner points to the created LinkTable, otherwise return NULL
 */
tLinkTable * CreateLinkTable()
{
    tLinkTable * p = (tLinkTable *)malloc(sizeof(tLinkTable));
    if(NULL == p)
        return NULL;
    p->pHead = NULL;
    p->pTail = NULL;
    p->sumOfNode = 0;
    return p;
}

/*
 *  Delete a LinkTable, and free the memory
 *  return value: Always zero
 */
int DeleteLinkTable(tLinkTable * pLinkTable)
{
    if(NULL == pLinkTable)
        return 0;
    tLinkTableNode * pNode = pLinkTable->pHead;
    tLinkTableNode * pHead = pNode;
    while(NULL != pNode)
    {
        pHead = pHead->pNext;
        free(pNode);
        pNode = pHead;
    }
    free(pLinkTable);
    return 0;
}

/*
 *  Add a LinkTableNode to LinkTable
 *  return value: If success, return zero, otherwise return one
 */
int AddLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
    if((NULL == pLinkTable) || (NULL == pNode))
        return 1;
    
    tLinkTableNode * pHead = pLinkTable->pHead;
    tLinkTableNode * pTail = pLinkTable->pTail;

    pNode->pNext = NULL;
    
    if(NULL == pHead)
    {
       pLinkTable->pHead = pLinkTable->pTail = pNode;
    }
    else
    {
        pLinkTable->pTail->pNext = pNode;
        pLinkTable->pTail = pNode;
    }
    pLinkTable->sumOfNode += 1;
    return 0;
}

/*
 *  Delete a LinkTableNode from LinkTable, but it will not free the memory
 *  return value: If success, return zero, otherwise return one
 */
int DeleteLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
    if((NULL == pLinkTable) || (NULL == pNode))
        return 1;
    
    tLinkTableNode * pHead = pLinkTable->pHead;
    int sumOfNode = pLinkTable->sumOfNode;

    if(0 == sumOfNode)
    {
        return 0;
    }
    else if(1 == sumOfNode)
    {
        if(pNode == pHead)
        {
            pLinkTable->pHead = pLinkTable->pTail = NULL;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if(pNode == pHead)
        {
            pLinkTable->pHead = pLinkTable->pHead->pNext;
            return 0;
        }
        else
        {
            tLinkTableNode * pPreNode = pHead;
            tLinkTableNode * pCurNode = pHead->pNext;
            while(NULL != pCurNode)
            {
                if(pNode == pCurNode)
                {
                    pPreNode->pNext = pCurNode->pNext;
                    return 0;
                }
                pPreNode = pCurNode;
                pCurNode = pCurNode->pNext;
            }
            return 0;
        }
    }
}

/*
 *  Get LinkTableHead
 *  return value: If success, return the pointer to the head node, otherwise return NULL
 */
tLinkTableNode * GetLinkTableHead(tLinkTable * pLinkTable)
{
    if(NULL == pLinkTable)
        return NULL;
    return pLinkTable->pHead;
}

/*
 *  Get Next LinkTableNode
 *  return value: If the next node exists, return the pointer to that node, otherwise return NULL
 */
tLinkTableNode * GetNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode)
{
    if((NULL == pLinkTable) || (NULL == pNode))
    {
        return NULL;
    }

    tLinkTableNode * pCurNode = pLinkTable->pHead;
    
    while(NULL != pCurNode)
    {
        if(pNode == pCurNode)
        {
            return pCurNode->pNext;
        }
    }
    return NULL;
}
