#include <iostream>
using namespace std;

#define max 20

void Insert(int hashtable[max], bool space[max], int x)
{
    int c=0;
    for(int i=0; i<max; i++)
    {
        if(space[i])
            c++;
    }
    if(c!=max)
    {
        int location = x%max;

        /** //Linear probing
        if(!space[location])
        {
            hashtable[location] = x;
            space[location] = 1;
        }
        else
        {
            int i = location;
            while(space[i])
            {
                if(i<19)
                {
                    i++;
                }
                else
                {
                    i=;
                }
            }
            hashtable[i] = x;
            space[i] = 1;
        }*/

        /** //Quadratic Probing
        if(!space[location])
        {
            hashtable[location] = x;
            space[location] = 1;
        }
        else
        {
            int j = 1;
            int loc1 = location;
            for(int i=1; i<max; i++)
            {
                loc1 = location+(j*j);
                if(loc1>19)
                    loc1 = loc1%max;
                //cout<<loc1<<endl;
                if(!space[loc1])
                    break;
                j++;
            }
            hashtable[loc1] = x;
            space[loc1] = 1;
        }*/

        //Double Hashing
        if(!space[location])
        {
            hashtable[location] = x;
            space[location] = 1;
        }
        else
        {
            int loc2 = location;
            int square = x*x;
            int sum = 0;
            while(square>0)
            {
                sum = sum + (square%10);
                square = square/10;
            }
            int k;
            for(k=1; k<=max; k++)
            {
                loc2 = location+(k*sum);
                loc2 = loc2%max;
                if(!space[loc2])
                {
                    hashtable[loc2]=x;
                    space[loc2]=1;
                    break;
                }
            }
            //cout<<"k = "<<k<<endl;
            //cout<<"x = "<<x<<endl;
            if(k==max & hashtable[loc2]!=x)
                cout<<"Could not find appropriate location."<<endl;
        }
    }
    else
    {
        cout<<"Hashtable is full."<<endl;
    }
}

void Print(int hashtable[max], bool space[max])
{
    for(int i=0; i<max; i++)
    {
        if(space[i])
            cout<<hashtable[i]<<endl;
        else
            cout<<"NULL"<<endl;
    }
}

int main()
{
    int hashtable[max] = {0};
    bool space[max] = {0};
    int arr[] = {5, 11, 24, 28, 31, 36, 41, 49, 54, 4544, 4324, 489, 400607, 3538, 575757, 2, 111, 1000, 100000, 389};
    int length = size(arr);
    for(int i=0; i<length; i++)
    {
        Insert(hashtable, space, arr[i]);
    }
    Print(hashtable, space);
}
