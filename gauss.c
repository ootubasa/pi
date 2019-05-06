#include <stdio.h>
#include <mpfr.h>

int main(void)
{
    int i = 1024 * 4;
    mpfr_t a, b, t, p, a1, b1, t1;

    mpfr_init2(a, i);
    mpfr_init2(b, i);
    mpfr_init2(t, i);
    mpfr_init2(p, i);
    mpfr_init2(a1, i);
    mpfr_init2(b1, i);
    mpfr_init2(t1, i);

    mpfr_set_d(a, 1, MPFR_RNDD);
    mpfr_sqrt_ui(b, 2, MPFR_RNDD);
    mpfr_ui_div(b, 1, b, MPFR_RNDD);
    mpfr_set_d(t, 0.25, MPFR_RNDD);
    mpfr_set_d(p, 1, MPFR_RNDD);

    for (i = 0; i < 1024; i++)
    {
        mpfr_add(a1, a, b, MPFR_RNDD);
        mpfr_div_ui(a1, a1, 2, MPFR_RNDD);
        mpfr_mul(b1, a, b, MPFR_RNDD);
        mpfr_sqrt(b1, b1, MPFR_RNDD);

        mpfr_sub(t1, a, a1, MPFR_RNDD);
        mpfr_mul(t1, t1, t1, MPFR_RNDD);
        mpfr_mul(t1, p, t1, MPFR_RNDD);
        mpfr_sub(t1, t, t1, MPFR_RNDD);

        mpfr_mul_ui(p, p, 2, MPFR_RNDD);

        mpfr_swap(a1, a);
        mpfr_swap(b1, b);
        mpfr_swap(t1, t);
    }

    mpfr_add(p, a, b, MPFR_RNDD);
    mpfr_mul(p, p, p, MPFR_RNDD);
    mpfr_div(p, p, t, MPFR_RNDD);
    mpfr_div_ui(p, p, 4, MPFR_RNDD);

    mpfr_printf("pi = %.1024Rf \n", p);


    mpfr_t PI;
    mpfr_init2(PI, 1024 * 4);
    mpfr_const_pi(PI, MPFR_RNDD);

    mpfr_sub(p, p, PI, MPFR_RNDD);
    mpfr_printf("p-PI = %.256Re \n", p);

    mpfr_clear(PI);


    mpfr_clear(a);
    mpfr_clear(b);
    mpfr_clear(t);
    mpfr_clear(a1);
    mpfr_clear(b1);
    mpfr_clear(t1);
    mpfr_free_cache();
}