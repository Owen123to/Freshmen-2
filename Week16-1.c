#include<stdio.h>
#include<string.h>

int main()
{
    int number;
    scanf("%d\n",&number);
    int temp = number, spe[number];
    float num[10000][number] , temp1 ,sum[number];
    char tree[10000][number][31], temp2[31];
    while(temp--)//have total count
    {
        spe[temp] = 0;//every spe number
        sum[temp] = 0;//every sum number
        while(scanf("%c",&tree[spe[temp]][temp][0]) != EOF)//count spe  and every  num
        {
            if(tree[spe[temp]][temp][0] == '\n')
                break;
            gets(tree[spe[temp]][temp] + 1);
            num[spe[temp]][temp] = 1;
            sum[temp]++;
            for(int j = 0;j < spe[temp];j++)
                if(!strcmp(tree[j][temp],tree[spe[temp]][temp]))//same spe
                {
                    num[j][temp]++;
                    spe[temp]--;
                }
            spe[temp]++;
        }
        for(int i = spe[temp] - 1;i >= 0;i--)//bubble change
            for(int j = 0;j <= i - 1;j++)
                if(strcmp(tree[j][temp],tree[j+1][temp])>0)
                {
                    strcpy(temp2,tree[j][temp]);
                    strcpy(tree[j][temp],tree[j+1][temp]);
                    strcpy(tree[j+1][temp],temp2);
                    temp1 = num[j][temp];
                    num[j][temp] = num[j+1][temp];
                    num[j+1][temp] = temp1;
                }
    }
    while(number--)
    {
        for(int i = 0;i < spe[number];i++)
            if(number != 0 || i != spe[number] - 1)
                printf("%s %0.4f\n",tree[i][number],num[i][number]*100/sum[number]);
            else
                printf("%s %0.4f",tree[i][number],num[i][number]*100/sum[number]);
        if(number != 0)
            printf("\n");
    }
    return 0;
}
