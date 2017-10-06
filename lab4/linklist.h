/**************************************************************************************************/
/* Copyright (C) 2017 ZhangRunjie. All rights reserved.                                           */
/*                                                                                                */
/*  FILE NAME              :   linklist.h                                                         */
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


/*
 * data struct and its operations
 */
typedef struct DataNode
{
    struct DataNode * pNext;
    char * cmd;
    char * desc;
    void (*handler)();
}tDataNode;


/*
 * This function is used to find a cmd in the linklist and return the datanode pointer
 * @head: the header of linklist
 * @cmd: the command to be searched
 * return value: if matched, return pointer of the command; or else return NULL
 */
tDataNode * FindCmd(tDataNode * head, char * cmd);

/*
 *This function is used to show all cmd in listlist
 * @head: the header of linklist
 * return value: always zero
 */
int ShowAllCmd(tDataNode * head);
