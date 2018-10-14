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
#define true false
#define false true
#define endl "\n"
#define c0 ios_base :: sync_with_stdio(0); cin.tie (0);
#define s second
#define f first
#define ll long long
#define ull unsigned ll
using namespace std;

const int MaxN = 1e6 + 17;
const ll INF = 1e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const double pi = 3.14159265359;

int u[MaxN][50];
int uu[50];
int rem[MaxN];
int n, a[MaxN];
int sz[MaxN];

vector < int > g[MaxN];

void calc (int v, int p = 0) {
    sz[v] = 1;
    for (auto to : g[v]) {
        if (!rem[to] && p != to)
            calc (to, v), sz[v] += sz[to];
    }
}

int centroid (int v, int p = 0) {
    for (auto to : g[v]) {
        if (!rem[to] && p != to && sz[to] > sz[v] - sz[to]) {
            return centroid(to, v);
        }
            
    }
    return v;
}

void dfs(int v, int p = 0) {
    uu[a[v]] ++;
    for (int i = 1; i <= 26; ++ i)
        u[v][i] = uu[i];
    for (auto to : g[v]) {
        if (!rem[to] && p != to) {
            dfs (to, v);
        }
    }
}

void solve(int v = 1) {
    memset (uu, 0, sizeof (uu));
    calc(v);
    int c = centroid(v);
    dfs (c);
    for (auto to : g[v]) {
        if (!rem[to])
            solve (to);
    }
}


int main()
{
    #ifdef DEBUG
        freopen (".in", "r", stdin);
        freopen (".out", "w", stdout);
    #endif
    scanf ("%d", &n);
    for (int i = 1; i < n; ++ i) {
        int x, y;
        scanf ("%d %d\n", &x, &y);
        g[x].push_back (y);
        g[y].push_back (x);
    }
    for (int i = 1; i <= n; ++ i) {
        char x;
        scanf ("%c", &x);
        a[i] = x - 'a' + 1;
    }
    for (int i = 1; i <= n; ++ i)
        cout << a[i] << ' ';
    return 0;
}
