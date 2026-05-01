#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> suf_min(n);
        suf_min[n-1] = a[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suf_min[i] = min(a[i], suf_min[i + 1]);
        }

        long long base_moves = 0;
        for (int i = 0; i < n; i++) {
            base_moves += a[i] - suf_min[i];
        }

        vector<int> ps(n, -1);
        stack<int> stk;
        for (int k = 0; k < n; k++) {
            while (!stk.empty() && a[stk.top()] >= a[k]) {
                stk.pop();
            }
            ps[k] = stk.empty() ? -1 : stk.top();
            stk.push(k);
        }

        long long best_gain = 0;
        for (int k = 0; k < n; k++) {
            if (suf_min[k] == a[k]) {
                long long gain = (long long) (k - 1 - ps[k]);
                best_gain = max(best_gain, gain);
            }
        }

        cout << base_moves + best_gain << '\n';
    }

    return 0;
}