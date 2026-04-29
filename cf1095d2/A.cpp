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
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != 1) {
                ans += a[i];
            }
        }

        if (a[n-1] == 1) ans++;

        cout << ans << '\n';
    }

    return 0;
}