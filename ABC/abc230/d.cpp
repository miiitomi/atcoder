#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) cin >> L[i] >> R[i];

    set<pair<int, int>> S, T;
    for (int i = 0; i < N; i++) {
        S.insert(make_pair(R[i], i));
        T.insert(make_pair(L[i], i));
    }

    int k = 0;
    while (!S.empty()) {
        k++;
        int r = S.begin()->first;
        int l = T.begin()->first;
        int j = T.begin()->second;
        while (l < r + D) {
            T.erase(make_pair(l, j));
            S.erase(make_pair(R[j], j));
            if (T.empty()) break;
            l = T.begin()->first;
            j = T.begin()->second;
        }
    }
    cout << k << endl;
}
