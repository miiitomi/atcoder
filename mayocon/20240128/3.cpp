// https://atcoder.jp/contests/abc064/tasks/abc064_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> cnt(9, 0);
    int N;
    cin >> N;
    while (N--) {
        int a;
        cin >> a;
        a /= 400;
        if (a <= 7) cnt[a]++;
        else cnt[8]++;
    }

    int tmp = 0;
    for (int i = 0; i <= 7; i++) if (cnt[i]) tmp++;

    if (cnt.back() == 0) {
        cout << tmp << " " << tmp << endl;
    } else if (tmp == 0) {
        cout << 1 << " " << cnt.back() << endl;
    } else {
        cout << tmp << " " << tmp + cnt.back() << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
