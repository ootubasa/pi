#include <stdio.h>
#include <mpfr.h>

int main(void)
{
    int i = 1024 * 4;
    mpfr_t a, t, sum;

    mpfr_init2(a, i);
    mpfr_init2(t, i);
    mpfr_init2(sum, i);
    mpfr_set_d(sum, 0, MPFR_RNDD);

    for (i = 0; i < 1024; i++)
    {
        mpfr_fac_ui(t, i, MPFR_RNDD);
        mpfr_ui_pow_ui(a, 4, i, MPFR_RNDD);
        mpfr_mul(t, t, a, MPFR_RNDD);
        mpfr_ui_pow_ui(a, 99, i, MPFR_RNDD);
        mpfr_mul(t, t, a, MPFR_RNDD);

        mpfr_fac_ui(a, 4 * i, MPFR_RNDD);
        mpfr_mul_ui(a, a, 1103 + 26390 * i, MPFR_RNDD);

        mpfr_div(a, a, t, MPFR_RNDD);
        mpfr_div(a, a, t, MPFR_RNDD);
        mpfr_div(a, a, t, MPFR_RNDD);
        mpfr_div(a, a, t, MPFR_RNDD);

        mpfr_add(sum, sum, a, MPFR_RNDD);
    }

    mpfr_sqrt_ui(a, 8, MPFR_RNDD);
    mpfr_mul(sum, sum, a, MPFR_RNDD);
    mpfr_ui_div(sum, 1, sum, MPFR_RNDD);
    mpfr_mul_ui(sum, sum, 99, MPFR_RNDD);
    mpfr_mul_ui(sum, sum, 99, MPFR_RNDD);

    mpfr_printf("sum = %.1024Rf \n", sum);


    mpfr_t PI;
    mpfr_init2(PI, 1024 * 4);
    mpfr_const_pi(PI, MPFR_RNDD);

    mpfr_sub(sum, sum, PI, MPFR_RNDD);
    mpfr_printf("sum-PI = %.256Re \n", sum);

    mpfr_clear(PI);


    mpfr_clear(a);
    mpfr_clear(t);
    mpfr_clear(sum);
    mpfr_free_cache();
}