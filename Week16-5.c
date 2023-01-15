#include<stdio.h>
#include<string.h>

int main()
{
    int n,m,i = 1;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n == 0 || m == 0)
            break;
        char a[n+2][m+2],c;
        scanf("%c",&c);
        for(int i = 0;i < n+2;i++)
            for(int j = 0;j < m+2;j++)
                a[i][j] = '.';
        for(int i = 1;i < n+1;i++)
            gets(a[i]+1);
        for(int i = 1;i < n+1;i++)
            for(int j = 1;j < m+1;j++)
                if(a[i][j] == '*')
                {
                    if(a[i][j+1] != '*')
                        a[i][j+1]++;
                    if(a[i][j-1] != '*')
                        a[i][j-1]++;
                    if(a[i+1][j] != '*')
                        a[i+1][j]++;
                    if(a[i-1][j] != '*')
                        a[i-1][j]++;
                    if(a[i+1][j+1] != '*')
                        a[i+1][j+1]++;
                    if(a[i-1][j+1] != '*')
                        a[i-1][j+1]++;
                    if(a[i+1][j-1] != '*')
                        a[i+1][j-1]++;
                    if(a[i-1][j-1] != '*')
                        a[i-1][j-1]++;
                }
        printf("Field #%d:\n",i);
        for(int i = 1;i < n+1;i++)
        {
            for(int j = 1;j < m+1;j++)
                if(a[i][j] != '*')
                    printf("%d",(a[i][j] - 46));
                else
                    printf("*");
            printf("\n");
        }
        printf("\n");
        i++;
    }
    return 0;
}
