#include <check.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "s21_math.h"

// s21_abs
START_TEST(test_s21_abs) {
    ck_assert_int_eq(s21_abs(21), abs(21));
    ck_assert_int_eq(s21_abs(-21), abs(-21));
    ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
    ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
}
END_TEST

// s21_ceil
START_TEST(test_s21_ceil) {
    ck_assert_msg(s21_ceil(0.0) == ceil(0.0), "s21_ceil");
    ck_assert_msg(s21_ceil(21.21) == ceil(21.21), "s21_ceil");
    ck_assert_msg(s21_ceil(21.91) == ceil(21.91), "s21_ceil");
    ck_assert_msg(s21_ceil(-21.21) == ceil(-21.21), "s21_ceil");
    ck_assert_msg(s21_ceil(-21.91) == ceil(-21.91), "s21_ceil");
}
END_TEST

// s21_fabs
START_TEST(test_s21_fabs) {
    ck_assert_msg(s21_fabs(0.000001) == fabs(0.000001), "s21_fabs");
    ck_assert_msg(s21_fabs(-21.000345) == fabs(-21.000345), "s21_fabs");
    ck_assert_msg(s21_fabs(-2147483600.543) == fabs(-2147483600.543), "s21_fabs");
    ck_assert_msg(s21_fabs(2147483600.4857) == fabs(2147483600.4857), "s21_fabs");
}
END_TEST

// s21_floor
START_TEST(test_s21_floor) {
    ck_assert_msg(s21_floor(0.0) == floor(0.0), "s21_floor");
    ck_assert_msg(s21_floor(21.21) == floor(21.21), "s21_floor");
    ck_assert_msg(s21_floor(21.91) == floor(21.91), "s21_floor");
    ck_assert_msg(s21_floor(-21.21) == floor(-21.21), "s21_floor");
    ck_assert_msg(s21_floor(-21.91) == floor(-21.91), "s21_floor");
}
END_TEST

// s21_fmod
START_TEST(test_s21_fmod) {
    ck_assert_msg(s21_fmod(21.21, 3) == fmod(21.21, 3), "s21_fmod");
    ck_assert_msg(s21_fmod(3, 21.21) == fmod(3, 21.21), "s21_fmod");
    ck_assert_msg(s21_fmod(-21.21, 3) == fmod(-21.21, 3), "s21_fmod");
    ck_assert_msg(s21_fmod(3, -21.21) == fmod(3, -21.21), "s21_fmod");
    ck_assert_msg(s21_fmod(100500, 9) == fmod(100500, 9), "s21_fmod");
    ck_assert_msg(s21_fmod(-100500, -9) == fmod(-100500, -9), "s21_fmod");
    ck_assert_msg(s21_fmod(-9, -100500) == fmod(-9, -100500), "s21_fmod");
    ck_assert_msg(s21_fmod(-9, -9) == fmod(-9, -9), "s21_fmod");
    ck_assert_msg(s21_fmod(10, 5) == fmod(10, 5), "s21_fmod");
}
END_TEST

