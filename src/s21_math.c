#include "s21_math.h"

int s21_abs(int x) {
  int result = (x < 0) ? -x : x;
  return result;
}

long double s21_acos(double x) {
  long double result = 0;
  if (s21_fabs(x) > 1 || x != x) {
    result = S21_NAN;
  } else {
    result = s21_atan(s21_sqrt(1 - x * x) / x);
    if (x >= -1 && x < 0) {
      result += S21_PI;
    }
  }
  return result;
}

long double s21_asin(double x) {
  long double result = 0;
  if (s21_fabs(x) > 1 || x != x) {
    result = S21_NAN;
  } else if (x == -1) {
    result = -S21_PI / 2;
  } else {
    result = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  if (x == S21_INF_PLUS) {
    result = S21_PI / 2;
  } else if (x == S21_INF_MINUS) {
    result = -S21_PI / 2;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x == -1) {
    result = -S21_PI / 4;
  } else if (x == 1) {
    result = S21_PI / 4;
  } else {
    if (s21_fabs(x) <= 1) {
      for (long double i = 0; i < 5000; i++) {
        result += (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / (1 + 2 * i);
      }
    } else if (s21_fabs(x) > 1) {
      result = S21_PI * s21_pow(x * x, 0.5) / (2 * x);
      for (long double i = 0; i < 7000; i++) {
        result -= (s21_pow(-1, i) * s21_pow(x, -1 - 2 * i)) / (1 + 2 * i);
      }
    }
  }
  return result;
}

long double s21_ceil(double x) {
  long double result = (long long int)x;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF_PLUS) {
    result = S21_INF_PLUS;
  } else if (x == S21_INF_MINUS) {
    result = S21_INF_MINUS;
  } else {
    if (s21_fabs(x) > 0 && x != result) {
      if (x > 0) {
        result++;
      }
    }
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 0;
  if (x != x || x == S21_INF_PLUS || x == S21_INF_MINUS) {
    result = S21_NAN;
  } else if (x == 0) {
    result = 1;
  } else {
    for (; x < -2 * S21_PI || x > 2 * S21_PI;) {
      if (x < -2 * S21_PI) {
        x += 2 * S21_PI;
      } else {
        x -= 2 * S21_PI;
      }
    }
    for (long double i = 0; i < 500; i++) {
      result += s21_pow(-1, i) * s21_pow(x, 2 * i) / s21_fac(2 * i);
    }
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1;
  if (x == S21_INF_MINUS) {
    result = 0;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x < 0) {
    result = 1 / s21_exp(-x);
  } else {
    long double add_value = 1;
    long double i = 1;
    while (s21_fabs(add_value) > S21_EPS) {
      add_value *= (x / i);
      i += 1;
      result += add_value;
      if (result > DBL_MAX) {
        result = S21_INF_PLUS;
        break;
      }
    }
  }
  return result;
}

long double s21_fabs(double x) {
  long double result = x;
  if (x == S21_INF_MINUS || x == S21_INF_PLUS) {
    result = S21_INF_PLUS;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x < 0) {
    result = -x;
  }
  return result;
}

long double s21_floor(double x) {
  long double result = (long long int)x;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF_PLUS) {
    result = S21_INF_PLUS;
  } else if (x == S21_INF_MINUS) {
    result = S21_INF_MINUS;
  } else if (s21_fabs(x - result) > 0 && s21_fabs(x) > 0) {
    if (x < 0) {
      result--;
    }
  }
  return result;
}

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (x == S21_INF_PLUS || x == S21_INF_MINUS || x != x || y == 0 || y != y) {
    result = S21_NAN;
  } else if (y == S21_INF_PLUS || y == S21_INF_MINUS) {
    result = x;
  } else {
    result = (long double)x - ((long long int)(x / y)) * (long double)y;
  }
  return result;
}

long double s21_log(double x) {
  int ex_pow = 0;
  long double result = 0;
  if (x < 0 || x != x) {
    result = S21_NAN;
  } else if (x == 0) {
    result = S21_INF_MINUS;
  } else if (x == S21_INF_PLUS) {
    result = S21_INF_PLUS;
  } else {
    double compare = 0;
    for (; x >= S21_EXP; x /= S21_EXP, ex_pow++)
      ;
    for (long double i = 0; i < 500; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }
  return result + ex_pow;
}

long double s21_pow(double base, double exp) {
  long double result = 1;
  long double copy = base;
  if ((base == 0 && exp == S21_INF_PLUS) ||
      ((base == S21_INF_MINUS || base < -1) && exp == S21_INF_MINUS)) {
    result = 0;
  } else if ((base < 0 && base > -1 && exp == S21_INF_MINUS) ||
             ((base == S21_INF_MINUS || base == S21_INF_PLUS) &&
              exp == S21_INF_PLUS)) {
    result = S21_INF_PLUS;
  } else if (((base == -1 || base == 1) &&
              (exp == S21_INF_PLUS || exp == S21_INF_MINUS)) ||
             (base == 1 && exp != exp) ||
             ((base != base || base == S21_INF_PLUS || base == S21_INF_MINUS ||
               base == 0) &&
              exp == 0)) {
    result = 1;
  } else if (base < 0 && (int)exp != exp && exp != S21_INF_PLUS) {
    result = S21_NAN;
  } else {
    unsigned long long copy_exp = s21_fabs(exp);
    if (copy_exp >= 1) {
      while (copy_exp != 0) {
        if ((copy_exp & 1) != 0) {
          result *= copy;
        }
        copy *= copy;
        copy_exp >>= 1;
      }
    }
    double remainder_degree = s21_fabs(exp) - (int)s21_fabs(exp);
    if (remainder_degree != 0) {
      if (base < 0) {
        base = -base;
        result = s21_exp(remainder_degree * s21_log(base));
      } else {
        result *= s21_exp(remainder_degree * s21_log(base));
      }
    }
    if (exp < 0) result = 1 / result;
  }
  return result;
}

long double s21_sin(double x) {
  long double result = 0;
  if (x != x || x == S21_INF_PLUS || x == S21_INF_MINUS) {
    result = S21_NAN;
  } else {
    for (; x < -2 * S21_PI || x > 2 * S21_PI;) {
      if (x < -2 * S21_PI) {
        x += 2 * S21_PI;
      } else {
        x -= 2 * S21_PI;
      }
    }
    for (long double i = 0; i < 500; i++) {
      result += s21_pow(-1, i) * s21_pow(x, 2 * i + 1) / s21_fac(2 * i + 1);
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = 0;
  result = s21_pow(x, 0.5);
  return result;
}

long double s21_tan(double x) {
  long double result = s21_sin(x) / s21_cos(x);
  return result;
}

long double s21_fac(long double x) {
  if (x < 2) {
    return 1;
  } else {
    return x * s21_fac(x - 1);
  }
}