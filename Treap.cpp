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
#include <unordered_set>
#define endl "\n"
#define c0 ios_base :: sync_with_stdio(0); cin.tie (0);
#define s second
#define f first
#define ll long long
#define ull unsigned ll
using namespace std;

const int MaxN = 2e5 + 17;
const int INF = 1e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-3;
const double pi = 3.14159265359;

struct node {
    node *l, *r;
    int cnt, x, y;
    node () {
        y = rand();
        cnt = 1;
        l = r = NULL;
        x = 0;
    }
} *t;

int getSize (node *t) {
    if (!t)
        return 0;
    return t -> cnt;
}

void upd (node *t) {
    if (!t)
        return;
    t -> cnt = getSize (t -> l) + getSize (t -> r) + 1;
}
node* Merge(node *a, node *b) {
    if (!a)
        return b;
    if (!b)
        return a;
    if (a -> y > b -> y) {
        a -> r = Merge (a -> r, b);
        upd (a);
        return a;
    }
    else {
        b -> l = Merge (a, b -> l);
        upd (b);
        return b;
    }
}
void split (node *v, int x, node* &a, node* &b) {
    if (!v)
        return void (a = b = NULL);
    int cnt = getSize (v);
    if (cnt <= x) {
        split (v -> r, x - cnt, v -> r, b);
        a = v;
    }
    else {
        split (v -> l, x, a, v -> l);
        b = v;
    }
    upd (a);
    upd (b);
}

int main() {
    #ifdef DEBUG
        freopen (".in", "r", stdin);
        freopen (".out", "w", stdout);
    #endif
    
    return 0;
}

