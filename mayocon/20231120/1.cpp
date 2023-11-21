// https://atcoder.jp/contests/abc270/tasks/abc270_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> cnt(3, 0);
    vector<int> a(2);
    cin >> a[0] >> a[1];

    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 3; k++) {
            if (a[j] % 2) cnt[k]++;
            a[j] /= 2;
        }
    }

    int ans = 0, tmp = 1;
    for (int s = 0; s < 3; s++) {
        if (cnt[s] > 0) {
            ans += tmp;
        }
        tmp *= 2;
    }
    cout << ans << endl;
}
