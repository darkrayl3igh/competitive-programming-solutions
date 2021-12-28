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

#define sonic ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main()
{
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int t; cin >> t;
    while(t--)
    {
        int best_case_a, best_case_b;
        int n, a = 0, b = 0, i; cin >> n;
        string s; cin >> s;
        for(i = 1; i <= 2 * n; i++)
        {
            if(i % 2 == 1 && s[i - 1] == '1') a++;
            else if(i % 2 == 0 && s[i - 1] == '1') b++;
            best_case_a = a + n - ceil(i / 2.0); best_case_b = b + n - floor(i / 2.0);
            if((best_case_a > best_case_b && a > best_case_b) || (best_case_b > best_case_a && b > best_case_a)) break;
        }
        if(a == b) cout << 2 * n << endl;
        else cout << i << endl;
    }
    return 0;
}