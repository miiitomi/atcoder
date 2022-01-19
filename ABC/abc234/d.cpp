#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];


    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 0; i < K; i++) {
        Q.push(P[i]);
    }

    int q = Q.top();
    cout << q << endl;

    for (int i = K; i < N; i++) {
        Q.push(P[i]);
        Q.pop();
        q = Q.top();
        cout << q << endl;
    }
}
