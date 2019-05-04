#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>

int main()
{
    mpfr_t work;

    mpfr_init2(work, 200);            // 有効桁数200bitで初期化
    mpfr_set_d(work, 1.0, MPFR_RNDD); // double変数を代入

    printf("work is ");
    mpfr_out_str(stdout, 10, 10, work, MPFR_RNDD); // 出力　2個目はn進数での出力指定　
    // 3個目は何桁出力するか(size_t) '0'を指定すると当該変数の有効桁数すべて出力する
    putchar('\n');

    mpfr_const_pi(work, MPFR_RNDD);
    printf("pi is ");
    mpfr_out_str(stdout, 10, 0, work, MPFR_RNDD);
    putchar('\n');

    mpfr_clear(work); // メモリの解放

    return 0;
}