// https://atcoder.jp/contests/abc294/tasks/abc294_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    set<int> S;
    int nxt = 1;

    for (int q = 0; q < Q; q++) {
        int x;
        cin >> x;

        if (x == 1) {
            S.insert(nxt);
            nxt++;
        } else if (x == 2) {
            int a;
            cin >> a;
            S.erase(a);
        } else {
            cout << *S.begin() << endl;
        }
    }
}
