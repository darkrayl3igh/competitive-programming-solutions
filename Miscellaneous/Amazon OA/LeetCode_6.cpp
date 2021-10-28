// https://leetcode.com/discuss/interview-question/1488281/Amazon-OA
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
    string book; cin >> book;
    int leftZeroes = 0, rightZeroes = 0, leftOnes = 0, rightOnes = 0, answer = 0;
    for(char& page: book) {
        rightZeroes += (page == '0');
        rightOnes += (page == '1');
    }

    for(char& page: book) {
        if(page == '0') {
            answer += leftOnes * rightOnes;
            leftZeroes++;
            rightZeroes--;
        } else {
            answer += leftZeroes * rightZeroes;
            leftOnes++;
            rightOnes--;
        }
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