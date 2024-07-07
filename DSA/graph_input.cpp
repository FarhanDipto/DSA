#include<stdio.h>
int graph[120][120];

int main()
{
    int i,j,node,edge;
    printf("Enter the number of nodes: \n");
    scanf("%d",&node);

    printf("Enter the number of edges: \n");
    scanf("%d",&edge);

    int source,destination,weight;

    for(int i=1; i<=edge; i++)
    {
        scanf("%d%d%d",&source, &destination, &weight);
        graph[source][destination] = weight;
        graph[destination][source] = weight;
    }
    for(i=1; i<=node; i++)
    {
        for(j=1; j<=node; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }


return 0;

}