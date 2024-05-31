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
    int n; cin >> n;
    vector<int> a(n), b(n+1);
    for(auto &elt: a) cin >> elt;
    for(auto &elt: b) cin >> elt;

    int ans = 0;
    bool flag = false;
    int mini1 = INT_MAX;
    for(int i=0; i<n; ++i) {
        ans += abs(b[i] - a[i]);
        if(!flag && ((a[i] >= b[n] && b[n] >= b[i]) || (a[i] <= b[n] && b[n] <= b[i]))) {
            ++ans;
            flag = true;
        }
        mini1 = min(mini1, abs(b[n] - a[i]));
        mini1 = min(mini1, abs(b[n] - b[i]));
    }

    if(!flag) {
        int mini2 = INT_MAX;
        for(int i=0; i<n; ++i) {
            mini2 = min(mini2, abs(b[n] - a[i]));
        }
        ans += min(mini1, mini2) + 1;
    }

    cout << ans << nl;
}
