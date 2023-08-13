#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    bool is_same = true;
    for (int i = 1; i < N; i++) {
        if (A[0] != A[i]) {
            is_same = false;
            break;
        } 
    }

    if (is_same) {
        cout << -1 << endl;
        return;
    }
    vector<int> B, C;
    int max_a = *max_element(A.begin(), A.end());
    for (int a : A) {
        if (a == max_a) C.push_back(a);
        else B.push_back(a);
    }

    cout << B.size() << " " << C.size() << endl;
    for (int b : B) cout << b << " ";
    cout << endl;
    for (int c : C) cout << c << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();    
}
