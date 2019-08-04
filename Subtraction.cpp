#include<bits/stdc++.h>
using namespace std;
/******* For Numbers Not containing unnecessary zeros in front ***********/
int CompareTwo(vector<char> &p,vector<char> &q)
{
    int sizep = p.size();
    int i;
    int sizeq = q.size();

    if(sizep>sizeq) return 1;
    else if(sizep==sizeq)
    { for(i=0;i<sizep;++i)
     {
         if(p[i]>q[i]) return 1;
         else if (p[i]<q[i]) return -1;

     }
     if(i==sizep) return 0;

    }

    else if(sizep<sizeq) return -1;

}



void subtract(vector<char> &p,vector<char> &q,vector<char> &s)
{
int compare = CompareTwo(p,q);
if(compare ==0)
    { s.push_back('0');
      return;}
else if(compare == -1)   swap(p,q);
int sizep = p.size();
int sizeq = q.size();
reverse(p.begin(),p.end());
reverse(q.begin(),q.end());

 for(int i=0;i<sizeq;++i)
        {   if(p[i]>=q[i])
            {int d =(p[i]-'0')-(q[i]-'0');
             char ch = (d) + '0';
            s.insert(s.begin(),ch);
            }
            else

            { int d = (p[i]-'0')-(q[i]-'0')+10;
              p[i+1]--;
              char ch = (d) + '0';
             s.insert(s.begin(),ch);

            }
        }

        for (int i=sizeq; i<sizep; i++)
        {
        int d = (p[i]-'0');
        char ch = (d) + '0';
        s.insert(s.begin(),ch);
        //carry = d/10;
        }
}




int main()
{

/************ Evaluating P-Q *****************/
    vector<char> p;
    vector<char> q;
    vector<char> s;
/********************* TAKING INPUT *******************************/

{
    char x;
    while(1)
    {
    x=getchar();
    if(x=='\n') break;
    else p.push_back(x);
    }

    while(1)
    {
    x=getchar();
    if(x=='\n') break;
    else q.push_back(x);
    }
}
/********************* INPUT TAKEN *******************************/

subtract(p,q,s);
      for(int i=0;i<s.size();++i)
      cout<<s[i];

return 0;
}
