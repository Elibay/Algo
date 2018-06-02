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

const int MaxN = 1e6 + 17;
const int INF = 1e9 + 17;
const int MOD = 1e8 + 7;
const double eps = 1e-9;
const double pi = 3.14159265359;

int pos[MaxN], u[MaxN], pr[MaxN];

vector < int > g[MaxN];

int n, ans;

int khun (int v) {
    if (u[v])
        return false;
    u[v] = 1;
    for (int i = pos[v]; i < g[v].size(); ++ i) {
        int to = g[v][i];
        if (pr[to] == -1 || khun (pr[to])) {
            pr[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    c0
//    cin >> n >> k;
    // read graph
    memset (pr, -1, sizeof (pr));
    for (int i = 1; i <= n; ++ i) {
        memset (u, 0, sizeof (u));
        ans += khun(i);
    }
    cotu << ans;
    return 0;
}
