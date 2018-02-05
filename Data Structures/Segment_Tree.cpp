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


int t[4 * MaxN];
int a[MaxN];
void build (int v, int l, int r) {
	if (l == r) 
	{
		t[v] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build (v + v, l, m);
	build (v + v + 1, m + 1, r);
	t[v] = t[v + v] + t[v + v + 1];
}
int get (int v, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return t[v];
	}
	if (l > R || r < L) 
		return 0;
	int m = (l + r) >> 1;
	return get (v + v, l, m, L, R) + get (v + v + 1, m + 1, r, L, R);
}






int main () {

	return 0;
}