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

// #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// #endif

    int t = 1, cnt = 1;
    // cin >> t;
    while(t--) {
        solve(cnt++);
    }

    return 0;
}

void solve(int TEST_CASE) {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &elt: a) cin >> elt;

    sort(a.begin(), a.end());

    int ans = 0;
    for(int i=0; i<n; ++i) {
        int ref = ceil(1.0 * a[i] / 2);
        int idx = lower_bound(a.begin(), a.end(), ref) - a.begin();
        ans = max(ans, i - idx + 1);
    }

    cout << (n - ans) << nl;
}
