#include <stdio.h>

/* 版1: Pascal の for 文版
 *   function factorial(x: integer): integer;
 *     var i, v: integer;
 *   begin
 *     v := 1;
 *     for i := 1 to x do v := v * i;
 *     factorial := v;
 *   end;
 */
long factorial_for(int x)
{
    long v;
    int i;

    v = 1;
    for (i = 1; i <= x; i++)
        v = v * i;
    return v;
}

/* 版2: for 文を while 文に分解した版
 *   i := 1;
 *   while i <= x do
 *     begin v := v * i; i := i + 1; end;
 */
long factorial_while(int x)
{
    long v;
    int i;

    v = 1;
    i = 1;
    while (i <= x) {
        /* ループ不変条件: v == (i - 1)! */
        v = v * i;
        i = i + 1;
    }
    /* ここで i == x + 1 なので v == x! */
    return v;
}

int main(void)
{
    int x;

    for (x = 0; x <= 20; x++)
        printf("%2d! = %ld (for) / %ld (while)\n",
               x, factorial_for(x), factorial_while(x));
    return 0;
}
