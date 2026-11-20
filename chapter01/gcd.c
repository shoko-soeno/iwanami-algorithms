#include <stdio.h>

/* 版1: p.3 の goto 版（手順書に忠実） */
int gcd_goto(int m, int n)
{
    int r;
L1:                     /* 1:                    */
    r = m % n;          /* r := m mod n;         */
    if (r == 0) goto L2;/* if r = 0 then goto 2; */
    m = n; n = r;       /* m := n; n := r;       */
    goto L1;            /* goto 1;               */
L2:                     /* 2:                    */
    return n;           /* gcd := n;             */
}

/* 版2: p.3-4 の repeat ... until 版（Pascal らしい形） */
int gcd_repeat(int m, int n)
{
    int r;
    do {                /* repeat                */
        r = m % n;      /*   r := m mod n;       */
        m = n; n = r;   /*   m := n; n := r;     */
    } while (r != 0);   /* until r = 0;          */
    return m;           /* gcd := m;             */
}

/* 版3: p.4 の再帰版（変数 r が不要） */
int gcd_rec(int m, int n)
{
    if (n == 0)                     /* if n = 0                     */
        return m;                   /*   then gcd := m              */
    else
        return gcd_rec(n, m % n);   /*   else gcd := gcd(n, m mod n) */
}

/* 再帰の様子を表示する版 */
int gcd_rec_trace(int m, int n, int depth)
{
    printf("%*sgcd(%d, %d)\n", depth * 2, "", m, n);
    if (n == 0)
        return m;
    return gcd_rec_trace(n, m % n, depth + 1);
}

int main(void)
{
    int tests[][2] = { {48, 18}, {18, 48}, {1071, 1029}, {17, 5}, {100, 25} };
    int k;
    for (k = 0; k < 5; k++) {
        int m = tests[k][0], n = tests[k][1];
        printf("gcd(%d, %d): goto=%d, repeat=%d, rec=%d\n",
               m, n, gcd_goto(m, n), gcd_repeat(m, n), gcd_rec(m, n));
    }

    printf("\n再帰版の呼び出しの様子:\n");
    printf("=> %d\n", gcd_rec_trace(1071, 1029, 0));

    printf("\nn = 0 を渡した場合（再帰版のみ動く）: gcd_rec(7, 0) = %d\n",
           gcd_rec(7, 0));
    return 0;
}
