#include<bits/stdc++.h>
using namespace std;

string crc(string data,string div) {
    int datalen=data.length();
    int divlen=div.length();

    for(int i=0; i<=datalen-divlen; i++) {
        if (data[i]=='1') {
            for (int j=0; j<divlen; j++) {
                    if(data[i+j]==div[j])
                      data[i+j]='0';
                   else
                     data[i+j]='1';

            }
        }
    }

    return data.substr(datalen-divlen +1);
}

int main() {
    string data;
    string divisor;

   cout<<"Enter the data bits: ";
   cin>>data;

  cout<<"Enter the divisor: ";
   cin>>divisor;

    int x=divisor.length()-1;
    for(int i=0; i<x; i++) {
        data.push_back('0');
    }

 string remainder=crc(data,divisor);

    cout<<"Remainder(CRC): "<<remainder<<endl;
    string rec;
    cout<<"Enter received bits: "<<endl;
    cin>>rec;
    /*for(int i=0; i<x; i++) {
        rec.push_back('0');
    }*/

    string recv=crc(rec,divisor);
    cout<<recv<<endl;
    int error=0;
    for(int p:recv)
    {
        if(p=='1')
            error=1;

    }
    if(error)
        cout<<"Error"<<endl;
    else
        cout<<"No error"<<endl;

    return 0;

}
