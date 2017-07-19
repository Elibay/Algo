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
 
const int MaxN = 1e6 + 17;
const ll INF = 1e9 + 17;
const int MOD = 1e9 + 17;
const double eps = 1e-9;
 
int n, Sum;
 
int d[MaxN], l[MaxN], a[MaxN], b[MaxN];
 
int get(int x)
{
    if (x == d[x])
        return x;
    return d[x] = get(d[x]);
}
 
void add (int x, int y)
{
    x = get(x);
    y = get(y);
    if (x == y)
        return;
    if (l[x] > l[y])
        swap(x, y);
    d[x] = y;
    l[y] += l[x];
}
 
int main()
{
    #ifdef DEBUG
        freopen (".in", "r", stdin);
        freopen (".out", "w", stdout);
    #endif
    scanf ("%d%d", &n, &c);
    for (int i = 1; i <= n; ++ i)
    {
        l[i] = 1;
        d[i] = i;
    }
    
    return 0;
         
}
