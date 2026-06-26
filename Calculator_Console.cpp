#include <iostream>
#include <limits>
using namespace std;

int main()
{
    double n1, n2, result;
    char operation;
    char choice='y';
    do
    {
        cout<<"Welcome to Console Calculator"<<endl;
        cout<<"Enter first number: ";

        cin>>n1;
        while(cin.fail())
        {
            cout<<"Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin>>n1;
        }

        cout<<"Enter second number: ";

        cin>>n2;
        while(cin.fail())
        {
            cout<<"Invalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin>>n2;
        }

        cout<<"Choose an operation(+, -, *, /): ";
        cin>>operation;

        switch(operation)
        {
        case '+':
            result = n1+n2;
            break;
        case '-':
            result = n1-n2;
            break;
        case '*':
            result = n1*n2;
            break;
        case '/':
            if(n2!=0)
                result = n1/n2;
            else
            {
                cout<<"Cannot divide by zero."<<endl;
                continue;
            }
            break;
        default:
            cout<<"Invalid operation."<<endl;
            continue;
        }
        cout<<"Result: "<<result<<endl;

        cout<<"Do you want to perform another calculation?(y/n): ";
        cin>>choice;
    }while(choice=='y' || choice=='Y');

    cout<<"Thank you."<<endl;
    return 0;
}
