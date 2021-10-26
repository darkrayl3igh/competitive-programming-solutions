// https://codeforces.com/problemset/problem/1133/A
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

int extract(string time) {
    int hours = 0, idx = 0, minutes = 0;
    while(time[idx] != ':') {
        hours *= 10;
        hours += time[idx++] - '0';
    }

    idx++;
    while(idx < time.size()) {
        minutes *= 10;
        minutes += time[idx++] - '0';
    }

    return 60*hours + minutes;
}

string convert(int time) {
    string hours = to_string(time/60), minutes = to_string(time%60);

    return (hours.size() == 1 ? "0" : "") + hours + ":" + (minutes.size() == 1 ? "0" : "") + minutes;
}

void solve() {
    string start, end; cin >> start >> end;
    int t1 = extract(start), t2 = extract(end);
    cout << convert((t2-t1)/2 + t1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        input_stream;
    #endif

    int t = 1; //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}