#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> P;
    P.reserve(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i > 0 && A[i-1] > A[i]) {
            P.push_back(A[i-1]);
        }
    }
    if (P.size() == 0) cout << 0 << endl;
    else cout << *max_element(P.begin(), P.end()) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
