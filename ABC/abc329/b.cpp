#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> B;
    int m = *max_element(A.begin(), A.end());
    for (int a : A) if (a != m) B.push_back(a);
    sort(B.begin(), B.end());

    cout << B.back() << endl;
}
