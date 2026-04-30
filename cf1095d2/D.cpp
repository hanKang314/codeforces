#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> even, odd;
        for (auto& z : a) {
            if (z % 2) odd.push_back(z);
            else even.push_back(z);
        }

        int even_min = 1e9;
        int even_max = -1e9;
        int odd_min = 1e9;
        int odd_max = -1e9;

        if (!even.empty()) {
            for (auto& z : even) {
                even_min = min(even_min, z);
                even_max = max(even_max, z);
            }
        }

        if (!odd.empty()) {
            for (auto& z : odd) {
                odd_min = min(odd_min, z);
                odd_max = max(odd_max, z);
            }
        }

        bool is = 1;

        if (even.size() > 1) {
            int mx = even[0];

            for (int i = 1; i < even.size(); i++) {
                if (mx > even[i]) {
                    if (odd_min > odd[i] && odd_max < mx) {
                        is = 0;
                        break;
                    }
                }
                else {
                    mx = even[i];
                }
            }
        }

        if (odd.size() > 1) {
            int mx = odd[0];

            for (int i = 1; i < odd.size(); i++) {
                if (mx > odd[i]) {
                    if (even_min > odd[i] && even_max < mx) {
                        is = 0;
                        break;
                    }
                }
                else {
                    mx = odd[i];
                }
            }
        }

        cout << (is ? "YES" : "NO") << '\n';
    }

    return 0;
}