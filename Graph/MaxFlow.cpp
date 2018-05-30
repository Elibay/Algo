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
#define pb push_back

using namespace std;

const int MaxN = 2e4 + 17;
const int INF = 1e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const double pi = 3.14159265359;

struct node {
    int v, to, cap, flow;
};
vector < node > e;
vector < int > g[MaxN];

int start, finish;

void add_edge (int v, int to, int cap) {
    g[v].push_back (e.size());
    e.push_back ({v, to, cap, 0});
    g[to].push_back (e.size());
    e.push_back ({to, v, 0, 0});
}

int d[MaxN], q[MaxN], pt[MaxN];
int head, tail;

inline bool bfs () {
    memset (d, -1, sizeof (d));
    d[start] = 0;
    head = tail = 0;
    q[tail ++] = start;
    while (head < tail) {
        int v = q[head ++];
        for (auto it : g[v]) {
            int to = e[it].to;
            if (d[to] == -1 && e[it].flow < e[it].cap) {
                d[to] = d[v] + 1;
                q[tail ++] = to;
            }
        }
    }
    return d[finish] != -1;
}

int dfs (const int &v, const int &flow) {
    if (v == finish || flow == 0)
        return flow;
    for (int &i = pt[v]; i < g[v].size(); ++ i) {
        int it = g[v][i];
        int to = e[it].to;
        if (d[to] == d[v] + 1 && e[it].cap > e[it].flow) {
            int pushed = dfs (to, min (flow, e[it].cap - e[it].flow));
            if (pushed) {
                e[it].flow += pushed;
                e[it ^ 1].flow -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}
int Flow () {
    for (auto &it : e)
        it.flow = 0;
    int res = 0;
    while (bfs ()) {
        memset (pt, 0, sizeof (pt));
        while (int x = dfs (start, INF))
            res += x;
    }
    return res;
}

int main() {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    int n, m;
    scanf ("%d%d", &n, &m);
    finish = n + n + 1;
    for (int i = 1; i <= n; ++ i) {
        add_edge(start, i, 1);
        add_edge(i + n, finish, 1);
    }
    for (int i = 1; i <= m; ++ i) {
        int x, y;
        scanf ("%d%d", &x, &y);
        add_edge (x, y + n, 1);
    }
    cout << n - Flow();
    return 0;
}
