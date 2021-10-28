// https://leetcode.com/discuss/interview-question/1527679/Amazon-OA-password-strength
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

int count(vector<int>& alpha) {
    int sum = 0;
    for(int& a: alpha) {
        if(a > 0) {
            sum++;
        }
    }
    return sum;
}

int slidingWindow(string& phrase, int len) {
    int left = 0, right = 0, sum = 0;
    vector<int> alpha(26);

    while(right < len) {
        alpha[phrase[right] - 'a']++;
        right++;
    }

    right--;

    while(right < phrase.size()) {
        sum += count(alpha);
        alpha[phrase[left++] - 'a']--;
        alpha[phrase[++right] - 'a']++;
    }

    return sum;
}

void solve() {
    string phrase; cin >> phrase;
    int answer = phrase.size();

    for(int len = 2; len <= phrase.size(); len++) {
        answer += slidingWindow(phrase, len);
    }

    cout << answer << endl;
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
