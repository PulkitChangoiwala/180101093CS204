#include<bits/stdc++.h>
#include<string>
#include<ctype.h>
using namespace std;
vector<string> assignment;
typedef struct tree
{
string s;
tree *left =NULL;
tree *right =NULL;

} tree;

int alpha(char c)
{
return((c>='a'&&c<='z')||(c>='A'&&c<='Z'));

}

int digit(char c)
{
return ((c >= '0' && c<= '9'));
}


int search_assigned(string s)
{
  for(int i=0;i<assignment.size();i=i+2)
   if(assignment[i]==s)
    return i;

  return -1;

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




vector<string> subevaluate(string s ,int index)
{
   vector<string> temp;
   temp.push_back("(");
    int lastBit_is_unary =0;

  for( int i=index;i<s.size();++i)
  { string tmp="";

    if(digit(s[i]))
       {while(digit(s[i]))
          tmp+=s[i++];i--;
          temp.push_back(tmp);
          if(lastBit_is_unary==1)
              {temp.push_back(")"); lastBit_is_unary =0;}

       }
    else if(alpha(s[i]))
      {

          while(alpha(s[i]))
          tmp+=s[i++]; i--;

          int pos = search_assigned(tmp);

          if(pos==-1) {temp.clear();temp.push_back("Can't Be Evaluated\n"); return temp;}
          else tmp= assignment[pos+1];
          temp.push_back(tmp);
          if(lastBit_is_unary==1)
              {temp.push_back(")"); lastBit_is_unary =0;}
      }


        else if (s[i]=='-'||s[i]=='+')
        {if(i==index||s[i-1]=='('||s[i-1]==')'||s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/'||s[i-1]=='%'||s[i-1]=='^')
         {  temp.push_back("(");
            temp.push_back("0");
            lastBit_is_unary =1;

         }
          tmp+=s[i];
          temp.push_back(tmp);
        }

        else
        {tmp+=s[i];
         temp.push_back(tmp);
        }

  }

temp.push_back(")");
return temp;


}





void func(string s)
{
vector<string> temp;
int i =0;
  //for(int i =0;i<s.size();++i)
{
if(alpha(s[i]))
     {

      string dummy="";
      while(alpha(s[i]))
      dummy+=s[i++];

      if(i<s.size()&&s[i]=='=')
       {
          string value ="";
          i++;
          temp=subevaluate(s,i);

          if(temp.size()==3)
             {
               int pos =search_assigned(dummy);
               if(pos>-1)
                  {assignment[pos]=dummy; assignment[pos+1]=temp[1];}
               else
                  {assignment.push_back(dummy); assignment.push_back(temp[1]);}
               return;
             }
          else if(temp.size()==1)
            { cout<<temp[0];return;
            }
          else {
                vector<string> postfix = infixToPostfix(temp);
                tree *root =constructTree(postfix);
                long long answer;
                if(root!=NULL)
                answer = evaluate(root);
                string answerS = to_string(answer);
                int pos =search_assigned(dummy);
                if(pos>-1)
                {assignment[pos]=dummy; assignment[pos+1]= answerS;}
                else
                {assignment.push_back(dummy); assignment.push_back(answerS);}
                return;
               }



       }
       else if(i==s.size())
       {
            int pos =search_assigned(dummy);
            if(pos==-1)
            cout<<"Can't Be Evaluated\n";
            else
            cout<<assignment[pos+1]<<endl;

       }
       else if (s[i]=='('||s[i]==')'||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%'||s[i]=='^')
       {
        temp=subevaluate(s,0);
        if(temp.size()==3) {cout<<temp[1]<<"\n"; return; }
        else if(temp.size()==1) {cout<<temp[0];return;}
        else    { vector<string> postfix = infixToPostfix(temp);
                tree *root =constructTree(postfix);
                long long answer;
                if(root!=NULL)
                answer = evaluate(root);
                cout<<answer<<endl;
                return;
               }

       }

      }
else if(digit(s[i]))
{
      temp=subevaluate(s,0);
      if(temp.size()==3) {cout<<temp[1]<<"\n"; return; }
      else if(temp.size()==1) {cout<<temp[0];return;}
      else    { vector<string> postfix = infixToPostfix(temp);
                tree *root =constructTree(postfix);
                long long answer;
                if(root!=NULL)
                answer = evaluate(root);
                cout<<answer<<endl;
                return;
              }
}


}

}



int main()
{
    int testc;
    cin>>testc;
   while(testc--)
    {assignment.clear();
    int NoOfLines;
    cin>>NoOfLines;
   while(NoOfLines--)
   {
    string s;
    cin>>s;
    func(s);

   }
   }
return 0;
}
