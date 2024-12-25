#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);
    vector<int> Q;
    int sum = 0;
    for (int i = 0; i < K+1; i++) {
        cout << "? ";
        for (int j = 0; j < K+1; j++) {
            if (j != i) cout << j+1 << " ";
        }
        cout << endl;
        int tmp;
        cin >> tmp;
        sum ^= tmp;
        Q.push_back(tmp);
    }
    for (int i = 0; i < K+1; i++) A[i] = Q[i] ^ sum;
    for (int i = K+1; i < N; i++) {
        sum = 0;
        cout << "? ";
        for (int j = 0; j < K-1; j++) {
            cout << j+1 << " ";
            sum ^= A[j];
        }
        cout << i+1 << endl;
        int tmp;
        cin >> tmp;
        A[i] = sum ^ tmp;
    }
    cout << "! ";
    for (int a : A) cout << a << " ";
    cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
