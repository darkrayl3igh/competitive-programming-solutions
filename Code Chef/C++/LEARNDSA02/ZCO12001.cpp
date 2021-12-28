// GALATIANS 4:16

#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#endif

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <optional>
#include <string_view>
#include <variant>
#endif

using namespace std;

#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long int
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);
#define sonic ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int mod = 1000000007;

ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

int main()
{
    /* sonic
    input_stream; */

    int n, i, counter = 0, depth = 1, depthi, max_seq = -1, sub_max_seq = 0, max_seqi, itr; si(n);
    vi brackets(n), pointers;
    fo(i, n)
    {
        si(brackets[i]);
        if(brackets[i] == 1) counter++;
        else counter--;
        depth = max(depth, counter);
        sub_max_seq++;
        if(counter == 0) 
        {
            max_seq = max(max_seq, sub_max_seq);
            sub_max_seq = 0;
            pointers.pb(i);
        }
    }
    fo(i, n)
    {
        if(brackets[i] == 2) counter--;
        else counter++;
        if(counter == depth) { depthi = i; break; }
    }
    fo(i, pointers.size())
    {
        itr = pointers[i]; itr--; counter = 1; sub_max_seq = 1;
        while(counter != 0)
        {
            if(brackets[itr] == 1) counter--;
            else counter++;
            sub_max_seq++;
            itr--;
        }
        if(sub_max_seq == max_seq)
        {
            max_seqi = pointers[i] + 1 - max_seq;
            break;
        }
    }
    cout << depth << " " << depthi + 1 << " " << max_seq << " " << max_seqi + 1 << endl;
    return 0;

}