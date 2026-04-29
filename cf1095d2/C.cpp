#include <bits/stdc++.h>
using namespace std;

static bool can_make_mex(int k, const vector<int>& a) {
    multiset<int> s(a.begin(), a.end());

    for (int v = k - 1; v >= 0; --v) {
        auto it = s.lower_bound(v);

        if (it != s.end() && *it == v) {
            s.erase(it);
        } else {
            it = s.lower_bound(2 * v + 1);
            if (it == s.end()) return false;
            s.erase(it);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int lo = 0, hi = n, mexwf = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (can_make_mex(mid, a)) {
                mexwf = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << mexwf << '\n';
    }
    return 0;
}
