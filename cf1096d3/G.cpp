#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n = 0) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    int sum(int idx) {
        int ret = 0;
        for (; idx > 0; idx -= idx & -idx) ret += bit[idx];
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<ll> a(n + 1), pref(n + 1);
        vector<ll> vals;

        vals.push_back(0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            if (i % 2 == 1) pref[i] = pref[i - 1] + a[i];
            else pref[i] = pref[i - 1] - a[i];

            vals.push_back(pref[i]);
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto get = [&](ll x) {
            return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
        };

        Fenwick even(vals.size()), odd(vals.size());

        ll ans = 0;

        even.add(get(pref[0]), 1);

        for (int j = 1; j <= n; j++) {
            int id = get(pref[j]);

            if (j % 2 == 1) {
                ans += even.sum(id - 1);
                odd.add(id, 1);
            } else {
                ans += odd.sum(vals.size()) - odd.sum(id);
                even.add(id, 1);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
