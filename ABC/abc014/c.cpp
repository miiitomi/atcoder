#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> x(1e6 + 1, 0);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        x[a]++;
        if (b < 1e6) x[b+1]--;
    }

    for (int i = 1; i <= 1e6; i++) {
        x[i] += x[i-1];
    }
    cout << *max_element(x.begin(), x.end()) << endl;
}
