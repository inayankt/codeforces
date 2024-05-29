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
    vector<int> a(n);
    for(auto &elt: a) cin >> elt;

    int yasser = accumulate(a.begin(), a.end(), 0ll);

    auto kadane = [&] (int st, int en) -> int {
        int sum = 0, curr = 0;
        for(int i=st; i<en; ++i) {
            curr += a[i];
            if(curr < 0) {
                curr = 0;
            }
            sum = max(sum, curr);
        }
        return sum;
    };

    int adel = max(kadane(0, n-1), kadane(1, n));

    if(yasser > adel) {
        yes;
    } else {
        no;
    }
}
