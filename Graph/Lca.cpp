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

const int MaxN = 4e5 + 17;
const int INF = 1e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const double pi = 3.14159265359;


int a[MaxN];
vector < int > g[MaxN];
int tin[MaxN], tout[MaxN], up[MaxN][30], l;
int timer;

void dfs (int v, int p) {
    tin[v] = ++ timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++ i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    
    tin[v] = timer;
    for (int i = 0; i < g[v].size(); ++ i) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v);
    }
    tout[v] = ++ timer;
}
bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))
        return a;
    if (upper (b, a))
        return b;
    for (int i = l; i >= 0; -- i)
        if (!upper(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}
int main () {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i) {
        scanf ("%d", a + i);
    }
    for (int i = 1; i < n; ++ i) {
        int x, y;
        scanf ("%d%d", &x, &y);
        g[x].push_back (y);
        g[y].push_back (x);
    }
    l = 1;
    while ((1<<l) <= n)
        ++ l;
    dfs (1, 1);
    cout << lca (5, 4);
    return 0;
}

