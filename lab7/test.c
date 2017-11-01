
/**************************************************************************************************/
/* Copyright (C) zhangrunjie, 2017                                                                */
/*                                                                                                */
/*  FILE NAME             :  test.c                                                               */
/*  PRINCIPAL AUTHOR      :  ZhangRunjie                                                          */
/*  SUBSYSTEM NAME        :  test                                                                 */
/*  MODULE NAME           :  test                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2017/10/31                                                           */
/*  DESCRIPTION           :  This is a test program of menu                                       */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by ZhangRunjie, 2017/10/31
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include "menu.h"

#define MAX_OPTION_ARGUMENT_SIZE 128

/*
 *This function is used to process the "compare" command.
 */
int compare(int argc, char * argv[])
{
    int ch;
    char argA[MAX_OPTION_ARGUMENT_SIZE];
    char argB[MAX_OPTION_ARGUMENT_SIZE];
    printf("This is the compare command...\n");
    /* for(int i = 0; i < argc; i++) */
    /* { */
    /*     printf("The argv[%d] = %s\n", i, argv[i]); */
    /* } */
    /* printf("optind: %d\n", optind); */
    optind = 1;  //这句必不可少，否则，多次执行相同的参数时，会出现结果不一致的情况
    while((ch = getopt(argc, argv, "a:b:")) != -1)
    {
        printf("optind: %d\n", optind);
        switch(ch)
        {
        case 'a':
            printf("HAVE option: -a\n");
            printf("The argument of -a is %s\n", optarg);
            argA[0] = '\0';
            if(NULL != optarg)
            {
                memcpy(argA, optarg, strlen(optarg));
            }
            break;
        case 'b':
            printf("HAVE option: -b\n");
            printf("The argument of -b is %s\n", optarg);
            argB[0] = '\0';
            if(NULL != optarg)
            {
                memcpy(argB, optarg, strlen(optarg));
            }
            break;
        case '?':
            printf("Unknown option: %c\n", (char)optopt);
            break;
            
        }
    }
    return 0;
}

/*
 *This function is used to process the "get" command.
 */
int get(int argc, char * argv[])
{
    printf("This is the get command...\n");
    return 0;
}

/*
 *This function is used to process the "pull" command.
 */
int pull(int argc, char * argv[])
{
    printf("This is the pull command...\n");
    return 0;
}

/*
 *This function is used to process the "push" command.
 */
int push(int argc, char * argv[])
{
    printf("This is the push command...\n");
    return 0;
}

/*
 *This function is used to process the "put" command.
 */
int put(int argc, char * argv[])
{
    printf("This is the put command...\n");
    return 0;
}

/*
 *This function is used to quit the program.
 */
int quit(int argc, char * argv[])
{
    printf("This is the quit command...\n");
    exit(0);
}

int main(int argc, int * argv[])
{
    MenuConfig("compare", "compare cmd:", compare);
    MenuConfig("get", "get cmd:", get);
    MenuConfig("pull", "pull cmd:", pull);
    MenuConfig("push", "push cmd:", push);
    MenuConfig("put", "put cmd:", put);
    MenuConfig("quit", "quit Cmd:", quit); 
    return ExecuteMenu();
}
