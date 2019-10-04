#include<bits/stdc++.h>
using namespace std;
typedef struct point
{
 int x;
 int y;
}
point;

point p0;

point minPt(point *p,int t)
{

point P =p[0];
int pos=0;
for(int i=1;i<t;++i)
{
if(p[i].y<P.y)
	{P=p[i]; pos =i;}
else if(p[i].y==P.y && p[i].x<P.x)
	{P=p[i];pos =i;}
}
point temp = p[0];
p[0]=p[pos];
p[pos]=temp;


return P;
}

//antiClockwise = 1 & clockwise = -1 & collinear =0
int orientation(point p ,point q, point r)
{
int a;
a =  (r.y-q.y)*(q.x-p.x) - (q.y-p.y)*(r.x-q.x);
if(a==0)return a;
else
return((a>0)?1:-1);
}


int compare(point q,point r)
{

 int a = orientation(p0,q,r);

 if(a==0)
 {
 int dis1,dis2;
 dis1 = (q.y-p0.y)*(q.y-p0.y) + (q.x-p0.x)*(q.x-p0.x);
 dis2 = (r.y-p0.y)*(r.y-p0.y) + (r.x-p0.x)*(r.x-p0.x);
 if(dis1<dis2)
 	return 1;//no change of ordering
 else return 0;//change of ordering
}
 else
 {  if(a==1 ) return 1;
    else if(a==-1) return 0;
 }


}


point underTop(stack<point> s)
{
    point top;
    top=s.top();
    s.pop();
    point belowTop = s.top();
    s.push(top);
    return belowTop;
}

int minimum(point p[],int n)
{
int pos=0;
for(int i=0;i<n;++i)
{
    if(p[i].x<p[pos].x) pos=i;
    else if(p[i].x==p[pos].x && p[i].y<p[pos].y) pos =i;

}
return pos;
}

int main()
{
int t;
cin>>t;
point p[t];
for(int i=0;i<t;++i)
{
cin>>p[i].x>>p[i].y;
}

p0 = minPt(p,t);
sort(p+1,p+t,compare);
int m=1;
for(int i=1;i<t;++i)
{
    while(i<t-1 && orientation(p0,p[i],p[i+1])==0)
        {
        i++;
        }
p[m]=p[i];
m++;

}

if(m<3)
{
    if(m==1) cout<<1<<endl<<p[0].x<<" "<<p[0].y<<endl;
    else if(m==2)
    {   cout<<2<<endl;
        if(p[0].x<=p[1].x)
         {cout<<p[0].x<<" "<<p[0].y<<endl<<p[1].x<<" "<<p[1].y<<endl;}
         else cout<<p[1].x<<" "<<p[1].y<<endl<<p[0].x<<" "<<p[0].y<<endl;
    }

    
    
}
else
{
stack<point> s;
s.push(p[0]);
s.push(p[1]);
s.push(p[2]);

for(int i=3;i<m;++i)
{
    while(orientation(underTop(s),s.top(),p[i])== -1)
        s.pop();

    s.push(p[i]);
}

int i=0,size=s.size();
point pA[size];
cout<<size<<endl;
while(!s.empty())
{
  pA[i++]=s.top();
  s.pop();
}
int index=minimum(pA,size);
for(int var =index;var<size;++var)
{cout<<pA[var].x<<" "<<pA[var].y<<endl;}
for(int var=0;var<index;++var)
{cout<<pA[var].x<<" "<<pA[var].y<<endl;}
}


}
