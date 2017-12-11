#ifndef EXERCISE7_COMPLEX_H
#define EXERCISE7_COMPLEX_H

class Complex {

private:
    double re, im;
    void tab_wsk_fun_init();

public:
    Complex();
    Complex(double re);
    Complex(double re, double im);

    double fun1();
    double fun2();
    double fun3();
    double fun4();

    double (Complex::*tab_wsk_fun[4])(void);
};


#endif
