#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int cmdNum = 4;
char cmdArr[20][2][128] = {
    {"Help", "print all command"},
    {"Hello", "welcome you here"},
    {"Work", "do something"},
    {"SayNoCmd", "that command doesn't exist"},
};
int Help();
int Hello();
int Work();
int SayNoCmd();

int main()
{
    char cmd[128];
    while(1)
    {
        scanf("%s", cmd);
        if(strcmp(cmd, "help") == 0)
        {
            Help();
        }
        else if(strcmp(cmd, "hello") == 0)
        {
            Hello();
        }
        else if(strcmp(cmd, "work") == 0)
        {
            Work();
        }
        else if(strcmp(cmd, "exit") == 0)
        {
            exit(0);
        }
        else
        {
            SayNoCmd();
        }
    }

    return 0;
}

int Help()
{
    for(int i=0; i<cmdNum; i++)
    {
        printf("%- 20s %- 20s\n", cmdArr[i][0], cmdArr[i][1]);
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

int SayNoCmd()
{
    printf("No that command\n");
    return 0;
}
