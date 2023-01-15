#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q_state = 0,k_state = 0,q_move = 0;
    while(scanf("%d%d%d",&k_state,&q_state,&q_move)!=EOF)
    {
        if(k_state == q_state)
            cout<<"Illegal state"<<endl;
        else if((k_state == 0 && q_move == 9) || (k_state == 7 && q_move == 14) ||
                    (k_state == 56 && q_move == 49) || (k_state == 63) && (q_move == 54))
            cout<<"Stop"<<endl;
        else if((k_state == q_move || q_state == q_move)||(q_state%8!= q_move% 8 && q_state/ 8 != q_move / 8)||
                    ((k_state > q_state)&&(k_state%8 == q_state%8) &&(q_move>k_state)&&(q_move%8 == q_state%8))||
                    ((k_state < q_state)&&(k_state%8 == q_state%8) &&(q_move<k_state)&&(q_move%8 == q_state%8)) ||
                    ((k_state > q_state)&&(k_state/8 == q_state/8) &&(q_move>k_state)&&(q_move/8 == q_state/8))||
                    ((k_state < q_state)&&(k_state/8 == q_state/8) &&(q_move<k_state)&&(q_move/8 == q_state/8)))
            cout<<"Illegal move"<<endl;
        else if((k_state+1 == q_move && q_move % 8 != 0 ) || (k_state-1 == q_move && q_move % 8 != 7) || (k_state-8 == q_move) || k_state+8 == q_move)
            cout<<"Move not allowed"<<endl;
        else
            cout<<"Continue"<<endl;
    }
}

