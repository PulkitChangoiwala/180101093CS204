#include<bits/stdc++.h>
using namespace std;
int cmpr(string str1,string str2){
	int n1=str1.length();
	int n2=str2.length();
	if(n1>n2) return 1;
	if(n2>n1) return -1;
	else{
		int i;
		for(i=0;i<n1;i++){
			if(str1[i]>str2[i]) return 1;
			if(str2[i]>str1[i]) return -1;
		}
		if(i==n1) return 0;
	}
}
string subtract(string str1,string str2)
{
	int sign;
	if(cmpr(str1,str2)==0) return "";
	else{
		if (cmpr(str1,str2)==-1){
			swap(str1,str2);
			sign=1;
		}
		string str = "";
		int n1 = str1.length(), n2 = str2.length();
        reverse(str1.begin(), str1.end());
	  	reverse(str2.begin(), str2.end());
	  	int carry = 0;
		for (int i=0; i<n2; i++)
		{
		        int sub = ((str1[i]-'0')-(str2[i]-'0')+carry);
			if(sub<0){
				carry=-1;
				sub+=10;
			}
			else carry=0;
		        str.push_back(sub + '0');
		}

		for (int i=n2;i<n1; i++)
		 {
			int sub = ((str1[i]-'0')+carry);
			if(sub<0){
				carry=-1;
				sub+= 10;
			}
			else carry=0;
		        str.push_back(sub + '0');
        }

		int i=str.length();
		while(str[i-1]=='0')
            {
			str.pop_back();
			i--;
            }


		if (sign==1) str.push_back('-');
		reverse(str.begin(), str.end());
		return str;
	}
}
int main(){
	int testc;
	cin>>testc;
	string Ranswers[testc];
	string Qanswers[testc];
	for(int k=0;k<testc;k++)
    {
	string s1,s2,s="";
	cin>>s1>>s2;
	int n1=s1.length();
	int n2=s2.length();
	if(s2=="0") cout<<"Not defined"<<"\n";
	else if(cmpr(s1,s2)==-1) cout<<0<<" "<<s1<<"\n";
	else if(cmpr(s1,s2)==0) cout<<1<<" "<<0<<"\n";
	else{
		string x="";
		int i;
		for(i=0;i<n2;i++)
			x.push_back(s1[i]);

		while(i<=n1){
			int qt=0;
			while(1){
				if(cmpr(x,s2)==-1){
					break;
				}
				else{
					string y=subtract(x,s2);
					x=y;
					qt++;
				}
			}
			if(i!=n2 || qt!=0) s.push_back(qt+'0');
			if(i<n1) x.push_back(s1[i]);
			i++;
		}
		if(x=="") x.push_back('0');

		Ranswers[k]=x;
		Qanswers[k]=s;
		//cout<<s<<" "<<x<<"\n";
	}
	}

	for(int i=0;i<testc;++i)
        cout<<Qanswers[i]<<" "<<Ranswers[i]<<endl;
	return 0;
}
