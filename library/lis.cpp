#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int> &A) {
    vector<int> L;
    L.push_back(A[0]);
    for (int i = 1; i < (int)A.size(); i++) {
        auto iter = lower_bound(L.begin(), L.end(), A[i]);
        if (iter == L.end()) L.push_back(A[i]);
        else *iter = A[i];
    }
    return (int)L.size();
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    cout << LIS(A) << endl;
}
