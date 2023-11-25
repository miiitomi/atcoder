#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X;
    vector<pair<int,int>> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<pair<int, int>> C(N);
    for (int i = 0; i < N; i++) {
        int j = (N-X+i)%N;
        C[j].first = B[i]; 
        C[j].second = A[j].second;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) cnt += (A[i].first > C[i].first);

    if (cnt == X) {
        cout << "YES" << endl;
        sort(C.begin(), C.end(), [](pair<int,int> &p1, pair<int,int> &p2) {return p1.second < p2.second;});
        for (pair<int,int> &c : C) cout << c.first << " ";
        cout << endl;
    } else {
        cout << "NO" << endl; 
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
