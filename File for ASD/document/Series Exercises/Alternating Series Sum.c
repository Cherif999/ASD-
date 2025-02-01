int alternating_series_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (i % 2 ? i : -i);
    return sum;
}