// s21_sin
START_TEST(test_s21_sin) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_sin(0.0);
    long double y;
    y = sin(0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(M_PI / 6);  // sin 30
    y = sin(M_PI / 6);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(M_PI / 4);  // sin 45
    y = sin(M_PI / 4);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(M_PI / 3);  // sin 60
    y = sin(M_PI / 3);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(M_PI / 2);  // sin 90
    y = sin(M_PI / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(sqrt((3 * M_PI) / 2));  // sin 270
    y = sin(sqrt((3 * M_PI) / 2));
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(2 * M_PI);  // sin 360
    y = sin(2 * M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(-2 * M_PI);  // sin 360
    y = sin(-2 * M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(-3 * M_PI);  // sin 360
    y = sin(-3 * M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(174.532925199433);  // sin 10000
    y = sin(174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sin(-174.532925199433);  // sin 10000
    y = sin(-174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_cos
START_TEST(test_s21_cos) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_cos(0.0);
    long double y;
    y = cos(0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(M_PI / 6);  // sin 30
    y = cos(M_PI / 6);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(M_PI / 4);  // sin 45
    y = cos(M_PI / 4);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(M_PI / 3);  // sin 60
    y = cos(M_PI / 3);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(M_PI / 2);  // sin 90
    y = cos(M_PI / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(sqrt((3 * M_PI) / 2));  // sin 270
    y = cos(sqrt((3 * M_PI) / 2));
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(2 * M_PI);  // sin 360
    y = cos(2 * M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(174.532925199433);  // sin 10000
    y = cos(174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_cos(-174.532925199433);  // sin 10000
    y = cos(-174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_tan
START_TEST(test_s21_tan) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_tan(0.0);
    long double y;
    y = tan(0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(M_PI / 6);  // sin 30
    y = tan(M_PI / 6);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(M_PI / 4);  // sin 45
    y = tan(M_PI / 4);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(M_PI);
    y = tan(M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(-2 * M_PI);
    y = tan(-2 * M_PI);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(M_PI / 3);  // sin 60
    y = tan(M_PI / 3);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(sqrt((3 * M_PI) / 2));  // sin 270
    y = tan(sqrt((3 * M_PI) / 2));
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(174.532925199433);  // sin 10000
    y = tan(174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_tan(-174.532925199433);  // sin 10000
    y = tan(-174.532925199433);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_asin
START_TEST(test_s21_asin) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_asin(0.0);
    long double y;
    y = asin(0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_asin(-1);
    y = asin(-1);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_asin(1);
    y = asin(1);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_asin(-sqrt(3) / 2);
    y = asin(-sqrt(3) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_asin(-sqrt(2) / 2);
    y = asin(-sqrt(2) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_asin(-1 / 2);
    y = asin(-1 / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_asin(1 / 2);
    y = asin(sqrt(1 / 2));
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_asin(sqrt(2) / 2);
    y = asin(sqrt(2) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_asin(sqrt(3) / 2);
    y = asin(sqrt(3) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_asin(1);
    y = asin(1);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_acos
START_TEST(test_s21_acos) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_acos(0.0);
    long double y;
    y = acos(0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_acos(-1);
    y = acos(-1);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_acos(-sqrt(3) / 2);
    y = acos(-sqrt(3) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_acos(-sqrt(2) / 2);
    y = acos(-sqrt(2) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_acos(-1 / 2);
    y = acos(-1 / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_acos(1 / 2);
    y = acos(sqrt(1 / 2));
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_acos(sqrt(2) / 2);
    y = acos(sqrt(2) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_acos(sqrt(3) / 2);
    y = acos(sqrt(3) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_acos(1);
    y = acos(1);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_atan
START_TEST(test_s21_atan) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_atan(0.0);
    long double y;
    y = atan(0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(-1);
    y = atan(-1);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(-sqrt(3) / 2);
    y = atan(-sqrt(3) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(-sqrt(2) / 2);
    y = atan(-sqrt(2) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(-1 / 2);
    y = atan(-1 / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(1 / 2);
    y = atan(sqrt(1 / 2));
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(sqrt(2) / 2);
    y = atan(sqrt(2) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(sqrt(3) / 2);
    y = atan(sqrt(3) / 2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(1);
    y = atan(1);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(1.23456e-7);
    y = atan(1.23456e-7);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(2.1234567);
    y = atan(2.1234567);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(2.1234567e-7);
    y = atan(2.1234567e-7);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_atan(2.1234567e-16);
    y = atan(2.1234567e-16);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_exp
START_TEST(test_s21_exp) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_exp(0.0);
    long double y;
    y = exp(0.0);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_exp(-1);
    y = exp(-1);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_exp(-100);
    y = exp(-100);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_exp(-1000000);
    y = exp(-1000000);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_exp(1);
    y = exp(1);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_exp(20);
    y = exp(20);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_exp(1000000);
    y = exp(1000000);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_log
START_TEST(test_s21_log) {
    char c[255] = {};
    char d[255] = {};
    long double x = 0;
    long double y = 0;
    x = s21_log(0.5);
    y = log(0.5);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(1);
    y = log(1);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(100);
    y = log(100);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(S21_DBL_MAX);
    y = log(S21_DBL_MAX);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(S21_PI / 3);
    y = log(S21_PI / 3);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(9.234578353457e-6);
    y = log(9.234578353457e-6);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(9.234578353457e6);
    y = log(9.234578353457e6);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(1234567.000000004);
    y = log(1234567.000000004);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(1.1e-16);
    y = log(1.1e-16);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(1.1e-16);
    y = log(1.1e-16);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(987654321123.123e-30);
    y = log(987654321123.123e-30);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_log(98765.123e-11);
    y = log(98765.123e-11);
    snprintf(c, sizeof(x), "%.8Lf", x);
    snprintf(d, sizeof(y), "%.8Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_pow
START_TEST(test_s21_pow) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_pow(0.0, 0.0);
    long double y;
    y = pow(0.0, 0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_pow(-1, 4);
    y = pow(-1, 4);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_pow(2, 18);
    y = pow(2, 18);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_pow(2.1, 11);
    y = pow(2.1, 11);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_pow(1.23456e-7, 2.21);
    y = pow(1.23456e-7, 2.21);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_pow(2.1234567, -2);
    y = pow(2.1234567, -2);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_pow(2.1234567e-7, -2.45e4);
    y = pow(2.1234567e-7, -2.45e4);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_pow(9.99999999e3, 9.95e-4);
    y = pow(9.99999999e3, 9.95e-4);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

// s21_sqrt
START_TEST(test_s21_sqrt) {
    char c[255] = {};
    char d[255] = {};
    long double x;
    x = s21_sqrt(0.0);
    long double y;
    y = sqrt(0.0);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sqrt(1);
    y = sqrt(1);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sqrt(100);
    y = sqrt(100);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sqrt(98765432.123);
    y = sqrt(98765432.123);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sqrt(981.123e6);
    y = sqrt(981.123e6);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
    x = s21_sqrt(981.123e-15);
    y = sqrt(981.123e-15);
    snprintf(c, sizeof(x), "%.6Lf", x);
    snprintf(d, sizeof(y), "%.6Lf", y);
    ck_assert_str_eq(c, d);
}
END_TEST

int main() {
    Suite *s1 = suite_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    // s21_abs
    TCase *s21_absCase = tcase_create("s21_absTest");
    suite_add_tcase(s1, s21_absCase);
    tcase_add_test(s21_absCase, test_s21_abs);

    // s21_ceil
    TCase *s21_ceilCase = tcase_create("s21_ceilTest");
    suite_add_tcase(s1, s21_ceilCase);
    tcase_add_test(s21_ceilCase, test_s21_ceil);

    // s21_fabs
    TCase *s21_fabsCase = tcase_create("s21_fabsTest");
    suite_add_tcase(s1, s21_fabsCase);
    tcase_add_test(s21_fabsCase, test_s21_fabs);

    // s21_floor
    TCase *s21_floorCase = tcase_create("s21_floorTest");
    suite_add_tcase(s1, s21_floorCase);
    tcase_add_test(s21_floorCase, test_s21_floor);

    // s21_fmod
    TCase *s21_fmodCase = tcase_create("s21_fmodTest");
    suite_add_tcase(s1, s21_fmodCase);
    tcase_add_test(s21_fmodCase, test_s21_fmod);

    // s21_sin
    TCase *s21_sinCase = tcase_create("s21_sinTest");
    suite_add_tcase(s1, s21_sinCase);
    tcase_add_test(s21_sinCase, test_s21_sin);

    // s21_cos
    TCase *s21_cosCase = tcase_create("s21_cosTest");
    suite_add_tcase(s1, s21_cosCase);
    tcase_add_test(s21_cosCase, test_s21_cos);

    // s21_tan
    TCase *s21_tanCase = tcase_create("s21_tanTest");
    suite_add_tcase(s1, s21_tanCase);
    tcase_add_test(s21_tanCase, test_s21_tan);

    // s21_asin
    TCase *s21_asinCase = tcase_create("s21_asinTest");
    suite_add_tcase(s1, s21_asinCase);
    tcase_add_test(s21_asinCase, test_s21_asin);

    // s21_acos
    TCase *s21_acosCase = tcase_create("s21_acosTest");
    suite_add_tcase(s1, s21_acosCase);
    tcase_add_test(s21_acosCase, test_s21_acos);

    // s21_atan
    TCase *s21_atanCase = tcase_create("s21_atanTest");
    suite_add_tcase(s1, s21_atanCase);
    tcase_add_test(s21_atanCase, test_s21_atan);

    // s21_exp
    TCase *s21_expCase = tcase_create("s21_expTest");
    suite_add_tcase(s1, s21_expCase);
    tcase_add_test(s21_expCase, test_s21_exp);

    // s21_log
    TCase *s21_logCase = tcase_create("s21_logTest");
    suite_add_tcase(s1, s21_logCase);
    tcase_add_test(s21_logCase, test_s21_log);

    // s21_pow
    TCase *s21_powCase = tcase_create("s21_powTest");
    suite_add_tcase(s1, s21_powCase);
    tcase_add_test(s21_powCase, test_s21_pow);

    // s21_sqrt
    TCase *s21_sqrtCase = tcase_create("s21_sqrtTest");
    suite_add_tcase(s1, s21_sqrtCase);
    tcase_add_test(s21_sqrtCase, test_s21_sqrt);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf != 0;
}
