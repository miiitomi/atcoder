#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N+1, 0);
    unordered_map<int, set<int>> S;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        S[A[i]].insert(i);
    }

    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int i, x;
            cin >> i >> x;
            S[A[i]].erase(i);
            A[i] = x;
            S[A[i]].insert(i);
        } else if (k == 2) {
            int x;
            cin >> x;
            if (!S.count(x) || S[x].empty()) cout << -1 << "\n";
            else cout << *S[x].begin()  << "\n";
        } else {
            int x;
            cin >> x;
            if (!S.count(x) || S[x].empty()) cout << -1 << "\n";
            else cout << *S[x].rbegin()  << "\n";
        }
    }
}
