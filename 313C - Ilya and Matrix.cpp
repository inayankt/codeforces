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
    // cin >> t;
    while(t--) {
        solve(cnt++);
    }

    return 0;
}

void solve(int TEST_CASE) {
    int x; cin >> x;
    vector<int> a(x);
    for(auto &elt: a) cin >> elt;

    sort(a.begin(), a.end());
    vector<int> pref(x+1, 0);
    for(int i=0; i<x; ++i) {
        pref[i+1] = pref[i] + a[i];
    }

    int ans = 0;
    int all = x;
    while(x) {
        ans += pref[all] - pref[all - x];
        x /= 4;
    }

    cout << ans << nl;
}
