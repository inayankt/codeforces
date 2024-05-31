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

int srch(vector<int> &a, int key) {
    int lo = 0, hi = a.size()-1;
    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if(a[mid] == key) {
            return mid;
        } else if(a[mid] > key) {
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    return -1;
}

void solve(int TEST_CASE) {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;

    int diff = xb - xa;
    if(diff <= 0) {
        cout << "Draw\n";
        return;
    }

    if(ya == yb) {
        string winner = (diff % 2) ? "Alice" : "Bob";
        cout << winner << nl;
        return;
    }

    int yaf, ybf;
    bool flag = false;
    if(diff % 2) {
        if(ya < yb) {
            ybf = min(w, yb + diff/2), yaf = min(w, ya + (diff+1)/2);
            if(yaf >= ybf) flag = true;
        } else {
            ybf = max(1ll, yb - diff/2), yaf = max(1ll, ya - (diff+1)/2);
            if(yaf <= ybf) flag = true;
        }
        if(flag) {
            cout << "Alice\n";
        } else {
            cout << "Draw\n";
        }
    } else {
        if(ya > yb) {
            ybf = min(w, yb + diff/2), yaf = min(w, ya + diff/2);
            if(yaf <= ybf) flag = true;
        } else {
            ybf = max(1ll, yb - diff/2), yaf = max(1ll, ya - diff/2);
            if(yaf >= ybf) flag = true;
        }
        if(flag) {
            cout << "Bob\n";
        } else {
            cout << "Draw\n";
        }
    }
}
