// GALATIANS 4:16

#include "bits/stdc++.h"

using namespace std;

#define fo(i,n) for(int i = 0; i < n; i++)
#define Fo(i,k,n) for(int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long int
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define debug(x) cout << #x << "=" << x << endl
#define debug_2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define newline cout << endl
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int MOD = 1000000007;

ll gcd (ll a, ll b) {return (a ? gcd(b % a, a) : b);}
int mpow(int base, int exp) {
    base %= MOD;
    int result = 1;
    while (exp > 0) {
      if (exp & 1) result = ((ll)result * base) % MOD;
      base = ((ll)base * base) % MOD;
      exp >>= 1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

    int t = 1; cin >> t;
    while(t--)
    {
        int players_count, months_count; cin >> players_count >> months_count;
        int answer = 0;
        vector< vector<int> > ratings(players_count, vector<int>(months_count + 1, 0));
        for(int i = 0; i < players_count; i++)
            cin >> ratings[i][0];
        for(int i = 0; i < players_count; i++)
        {
            for(int j = 1; j <= months_count; j++)
            {
                int change; cin >> change;
                ratings[i][j] = ratings[i][j - 1] + change;
            }
        }
        vector<pair<int, int> > max_ratings(players_count);
        for(int i = 0; i < players_count; i++)
        {
            int max_rating = -1;
            for(int j = 1; j <= months_count; j++)
            {
                if(ratings[i][j] > max_rating) {max_ratings[i] = {ratings[i][j], j}; max_rating = ratings[i][j];}
            }
        }
        vector<pair<int, int> > max_ranks(players_count, {INT_MAX, INT_MAX});
        for(int i = 1; i <= months_count; i++)
        {
            vector<pair<int, int> > monthly_ranks;
            for(int j = 0; j < players_count; j++)
            {
                monthly_ranks.pb({ratings[j][i], j});
            }
            sort(monthly_ranks.begin(), monthly_ranks.end(), greater<>());
            int rank = 1, counter = 1;
            for(int j = 0; j < players_count - 1; j++)
            {
                if(rank < max_ranks[monthly_ranks[j].S].F)
                    max_ranks[monthly_ranks[j].S] = {rank, i};
                if(monthly_ranks[j].F == monthly_ranks[j + 1].F) counter++;
                else {rank += counter; counter = 1;}
            }
            if(rank < max_ranks[monthly_ranks[players_count - 1].S].F)
                max_ranks[monthly_ranks[players_count - 1].S] = {rank, i};
        }
        for(int i = 0; i < players_count; i++)
        {
            if(max_ratings[i].S != max_ranks[i].S) answer++;
        }
        cout << answer << endl;
    }
    return 0;
}