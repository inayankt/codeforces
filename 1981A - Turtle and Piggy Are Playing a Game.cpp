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

int msb(int n) {
    n /= 2;
    int cnt = 0;
    while(n) {
        ++cnt;
        n /= 2;
    }
    return cnt;
}

void solve(int TEST_CASE) {
    int l, r; cin >> l >> r;

    cout << msb(r) << nl;
}
