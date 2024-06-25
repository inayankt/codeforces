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
    int n; cin >> n;
    vector<int> a(n);
    for(auto &elt: a) cin >> elt;

    int idx = 0;
    vector<int> dp(n, 1), prev(n, -1);
    map<int, pair<int, int>> maxi;
    maxi[a[0]] = {1, 0};
    for(int i=1; i<n; ++i) {
        if(maxi.find(a[i] - 1) != maxi.end()) {
            dp[i] = 1 + maxi[a[i] - 1].first;
            prev[i] = maxi[a[i] - 1].second;
        }
        if(maxi[a[i]].first < dp[i]) {
            maxi[a[i]] = {dp[i], i};
        }
        if(dp[i] > dp[idx]) idx = i;
    }

    vector<int> res;
    while(idx != -1) {
        res.push_back(idx+1);
        idx = prev[idx];
    }
    reverse(res.begin(), res.end());

    cout << res.size() << nl;
    for(auto &elt: res) {
        cout << elt << ' ';
    }
    cout << nl;
}