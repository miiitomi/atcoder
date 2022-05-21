#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int max_oishisa = -1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        max_oishisa = max(max_oishisa, A[i]);
    }
    set<int> B;
    for (int j = 0; j < K; j++) {
        int b;
        cin >> b;
        b--;
        B.insert(b);
    }

    for (int i = 0; i < N; i++) {
        int a = A[i];
        if (a == max_oishisa) {
            if (B.count(i)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
