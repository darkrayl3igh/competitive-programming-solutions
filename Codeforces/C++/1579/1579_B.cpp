// https://codeforces.com/problemset/problem/1579/B
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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int> > answer, final_ans;
    int r, diff = INT_MAX, flag = 1;
    while(flag) {
        flag = 0;
        for(int i = 0; i < n; i++) {
            r = 0;
            for(int j = i+1; j < n; j++) {
                if(arr[i] > arr[j]) {
                    if(diff >= arr[i] - arr[j]) {
                        r = j;
                        diff = arr[i] - arr[j];
                    }
                }
            }
            if(r) {
                vector<int> temp(3); temp[0] = i+1; temp[1] = r+1; temp[2] = 1;
                answer.push_back(temp);
                rotate(arr, i, r);
                flag = 1;
                break;
            }
        }
    }

    final_ans.push_back(answer.front());
    for(int i = 1; i < answer.size(); i++) {
        if(final_ans.back()[0] == answer[i][0] && final_ans.back()[1] == answer[i][1]) {
            final_ans.back()[2]++;
        } else {
            final_ans.push_back(answer[i]);
        }
    }

    cout << final_ans.size() << endl;
    if(final_ans.size() == 0) return;
    for(vector<int>& f : final_ans) {
        cout << f[0] << " " << f[1] << " " << f[2] << endl;
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