int factorial_sum(int n) {
    int sum = 0, fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        sum += fact;
    }
    return sum;
}
