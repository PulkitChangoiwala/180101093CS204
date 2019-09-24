#include<bits/stdc++.h>
#include<iostream>
using namespace std;





double findmedian(double arr[] , int n)
{

	sort(arr,arr+n);
	return(arr[(n-1)/2]);
}

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}


int partition(double arr[], int l, int r, double x)
{

    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}




double findElt(double arr[],int p, int r,int q)
{

if(q>0 && q<= r-p+1)
{
 int n= r-p+1;

 int m = (n+4)/5;
 int i;
 double medians[m];
 for(i=0;i<n/5;++i)
	medians[i]=findmedian(arr+i*5+p , 5);
 if (i*5 < n)
        {
            medians[i] = findmedian(arr+p+i*5, n%5);
            i++;
        }

 double medofMed = (i == 1)? medians[i-1]: findElt(medians, 0, i-1, i/2);

 int pos = partition(arr, p, r, medofMed);


        if (pos-p == q-1)
            return arr[pos];
        if (pos-p > q-1)
            return findElt(arr, p, pos-1, q);

        return findElt(arr, pos+1, r, q-pos+p-1);
}
else return -1;

}






int main()
{
 int t;
 cin >> t;
 while(t--)
 {
   int k;
   cin>>k;
   int x,y;
   int points[k][2];
   for(int i =0;i<k;++i)
   {cin>>x>>y;
    points[i][0]=x;
    points[i][1]=y;
   }
   double radius[k];
   for(int i =0;i<k;++i)
   {
   	radius[i]= sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
   	cout<<radius[i]<<endl;
   }
   double CircleRadius = findElt(radius,0,k-1,(k+1)/2);
   cout<<CircleRadius<<endl;




 }




}
