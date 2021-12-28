#include "bits/stdc++.h"

using namespace std;

int main()
{
    vector<bool> prime(4000000, true);
    vector<int> sieve;
    for(int p = 2; p*p <= prime.size(); p++) 
    { 
        if(prime[p]) 
        { 
            for(int i = p*p; i <= prime.size(); i += p) 
                prime[i] = false; 
        }
    }

    for(int i = 2; i < prime.size(); i++)
    {
        if(prime[i]) sieve.push_back(i);
    }

    int t = 1; cin >> t;
    while(t--)
    {
        int n, curr = 0; cin >> n;
        vector<int> arr(n + 1);
        map<int, int> occurence;
        for(int i = 1; i <= n; i++)
        {
            int temp; cin >> temp;
            if(!occurence[temp])
            {
                occurence[temp] = sieve[curr];
                curr++;
            }
            arr[i] = occurence[temp];
        }

        for(int i = 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}