#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    set<int> S;
    vector<int> V;
    for (int a : A) {
        if (!S.count(a)) {
            S.insert(a);
            V.push_back(a);
        }
    }
    sort(V.begin(), V.end());

    for (int i = 0; i < N; i++) {
        int a = A[i];
        auto iter = lower_bound(V.begin(), V.end(), a);
        int b = 1 + (int)distance(V.begin(), iter);
        cout << b;
        if (i == N-1) cout << endl;
        else cout << " ";
    }
}
