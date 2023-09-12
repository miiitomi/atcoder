#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<pair<int,int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        pair<int,int> p = A[i];
        int j = p.second;
        B[j] = i+1;
    }
    for (int b : B) cout << b << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
