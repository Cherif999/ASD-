int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void sieve(int n, int primes[]) {
    for (int i = 0; i <= n; i++) primes[i] = 1;
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (primes[i])
            for (int j = i * i; j <= n; j += i)
                primes[j] = 0;
}
