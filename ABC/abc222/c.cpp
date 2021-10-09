#include <bits/stdc++.h>
using namespace std;

int win(char a, char b) {
    if (a == b) return 0;
    if (a == 'G') {
        if (b == 'C') return 1;
        else return -1;
    } else if (a == 'C') {
        if (b == 'P') return 1;
        else return -1;
    } else {
        if (b == 'G') return 1;
        else return -1;
    }
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second != b.second) return (a.second > b.second);
    else if (a.first <= b.first) return true;
    else return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(2*N);
    for (int i = 0; i < 2*N; i++) cin >> A[i];

    vector<pair<int, int>> V(2*N);
    for (int i = 0; i < 2*N; i++) {
        V[i].first = i;
        V[i].second = 0;
    }

    for (int i = 0; i < M; i++) {
        for (int k = 0; k < N; k++) {
            int idx1 = V[2*k].first;
            int idx2 = V[2*k+1].first;
            int w = win(A[idx1][i], A[idx2][i]);
            if (w == 1) {
                V[2*k].second++;
            } else if (w == -1) {
                V[2*k+1].second++;
            }
        }
        sort(V.begin(), V.end(), cmp);
    }
    
    for (int i = 0; i < 2*N; i++) cout << V[i].first + 1 << endl;
}
