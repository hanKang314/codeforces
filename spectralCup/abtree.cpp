#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;

        priority_queue<int> odd;
        priority_queue<int> even;
        vector<int> mark(m);

        bool isOdd = true;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (isOdd) {
                odd.push(a);
                isOdd = false;
            } else {
                even.push(a);
                isOdd = true;
            }
        }

        int oddFirst = odd.empty() ? INT_MIN : odd.top();
        int evenFirst = even.empty() ? INT_MIN : even.top();

        int evenCnt = 0;
        int oddCnt = 0;

        for (int i = 0; i < m; i++) {
            cin >> mark[i];
            if (mark[i] % 2 == 0) {
                if (!even.empty()) {
                    if (even.top() > 0 || (even.top() == evenFirst && evenCnt == 0)) {
                        even.pop();
                    }
                }
                evenCnt++;
            } else {
                if (!odd.empty()) {
                    if (odd.top() > 0 || (odd.top() == oddFirst && oddCnt == 0)) {
                        odd.pop();
                    }
                }
                oddCnt++;
            }
        }

        long long ans = 0;

        while (!odd.empty()) {
            ans += odd.top();
            odd.pop();
        }

        while (!even.empty()) {
            ans += even.top();
            even.pop();
        }

        cout << ans << '\n';
    }

    return 0;
}