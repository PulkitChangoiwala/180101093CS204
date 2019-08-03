
#include<bits/stdc++.h>
using namespace std;

void sum(vector<char> &a, vector<char> &b)
{
    int carry=0;
    char ch;



    int n1 = a.size();
    int n2 = b.size();

        for(int i=0;i<n1;++i)
        {
            int d =(a[i]-'0')+(b[i]-'0') +carry;
            ch = (d%10) + '0';
            carry = d/10;
            a[i]=ch;

        }

        for (int i=n1; i<n2; i++)
        {
        int d = ((b[i]-'0')+carry);
        ch = (d%10) + '0';
        a.push_back(ch);
        carry = d/10;
        }

        if(carry)
        a.push_back(carry+'0');

}
















int main() {


    vector<char> a;
    vector<char> b;
    vector<char> c;
    vector<char> d;
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
    for(int i= 0;i<b.size();++i)
    {
        for(int k= 0;k<i;++k)
        {
            c.push_back('0');

        }
        for(int j=0;j<a.size();++j)
        {
            int d =(a[j]-'0')*(b[i]-'0') +carry;
            ch = (d%10) + '0';
            carry = d/10;
            c.push_back(ch);
        }

    if(carry>0)
    c.push_back((carry + '0'));

    if(i==0)
    swap(d,c);
    else sum(d,c);
    c.clear();
    }



    reverse(d.begin(),d.end());
    for(int i =0;i<d.size();++i)
    cout<<d[i];



    return 0;
}
