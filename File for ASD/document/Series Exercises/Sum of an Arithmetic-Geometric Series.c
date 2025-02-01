double arithmetic_geometric_sum(int a, int d, double r, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += (a + i * d) * mod_exponentiation(r, i, 1000000007);
    return sum;
}
