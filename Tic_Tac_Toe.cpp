//This is a fully working Tic-Tac-Toe program in newly learnt C++. Enjoy the code and enjoy playing it.
#include <iostream>
using namespace std;

int print(char arr[3][3])
{
    cout<<" "<<arr[0][0]<<" "<<(char)179<<" "<<arr[0][1]<<" "<<(char)179<<" "<<arr[0][2]<<" "<<endl;
    cout<<(char)196<<(char)196<<(char)196<<(char)197<<(char)196<<(char)196<<(char)196<<(char)197<<(char)196<<(char)196<<(char)196<<endl;
    cout<<" "<<arr[1][0]<<" "<<(char)179<<" "<<arr[1][1]<<" "<<(char)179<<" "<<arr[1][2]<<" "<<endl;
    cout<<(char)196<<(char)196<<(char)196<<(char)197<<(char)196<<(char)196<<(char)196<<(char)197<<(char)196<<(char)196<<(char)196<<endl;
    cout<<" "<<arr[2][0]<<" "<<(char)179<<" "<<arr[2][1]<<" "<<(char)179<<" "<<arr[2][2]<<" "<<endl;
    return 0;
}


bool full(char arr[3][3])
{
    bool f = false;
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j]=='-')
                {count++;}
        }
    }
    if(count==0)
    {
        f=true;
    }
    return f;
}


bool win(char arr[3][3],const char ip)
{
    bool w = false;
    int c;

    for (int i = 0; i < 3; i++)     //For checking rows
    {
        c = 0;
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j]==ip)
            {c++;}
        }
        if(c==3)
        {
            w = true;
            return w;
        }
    }

    for (int i = 0; i < 3; i++)     //For checking columns
    {
        c = 0;
        for (int j = 0; j < 3; j++)
        {
            if(arr[j][i]==ip)
            {c++;}
        }
        if(c==3)
        {
            w = true;
            return w;
        }
    }

    c = 0;
    for (int i = 0; i < 3; i++)     //For checking diagonal 1
    {
        for (int j = 0; j < 3; j++)
        {
            if(i==j && arr[i][j]==ip)
            {c++;}
        }
        if(c==3)
        {
            w = true;
            return w;
        }
    }

    c = 0;
    for (int i = 0; i<3; i++)     //For checking diagonal 2
    {
        for (int j = 2; j>-1; j--)
        {
            if(i+j==2 && arr[i][j]==ip)
            {c++;}
        }
        if(c==3)
        {
            w = true;
            return w;
        }
    }
    return w;
}

bool winnable(char arr[3][3], char cip)
{
    bool w = false;
    int c, d;
    int x, y;

    for (int i = 0; i < 3; i++)     //For checking rows
    {//cout<<"q"<<endl;
        c = 0;
        d = 0;
        for (int j = 0; j < 3; j++)
        {//cout<<"1"<<endl;
            if(arr[i][j]==cip)
            {c++;}
            else if(arr[i][j]=='-')
            {
                d++;
                x = i;
                y = j;
            }
        }
        //cout<<c<<d;
        if(c==2 && d==1)
        {
            arr[x][y]= cip;
            w = true;
            return w;
        }
    }

    for (int i = 0; i < 3; i++)     //For checking columns
    {//cout<<"s"<<endl;
        c = 0;
        d = 0;
        for (int j = 0; j < 3; j++)
        {//cout<<"2"<<endl;
            if(arr[j][i]==cip)
            {c++;}
            else if(arr[j][i]=='-')
            {
                d++;
                x = j;
                y = i;
            }
        }
        if(c==2 && d==1)
        {
            arr[x][y]=cip;
            w = true;
            return w;
        }
    }

    c = 0;
    d = 0;
    for (int i = 0; i < 3; i++)     //For checking diagonal 1
    {//cout<<"t"<<endl;
        for (int j = 0; j < 3; j++)
        {
            if(i==j && arr[i][j]==cip)
            {c++;}
            else if(i==j && arr[i][j]=='-')
            {
                d++;
                x = i;
                y = j;
            }
        }
        if(c==2 && d==1)
        {
            arr[x][y]=cip;
            w = true;
            return w;
        }
    }

    c = 0;
    d = 0;
    for (int i = 0; i < 3; i++)     //For checking diagonal 2
    {//cout<<"u"<<endl;
        for (int j = 2; j >=0; j--)
        {
            if(i+j==2 && arr[i][j]==cip)
            {c++;}
            else if(i+j==2 && arr[i][j]=='-')
            {
                d++;
                x = i;
                y = j;
            }
        }
        if(c==2 && d==1)
        {
            arr[x][y]=cip;
            w = true;
            return w;
        }
    }
    return w;
}


