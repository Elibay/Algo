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

const int MaxN = 1e5 + 17;
const int INF = 1e9 + 17;
const int MOD = 1e9 + 7;
const double eps = 1e-3;
const double pi = 3.14159265359;

int a[MaxN];
int ans[444][MaxN];
int sz, k, n;
vector < int > v[444];

void fill_array () {
    n = 0;
    for (int i = 0; i < sz; ++ i)
        for (int j = 0; j < v[i].size(); ++ j)
            a[n++] = v[i][j], ans[i][v[i][j]] --;
}

void build () {
    for (int i = 0; i < sz; ++ i) {
        v[i].clear();
    }
    for (int i = 0; i < n; ++ i) {
        v[i / k].push_back (a[i]);
        ans[i / k][a[i]] ++;
    }
}

pair < int, int > get_info (int pos) {
    for (int i = 0; i < sz; ++ i) {
       if (pos < v[i].size())
           return make_pair (i, pos);
        pos -= v[i].size();
    }
    exit (0);
}

int get (pair < int, int > bi) {
    int b_id = bi.first;
    int id = bi.second;
    return v[b_id][id];
}

void del (pair < int, int > bi, int val) {
    int b_id = bi.first;
    int id = bi.second;
    ans[b_id][val] --;
    v[b_id].erase (v[b_id].begin() + id);
}

void insert (pair < int, int > bi, int val) {
    int b_id = bi.first;
    int id = bi.second;
    ans[b_id][val] ++;
    v[b_id].insert (v[b_id].begin() + id, val);
}

int get_ans (int l, int r, int val) {
    pair < int, int > li = get_info (l);
    pair < int, int > ri = get_info (r);
//    cout << li.first << ' ' << ri.first << endl;
//    cout << li.second << ' ' << ri.second << endl;
    int Ans = 0;
    int l1 = li.second;
    int r1 = ri.second;
    if (li.first == ri.first) {
        for (int i = l1; i <= r1; ++ i)
            if (v[li.first][i] == val)
                ++ Ans;
    } else {
        for (int i = li.first + 1; i < ri.first; ++ i)
            Ans += ans[i][val];
        for (int i = l1; i < v[li.first].size(); ++ i)
            if (v[li.first][i] == val)
                ++ Ans;
        for (int i = r1; i >= 0; -- i)
            if (v[ri.first][i] == val)
                ++ Ans;
    }
    return Ans;
}

int main() {
    #ifdef DEBUG
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf ("%d", &n);
    for (int i = 0; i < n; ++ i)
        scanf ("%d", a + i);
    k = 376;
    sz = (n + k - 1) / k;
    int q, last = 0;
    build ();
    scanf ("%d", &q);
    for (int i = 0; i < q; ++ i) {
//        print();
        if (i % 400 == 0 && i > 0) {
            fill_array();
            build ();
        }
        int t, lp, rp, xp;
        scanf ("%d%d%d", &t, &lp, &rp);
        int l = (lp + last - 1) % n;
        int r = (rp + last - 1) % n;
        if (l > r)
            swap (l, r);
        if (t == 1) {
            if (l == r)
                continue;
            pair < int, int > bi = get_info(r);
            pair < int, int > bi2 = get_info (l);
            int x = get (bi);
            del (bi, x);
            insert (bi2, x);
        }
        else {
            scanf ("%d", &xp);
            int x = (xp + last - 1) % n + 1;
            last = get_ans (l, r, x);
            printf ("%d\n", last);
        }
    }
    return 0;
}
