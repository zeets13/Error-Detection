#include<bits/stdc++.h>
using namespace std;

string add(string a,string b)
{
    string sum;
    int carry=0;
    for(int i=7;i>=0;i--)
    {
        if(carry==0)
        {
            if(a[i]=='1' && b[i]=='1')
                sum.push_back('0'),carry=1;
            else if(a[i]=='1' || b[i]=='1')
                sum.push_back('1');
            else
                sum.push_back('0');
        }
        else{
            if(a[i]=='1'&& b[i]=='1')
                sum.push_back('1');
            else if(a[i]=='1'||b[i]=='1')
                sum.push_back('0');
            else
                sum.push_back('1'),carry=0;
        }
    }
    reverse(sum.begin(),sum.end());
    if(carry==1){
        return add(sum,"00000001");

    }
    return sum;

}
string comp(string s)
{
    for(int i=0;i<s.length();i++)
    {
         if(s[i]=='0')
        s[i]='1';
    else
        s[i]='0';
    }


  return s;
}
int main()
{
    string a,b;
    cout<<"Enter two binary string of 8 bits: "<<endl;
    cin>>a>>b;
    string sumRes=add(a,b);
    string checksum=comp(sumRes);
    cout<<a<<" "<<b<<" "<<checksum<<endl;

    string x,y,z;
    cout<<"Enter the bits received: "<<endl;
    cin>>x>>y>>z;

    string res=add(add(x,y),z);
    int error=0;
    for(auto c:res){
        if(c=='0')
        error=1;
    }
    if(error)
        cout<<"Received bits are corrupted"<<endl;
    else
        cout<<"Received bits are correct"<<endl;

}
