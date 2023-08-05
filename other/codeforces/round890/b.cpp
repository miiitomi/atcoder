#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    if (N == 1) {
        cout << "NO" << endl;
        return;
    }

    if (sum / N >= 2) {
        cout << "YES" << endl;
        return;
    }

    int a = N - (sum % N);
    int c = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] != 1) c++;
    }
    if (a > c) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
