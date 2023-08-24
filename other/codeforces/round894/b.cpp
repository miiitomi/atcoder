#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> B;
    B.reserve(2*N);

    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i-1] <= A[i]) B.push_back(A[i]);
        else {
            B.push_back(A[i]);
            B.push_back(A[i]);
        }
    }

    cout << (int)B.size() << endl;
    for (int b : B) cout << b << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
