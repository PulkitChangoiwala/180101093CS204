#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
using namespace std; 
  

int myCompare(string X, string Y) 
{ 

    string XY = X.append(Y); 
  
    
    string YX = Y.append(X); 
  
   
    return XY.compare(YX) > 0 ? 1: 0; 
} 
  

void printL(vector<string> arr) 
{ 
    
    sort(arr.begin(), arr.end(), myCompare); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 
  
 
int main() 
{ 
   long int t;
   cin>>t;
   while(t--)
   {
    long int q;
    cin>>q;
    string v;
    vector<string> arr; 
    for(long int i=0;i<q;++i)
    {
      cin>>v;
      arr.push_back(v); 


    }
    printL(arr); 
    cout<<endl;
     
  
  }
return 0; 
} 
