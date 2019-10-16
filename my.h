#ifndef __MY_H__
#define __MY_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 0
#define OK 1

typedef struct  Link{
    char name[21];
    char sex;
    char phonenum[12];
    char etc[31];
    struct Link *next;
}Link;

void ShowLink(Link* Head);
void *InLink(Link *Head);
int InsertLink(Link * Head);
void SearchLink(Link *Head,int i);
void SearchMenu(Link *Head);
void DelLinkByName(Link *Head);
void DelLinkByPN(Link *Head);
void DelLink(Link *Head);
Link * CreatNewLink();
void FreeLink(Link *Head);
int SaveLink(Link * Head);
void mainmenu();
void LoadLink(Link * Head);
void Selectesc(Link *Head);
#endif