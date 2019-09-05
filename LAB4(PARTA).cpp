#include<bits/stdc++.h>
#include<stack>
using namespace std;
typedef struct tree
{
string s;
tree *left =NULL;
tree *right =NULL;

} tree;
//Converts a string to a vector of strings
vector<string> vctrstr(string s)
{
    vector<string> temp;
    temp.push_back("(");
    int lastBit_is_unary=0;
    for(int i =0;i<s.size();++i)
    {   string tmp ="";


      if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
      {

          temp.clear();
          temp.push_back("Can't Be Evaluated \n");\
          return temp;

      }
       else if(s[i]>='0'&&s[i]<='9')
          {for(int j=i;(s[j]>='0'&&s[j]<='9');++j)
            {tmp+= s[j];i++;}
            i--;
            temp.push_back(tmp);
            if(lastBit_is_unary==1)
              {temp.push_back(")"); lastBit_is_unary =0;}
          }


        else if (s[i]=='-'||s[i]=='+')
        {if(i==0||s[i-1]=='('||s[i-1]==')'||s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/'||s[i-1]=='%'||s[i-1]=='^')
         {  temp.push_back("(");
            temp.push_back("0");
            lastBit_is_unary =1;

         }
          tmp+=s[i];
          temp.push_back(tmp);
        }

        else
        {
         tmp+=s[i];
         temp.push_back(tmp);
        }

    }
    temp.push_back(")");
    return temp;
}

int precedenceInput(char ch)
{
    if(ch=='^') return 4;
    else if(ch == '*' || ch == '/' || ch == '%') return 2;
    else if(ch == '+' || ch == '-') return 1;
}
int precedenceTop(char ch)
{
    if(ch=='^') return 3;
    else if(ch == '*' || ch == '/' || ch == '%') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else if(ch == '(') return 0;
}

vector<string> infixToPostfix(vector<string> s)
{  stack<string> Stack;
   vector<string> postfix;

    for (int i = 0; i < s.size(); i++)

    {
       if ((s[i][0] >= '0' && s[i][0] <= '9'))
             {postfix.push_back(s[i]);

        }

        else if (s[i] == "(")
            {Stack.push(s[i]);

            }
        else if (s[i] == ")")

        {
            while (Stack.top() != "(")

            {
                postfix.push_back(Stack.top());
                Stack.pop();
            }

            Stack.pop();
        }

        else if(s[i]=="^"||s[i]=="+"||s[i]=="-"||s[i]=="/"||s[i]=="%"||s[i]=="*")
        {
            if(Stack.empty())
                Stack.push(s[i]);
            else
            {while(precedenceTop((Stack.top())[0]) >= precedenceInput(s[i][0]))
            {
                postfix.push_back(Stack.top());
                Stack.pop();
            }
            Stack.push(s[i]);
            }
        }
    }


    return postfix;

}

tree* constructTree(vector<string> postfix)
{
   tree* root =NULL;
   stack <tree *> stck;
   for(int i=0;i<postfix.size();++i)
   {
      if(postfix[i]!="+"&&postfix[i]!="-"&&postfix[i]!="/"&&postfix[i]!="*"&&postfix[i]!="%"&&postfix[i]!="^")
      {
        tree* tmp = new tree;
        tmp->s=postfix[i];
        stck.push(tmp);

      }
      else
      {
        if(stck.size()<2) return NULL;
        else
            {tree*s1 = stck.top();
             stck.pop();
             tree*s2 = stck.top();
             stck.pop();
             tree *temp =new tree;
             temp->s=postfix[i];
             temp->right=s1;
             temp->left=s2;
             stck.push(temp);


            }
      }

   }

   return stck.top();

}



long long evaluate(tree * root)
{
    string str=root->s;

    long long ans=0;
    if(str != "+" && str != "-" && str!="%"&&str != "*" && str != "/" && str != "^")
    {
        return stoi(str);
    }

    else
    {
        long long  l= evaluate(root->left);
        long long r =evaluate(root->right);
        if (str == "+")
            ans = l + r;
        else if (str == "-")
            ans = l - r;
        else if (str == "*")
            ans = l * r;
        else if (str == "/")
            ans = l / r;
        else if(str =="%")
            ans =l%r;
        else
        {ans = 1;
         for(int k=0;k<r;++k)
            ans*=l;
        }
    }
    return ans;
}




















int main()
{
    int testc;
    cin>>testc;
   while(testc--)
    {
    int NoOfLines;
    cin>>NoOfLines;
   while(NoOfLines--)
   {
    string s;
    cin>>s;
    vector<string> str = vctrstr(s);
    if(str.size()==3) {cout<<str[1]<<endl;continue;}//Only values
    else if(str.size() ==1) {cout<<str[0];continue;}
    vector<string> postfix = infixToPostfix(str);

    tree *root=constructTree(postfix);
    ;
    if(root!=NULL)
    cout<<evaluate(root)<<"\n";
    else cout<<"Not";
    str.clear();
   }
   }
return 0;
}
