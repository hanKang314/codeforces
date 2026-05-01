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

        vector<int> ans(n);

        vector<int> x6, x3, x2, x;

        for (int i = 0; i < n; i++) {
            if (a[i] % 6 == 0) x6.push_back(a[i]);
            else if (a[i] % 2 == 0) x2.push_back(a[i]);
            else if (a[i] % 3 == 0) x3.push_back(a[i]);
            else x.push_back(a[i]);
        }

        int s6 = x6.size();
        int s3 = x3.size();
        int s2 = x2.size();
        int s = x.size();

        for (int i = 0; i < s6; i++) ans[i] = x6[i];
        for (int i = 0; i < s2; i++) ans[i + s6] = x2[i];
        for (int i = 0; i < s; i++) ans[i + s6 + s2] = x[i];
        for (int i = 0; i < s3; i++) ans[i + s6 + s2 + s] = x3[i];
        
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}