bool prevention(char arr[3][3], char uip, char cip)
{
    bool w = false;
    int c, d;
    int x, y;

    for (int i = 0; i < 3; i++)     //For checking rows
    {
        c =0;
        d = 0;
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j]==uip)
            {c++;}
            else if(arr[i][j]=='-')
            {
                d++;
                x = i;
                y = j;
            }
        }
        if(c==2 && d==1)
        {
            arr[x][y]= cip;
            w = true;
            return w;
        }
    }

    for (int i = 0; i < 3; i++)     //For checking columns
    {
        c = 0;
        d = 0;
        for (int j = 0; j < 3; j++)
        {
            if(arr[j][i]==uip)
            {c++;}
            else if(arr[j][i]=='-')
            {
                d++;
                x = j;
                y = i;
            }
        }
        if(c==2 && d==1)
        {
            arr[x][y]=cip;
            w = true;
            return w;
        }
    }

    c = 0;
    d = 0;
    for (int i = 0; i < 3; i++)     //For checking diagonal 1
    {
        for (int j = 0; j < 3; j++)
        {
            if(i==j && arr[i][j]==uip)
            {c++;}
            else if(i==j && arr[i][j]=='-')
            {
                d++;
                x = i;
                y = j;
            }
        }
        if(c==2 && d==1)
        {
            arr[x][y]=cip;
            w = true;
            return w;
        }
    }

    c = 0;
    for (int i = 0; i < 3; i++)     //For checking diagonal 2
    {
        for (int j = 2; j >=0; j--)
        {
            if(i+j==2 && arr[i][j]==uip)
            {c++;}
            else if(i+j==2 && arr[i][j]=='-')
            {
                d++;
                x = i;
                y = j;
            }
        }
        if(c==2 && d==1)
        {
            arr[x][y]=cip;
            w = true;
            return w;
        }
    }
    return w;
}


bool next_move(char arr[3][3], char ip)        //Called from comp_move
{
    //cout<<"n"<<endl;
    if(arr[1][1]=='-')
    {//cout<<"o"<<endl;
        arr[1][1]=ip;}

    else if(arr[2][0]=='-')
    {//cout<<"p"<<endl;
        arr[2][0]=ip;}

    else if(arr[2][2]=='-')
    {arr[2][2]=ip;}

    else if(arr[0][2]=='-')
    {arr[0][2]=ip;}

    else if(arr[0][0]=='-')
    {arr[0][0]=ip;}

    else if(arr[2][1]=='-')
    {arr[2][1]=ip;}

    else if(arr[1][0]=='-')
    {arr[1][0]=ip;}

    else if(arr[0][1]=='-')
    {arr[0][1]=ip;}

    else if(arr[1][2]=='-')
    {arr[1][2]=ip;}
    return true;
}


int comp_move(char arr[3][3], char uip, char cip)       //Called from main
{
    //cout<<"j"<<endl;
    if(winnable(arr, cip))
    {//cout<<"k"<<endl;
        return 0;}

    else if(prevention(arr, uip, cip))
    {//cout<<"l"<<endl;
        return 0;}

    else
    {
        //cout<<"m"<<endl;
        next_move(arr,cip);
        return 0;
    }
}


int main()
{
    const char uip = 'x';
    const char cip = 'o';
    int r, c;
    bool won = false;
    bool full1 = false;
    char ttt[3][3]={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    //char ttt[3][3]={{'x','o','x'},{'o','x','x'},{'x','x','o'}};
    print(ttt);

    while(!won && !full1)
    {
        cout<<"Enter row number:"<<endl;
        cin>>r;
        cout<<"Enter column number:"<<endl;
        cin>>c;
        //cout<<"a"<<endl;
        if(ttt[r-1][c-1]=='-')
        {ttt[r-1][c-1] = uip;}
        //cout<<"b"<<endl;}
        else
        {
            cout<<"Cell is full. Input again."<<endl;
            //cout<<"c"<<endl;
            continue;
        }
        //cout<<"d"<<endl;
        if(won=win(ttt, uip))
        {
            print(ttt);
            cout<<"User won!\n";
            cout<<"e"<<endl;
            break;
        }
        else if(full1=full(ttt))
        {
            print(ttt);
            cout<<"Game over. It's a tie"<<endl;
            //cout<<"f"<<endl;
            break;
        }
        //cout<<"g"<<endl;
        comp_move(ttt, uip, cip);
        //cout<<"h"<<endl;
        if(won=win(ttt, cip))
        {
            print(ttt);
            cout<<"Computer won!\n";
            break;
        }
        else if(full1=full(ttt))
        {
            print(ttt);
            cout<<"Game over. It's a tie"<<endl;
            break;
        }
        //cout<<"i"<<endl;
        print(ttt);
    }

    return 0;
}
