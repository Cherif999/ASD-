void fibonacci_series(int n, int fib[]) {
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i < n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
}
