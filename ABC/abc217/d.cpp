#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, Q;
    cin >> L >> Q;
    vector<int> c(Q), x(Q);
    for (int i = 0; i < Q; i++) cin >> c[i] >> x[i];

    set<int> S, T;
    S.insert(0);
    S.insert(L);
    T.insert(0);
    T.insert(-L);

    for (int i = 0; i < Q; i++) {
        if (c[i] == 1) {
            S.insert(x[i]);
            T.insert(-x[i]);
        } else {
            int i1 = *S.lower_bound(x[i]);
            int i2 = *T.lower_bound(-x[i]);
            cout << i1 + i2 << endl;
        }
    }
}
