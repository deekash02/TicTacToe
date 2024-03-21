#include<bits/stdc++.h>
using namespace std;
char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row, col;
char token = 'x';
string n1;
string n2;
bool draw;
void fun1()
{
    cout<<"         |         |         \n";
    cout<<"    " <<space[0][0] <<"    |"<<"    "<<space[0][1] <<"    |"<<"    "<<space[0][2] <<"          \n";
    cout<<"_________|_________|_________\n";
    cout<<"         |         |          \n";
    cout<<"    " <<space[1][0] <<"    |"<<"    "<<space[1][1] <<"    |"<<"    "<<space[1][2] <<"          \n";
    cout<<"_________|_________|_________\n";
    cout<<"         |         |          \n";
    cout<<"    " <<space[2][0] <<"    |"<<"    "<<space[2][1] <<"    |"<<"    "<<space[2][2] <<"          \n";
    cout<<"         |         |          \n";
}
void fun2()
{
    int digit;
    if(token=='x')
    {
        cout<<n1<<" please enter "<<endl;
        cin>>digit;
    }
    if(token=='0')
    {
        cout<<n2<<" please enter "<<endl;
        cin>>digit;
    }

    if(digit==1)
    {
        row=0; col=0;
    }
    if(digit==2)
    {
        row=0; col=1;
    }
    if(digit==3)
    {
        row=0; col=2;
    }
    if(digit==4)
    {
        row=1; col=0;
    }
    if(digit==5)
    {
        row=1; col=1;
    }
    if(digit==6)
    {
        row=1; col=2;
    }
    if(digit==7)
    {
        row=2; col=0;
    }
    if(digit==8)
    {
        row=2; col=1;
    }
    if(digit==9)
    {
        row=2; col=2;
    }
    else if(digit<1 && digit>9)
    cout<<"Invalid position entered "<<endl;
    if(token=='x' && space[row][col]!='x' && space[row][col]!='0')
    {
        space[row][col]='x';
        token = '0';
    }
    else if(token=='0' && space[row][col]!='x' && space[row][col]!='0')
    {
        space[row][col]='0';
        token = 'x';
    }
    else
    {
        cout<<"There is no empty space "<<endl;
        fun3();
    }
    //fun1();
}

bool fun3()
{
    for(int i=0; i<3; i++)
    {
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        return true;
    }

    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[0][2]==space[2][0])
    return true;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(space[i][j]!='x'&& space[i][j]!='0')
            return false;
        }
    }
    draw = true;
    return false;
}
int main()
{
    cout<<"Enter player 1 name: "<<endl;
    getline(cin, n1);
    cout<<"Enter player 2 name: "<<endl;
    getline(cin, n2);
    while(!fun3())
    {
        fun1();
        fun2();
        fun3();
    }
    if(token=='x' && draw==false)
    cout<<n2<<" Wins!!"<<endl;
    else if(token=='0' && draw==false)
    cout<<n1<<" wins!!"<<endl;

    else
    cout<<"It's a draw!"<<endl;

    return 0;
}