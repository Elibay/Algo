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

const int MaxN = 1000 + 17;
const ll INF = 1e18 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-3;
const double pi = 3.14159265359;

string s;
int na[MaxN], head[MaxN], a[MaxN], color[MaxN], ncolor[MaxN];
int n, cn;

bool cmp (int i, int j)
{
    return (s[i] < s[j]);
}
int main()
{
    #ifdef DEBUG
        freopen (".in", "r", stdin);
        freopen (".out", "w", stdout);
    #endif
    getline (cin, s);
    s += char (31);
    n = s.size();
    for (int i = 0; i < n; i ++)
        a[i] = i;
    sort (a, a + n, cmp);
    for (int i = 0; i < n; i ++)
    {
        if (i == 0 || s[a[i - 1]] != s[a[i]])
            head [cn] = i, color[a[i]] = cn ++;
        else
            color [a[i]] = cn - 1;
    }
    for (int len = 1; len < n; len += len)
    {
        for (int j = 0; j < n; j ++)
        {
            int i = a[j] - len;
            if (i < 0)
                i += n;
            na [head [color [i]] ++] = i;
        }
        cn = 0;
        for (int i = 0; i < n; i ++)
        {
            a[i] = na[i];
            if (i == 0 || color [a [i]] != color [a [i - 1]] || color [(a[i] + len) % n] != color [(a[i - 1] + len) % n])
                head [cn] = i, ncolor [a [i]] = cn ++;
            else
                ncolor [a [i]] = cn - 1;
        }
        memcpy (color, ncolor, n * sizeof (int));
    }
    for (int i = 1; i < n; i ++)
        cout << a[i] + 1 << ' ';
    return 0;
}


