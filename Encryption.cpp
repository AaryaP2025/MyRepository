#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void EncryptFile(const string& inputFile, const string& outputFile, int shift)
{
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    if(!inFile)
    {
        cerr<<"Error opening input file."<<endl;
        return;
    }
    if(!outFile)
    {
        cerr<<"Error opening output file."<<endl;
        return;
    }

    char ch;
    while(inFile.get(ch))
    {
        if(ch>='A' && ch<='Z')
        {
            ch = (ch-'A'+shift)%26+'A';
        }
        else if(ch>='a' && ch<='z')
        {
            ch = (ch-'a'+shift)%26+'a';
        }
        outFile.put(ch);
    }
    inFile.close();
    outFile.close();
}

void DecryptFile(const string& inputFile, const string& outputFile, int shift)
{
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    if(!inFile)
    {
        cerr<<"Error opening input file."<<endl;
        return;
    }
    if(!outFile)
    {
        cerr<<"Error opening output file."<<endl;
        return;
    }

    char ch;
    while(inFile.get(ch))
    {
        if(ch>='A' && ch<='Z')
        {
            ch = (ch-'A'-shift+26)%26+'A';
        }
        else if(ch>='a' && ch<='z')
        {
            ch = (ch-'a'-shift+26)%26+'a';
        }
        outFile.put(ch);
    }
    inFile.close();
    outFile.close();
}

int main()
{
    string inputFile, outputFile;
    int shift;

    cout<<"Enter the name of input file: ";
    cin>>inputFile;
    cout<<"Enter the name of output file: ";
    cin>>outputFile;
    cout<<"Enter shift value: ";
    cin>>shift;
    EncryptFile(inputFile, outputFile, shift);
    cout<<"File encrypted successfully"<<endl;
    DecryptFile(outputFile, "decrypted_"+outputFile, shift);
    cout<<"File decrypted successfully."<<endl;
}
