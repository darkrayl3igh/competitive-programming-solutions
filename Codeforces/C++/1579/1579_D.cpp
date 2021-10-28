// https://codeforces.com/problemset/problem/1579/D
// GALATIANS 4:16

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define debug(x) cout << #x << "=" << x << endl
#define mp make_pair
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define newline cout << "\n"
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

const int MOD = 1e9+7;

ll gcd (ll a, ll b) {return (a ? gcd(b % a, a) : b);}
int random(int x, int y) {return (rand() % (y-x)) + x;}

void rotate(vector<int>& arr, int l, int r) {
    int temp = arr[l];
    for(int i = l; i < r; i++) {
        arr[i] = arr[i+1];
    }
    arr[r] = temp;
}

void solve() { 
    int n; cin >> n;
    vector<int> arr(n), sorted;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sorted = arr;
    sortall(sorted);

    vector<pair<int, pair<int, int> > > answer;
    for(int i = 0; i < n; i++) {
        if(arr[i] == sorted[i]) {
            continue;
        }

        for(int j = i+1; j < n; j++) {
            if(arr[j] == sorted[i]) {
                answer.push_back(make_pair(i+1, make_pair(j+1, j-i)));
                while(sorted[i] != arr[i]) {
                    rotate(arr, i, j);
                }
            }
        }
    }

    cout << answer.size() << endl;
    if(answer.size() > 0) {
        for(int i = 0; i < answer.size(); i++) {
            cout << answer[i].first << " " << answer[i].second.first << " " << answer[i].second.second << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}