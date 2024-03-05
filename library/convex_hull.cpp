template<typename T> vector<pair<T,T>> convex_hull(vector<pair<T,T>> P) {
    // Return ConvecHull of the set of points P via Graham's scan algorithm
    auto pair_minus = [](pair<T,T> p, pair<T,T> q) -> pair<T,T> {return make_pair(p.first - q.first, p.second - q.second);};
    auto cross_product = [](pair<T,T> p, pair<T, T> q) -> T {return p.first*q.second - p.second*q.first;};
    sort(P.begin(), P.end());
    vector<pair<T,T>> Q_over={P[0],P[1]}, Q_under={P[0],P[1]};
    for (int i = 2; i < (int)P.size(); i++) {
        while ((int)Q_over.size() >= 2 && cross_product(pair_minus(P[i], Q_over.back()), pair_minus(Q_over[(int)Q_over.size()-2], Q_over.back())) >= 0) Q_over.pop_back();
        Q_over.push_back(P[i]);
        while ((int)Q_under.size() >= 2 && cross_product(pair_minus(P[i], Q_under.back()), pair_minus(Q_under[(int)Q_under.size()-2], Q_under.back())) <= 0) Q_under.pop_back();
        Q_under.push_back(P[i]);
    }
    vector<pair<T,T>> Q = Q_under;
    for (int i = Q_over.size()-2; i > 0; i--) Q.push_back(Q_over[i]);
    return Q;
}
