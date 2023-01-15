#include<stdio.h>
#include<ctype.h>

int main()
{
    char a[1000];
    int temp,sum,num,flag,max;
    while(scanf("%c",&a[0]) != EOF)
    {
        flag = 0;
        sum = 0;
        max = 1;
        gets(&a[1]);
        for(int i = 0;a[i] != '\0';i++)
        {
            if(isdigit(a[i]))
            {
                temp = a[i] - 48;
                flag = 1;
            }
            else if(isupper(a[i]))
            {
                temp = a[i] - 55;
                flag = 1;
            }
            else if(islower(a[i]))
            {
                temp = a[i] - 61;
                flag = 1;
            }
            if(flag == 1)
            {
                sum += temp;
                if(temp > max)
                    max = temp;
            }
            flag = 0;
        }
        for(int i = max;i < 62;i++)
            if(sum%i == 0)
            {
                printf("%d\n",i+1);
                flag=1;
                break;
            }
        if(flag==0)
            printf("such number is impossible!\n");
    }
    return 0;
}
