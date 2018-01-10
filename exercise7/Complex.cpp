#include "Complex.h"
#include <cmath>

Complex::Complex(): re(0), im(0) { tab_wsk_fun_init(); }
Complex::Complex(double re): re(re), im(0) { tab_wsk_fun_init(); }
Complex::Complex(double re, double im): re(re), im(im) { tab_wsk_fun_init(); }

double Complex::fun1() { return re; }

double Complex::fun2() { return im; }

double Complex::fun3() { return re * re + im * im; }

double Complex::fun4() { return sqrt(fun3()); }

void Complex::tab_wsk_fun_init() {
    tab_wsk_fun[0] = &Complex::fun1;
    tab_wsk_fun[1] = &Complex::fun2;
    tab_wsk_fun[2] = &Complex::fun3;
    tab_wsk_fun[3] = &Complex::fun4;
}
