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
    int n, m; cin >> n >> m;

    int ans = n;
    int temp1 = n, temp2 = m;
    int x = 1;
    while(temp2 > 0) {
        temp1 += x;
        int fz = temp1 & (-temp1);
        ans |= fz;
        x = fz;
        temp2 -= fz;
    }
    temp1 = n, temp2 = m;
    while(temp1 > 0 && temp2 > 0) {
        int lsb = temp1 & (-temp1);
        temp1 &= ~(lsb);
        temp2 -= lsb;
        --lsb;
        ans |= lsb;
    }

    cout << ans << nl;
}
