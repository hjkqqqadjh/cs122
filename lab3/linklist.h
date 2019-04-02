#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DataNode
{
    char* scmd;
    char* sdesc;
    int (*handler)();
    struct DataNode* next;
}tDataNode, *pDataNode;

pDataNode FindCmd(char* scmd, pDataNode ahead)
{
    pDataNode pcur = ahead;
    while(pcur != NULL)
    {
        if(strcmp(scmd, pcur->scmd) == 0)
        {
            return pcur;
        }
        pcur = pcur->next;
    }
    return NULL;
}
