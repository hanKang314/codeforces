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
        vector<int> a(n, 0);
        bool isWonderful = false;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 100) {
                isWonderful = true;
            }
        }

        cout << (isWonderful ? "YES" : "NO") << '\n';
    }

    return 0;
}