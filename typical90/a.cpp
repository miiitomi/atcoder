#include <bits/stdc++.h>
using namespace std;

bool f(int s, vector<int> &A, int K, int L) {
    int last = 0;
    int counter = 0;
    for (int i = 0; i < (int)A.size(); i++) {
        if (A[i] - last >= s) {
            counter++;
            last = A[i];
            if (counter == K) break;
        }
    }
    if (counter == K && L - last >= s) return true;
    else return false;
}

int main() {
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int left = 1;
    int right = 1000000000;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (f(mid, A, K, L)) left = mid;
        else right = mid;
    }
    cout << left << endl;
}
