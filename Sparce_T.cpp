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

const int MaxN = 5000 + 17;

int st[30][MaxN], u[MaxN];
int n;
void build()
{
    for (int i = 2; i <= n; ++ i)
        u[i] = u[i / 2] + 1;
    for (int i = 1; i <= n; ++ i)
        st[0][i] = a[i];
    for (int i = 1; i <= u[n]; ++ i)
        for (int j = 1; j <= n; ++ j)
            st[i][j] = max (st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}
int get (int l, int r)
{
    int x = u[(r - l + 1)];
    return max (st[x][l], st[x][r - (1 << x) + 1]);
}
int main()
{
    #ifdef DEBUG
        freopen (".in", "r", stdin);
        freopen (".out", "w", stdout);
    #endif
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++ i)
        scanf ("%d", a + i);
    build ();
    return 0;
}
