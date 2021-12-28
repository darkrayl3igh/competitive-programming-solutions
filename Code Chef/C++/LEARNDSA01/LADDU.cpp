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
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int t; cin >> t;
    while(t--)
    {
        int n, laddu = 0, count; string nationality, temp;
        cin >> n >> nationality;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            if(temp == "CONTEST_WON") 
            {
                cin >> count;
                if(count < 20) laddu += 20 - count;
                laddu += 300;  
            }
            else if (temp == "TOP_CONTRIBUTOR") laddu += 300;
            else if (temp == "BUG_FOUND")
            {
                cin >> count;
                laddu += count;
            }
            else laddu += 50;
        }
        if(nationality == "INDIAN") cout << laddu / 200 << endl;
        else cout << laddu / 400 << endl;
    }
    return 0;
}