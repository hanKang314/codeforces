#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> prefix(n+1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = i;
        }
        prefix[r] = l - 1;
        vector<int> arr(n+1, 0);
        for (int i = 1; i <= n; i++) {
            arr[i] = prefix[i] ^ prefix[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}