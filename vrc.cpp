#include<bits/stdc++.h>
using namespace std;
//converts ascii characters to binary string
void toAscii(string word,int n,string asci[])
{
    for(int i=0;i<n;i++)
    {
        int c=word[i];
        string bin;
        while(c)
        {

            bin.push_back(c%2+'0');
            c/=2;
        }
        reverse(bin.begin(),bin.end());
        int one=0;
        for(auto x:bin)
        {
            if(x=='1')
                one++;
        }
        bin.push_back(one%2+'0');
        asci[i]=bin;

    }
}
int main()
{
    string a;
    cout<<"Enter the word: "<<endl;
    cin>>a;
    int len=a.length();
    string sent[len];
    toAscii(a,len,sent);
    cout<<"Sent bits with even parity: ";
    for(auto p:sent)
        cout<<p<<" "<<endl;

    int ch;
    cout<<"How many characters are received? "<<endl;
    cin>>ch;
    if(ch==len)
        cout<<"All bits are received."<<endl;  //checks if all bits are sent or not
    else
        cout<<"All bits are not received."<<endl;

    string rec[ch];
    cout<<"Enter the received bits: "<<endl;
    for(int i=0;i<ch;i++)
    {
        cin>>rec[i];
    }
    int error=0;
    for(int i=0;i<ch;i++)
    {
        int one=0;
        for(auto p:rec[i])
        {
            if(p=='1')
                one++;
        }
        if(one%2!=0)
            error=1;
    }
    if(error==1)
        cout<<"Bits are corrupted."<<endl;
    else
        cout<<"Bits are correct."<<endl;


}
