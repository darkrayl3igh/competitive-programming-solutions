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
// #include <execution>
#include <optional>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <bit>
#include <compare>
#include <concepts>
#include <numbers>
#include <ranges>
#include <span>s
#include <stop_token>
// #include <syncstream>
#include <version>
#endif

using namespace std;

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int t; cin >> t;
    while(t--)
    {
        vector<int> alpha(26), beta(26);
        string s; cin >> s;
        int n = s.size();
        if(n % 2 == 0)
        {
            for(int i = 0; i < n/2; i++)
                alpha[s[i] - 'a']++;
            for(int i = n/2; i < n; i++)
                beta[s[i] - 'a']++;
        }
        else
        {
            for(int i = 0; i < n/2; i++)
                alpha[s[i] - 'a']++;
            for(int i = n/2 + 1; i < n; i++)
                beta[s[i] - 'a']++;
        }
        bool flag = true;
        for(int i = 0; i < 26; i++)
        {
            if(alpha[i] != beta[i]) flag = false;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}