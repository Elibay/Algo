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

const int MaxN = 2e6 + 17;
const int INF = 1e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const double pi = 3.14159265359;


double f (double r) {
    return 0;
}
int main () {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    double l = 0, r = 1e9;
    for (int i = 1; i <= 30; ++ i)
    {
        double m3 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m3);
        double f2 = f(m2);
        if (f1 < f2)
            l = m3;
        else
            r = m2;
    }
    
    return 0;
}
