#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

#define CMD_MAX_LEN 128
#define DESC_MAX_LEN 1024
#define CMD_NUM 10

int Help();
int Hello();
int Work();
int Quit();

static tDataNode ahead[] =
{
    {"help", "print all command", Help, &ahead[1]},
    {"hello", "welcome you here", Hello, &ahead[2]},
    {"work", "do something", Work, &ahead[3]},
    {"quit", "exit the program", Quit, NULL},
};

int main()
{
    char scmd[CMD_MAX_LEN];
    while(1)
    {
        scanf("%s", scmd);
        pDataNode pcmd = FindCmd(scmd, ahead);
        if(pcmd != NULL)
        {
            if(pcmd->handler != NULL)
            {
                pcmd->handler();
            }
        }
        else
        {
            printf("No that command\n");
        }
    }
    return 0;
}

int Help()
{
    pDataNode pcur = ahead;
    while(pcur != NULL)
    {
        printf("%- 20s %- 20s\n", pcur->scmd, pcur->sdesc);
        pcur = pcur->next;
    }
    return 0;
}

int Hello()
{
    printf("Hello\n");
    return 0;
}

int Work()
{
    printf("Work\n");
    return 0;
}

int Quit()
{
    exit(0);
}
