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

    vector<pair<int, int>> v;
    int st = 0;
    for(int i=1; i<n; ++i) {
        if(a[i] <= a[i-1]) {
            v.push_back({st, i});
            st = i;
        }
    }
    v.push_back({st, n});

    int m = v.size();
    int ans = 0;
    for(int i=0; i<m-1; ++i) {
        if(v[i+1].second - v[i+1].first > 1 && a[v[i+1].first + 1] - a[v[i].second - 1] > 1) {
            ans = max(ans, v[i+1].second - v[i].first);
        } else if(v[i].second - v[i].first > 1 && a[v[i+1].first] - a[v[i].second - 2] > 1) {
            ans = max(ans, v[i+1].second - v[i].first);
        } else {
            ans = max(ans, v[i].second - v[i].first + 1);
        }
    }
    ans = max(ans, v[m-1].second - v[m-1].first + 1);

    cout << min(ans, n) << nl;
}
