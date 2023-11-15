// https://atcoder.jp/contests/abc298/tasks/abc298_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    map<int, set<int>> A;
    map<int, multiset<int>> B;

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            cin >> i >> j;
            A[i].insert(j);
            B[j].insert(i);
        } else if (t == 2) {
            int j;
            cin >> j;
            for (int i : B[j]) cout << i << " ";
            cout << endl;
        } else {
            int i;
            cin >> i;
            for (int j : A[i]) cout << j << " ";
            cout << endl;
        }
    }
}
