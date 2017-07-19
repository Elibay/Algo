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
#define endl "\n"
#define c0 ios_base :: sync_with_stdio(0); cin.tie (0);
#define s second
#define f first
#define ll long long
#define ull unsigned ll
using namespace std;

const int MaxN = 1e5 + 17;
const ll INF = 2e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-3;
const double pi = 3.14159265359;

int t[8 * MaxN];

void upd (int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        t[v] = max (t[v], val);
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
    {
        upd (v + v, l, m, pos, val);
    }
    else
    {
        upd (v + v + 1, m + 1, r, pos, val);
    }
    t[v] = max (t[v + v], t[v + v + 1]);
}
int Get (int v, int l, int r, int L, int R)
{
    if (l > R || r < L)
        return 0;
    if (L <= l && r <= R)
        return t[v];
    int m = (l + r) >> 1;
    return max (Get (v + v, l, m, L, R), Get (v + v + 1, m + 1, r, L, R));
}


int main()
{
    #ifdef DEBUG
        freopen (".in", "r", stdin);
        freopen (".out", "w", stdout);
    #endif
    
    return 0;
}
