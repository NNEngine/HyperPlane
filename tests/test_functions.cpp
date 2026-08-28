#include "../includes/Functions.h"
#include "Test.h"

void test_func_abs()
{
    Point p{-1.5, 2.0, -3.5};

    Point result = func_abs(p);

    ASSERT_NEAR(result[0], 1.5, 1e-9);
    ASSERT_NEAR(result[1], 2.0, 1e-9);
    ASSERT_NEAR(result[2], 3.5, 1e-9);
}

void test_func_sqrt()
{
    Point p{1, 4, 9, 16};

    Point result = func_sqrt(p);

    ASSERT_NEAR(result[0], 1, 1e-9);
    ASSERT_NEAR(result[1], 2, 1e-9);
    ASSERT_NEAR(result[2], 3, 1e-9);
    ASSERT_NEAR(result[3], 4, 1e-9);
}

void test_func_cbrt()
{
    Point p{1, 8, 27, 64};

    Point result = func_cbrt(p);

    ASSERT_NEAR(result[0], 1, 1e-9);
    ASSERT_NEAR(result[1], 2, 1e-9);
    ASSERT_NEAR(result[2], 3, 1e-9);
    ASSERT_NEAR(result[3], 4, 1e-9);
}

void test_func_pow()
{
    Point p{1, 2, 3, 4};

    Point result = func_pow(p, 2);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 4);
    ASSERT_EQUAL(result[2], 9);
    ASSERT_EQUAL(result[3], 16);
}

void test_func_exp()
{
    Point p{0, 1, 2};

    Point result = func_exp(p);

    ASSERT_NEAR(result[0], 1.0, 1e-9);
    ASSERT_NEAR(result[1], std::exp(1.0), 1e-9);
    ASSERT_NEAR(result[2], std::exp(2.0), 1e-9);
}

void test_func_log()
{
    Point p{1, std::exp(1.0), std::exp(2.0)};

    Point result = func_log(p);

    ASSERT_NEAR(result[0], 0.0, 1e-9);
    ASSERT_NEAR(result[1], 1.0, 1e-9);
    ASSERT_NEAR(result[2], 2.0, 1e-9);
}

void test_func_log10()
{
    Point p{1, 10, 100, 1000};

    Point result = func_log10(p);

    ASSERT_NEAR(result[0], 0.0, 1e-9);
    ASSERT_NEAR(result[1], 1.0, 1e-9);
    ASSERT_NEAR(result[2], 2.0, 1e-9);
    ASSERT_NEAR(result[3], 3.0, 1e-9);
}

void test_func_sin()
{
    Point p{0, M_PI / 2.0, M_PI};

    Point result = func_sin(p);

    ASSERT_NEAR(result[0], 0.0, 1e-9);
    ASSERT_NEAR(result[1], 1.0, 1e-9);
    ASSERT_NEAR(result[2], 0.0, 1e-9);
}

void test_func_cos()
{
    Point p{0, M_PI / 2.0, M_PI};

    Point result = func_cos(p);

    ASSERT_NEAR(result[0], 1.0, 1e-9);
    ASSERT_NEAR(result[1], 0.0, 1e-9);
    ASSERT_NEAR(result[2], -1.0, 1e-9);
}

void test_func_tan()
{
    Point p{0, M_PI / 4.0};

    Point result = func_tan(p);

    ASSERT_NEAR(result[0], 0.0, 1e-9);
    ASSERT_NEAR(result[1], 1.0, 1e-9);
}

void test_func_asin()
{
    Point p{-1, 0, 1};

    Point result = func_asin(p);

    ASSERT_NEAR(result[0], -M_PI / 2.0, 1e-9);
    ASSERT_NEAR(result[1], 0.0, 1e-9);
    ASSERT_NEAR(result[2], M_PI / 2.0, 1e-9);
}

void test_func_acos()
{
    Point p{-1, 0, 1};

    Point result = func_acos(p);

    ASSERT_NEAR(result[0], M_PI, 1e-9);
    ASSERT_NEAR(result[1], M_PI / 2.0, 1e-9);
    ASSERT_NEAR(result[2], 0.0, 1e-9);
}

void test_func_atan()
{
    Point p{-1, 0, 1};

    Point result = func_atan(p);

    ASSERT_NEAR(result[0], -M_PI / 4.0, 1e-9);
    ASSERT_NEAR(result[1], 0.0, 1e-9);
    ASSERT_NEAR(result[2], M_PI / 4.0, 1e-9);
}

void test_func_floor()
{
    Point p{1.2, 2.8, -1.2, -2.8};

    Point result = func_floor(p);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], -2);
    ASSERT_EQUAL(result[3], -3);
}

void test_func_ceil()
{
    Point p{1.2, 2.8, -1.2, -2.8};

    Point result = func_ceil(p);

    ASSERT_EQUAL(result[0], 2);
    ASSERT_EQUAL(result[1], 3);
    ASSERT_EQUAL(result[2], -1);
    ASSERT_EQUAL(result[3], -2);
}

void test_func_round()
{
    Point p{1.4, 1.6, -1.4, -1.6};

    Point result = func_round(p);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], -1);
    ASSERT_EQUAL(result[3], -2);
}
