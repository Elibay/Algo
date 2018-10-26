#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>

#define c0 ios_base :: sync_with_stdio(0); cin.tie (0);
#define ll long long
#define ull unsigned long long

using namespace std;

const int MaxN = 1e6 + 17;
const int INF = 1e9 + 17;
const int MOD = 1e9 + 3;
const double eps = 1e-4;
const double pi = 3.14159265359;

int main () {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector < int > d1(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++ i) {
        int k = (i > r ? 0 : min (d1[l + r - i], r - i)) + 1;
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k])
            ++ k;
        d1[i] = k --;
        if (i + k > r)
            l = i - k,  r = i + k;
    }
    vector < int > d2(n);
    l = 0, r = -1;
    for (int i = 0; i < n; ++ i) {
        int k = (i > r ? 0 : min (d2[l + r - i + 1], r - i + 1)) + 1;
        while (i + k - 1 < n && i - k >= 0 && s[i + k - 1] == s[i - k])
            ++ k;
        d2[i] = k --;
        if (i + k > r)
            l = i - k,  r = i + k;
    }
    int sum = 0;
    for (int i = 0; i < n; ++ i) {
        sum += d1[i];
        sum += d2[i] - 1;
    }
    cout << sum;
    
    return 0;
}
