#include <bits/stdc++.h>
using namespace std;

const int INF = pow(10, 9);

void solve() {
    int N;
    cin >> N;
    int M = (N*(N-1)) / 2;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];
    map<int, int> mp;
    for (int a : A) mp[a]++;

    vector<int> V(N, INF);
    int now = 0;

    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        int a = iter->first;
        int x = iter->second;
        while (x > 0) {
            if (N-1-now >= x) {
                V[N-1-x] = a;
                now = N-1-x+1;
                x = 0;
            } else {
                V[now] = a;
                x -= N-1-now;
                now++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i == N-1) cout << V[i] << endl;
        else cout << V[i] << " ";
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();    
}
