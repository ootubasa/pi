#include <stdio.h>
#include <mpfr.h>

int main(void)
{
    int i = 1024 * 4;
    mpfr_t a, sum;

    mpfr_init2(a, i);
    mpfr_init2(sum, i);
    mpfr_set_d(sum, 0, MPFR_RNDD);

    for (i = 0; i < 1024; i++)
    {
        mpfr_set_d(a, -1.0 / 3.0, MPFR_RNDD);
        mpfr_pow_ui(a, a, i, MPFR_RNDD);
        mpfr_div_ui(a, a, 2 * i + 1, MPFR_RNDD);

        mpfr_add(sum, sum, a, MPFR_RNDD);
    }

    mpfr_sqrt_ui(a, 12, MPFR_RNDD);
    mpfr_mul(sum, sum, a, MPFR_RNDD);

    mpfr_printf("sum = %.1024Rf \n", sum);

    mpfr_t PI;
    mpfr_init2(PI, 1024 * 4);
    mpfr_const_pi(PI, MPFR_RNDD);

    mpfr_sub(sum, sum, PI, MPFR_RNDD);
    mpfr_printf("sum-PI = %.256Re \n", sum);

    mpfr_clear(PI);


    mpfr_clear(a);
    mpfr_clear(sum);
    mpfr_free_cache();
}