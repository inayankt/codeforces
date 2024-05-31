#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define nl      '\n'
#define no      cout<<"NO\n"
#define yes     cout<<"YES\n"

void solve(int);

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1, cnt = 1;
    cin >> t;
    while(t--) {
        solve(cnt++);
    }

    return 0;
}

void solve(int TEST_CASE) {
    int n, k; cin >> n >> k;
    for(int i=0; i<k; ++i) {
        int r, c; cin >> r >> c;
        if(r == c) --n;
        else n -= 2;
    }

    int mod = 1e9 + 7;
    int prev2 = 1, prev1 = 1;
    for(int i=2; i<=n; ++i) {
        int curr = prev1 + 2 * (i-1) * prev2;
        curr %= mod;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << nl;
}
