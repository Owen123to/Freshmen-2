#include<stdio.h>
#include<string.h>

int main()
{
    int n,count,k = 0;
    scanf("%d\n",&n);
    char a[n][28],b[n][20],temp[20];
    for(int i = 0;i < n;i++)
    {
        scanf("%s",a[i]);
        strcpy(b[i],a[i]);
        gets(a[i]+strlen(a[i]));
    }
    for(int i = 1;i < n;i++)//bubble national
        for(int j = 0;j < n - i;j++)
            if(strcmp(b[j],b[j+1]) > 0)
            {
                strcpy(temp,b[j]);
                strcpy(b[j],b[j+1]);
                strcpy(b[j+1],temp);
            }
    while(k < n)
    {
        count = 1;
        for(;k < n-1;k++)
        {
            if(strcmp(b[k],b[k+1]))
                break;
            count++;
        }
        printf("%s %d",b[k],count);
        k++;
        if(k != n)
            printf("\n");
    }
    return 0;
}
