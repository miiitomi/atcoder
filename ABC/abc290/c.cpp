#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    set<int> S;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        S.insert(a);
    }

    for (int k = 0; k < K; k++) {
        if (!S.count(k)) {
            cout << k << endl;
            return 0;
        }
    }
    cout << K << endl;
}
