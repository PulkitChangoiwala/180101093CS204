#include<bits/stdc++.h>
using namespace std;



int main() {


    vector<char> a;
    vector<char> b;
    vector<char> c;
    char x;
    while(1)
    {
    x=getchar();
    if(x=='\n')
    break;
    else
    a.insert(a.begin(),x);
    }

    while(1)
    {
    x=getchar();
    if(x=='\n')
    break;
    else
    b.insert(b.begin(),x);
    }


    int carry=0;
    char ch;


    if(a.size()>b.size())
    swap(a,b);
    int n1 = a.size();
    int n2 = b.size();

        for(int i=0;i<n1;++i)
        {
            int d =(a[i]-'0')+(b[i]-'0') +carry;
            ch = (d%10) + '0';
            carry = d/10;
            c.insert(c.begin(),ch);
        }

        for (int i=n1; i<n2; i++)
        {
        int d = ((b[i]-'0')+carry);
        ch = (d%10) + '0';
        c.insert(c.begin(),ch);
        carry = d/10;
        }

        if(carry)
        c.insert(c.begin(),(carry + '0'));




    for(int i =0;i<c.size();++i)
    cout<<c[i];



    return 0;
}