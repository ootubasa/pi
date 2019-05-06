#include <stdio.h>
#include <mpfr.h>

int main(void)
{
    int i = 1024 * 4;
    mpfr_t a, b, a1, b1;

    mpfr_init2(a, i);
    mpfr_init2(b, i);
    mpfr_init2(a1, i);
    mpfr_init2(b1, i);
    mpfr_sqrt_ui(a, 12, MPFR_RNDD);
    mpfr_set_d(b, 3, MPFR_RNDD);

    for (i = 0; i < 1024; i++)
    {
        mpfr_mul(a1, a, b, MPFR_RNDD);
        mpfr_mul_ui(a1, a1, 2, MPFR_RNDD);
        mpfr_add(b1, a, b, MPFR_RNDD);
        mpfr_div(a1, a1, b1, MPFR_RNDD);

        mpfr_mul(a, a1, b, MPFR_RNDD);
        mpfr_sqrt(b1, a, MPFR_RNDD);

        mpfr_swap(a, a1);
        mpfr_swap(b, b1);
    }

    mpfr_printf("a = %.256Rf \n", a);
    mpfr_printf("b = %.256Rf \n", b);


    mpfr_t PI;
    mpfr_init2(PI, 1024 * 4);
    mpfr_const_pi(PI, MPFR_RNDD);

    mpfr_sub(a, a, PI, MPFR_RNDD);
    mpfr_printf("a-PI = %.256Re \n", a);

    mpfr_clear(PI);


    mpfr_clear(a);
    mpfr_clear(b);
    mpfr_clear(a1);
    mpfr_clear(b1);
    mpfr_free_cache();
}