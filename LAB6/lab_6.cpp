#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli binary_search(vector<lli> arr, lli i, lli j, lli key) {
    if(i > j) {
        return -1;
    }

    lli m = (i + j) / 2;
    if(arr[m] < key) {
        return binary_search(arr, m+1, j, key);
    } else if(arr[m] > key) {
        return binary_search(arr, i, m-1, key);
    }
    return m;
}

int main() 
{
    lli n;
    cin >> n;
    lli queries;
    cin >> queries;
    lli record[queries][3];
    vector<lli> id;
    for(lli i = 0; i < queries; ++i) 
     {
        cin >> record[i][0];
        if(record[i][0] == 1) {
            cin >> record[i][1] >> record[i][2];
            id.push_back(record[i][1]);
     }
    }

    sort(id.begin(),id.end());
    
    lli j = 1;
    for(lli i = 1; i<id.size(); ++i) 
       {
        if(id[i] != id[i-1]) 
        {
            id[j] = id[i];
            ++j;
        }
    }
    lli newSize =j;
    


    lli max_user_id = -1;
    lli max_amount = -1;
    vector<lli> amount(j, 0);

    for(lli i = 0; i < queries; ++i) {
        if(record[i][0] == 1) {
            lli index = binary_search(id, 0, newSize-1, record[i][1]);
            amount[index] += record[i][2];
            if(max_amount < amount[index]) {
                max_amount = amount[index];
                max_user_id = record[i][1];
            }
        } else {
            if(max_amount>-1) {
                cout << max_user_id << '\n';
            } else {
                cout << "No data available." << '\n';
            }
        }
    }


    return 0;
}
