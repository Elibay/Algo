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


string S;
ull h[MaxN], d[MaxN];

ull get (int x, int l, int r)
{
    return h[r] - h[l - 1] * d[r - l + 1];
}

int main()
{
    #ifdef DEBUG
        freopen (".in", "r", stdin);
        freopen (".out", "w", stdout);
    #endif
    d[0] = 1;
    for (int i = 1; i <= S.size(); ++ i)
        h[i] = h[i - 1] * 37 + S[i - 1] , d[i] = d[i - 1] * 37;
    
    return 0;
}
