double exponential_series(double x, int n) {
    double sum = 1.0, term = 1.0;
    for (int i = 1; i <= n; i++) {
        term *= x / i;
        sum += term;
    }
    return sum;
}
