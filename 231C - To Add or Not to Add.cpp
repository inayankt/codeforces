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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &elt: a) cin >> elt;

    sort(a.begin(), a.end());

    int mx = 0, ans;
    int l = n-1, r = n-1;
    int s = 0;
    while(l >= 0) {
        s += a[r] - a[l];
        while(s > k) {
            --r;
            s -= (r-l+1) * (a[r+1] - a[r]);
        }
        if(r-l+1 >= mx) {
            mx = r-l+1;
            ans = a[r];
        }
        --l;
    }

    cout << mx << ' ' << ans << nl;
}