#include <bits/stdc++.h>
using namespace std;

void rec(int N, int M, vector<int> &V) {
    for (int i = 0; i < N; i++) {
        cout << V[i] << " ";
    }
    cout << endl;

    bool b = false;
    for (int i = 0; i < N; i++) {
        if (V[N-1-i] < M-i) {
            b = true;
            V[N-1-i]++;
            int now = V[N-1-i];
            for (int j = N-1-i+1; j < N; j++) {
                now++;
                V[j] = now;
            }
            break;
        }
    }

    if (b) {
        rec(N, M, V);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> V(N, 0);
    for (int i = 0; i < N; i++) V[i] = i+1;

    rec(N, M, V);
}
