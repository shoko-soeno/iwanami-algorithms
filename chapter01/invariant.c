/*
 * ループ不変条件を assert で確かめる例
 *
 * - Euclid の互除法: 不変条件 gcd(m, n) == gcd(m0, n0)
 * - 階乗:            不変条件 v == (i - 1)!
 *
 * 不変条件の確認には、別の方法で計算した「正解」を使う。
 * （証明の代わりではなく、不変条件のイメージをつかむための実験用）
 */
#include <assert.h>
#include <stdio.h>

/* 確認用: 素朴な方法で最大公約数を求める（遅いが明らかに正しい） */
static int gcd_naive(int a, int b)
{
    int k = (a < b) ? a : b;
    while (a % k != 0 || b % k != 0)
        k--;
    return k;
}

/* 確認用: 素朴な方法で階乗を求める */
static long fact_naive(int x)
{
    long v = 1;
    int k;
    for (k = 2; k <= x; k++)
        v *= k;
    return v;
}

/* Euclid の互除法（m, n は正の整数） */
int gcd_checked(int m, int n)
{
    const int g0 = gcd_naive(m, n); /* 最初の m0, n0 の最大公約数 */
    int prev_n = n + 1;
    int r;

    for (;;) {
        /* ループ不変条件: gcd(m, n) == gcd(m0, n0) */
        assert(gcd_naive(m, n) == g0);
        /* 停止性: n はループのたびに必ず小さくなる */
        assert(0 < n && n < prev_n);
        prev_n = n;

        r = m % n;
        if (r == 0)
            break;
        m = n;
        n = r;
    }
    /* 終了時: n が m を割り切る -> gcd(m, n) == n */
    assert(n == g0);
    return n;
}

/* 階乗（for 文を while 文に分解した形） */
long factorial_checked(int x)
{
    long v = 1;
    int i = 1;

    while (i <= x) {
        /* ループ不変条件: v == (i - 1)! */
        assert(v == fact_naive(i - 1));
        v = v * i;
        i = i + 1;
    }
    /* 終了時: i == x + 1 なので v == x! */
    assert(i == x + 1 && v == fact_naive(x));
    return v;
}

int main(void)
{
    int m, n, x;

    for (m = 1; m <= 200; m++)
        for (n = 1; n <= 200; n++)
            gcd_checked(m, n);
    printf("gcd: 1..200 x 1..200 の全組み合わせで不変条件が成立\n");

    for (x = 0; x <= 20; x++)
        factorial_checked(x);
    printf("factorial: 0..20 で不変条件が成立 (20! = %ld)\n",
           factorial_checked(20));
    return 0;
}
