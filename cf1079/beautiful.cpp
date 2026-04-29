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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int s = arr[i];
            int cur = i;
            int want = 1;
            while (cur + s < n) {
                cur += s;
                if (arr[cur] == want) {
                    ans++;
                }
                want++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}