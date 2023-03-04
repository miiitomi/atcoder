#include <bits/stdc++.h>
using namespace std;

int N;
vector<double> X, Y;
vector<int> V;

double compute_distance(int i, int j) {
    return sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
}

double compute_score() {
    double ans = 0;
    for (int i = 0; i < N; i++) {
        int p = V[i];
        int q = V[i+1];
        ans += compute_distance(p, q);
    }
    return ans;
}

vector<int> greedy() {
    set<int> S;
    int i = 0;
    V.push_back(i);
    S.insert(i);

    for (int t = 0; t < N-1; t++) {
        double min_value = 1e+9;
        int min_idx = -1;
        for (int j = 0; j < N; j++) {
            if (S.count(j)) continue;
            double tmp_distance = compute_distance(i, j);
            if (min_value > tmp_distance) {
                min_value = tmp_distance;
                min_idx = j;
            } 
        }
        V.push_back(min_idx);
        S.insert(min_idx);
    }

    V.push_back(0);
    return V;
}

int main() {
    cin >> N;
    X.resize(N);
    Y.resize(N);
    V.resize(0);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    vector<int> V = greedy();

    for (int i : V) {
        cout << i + 1 << endl;
    }
}
