#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(9, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a <= 3199) A[a/400]++;
        else A[8]++;
    }

    int k = 0;
    for (int i = 0; i < 8; i++) k += (A[i] > 0);
    if (k == 0) cout << "1" << " ";
    else cout << k << " ";

    cout << k + A[8] << endl;
}
