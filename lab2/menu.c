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
 *
 * Created by ZhangRunjie, 2017/09/20
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "help.h"
#include "read.h"
#include "write.h"
#include "get.h"
#include "pull.h"
#include "push.h"
#include "compare.h"
#include "put.h"

int main()
{
    char cCmd[128];
    
    while(1)
    {
        scanf("%s", cCmd);
        if(0 == strcmp(cCmd, "help"))
        {
            help();
        }
        else if(0 == strcmp(cCmd, "read"))
        {
            read();
        }
        else if(0 == strcmp(cCmd, "write"))
        {
            write();
        }
        else if(0 == strcmp(cCmd, "get"))
        {
            get();
        }
        else if(0 == strcmp(cCmd, "pull"))
        {
            pull();
        }
        else if(0 == strcmp(cCmd, "push"))
        {
            push();
        }
        else if(0 == strcmp(cCmd, "compare"))
        {
            compare();
        }
        else if(0 == strcmp(cCmd, "put"))
        {
            put();
        }
        else if(0 == strcmp(cCmd, "quit"))
        {
            exit(0);
        }
        else
        {
            printf("Undefined command...\n");
        }
    }
    return 0;
}
