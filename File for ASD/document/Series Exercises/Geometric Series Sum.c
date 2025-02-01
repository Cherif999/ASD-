
int geometric_series_sum(int a, int r, int n) {
    if (r == 1) return n * a;
    return a * (1 - mod_exponentiation(r, n, 1000000007)) / (1 - r);
}
