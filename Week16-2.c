#include<stdio.h>
#include<string.h>

int main()
{
	int test, i, j;
	char op;
	int az[26] = {0};
	scanf("%d",&test);
	scanf("%c",&op);
	while(test--)//scan string
	{
		char str[1001] = {0};
		gets(str);
		for(i = 0; i < strlen(str); i++)//toupper
			if(str[i] >= 'a' && str[i] <= 'z')
                str[i] += 'A'-'a';
		for(i = 0; i < strlen(str); i++)//count number
            if(str[i] >= 'A' && str[i] <= 'Z')
                az[str[i]-'A']++;
	}
	int max = 0 , count = 0;
	for (i = 0; i < 26; i++)//count the max
        if(az[i] > max)
            max = az[i];
    for (i = 0;i < 26;i++)//count total
        if(az[i] != 0)
        count++;
	for(j = max; j > 0; j--)
        for(i = 0; i < 26; i++)
            if(az[i] == j && count > 1)
            {
                printf("%c %d\n",'A'+i,j);
                count--;
            }
            else if (az[i] == j && count <= 1)
                printf("%c %d",'A'+i,j);
    return 0;
}
