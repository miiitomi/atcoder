#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int s = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        s ^= A[i];
    }

    if (*max_element(A.begin(), A.end()) == 0) {
        cout << 0 << endl;
        return;
    }

    vector<pair<int,int>> V;
    V.push_back({1, (int)A.size()});
    for (int i = 0; i < N; i++) A[i] = s;

    if (*max_element(A.begin(), A.end()) == 0) {
        cout << (int)V.size() << endl;
        for (auto v : V) cout << v.first << " " << v.second << endl;
        return;
    }

    if (N % 2 == 0) {
        V.push_back({1, (int)A.size()});
        cout << (int)V.size() << endl;
        for (auto v : V) cout << v.first << " " << v.second << endl;
        return;
    }

    V.push_back({2, (int)A.size()});
    V.push_back({1, 2});
    V.push_back({1, 2});

    cout << (int)V.size() << endl;
    for (auto v : V) cout << v.first << " " << v.second << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
