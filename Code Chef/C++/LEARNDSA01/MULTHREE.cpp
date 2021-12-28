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
#include <span>
#include <stop_token>
// #include <syncstream>
#include <version>
#endif

#define sonic ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    long long int t; cin >> t;
    while(t--)
    {
        long long int k, d0, d1, d2, sum, s;
        cin >> k >> d0 >> d1;
        d2 = (d0 + d1) % 10; sum = d0 + d1 + d2;
        s = ((2 * (d0 + d1)) % 10) + ((4 * (d0 + d1)) % 10) + ((8 * (d0 + d1)) % 10) + ((16 * (d0 + d1)) % 10);
        sum += s * ((k - 3) / 4);
        if ((k - 3) % 4 == 1)
            sum += (2 * (d0 + d1)) % 10;
        else if ((k - 3) % 4 == 2)
            sum += ((2 * (d0 + d1)) % 10) + ((4 * (d0 + d1)) % 10);
        else if ((k - 3) % 4 == 3)
            sum += ((2 * (d0 + d1)) % 10) + ((4 * (d0 + d1)) % 10) + ((8 * (d0 + d1)) % 10);
        if(sum % 3 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}