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

#define FNAME ""

#define mp make_pair
#define pb push_back

#define pii pair < int, int >
#define pll pair < ll, ll >

using namespace std;

const int MaxN = 10000 + 17;
const ll INF = 1e15 + 17;
const int MOD = 1e8 + 7;
const double eps = 1e-9;
const double pi = 3.14159265359;

string s;
int n;
vector < int > z_func () {
    vector < int > z (n);
    for (int i = 1, l = 0, r = 0; i < n; ++ i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++ z[i];
        if (i + z[i] - 1 > r)
            l = i,  r = i + z[i] - 1;
    }
    return z;
}


int main() {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    cin >> s;
    n = s.size();
    return 0;
}
