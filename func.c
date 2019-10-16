# include "my.h"

//---------------------------纯靠靠?----------------------------------------
void ShowLink(Link* Head)
{
    Link *p;
    p = Head->next;
    while(1)
    {
	if(p != NULL)
	{
           	printf("name:%s\nsex:%c\nphone number:%s\netc:%s\n\n",p->name,p->sex,p->phonenum,p->etc);
            	p = p->next;
	}
	else
		break;
    }

}
//---------------------------靠靠?----------------------------------------
void *InLink(Link *Head)
{
    Link *p;
    p = Head->next;
    printf("**************************************\n");
    printf("input new contact name(do not larger than 20 bytes):");
    scanf("%s",p->name);
    fflush(stdin);
    if(strlen(p->name) > 20) {printf("the name is too large, please input again\n"); p = InLink(Head); return;}
    printf("please input sex('m'or'f'):");
    scanf(" %c",&(p->sex));
    if(p->sex != 'm' && p->sex != 'f') {printf("sex input wrong ,please input again\n"); p = InLink(Head); return;}
    printf("please input phone number(11 bytes):");
    scanf(" %s",p->phonenum);
    if(strlen(p->phonenum) != 11) {printf("phone number input wrong,please input again\n"); p = InLink(Head); return;}
    printf("please input other information(no more than 30 bytes):");
    scanf(" %s",p->etc);
    if(strlen(p->etc)  >30) {printf("other information is too large,please input again\n"); p = InLink(Head); return;}

}
//---------------------------insert the Link from head-----------------------------------------
int InsertLink(Link * Head)
{
    Link * p;
    p =  (Link *)malloc(sizeof(Link));
    if(p == NULL)
        return ERROR;
     p->next = Head->next;
     Head->next = p;
     return OK;
}
//---------------------------靠靠靠?----------------------------------------
void SearchLink(Link *Head,int i)
{
    Link *p,*q;
    q = Head->next;
    char a[21];
    switch(i){
        case 1:
            printf("please input name:");
            scanf(" %s",a);
            while(q)
            {
                    if(strcmp(q->name,a) == 0)
                    printf("name:%s\nsex:%c\nphone number:%s\netc:%s\n",q->name,q->sex,q->phonenum,q->etc);
                    q = q->next;
            }
             break;
        case 2:
            printf("please input phone number:");
            scanf("%s",a);
            while(q)
            {
                     if(strcmp(q->phonenum,a) == 0)
                    printf("name:%s\nsex:%c\nphone number:%s\netc:%s\n",q->name,q->sex,q->phonenum,q->etc);
                    q = q->next;
            }
            break;
        case 3:
            while(q)
            {
                     if(q->sex=='m' )
                    printf("name:%s\nsex:%c\nphone number:%s\netc:%s\n",q->name,q->sex,q->phonenum,q->etc);
                    q = q->next;
            }
            break;
        case 4:
            while(q)
            {
                     if(q->sex=='f' )
                    printf("name:%s\nsex:%c\nphone number:%s\netc:%s\n",q->name,q->sex,q->phonenum,q->etc);
                    q = q->next;
            }
            break;
        }
 
}
//---------------------------查找节点菜单-----------------------------------------
void SearchMenu(Link *Head)
{
    int i;
    printf("**************************************\n");
    printf("1.search by name \n2.search by phone number\n");
    printf("**************************************\n");
    scanf(" %d",&i);
    if(i == 1 || i ==2)
        {SearchLink(Head,i);}
    else
        {
            printf("please input 1 or 2!");
            SearchMenu(Head);
         }
}
//---------------------------按姓名删除链表节点-----------------------------------------
void DelLinkByName(Link *Head)
{
    Link *p,*q;
    p = Head;
    q = p->next;
    char a[21];
    printf("please input name:");
    scanf(" %s",a);
    while(q)
    {
        if(strcmp(q->name,a) == 0)
            {
                p ->next = q->next;
                q->next = NULL;
                free(q);
                printf("delete completed\n");
                return;
            }
        p = q;
        q = q->next;
    }
    if(q == NULL){
        printf("can not find this person\n");
        return;
    }

}
//---------------------------按电话号码删除链表节点-----------------------------------------
void DelLinkByPN(Link *Head)
{
    Link *p,*q;
    p = Head;
    q = p->next;
    char a[21];
    printf("please input phone number:");
    scanf(" %s",a);
    while(q)
    {
        if(strcmp(q->phonenum,a) == 0)
            {
                p ->next = q->next;
                q->next = NULL;
                free(q);
		printf("delete completed\n");
                return;
            }
        p = q;
        q = q->next;
    }
    if(q == NULL){
        printf("can not find this person\n");
        return;
    }

}
//---------------------------删除某个链表信息-----------------------------------------
void DelLink(Link *Head)
{
    int i = 0;
    printf("**************************************\n");
    printf("1.delete by name \n2.delete by phone number \n");
    printf("**************************************\n");
    scanf(" %d",&i);
    if(i ==1) {DelLinkByName(Head);}
    else if(i == 2){DelLinkByPN(Head);}
    else {
        printf("please input 1 or 2!\n");
        DelLink(Head);
    }
}
//---------------------------创建新链表头-----------------------------------------
Link * CreatNewLink()
{
    Link *Head;
    Head = (Link *)malloc(sizeof(Link));
    if(Head == NULL)
    {
        printf("creat failed");
        return NULL;
    }
    Head->next = NULL;
    return  Head;
}
//---------------------------释放链表-----------------------------------------
void FreeLink(Link *Head)
{
    Link *a,*b;
    a = Head->next;
    Head ->next = NULL;//take for an ask!!
    while(1)
    {
	if(a)
	{
	    b = a-> next;
	    a ->next = NULL;
	    free(a);
	    a = b;
	}
	else
	    break;
    }
}
//---------------------------将链表保存至文件-----------------------------------------
int SaveLink(Link * Head)
{
    Link *p;
    FILE *fp;
    fp = fopen("data.txt","wb+");
    if(fp == NULL)
    {
         printf("can not open backfile\n");
        return ERROR;
    }
    for(p = Head->next;p;p = p->next)
    {
	printf("%s's information has been stored\n",p->name);
        if(fwrite(p,sizeof(Link),1,fp) != 1)
            {
                printf("can not write backfile\n");
                return ERROR;
            }
      }
      fclose(fp);
      printf("save completed\n");

      return OK;
}

