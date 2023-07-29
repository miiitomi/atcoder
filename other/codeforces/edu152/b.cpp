#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first) return (a.first > b.first);
    else return (a.second < b.second);
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> V(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x = x % K;
        if (x == 0) x = K;
        V[i].first = x;
        V[i].second = i+1;
    }
    sort(V.begin(), V.end(), comp);
    for (auto p : V) {
        cout << p.second << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
