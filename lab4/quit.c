/**************************************************************************************************/
/* Copyright (C) 2017 ZhangRunjie. All rights reserved.                                           */
/*                                                                                                */
/*  FILE NAME              :   quit.c                                                             */
/*  PRINCIPAL AUTHOR       :   ZhangRunjie                                                        */
/*  SUBSYSTEM NAME         :   quit                                                               */
/*  MODULE NAME            :   quit                                                               */
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


#include <stdio.h>
#include <stdlib.h>

#include "linktable.h"

extern tLinkTable * pLinkTable;

/*
 *This function is used to process the "quit" command.
 */
void quit()
{
    DeleteLinkTable(pLinkTable);
    exit(0);
}
