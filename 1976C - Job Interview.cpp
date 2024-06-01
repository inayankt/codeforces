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
    int sz = n+m+1;
    vector<int> a(sz), b(sz);
    for(auto &elt: a) cin >> elt;
    for(auto &elt: b) cin >> elt;

    int temp = 0;
    vector<int> prog, test;
    for(int i=0; i<sz; ++i) {
        if(test.size() > m || (prog.size() <= n && a[i] > b[i])) {
            prog.push_back(i);
            temp += a[i];
        } else {
            test.push_back(i);
            temp += b[i];
        }
    }

    vector<int> ans(sz);
    for(int i=0; i<sz; ++i) {
        if(binary_search(prog.begin(), prog.end(), i)) {
            ans[i] = temp - a[i];
            if(prog.size() != n+1) {
                ans[i] += a[test.back()] - b[test.back()];
            }
        } else {
            ans[i] = temp - b[i];
            if(test.size() != m+1) {
                ans[i] += b[prog.back()] - a[prog.back()];
            }
        }
    }

    for(auto &elt: ans) {
        cout << elt << ' ';
    }
    cout << nl;
}
