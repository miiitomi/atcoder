#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h.at(i);

    vector<int> cost(N);
    cost.at(0) = 0;
    cost.at(1) = abs(h.at(1) - h.at(0));
    for (int i = 2; i < N; i++) {
        cost.at(i) = min(cost.at(i-2) + abs(h.at(i-2)-h.at(i)), cost.at(i-1) + abs(h.at(i-1)-h.at(i)));
    }

    cout << cost.at(N-1) << endl;
}
