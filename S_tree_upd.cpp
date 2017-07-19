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

struct Tree
{
    int x, add;
    Tree()
    {
        x = 0;
        add = 0;
    }
} t[MaxN];

int a[MaxN];

void push (int v)
{
    if (t[v].add)
    {
        t[v].x += t[v].add;
        t[v + v].add += t[v].add;
        t[v + v + 1].add += t[v].add;
        t[v].add = 0;
    }
}
int get (int v, int l, int r, int L, int R)
{
    push (v);
    if (l > R || r < L)
        return INF;
    if (L <= l && r <= R)
        return t[v].x;
    int m = (l + r) >> 1;
    return min (get (v + v, l, m, L, R), get (v + v + 1, m + 1, r, L, R));
}
void upd(int v, int l, int r, int L, int R, int x)
{
    push(v);
    if (l > R || r < L)
        return;
    if (L <= l && r <= R)
    {
        t[v].add += x;
        push(v);
        return;
    }
    int m = (l + r) >> 1;
    upd (v + v, l, m, L, R, x);
    upd (v + v + 1, m + 1, r, L, R, x);
    t[v].x = min (t[v + v].x, t[v + v + 1].x);
}


int main()
{
    #ifdef DEBUG
        freopen (".in", "r", stdin);
        freopen (".out", "w", stdout);
    #endif
    
    return 0;
}
