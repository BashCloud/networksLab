#include<stdio.h>
#define infinity 999
prev[10]={-1};
void path(int i)
{
    if(prev[i]==-1)
        return;
    path(prev[i]);
    printf("%d -> ",prev[i]);
}

void main(){
    int size,matrix[10][10],i,j,source,dist[10],prev[10]={-1},min;
    printf("Enter total number of nodes: ");
    scanf("%d",&size);
    printf("Initialize Adjacency matrix: \n");

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Entered Adjacency Matrix is: \n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("Enter the source Node: ");
    scanf("%d",&source);
    for(i=0;i<size;i++)
    {
        if(i==source)
            dist[i]=0;
        else
            dist[i]=infinity;
    }
    min=source;
    for(i=0;i<size;i++)
    {
        source=min;
        min=-1;//not defined
        for(j=0;j<size;j++)
        {
            if(matrix[source][j]>0)//has weight
            {
                if(dist[j]>matrix[source][j]+dist[source])
                {
                    dist[j]=matrix[source][j]+dist[source];
                    prev[j]=source;
                }
            }
            if(min==-1 && dist[j]>=dist[source])
                min=j;
            if(dist[j]<dist[min] && dist[j]>=dist[source])
                min=j;
        }
    }
    printf("distances of each node from Source Node: \n");
    printf("Node\t|Distance\t|Path Followed\n");
    for(i=0;i<size;i++){
        printf("%d \t| %d\t\t|",i,dist[i]);
        path(i);
        printf("\n");
    }
}
