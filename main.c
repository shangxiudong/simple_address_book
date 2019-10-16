#include "my.h"

int main()
{
    char C;
    int i = 1;
    Link * Head;
     Head = CreatNewLink();
    while(i)
    {
	getchar();
        printf("please input number'0-9'to select function:\n");
        mainmenu();
        scanf(" %c",&C);
        switch(C){
            case'1':
                ShowLink(Head);
                break;
            case'2':
                     if(InsertLink(Head) ==OK)
                        InLink(Head);
                        break;
            case'3':
                DelLink(Head);
                break;
            case'4':
                SearchMenu(Head);
                break;
            case'5':
                FreeLink(Head);
                break;
            case'6':
                SearchLink(Head,3);
                break;
            case'7':
                SearchLink(Head,4);
                break;            
            case'8':
		LoadLink(Head);
                break;
            case'9':
                SaveLink(Head);
                break;
            case'0':
                Selectesc(Head); 
                i = 0;
            default:
                break;
        }
        getchar();
    }
    free(Head);
    return 0;
    
}

