#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> Q(N, -1);
    vector<int> A(N, -1);

    int sum = 0;
    for (int i = 1; i <= K+1; i++) {
        cout << "? ";
        for (int j = 1; j <= K+1; j++) {
            if (j != i) cout << j << " ";
        }
        cout << endl;
        int T;
        cin >> T;
        sum += T;
        Q[i-1] = T;
    }
    int new_sum = 0;
    for (int i = 0; i < K+1; i++) {
        A[i] = abs(sum - Q[i]) % 2;
        if (i < K-1) new_sum += A[i];
    }

    for (int i = 0; i < N - (K+1); i++) {
        cout << "? ";
        for (int j = 1; j <= K-1; j++) cout << j << " ";
        cout << K+2+i << endl;
        int T;
        cin >> T;
        A[K+1+i] = abs(new_sum - T) % 2;
    }

    cout << "! ";
    for (int a: A) cout << a << " ";
    cout << endl;
}
