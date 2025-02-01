
int chinese_remainder(int num[], int rem[], int k) {
    int prod = 1, result = 0;
    for (int i = 0; i < k; i++) prod *= num[i];
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * mod_exponentiation(pp, num[i] - 2, num[i]) * pp;
    }
    return result % prod;
}
