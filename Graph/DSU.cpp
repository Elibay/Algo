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
const ll INF = 1e18 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const double pi = 3.14159265359;
 
int n, m;
int p[MaxN], sz[MaxN];
 
int get (int x) {
    if (x == p[x])
        return x;
    return p[x] = get(p[x]);
}
 
void add (int x, int y) {
    x = get (x);
    y = get (y);
    if (x == y)
        return;
    if (sz[x] > sz[y])
        swap(x, y);
    p[x] = y;
    sz[y] += sz[x];
}
 
int main () {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    for (int i = 1; i <= n; ++ i) {
        p[i] = i;
        sz[i] = 1;
    }
    return 0;
}
