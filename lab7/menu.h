
/**************************************************************************************************/
/* Copyright (C) zhangrunjie, 2017                                                                */
/*                                                                                                */
/*  FILE NAME             :  menu.h                                                               */
/*  PRINCIPAL AUTHOR      :  ZhangRunjie                                                          */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2017/10/31                                                           */
/*  DESCRIPTION           :  This is a interface of menu                                          */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by ZhangRunjie, 2017/10/31
 *
 */


/*
 * Add cmd to menu.
 * @cmd: Name of the cmd to be added.
 * @desc: Description of the cmd to be added.
 * @handler: A function handler which executes the cmd.
 * @return: Number reflects function status.
 */
int MenuConfig(char * cmd, char * desc, int (*handler)(int argc, char * argv[]));

/*
 * Menu Engine Execute.
 * @return: Number reflects function status.
 */
int ExecuteMenu();