//---------------------------主菜单-----------------------------------------
void mainmenu()
{
    printf("**************************************\n");
    printf("1.show all contact's information\n2.insert contact \n3.delete one contact's information \n4.search contact's information \n5.clear all information\
     \n6.check all man's information \n7.check all woman's information \n8.reading contact's information from file \n9.save contact's information to file \n0.quit\n");
    printf("**************************************\n");
}
//--------------------------read information from file------------------------------------
void LoadLink(Link * Head)
{
    Link *p;
    FILE *fp;
    int i = 0;
    fp = fopen("data.txt","rb+");
    printf("open file success\n");
    if(fp == NULL)
    {
         printf("can not open backup file\n");
        return;
    }
    while(1)
    {
        if(InsertLink(Head) == OK)
            {
                p = Head->next;
		i = fread(p,sizeof(Link),1,fp);
		printf("%d\n",&i);
                 if((fgetc(fp)) == EOF)
                    {
                        Head->next = p->next;
                        p->next = NULL;
                        free(p);
			printf("get into file's tail\n");
                        break;
                    }
		printf("%d\n",&i);
            }
        else
            {
                printf("Load file failed\n");
                return;
            }
    }
    fclose(fp);
    printf("Load contact's information completed\n");

}
//---------------------------select save or quit-----------------------------------------
void Selectesc(Link *Head)
{
    int i = -1;
    printf("**************************************\n");
    printf("1.save information \n0.quit directly \n");
    printf("**************************************\n");
    scanf(" %d",&i);
    if(i ==1) 
    {
        if(SaveLink(Head) == OK) 
             {
                FreeLink(Head); 
             } 
        else
            Selectesc(Head);
    }
    else if(i ==0) 
    {
        FreeLink(Head);
    }
    else{
        printf("please input 1 or 0!");
        Selectesc(Head);
        }
}