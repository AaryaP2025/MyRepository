#include <iostream>
using namespace std;

#define max 10

struct Pair
{
    int data;
    struct Pair *next;
};

void Insert(Pair *hashtable[], int x)
{
    //cout<<"Start of insert"<<endl;
    Pair *newdata;
    newdata = (Pair*)malloc(sizeof(Pair));
    newdata->data = x;
    newdata->next = NULL;
    int location = x%max;
    Pair *p;
    p = (Pair*)malloc(sizeof(Pair));
    if(hashtable[location]==NULL)
        hashtable[location]=newdata;
    else
    {
        for(p=hashtable[location]; p->next!=NULL; p = p->next);
        p->next = newdata;
    }
    //cout<<"After assignment"<<endl;
    //cout<<hashtable<<endl;
}

void print(Pair *hashtable[])
{
    Pair *p;
    for(int i=0; i<max; i++)
    {
        p = hashtable[i];
        if(p==NULL)
            cout<<"NULL"<<endl;
        else
        {
            while(p!=NULL)
            {
                cout<<(p->data)<<"  ";
                p = p->next;
            }
            cout<<endl;
        }
    }
}

int main()
{
    Pair *hashtable[max];
    int arr[] = {5, 11, 24, 28, 31, 36, 41, 49, 54, 4544, 4324};
    //cout<<"Before init"<<endl;
    for(int i = 0; i<max; i++)
    {
        hashtable[i] = NULL;
    }
    //cout<<"After init"<<endl;
    Insert(hashtable, 157);
    //cout<<"After insert"<<endl;
    int length = size(arr);
    for(int i=0; i<length; i++)
    {
        Insert(hashtable, arr[i]);
    }

    print(hashtable);
    return 0;
}
