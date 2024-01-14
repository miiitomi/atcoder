// https://atcoder.jp/contests/abc217/tasks/abc217_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, Q;
    cin >> L >> Q;
    set<int> S;
    S.insert(0);
    S.insert(L);

    while (Q--) {
        int c, x;
        cin >> c >> x;
        if (c == 1) S.insert(x);
        else {
            auto iter = S.lower_bound(x);
            int l, r;
            r = *iter;
            iter--;
            l = *iter;
            cout << r - l << "\n";
        }
    }
}
