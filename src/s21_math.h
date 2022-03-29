#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_PI 3.1415926535897932384626433832795
#define S21_EPS 1e-15
#define S21_INF 1.0 / 0.0
#define S21_NEG_INF -1.0 / 0.0
#define S21_DBL_MAX 1.7976931348623158e+308
#define S21_EPSEQ 1e-7
#define S21_NAN 0.0 / 0.0
#define S21_Log10 2.30258509299
#define S21_Log2 0.69314718056
#define S21_EPS100 1e-100


long int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
int is_nan(double x);
int is_neg_inf(double x);
int is_inf(double x);


#endif  // SRC_S21_MATH_H_
