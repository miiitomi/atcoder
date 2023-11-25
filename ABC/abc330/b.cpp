#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int a : A) {
        if (a <= L) cout << L << " ";
        else if (a >= R) cout << R << " ";
        else cout << a << " ";
    }

    cout << endl;
}
