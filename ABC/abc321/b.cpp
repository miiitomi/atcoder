#include <bits/stdc++.h>
using namespace std;

int N, X;

bool is_ok(vector<int> &A) {
    int min_v = *min_element(A.begin(), A.end());
    int max_v = *max_element(A.begin(), A.end());
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    sum -= (max_v + min_v);

    if (sum >= X) return true;
    else return false;
}

int main() {
    cin >> N >> X;
    vector<int> A(N, 0);
    for (int i = 0; i < N-1; i++) cin >> A[i];

    for (int a = 0; a <= 100; a++) {
        A[N-1] = a;
        if (is_ok(A)) {
            cout << a << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
