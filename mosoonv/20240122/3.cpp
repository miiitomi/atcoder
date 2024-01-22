// https://atcoder.jp/contests/arc006/tasks/arc006_1
#include <bits/stdc++.h>
using namespace std;

void solve() {
    set<int> E;
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        E.insert(x);
    }
    int B;
    cin >> B;
    set<int> L;
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        L.insert(x);
    }

    swap(E, L);

    if (E == L) {
        cout << 1 << endl;
        return;
    }

    int cnt = 0, bonus = 0;
    for (int e : E) {
        if (L.count(e)) cnt++;
        else if (e == B) bonus++;
    }

    if (cnt == 5 && bonus) cout << 2 << endl;
    else if (cnt >= 3) cout << 8 - cnt << endl;
    else cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
