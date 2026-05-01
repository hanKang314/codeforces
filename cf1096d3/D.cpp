#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> mn;

    SegTree(int sz) {
        n = 1;
        while (n < sz) n <<= 1;
        mn.assign(2 * n, -1);
    }

    void update(int idx, int val) {
        idx += n;
        mn[idx] = val;
        idx >>= 1;

        while (idx) {
            mn[idx] = min(mn[idx << 1], mn[idx << 1 | 1]);
            idx >>= 1;
        }
    }

    int firstLessThan(int val) {
        int idx = 1;

        while (idx < n) {
            if (mn[idx << 1] < val) idx <<= 1;
            else idx = idx << 1 | 1;
        }

        return idx - n;
    }
};

vector<int> manacherOdd(const vector<int>& a) {
    int n = a.size();
    vector<int> d1(n);
    int l = 0, r = -1;

    for (int i = 0; i < n; i++) {
        int k = 1;
        if (i <= r) k = min(d1[l + r - i], r - i + 1);

        while (i - k >= 0 && i + k < n && a[i - k] == a[i + k]) {
            k++;
        }

        d1[i] = k;

        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    return d1;
}

vector<int> manacherEven(const vector<int>& a) {
    int n = a.size();
    vector<int> d2(n);
    int l = 0, r = -1;

    for (int i = 0; i < n; i++) {
        int k = 0;
        if (i <= r) k = min(d2[l + r - i + 1], r - i + 1);

        while (i - k - 1 >= 0 && i + k < n && a[i - k - 1] == a[i + k]) {
            k++;
        }

        d2[i] = k;

        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }

    return d2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int m;
        cin >> m;

        int n = 2 * m;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> queries;

        vector<int> d1 = manacherOdd(a);
        for (int i = 0; i < n; i++) {
            int l = i - d1[i] + 1;
            int r = i + d1[i] - 1;
            queries.push_back({r, l});
        }

        vector<int> d2 = manacherEven(a);
        for (int i = 0; i < n; i++) {
            if (d2[i] == 0) continue;

            int l = i - d2[i];
            int r = i + d2[i] - 1;
            queries.push_back({r, l});
        }

        sort(queries.begin(), queries.end());

        SegTree seg(n + 2);
        int cur = -1;
        int ans = 0;

        for (auto [r, l] : queries) {
            while (cur < r) {
                cur++;

                if (0 <= a[cur] && a[cur] <= n + 1) {
                    seg.update(a[cur], cur);
                }
            }

            ans = max(ans, seg.firstLessThan(l));
        }

        cout << ans << '\n';
    }

    return 0;
}
