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

vector < int > g[MaxN];
vector < pii > ans;
int u[MaxN];
int timer, tin[MaxN], fup[MaxN];

void dfs (int v, int p = -1) {
    u[v] = 1;
    tin[v] = fup[v] = ++ timer;
    for (auto to : g[v]) {
        if (to == p)
            continue;
        if (u[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v])
                ans.push_back (mp(v, to));
        }
    }
}


int main() {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i) {
        int x, y;
        scanf ("%d%d", &x, &y);
        g[x].push_back (y);
        g[y].push_back (x);
    }
    for (int i = 1; i <= n; ++ i)
        if (!u[i])
            dfs (i);
    return 0;
}
