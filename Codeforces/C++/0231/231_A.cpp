// https://codeforces.com/problemset/problem/231/A
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

void solve() {
	int n, num, sum = 0, answer = 0; cin >> n;
	for(int i = 0; i < n; i++) {
		sum = 0;
		for(int j = 0; j < 3; j++) {
			cin >> num; sum += num;
		}
		answer += (sum >= 2);
	}

	cout << answer << endl;
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