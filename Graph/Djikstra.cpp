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
#define s second
#define f first
#define ll long long
#define ull unsigned long long

using namespace std;

const int MaxN = 5e5 + 17;
const int INF = 1e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const double pi = 3.14159265359;

int n, m;
vector < pair < int, int > > g[MaxN];
set < pair < int, int > > S;
int s, f;
int d[MaxN];

int main () {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf ("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; ++ i) {
        int x, y, w;
        scanf ("%d%d%d", &x, &y, &w);
        g[x].push_back (make_pair (y, w));
        g[y].push_back (make_pair (x, w));
    }
    for (int i = 1; i <= n; ++ i)
        d[i] = INF;
    d[s] = 0;
    S.insert (make_pair (0, s));
    while (!S.empty()) {
        int v = S.begin() -> second;
        S.erase (*S.begin());
        for (int i = 0; i < g[v].size(); ++ i) {
            int to = g[v][i].first;
            int w = g[v][i].second;
            if (d[v] + w < d[to]) {
                S.erase(make_pair (d[to], to));
                d[to] = d[v] + w;
                S.insert(make_pair (d[to], to));
            }
        }
    }
    return 0;
}
