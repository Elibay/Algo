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
const int INF = 1e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const double pi = 3.14159265359;

string s;

int a[MaxN], na[MaxN], c[MaxN], nc[MaxN], h[MaxN];
int p[MaxN], lcp[MaxN];

int n, cn;

bool cmp (int i, int j) {
    return (s[i] < s[j]);
}

int main () {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    cin >> s;
    s += '#';
    n = int (s.size());
    for (int i = 0; i < n; ++ i) {
        a[i] = i;
    }
    sort (a, a + n, cmp);
    for (int i = 0; i < n; ++ i) {
        if (i == 0 || s[a[i]] != s[a[i - 1]])
            h[cn] = i, cn ++;
        c[a[i]] = cn - 1;
    }
    for (int len = 1; len < n; len += len) {
        for (int j = 0; j < n; ++ j) {
            int i = a[j] - len;
            if (i < 0)
                i += n;
            na[h[a[c[i]]] ++] = i;
        }
        cn = 0;
        for (int i = 0; i < n; ++ i) {
            a[i] = na[i];
            if (i == 0 || c[a[i]] != c[a[i - 1]] || c[(a[i] + len) % n] != c[(a[i - 1] + len) % n])
                h[cn] = i, cn ++;
            nc[a[i]] = cn - 1;
        }
        memcpy (c, nc, n * sizeof (int));
    }
    for (int i = 0; i < n; ++ i)
        p[a[i]] = i;
    int m = 0;
    for (int i = 0; i < n; ++ i) {
        int j = p[i];
        if (j == n - 1) {
            lcp[j] = 0;
            m = 0;
            continue;
        }
        m = max (m - 1, 0);
        while (i + m < n && a[j + 1] + m < n && s[i + m] == s[a[j + 1] + m])
            m ++;
        lcp[j] = m;
    }
    
    return 0;
}
