#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0) A.push_back(a);
    }

    int n = A.size();
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i == n-1) cout << endl;
        else cout << " ";
    }
}
