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
    string a, b; cin >> a >> b;

    int ans = 0;
    for(int i=0; i<n-1; ++i) {
        if(a[i] != b[i]) {
            if(a[i+1] != b[i+1] && a[i+1] != a[i]) {
                swap(a[i], a[i+1]);
            } else {
                a[i] = b[i];
            }
            ++ans;
        }
    }
    ans += (a[n-1] != b[n-1]);

    cout << ans << nl;
}
