#include<bits/stdc++.h>
using namespace std;
deque<int> target,answer,temp,temp1;
deque<deque<int>> out;
int main()
{
    int tag = 0,n,number,a = 0,b = 0,num;
    while(cin>>n && n!=0)
    {
        num = 0;
        tag++;
        for(int i = 0;i<n;i++)
        {
            cin>>number;
            target.push_back(number);
        }
        while(1)
        {
            for(int i = 0;i<n;i++)
                {
                    cin>>number;
                    answer.push_back(number);
                }
            if(answer[0] == 0)
            {
                answer.clear();
                break;
            }
            temp1 = target;
            for(int i = 0;i < n;i++)
                for(int j = 0;j < n;j++)
                    if(answer[i] == temp1[j] && i == j)
                    {
                        a++;
                        temp1[j] = 0;
                        answer[i] = -1;
                    }
            for(int i = 0;i < n;i++)
                for(int j = 0;j<n;j++)
                if(answer[i] == temp1[j] && i!= j)
                {
                    b++;
                   temp1[j] = 0;
                   answer[i] = -2;
                }
                temp.push_back(a);
                temp.push_back(b);
                out.push_back(temp);
                a= 0,b=0;
                num++;
            answer.clear();
            temp.clear();
        }
        cout<<"Game "<<tag<<":"<<endl;
        for(int i = 0;i < num;i++)
            cout<<"("<<out[i][0]<<","<<out[i][1]<<")"<<endl;
        target.clear();
        out.clear();
    }
}
