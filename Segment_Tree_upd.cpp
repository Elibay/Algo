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

const int MaxN = 1e5 + 17;
const int INF = 1e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const double pi = 3.14159265359;


int a[MaxN];
struct Tree
{
    int x, add;
    Tree()
    {
        x = 0;
        add = 0;
    }
} t[MaxN];

void push (int v, int l, int r)
{
    if (t[v].add)
    {
        t[v].x += t[v].add * (r - l + 1);
        t[v + v].add += t[v].add;
        t[v + v + 1].add += t[v].add;
        t[v].add = 0;
    }
}

void upd (int v, int l, int r, int L, int R, int x)
{
    push(v, l, r);
    if (l > R || r < L)
        return;
    if (L <= l && r <= R)
    {
        t[v].add += x;
        push(v, l, r);
        return;
    }
    int m = (l + r) >> 1;
    upd (v + v, l, m, L, R, x);
    upd (v + v + 1, m + 1, r, L, R, x);
    t[v].x = t[v + v].x + t[v + v + 1].x;
}

int get (int v, int l, int r, int L, int R) {
    push (v, l, r);
    if (L <= l && r <= R) {
        return t[v].x;
    }
    if (l > R || r < L)
        return 0;
    int m = (l + r) >> 1;
    return get (v + v, l, m, L, R) + get (v + v + 1, m + 1, r, L, R);
}

int main () {
    
    return 0;
}
