#include "s21_math.h"

long int s21_abs(int x) {
  if (is_inf(x) || is_neg_inf(x) || is_nan(x)) return (long double)x;
  if (x < 0) x *= -1;
  return x;
}

long double s21_ceil(double x) {
  if (is_inf(x) || is_neg_inf(x) || is_nan(x)) return (long double)x;
  x = (int)(x);
  if (x > 0) x += 1;
  return x;
}

long double s21_fabs(double x) {
    if (x < 0) x *= -1;
    return x;
}

long double s21_floor(double x) {
  if (is_inf(x) || is_neg_inf(x) || is_nan(x)) return (long double)x;
  long double y = (int)(x);
  if (x < 0) y -= 1;
  return y;
}

long double s21_fmod(double x, double y) {
  long double fmod = 0;
  if (is_inf(x) || is_neg_inf(x) || is_nan(x) || is_nan(y)) {
    fmod = S21_NAN;
  } else {
    int sign = 0;
    if (x < 0) {
      sign = 1;
      x = s21_fabs(x);
    }
    if (y < 0) y = s21_fabs(y);
    fmod = x;
    if (y == 0) {
      fmod = S21_NAN;
    } else if (x == y) {
      fmod = 0;
    } else if (x < y) {
      fmod = x;
    } else {
      int i = 1;
      while (fmod >= y) fmod = x - y * i++;
    }
    if (sign == 1) fmod *= -1;
  }
  return fmod;
}

long double s21_sin(double x) {
  double sin;
  if (is_neg_inf(x) || is_inf(x) || is_nan(x)) {
    sin = S21_NAN;
  } else if (s21_fmod(x, 2 * S21_PI) == 0 && x > 0.00) {
    sin = -1 * S21_EPS;
  } else if (s21_fmod(x, 2 * S21_PI) == 0 && x < 0.00) {
    sin = S21_EPS;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    sin = x;
    double r = x;
    int i = 1;
    while (s21_fabs(r) > S21_EPS) {
      r = -1 * r * x * x / (2 * i * (2 * i + 1));
      sin += r;
      i++;
    }
  }
  return sin;
}

long double s21_cos(double x) { return s21_sin((S21_PI / 2.0) - x); }

long double s21_tan(double x) {
  long double res;
  if (is_neg_inf(x) || is_inf(x) || is_nan(x)) {
    res = S21_NAN;
  } else if (s21_fmod(x, S21_PI) == 0 && x > 0.00) {
    res = -1 * S21_EPS;
  } else if (s21_fmod(x, S21_PI) == 0 && x < 0.00) {
    res = S21_EPS;
  } else {
    x = s21_fmod(x, S21_PI);
    if (s21_fabs(x - S21_PI / 2) < S21_EPSEQ ||
        s21_fabs(x + S21_PI / 2) < S21_EPSEQ)
      res = S21_INF;
    else
      res = s21_sin(x) / s21_cos(x);
  }
  return res;
}

long double s21_exp(double x) {
  long double res = 1;
  if (is_nan(x) || is_inf(x)) {
    res = x;
  } else {
    int sign = 0;
    if (x < 0) {
      sign = 1;
      x *= -1;
    }
    double next = 1;
    for (int i = 1; s21_fabs(next) > S21_EPS && res != S21_INF; i++) {
      next *= x / i;
      res += next;
      if (res > S21_DBL_MAX) res = S21_INF;
    }
    if (sign) res = 1. / res;
  }
  return res;
}

long double s21_asin(double x) {
  long double buf = x;
  long double res = x;
  if (x < -1. || x > 1. || is_nan(x)) {
    res = S21_NAN;
  } else if (s21_fabs(x - 1.) < S21_EPSEQ || s21_fabs(x + 1.) < S21_EPSEQ) {
    res = S21_PI / 2;
    if (x == -1) res *= -1;
  } else {
    for (int i = 1; s21_fabs(buf) > S21_EPS;) {
      buf *= x * x * (2 * i - 1) * (2 * i - 1) * (2 * i);
      buf /= (2 * i + 1) * 4 * i * i;
      res += buf;
      i++;
    }
    if (x == -1) res *= -1;
  }
  return res;
}

long double s21_acos(double x) {
  long double res;
  if (x < -1 || x > 1 || is_nan(x))
    res = S21_NAN;
  else if (s21_fabs(x - 1.) < S21_EPSEQ)
    res = 0;
  else if (s21_fabs(x + 1.) < S21_EPSEQ)
    res = S21_PI;
  else
    res = (S21_PI / 2 - s21_asin(x));
  return res;
}

long double s21_log(double x) {
  long double res;
  if (x < 0 || is_nan(x)) {
    res = S21_NAN;
  } else if (is_inf(x)) {
    res = x;
  } else if (x == 0.0) {
    res = S21_NEG_INF;
  } else {
    int scale = 0;
    if (x > 2) {
      while (x > 1) {
        x /= 10;
        scale++;
      }
    } else if (x < 1) {
      while (x * 10 < 1) {
        x *= 10;
        scale--;
      }
    }
    int div = 0;
    while ((x) >= 2) {
      x /= 2;
      div++;
    }
    res = scale * S21_Log10 + div * S21_Log2;
    long double f = x - 1;
    long double buf = 1;
    long double resln_x = 0;
    int i = 1;
    int sign = 1;
    while (s21_fabs(buf) > S21_EPS) {
      buf *= f;
      resln_x += sign * buf / i;
      i++;
      sign *= -1;
    }
    res += resln_x;
  }
  return res;
}

long double s21_pow(double base, double exp) {
  long double res = 0;
  if (is_nan(base) || is_nan(exp)) {
    res = S21_NAN;
  } else if (is_neg_inf(base) || is_inf(base) || is_inf(exp)) {
    res = S21_INF;
  } else if (base == 0.0 && exp == 0.0) {
    res = 1.0;
  } else {
    long double t_base = s21_fabs(base);
    res = s21_exp(exp * s21_log(t_base));
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res;
  if (x < 0 || is_nan(x))
    res = S21_NAN;
  else
    res = s21_pow(x, 0.5);
  return res;
}

long double s21_atan(double x) {
  long double res;
  res = x / s21_sqrt(1 + s21_pow(x, 2));
  res = s21_asin(res);
  return res;
}

int is_inf(double x) { return (x == S21_INF); }

int is_neg_inf(double x) { return (x == S21_NEG_INF); }

int is_nan(double x) { return (x != x); }
