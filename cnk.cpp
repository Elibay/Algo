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
#define ll long long
#define ull unsigned long long

#define FNAME "fate"

using namespace std;

const int MaxN = 1e4 + 17;
const int INF = 1e9 + 17;
const int MOD = 1e6 + 3;
const double eps = 1e-4;
const double pi = 3.14159265359;

int f[MaxN], inv[MaxN];


inline int binpow(int a, int n, int MOD) {
    int res = 1;
    while (n) {
        if (n & 1) res = (res * 1ll * a) % MOD;
        a = (a * 1ll * a) % MOD;
        n >>= 1;
    }
    return res;
}

inline int get(int n, int k) {
    return f[n] * 1ll * inv[k] % MOD * 1ll * inv[n - k] % MOD;
}


int main () {
	inv[0] = f[0] = 1;
    for (int i = 1; i < MaxN; ++ i) {
        f[i] = f[i - 1] * 1ll * i % MOD;
        inv[i] = binpow(f[i], MOD - 2, MOD);
    }
	return 0;
}

