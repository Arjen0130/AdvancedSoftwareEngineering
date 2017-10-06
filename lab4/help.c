/**************************************************************************************************/
/* Copyright (C) 2017 ZhangRunjie. All rights reserved.                                           */
/*                                                                                                */
/*  FILE NAME              :   help.c                                                             */
/*  PRINCIPAL AUTHOR       :   ZhangRunjie                                                        */
/*  SUBSYSTEM NAME         :   help                                                               */
/*  MODULE NAME            :   help                                                               */
/*  LANGUAGE               :   C                                                                  */
/*  TARGET ENVIRONMENT     :   ANY                                                                */
/*  DATE OF FIRST RELEASE  :   2017/09/20                                                         */
/*  DESCRIPTION            :   This is a module of menu                                           */
/**************************************************************************************************/

/*
 * Revision log:
 *    2017/10/06, change the help command
 *
 * Created by ZhangRunjie, 2017/09/20
 *
 */


#include <stdio.h>
#include "help.h"
#include "linklist.h"

extern tDataNode * head;

/*
 *This function is used to process the "help" command.
 */
void help()
{
    printf("This is the help command...\n");
    ShowAllCmd(head);
}
