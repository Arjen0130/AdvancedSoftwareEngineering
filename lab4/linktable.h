/**************************************************************************************************/
/* Copyright (C) 2017 ZhangRunjie. All rights reserved.                                           */
/*                                                                                                */
/*  FILE NAME              :   linktable.h                                                        */
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

#ifndef _LINK_TABLE_H
#define _LINK_TABLE_H

#define SUCCESS    0
#define FAILURE    (-1)

/*
 *  LinkTable Node Type
 */
typedef struct LinkTableNode
{
    struct LinkTableNode * pNext;
}tLinkTableNode;

/*
 *  LinkTable Type
 */
typedef struct LinkTable
{
    tLinkTableNode * pHead;
    tLinkTableNode * pTail;
    int sumOfNode;
}tLinkTable;

/*
 *  Create a LinkTable
 *  return value: A poiner points to the created LinkTable
 */
tLinkTable * CreateLinkTable();

/*
 *  Delete a LinkTable, and free the memory
 *  return value: Always zero
 */
int DeleteLinkTable(tLinkTable * pLinkTable);

/*
 *  Add a LinkTableNode to LinkTable
 *  return value: If success, return zero, otherwise return one
 */
int AddLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

/*
 *  Delete a LinkTableNode from LinkTable, but it will not free the memory
 *  return value: If success, return zero, otherwise return one
 */
int DeleteLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

/*
 *  Get LinkTableHead
 *  return value: If success, return the pointer to the head node, otherwise return NULL
 */
tLinkTableNode * GetLinkTableHead(tLinkTable * pLinkTable);

/*
 *  Get Next LinkTableNode
 *  return value: If the next node exists, return the pointer to that node, otherwise return NULL
 */
tLinkTableNode * GetNextLinkTableNode(tLinkTable * pLinkTable, tLinkTableNode * pNode);

#endif  //_LINK_TABLE_H
