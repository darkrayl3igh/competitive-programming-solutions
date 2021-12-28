// GALATIANS 4:16

// #include "/Users/shivaber/Desktop/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

#define fo(i,n) for(i = 0; i < n; i++)
#define Fo(i,k,n) for(i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
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

ll calculate_quarrles(vector<ll> guests, int i, int j);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

    int t = 1; cin >> t;
    while(t--)
    {
        ll guests_count, table_cost; cin >> guests_count >> table_cost;
        if(guests_count < 200)
        {
            ll dp_value;
            vector<ll> guests(guests_count), dp(guests_count + 1);
            vector< vector<ll> > quarrles(guests_count, vector<ll>(guests_count, 0));
            for(int i = 0; i < guests_count; i++)
                cin >> guests[i];
            for(int i = 0; i < guests_count; i++)
                for(int j = i; j < guests_count; j++)
                    quarrles[i][j] = calculate_quarrles(guests, i, j);
            dp[guests_count] = table_cost; dp[guests_count - 1] = table_cost;
            for(int i = guests_count - 2; i > -1; i--)
            {
                dp_value = quarrles[i][guests_count - 1] + table_cost;
                for(int j = guests_count - 1; j > i; j--)
                {
                    dp_value = min(dp_value, quarrles[i][j - 1] + table_cost + dp[j]);
                }
                dp[i] = dp_value;
            }
            cout << dp[0];
            newline;
        }
        else
        {
        int itr = 0, start = 0, quarrels, total_quarrels = 0, left_table, right_table, merged_table; 
        vector<int> guests(guests_count), families(101); vector< pair<int, int> > splits; bool flag;
        for(int i = 0; i < guests_count; i++)
            cin >> guests[i];
        while(itr < guests_count)
        {
            if(!families[guests[itr]]) {families[guests[itr]]++; itr++;}
            else
            {
                splits.push_back(mp(start, itr - 1)); start = itr;
                for(int i = 0; i < 102; i++) families[i] = 0;
            }
        }
        splits.push_back(mp(start, itr - 1));
        for(int i = 0; i < 102; i++) families[i] = 0;
        auto ptr = splits.begin(); auto ptr_2 = splits.begin(); ptr_2++; flag = true;
        while(true)
        {
            ptr = splits.begin(); ptr_2 = splits.begin(); ptr_2++; flag = true;
            while(ptr_2 != splits.end())
            {
                for(int j = 0; j < 102; j++) families[j] = 0; quarrels = 0;
                for(int i = (*ptr).F; i <= (*ptr).S; i++)
                {
                    if(families[guests[i]] == 0) {families[guests[i]]++;}
                    else if(families[guests[i]] == 1) {families[guests[i]]++; quarrels += 2;}
                    else quarrels++;
                }
                left_table = table_cost + quarrels;
                for(int j = 0; j < 102; j++) families[j] = 0; quarrels = 0;
                for(int i = (*ptr_2).F; i <= (*ptr_2).S; i++)
                {
                    if(families[guests[i]] == 0) {families[guests[i]]++;}
                    else if(families[guests[i]] == 1) {families[guests[i]]++; quarrels += 2;}
                    else quarrels++;
                }
                right_table = table_cost + quarrels;
                for(int j = 0; j < 102; j++) families[j] = 0; quarrels = 0;
                for(int i = (*ptr).F; i <= (*ptr_2).S; i++)
                {
                    if(families[guests[i]] == 0) {families[guests[i]]++;}
                    else if(families[guests[i]] == 1) {families[guests[i]]++; quarrels += 2;}
                    else quarrels++;
                }
                merged_table = table_cost + quarrels;
                if(merged_table < left_table + right_table)
                {
                    (*ptr).S = (*ptr_2).S;
                    splits.erase(ptr_2); flag = false;
                    for(int j = 0; j < 102; j++) families[j] = 0;
                }
                else {ptr++; ptr_2++;}
            }
            if(flag) break;
        }   
        for(auto ptr = splits.begin(); ptr != splits.end(); ptr++)
        {
            for(int j = 0; j < 102; j++) families[j] = 0; quarrels = 0;
            for(int i = (*ptr).F; i <= (*ptr).S; i++)
            {
                if(families[guests[i]] == 0) {families[guests[i]]++;}
                else if(families[guests[i]] == 1) {families[guests[i]]++; quarrels += 2;}
                else quarrels++;
            }
            total_quarrels += quarrels;
        }
        // for(auto ptr = splits.begin(); ptr != splits.end(); ptr++)
        //     cout << (*ptr).F << " " << (*ptr).S << endl;
        cout << table_cost * splits.size() + total_quarrels << endl;
        }
    }
    return 0;
}

ll calculate_quarrles(vector<ll> guests, int i, int j)
{
    ll answer = 0; vector<int> families(101);
    if(i == j) return 0;
    for(int k = i; k <= j; k++)
    {
        if(!families[guests[k]]) families[guests[k]]++;
        else if(families[guests[k]] == 1) {answer += 2; families[guests[k]]++;}
        else answer++;
    }
    return answer;
}
