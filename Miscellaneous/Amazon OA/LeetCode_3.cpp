// https://leetcode.com/discuss/interview-question/1475105/Amazon-OA
// GALATIANS 4:16

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
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

void solve() {
    int sum = 0, n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> tracker;
    for(int i = 0; i < n; i++) {
        int length; cin >> length;
        tracker.push(length);
    }

    while(tracker.size() > 1) {
        int len1 = tracker.top(); tracker.pop();
        int len2 = tracker.top(); tracker.pop();

        cout << len1 << " " << len2 << " " << sum << endl;
        sum += len1 + len2;
        tracker.push(len1 + len2);
    }

    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}