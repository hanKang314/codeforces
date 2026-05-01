#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    long long sum(int idx) {
        long long ret = 0;

        for (; idx > 0; idx -= idx & -idx) {
            ret += bit[idx];
        }

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

        vector<int> a(n + 1);
        vector<int> freq(n + 2, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        long long base = 0;
        Fenwick cnt(n), sum(n);
        long long totalSum = 0;

        for (int i = 1; i <= n; i++) {
            long long leCnt = cnt.sum(a[i]);
            long long leSum = sum.sum(a[i]);
            long long greaterCnt = (i - 1) - leCnt;
            long long greaterSum = totalSum - leSum;

            base += greaterSum - greaterCnt * a[i];

            cnt.add(a[i], 1);
            sum.add(a[i], a[i]);
            totalSum += a[i];
        }

        vector<int> ge(n + 2, 0);
        for (int h = n; h >= 1; h--) {
            ge[h] = ge[h + 1] + freq[h];
        }

        long long bestDelta = 0;
        for (int i = 1; i <= n; i++) {
            long long delta = (long long)i + ge[a[i]] - n - 1;
            bestDelta = max(bestDelta, delta);
        }

        cout << base + bestDelta << '\n';
    }

    return 0;
}
