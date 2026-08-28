#include "../includes/Point.h"
#include "Test.h"

void test_operator_add()
{
    Point p1{1, 2, 3};
    Point p2{4, 5, 6};

    Point result = p1 + p2;

    ASSERT_EQUAL(result[0], 5);
    ASSERT_EQUAL(result[1], 7);
    ASSERT_EQUAL(result[2], 9);
}

void test_operator_sub()
{
    Point p1{10, 20, 30};
    Point p2{4, 5, 6};

    Point result = p1 - p2;

    ASSERT_EQUAL(result[0], 6);
    ASSERT_EQUAL(result[1], 15);
    ASSERT_EQUAL(result[2], 24);
}

void test_operator_mul()
{
    Point p1{2, 3, 4};
    Point p2{5, 6, 7};

    Point result = p1 * p2;

    ASSERT_EQUAL(result[0], 10);
    ASSERT_EQUAL(result[1], 18);
    ASSERT_EQUAL(result[2], 28);
}

void test_operator_div()
{
    Point p1{10, 20, 30};
    Point p2{2, 4, 5};

    Point result = p1 / p2;

    ASSERT_EQUAL(result[0], 5);
    ASSERT_EQUAL(result[1], 5);
    ASSERT_EQUAL(result[2], 6);
}

void test_operator_mod()
{
    Point p1{10, 21, 32};
    Point p2{3, 5, 7};

    Point result = p1 % p2;

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 1);
    ASSERT_EQUAL(result[2], 4);
}

void test_operator_scalar_add()
{
    Point p{1, 2, 3};

    Point result = p + 5.0;

    ASSERT_EQUAL(result[0], 6);
    ASSERT_EQUAL(result[1], 7);
    ASSERT_EQUAL(result[2], 8);
}

void test_operator_scalar_sub()
{
    Point p{10, 20, 30};

    Point result = p - 5.0;

    ASSERT_EQUAL(result[0], 5);
    ASSERT_EQUAL(result[1], 15);
    ASSERT_EQUAL(result[2], 25);
}

void test_operator_scalar_mul()
{
    Point p{1, 2, 3};

    Point result = p * 5.0;

    ASSERT_EQUAL(result[0], 5);
    ASSERT_EQUAL(result[1], 10);
    ASSERT_EQUAL(result[2], 15);
}

void test_operator_scalar_div()
{
    Point p{10, 20, 30};

    Point result = p / 5.0;

    ASSERT_EQUAL(result[0], 2);
    ASSERT_EQUAL(result[1], 4);
    ASSERT_EQUAL(result[2], 6);
}

void test_operator_scalar_mod()
{
    Point p{10, 21, 32};

    Point result = p % 3.0;

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 0);
    ASSERT_EQUAL(result[2], 2);
}

void test_operator_unary_minus()
{
    Point p{1, -2, 3};

    Point result = -p;

    ASSERT_EQUAL(result[0], -1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], -3);
}

void test_operator_unary_plus()
{
    Point p{1, -2, 3};

    Point result = +p;

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], -2);
    ASSERT_EQUAL(result[2], 3);
}

void test_operator_plus_equals()
{
    Point p1{1, 2, 3};
    Point p2{4, 5, 6};

    p1 += p2;

    ASSERT_EQUAL(p1[0], 5);
    ASSERT_EQUAL(p1[1], 7);
    ASSERT_EQUAL(p1[2], 9);
}

void test_operator_minus_equals()
{
    Point p1{10, 20, 30};
    Point p2{4, 5, 6};

    p1 -= p2;

    ASSERT_EQUAL(p1[0], 6);
    ASSERT_EQUAL(p1[1], 15);
    ASSERT_EQUAL(p1[2], 24);
}

void test_operator_multiply_equals()
{
    Point p1{2, 3, 4};
    Point p2{5, 6, 7};

    p1 *= p2;

    ASSERT_EQUAL(p1[0], 10);
    ASSERT_EQUAL(p1[1], 18);
    ASSERT_EQUAL(p1[2], 28);
}

void test_operator_divide_equals()
{
    Point p1{10, 20, 30};
    Point p2{2, 4, 5};

    p1 /= p2;

    ASSERT_EQUAL(p1[0], 5);
    ASSERT_EQUAL(p1[1], 5);
    ASSERT_EQUAL(p1[2], 6);
}

void test_operator_modulo_equals()
{
    Point p1{10, 21, 32};
    Point p2{3, 5, 7};

    p1 %= p2;

    ASSERT_EQUAL(p1[0], 1);
    ASSERT_EQUAL(p1[1], 1);
    ASSERT_EQUAL(p1[2], 4);
}

void test_operator_scalar_plus_equals()
{
    Point p{1, 2, 3};

    p += 5.0;

    ASSERT_EQUAL(p[0], 6);
    ASSERT_EQUAL(p[1], 7);
    ASSERT_EQUAL(p[2], 8);
}

void test_operator_scalar_minus_equals()
{
    Point p{10, 20, 30};

    p -= 5.0;

    ASSERT_EQUAL(p[0], 5);
    ASSERT_EQUAL(p[1], 15);
    ASSERT_EQUAL(p[2], 25);
}

void test_operator_scalar_multiply_equals()
{
    Point p{1, 2, 3};

    p *= 5.0;

    ASSERT_EQUAL(p[0], 5);
    ASSERT_EQUAL(p[1], 10);
    ASSERT_EQUAL(p[2], 15);
}

void test_operator_scalar_divide_equals()
{
    Point p{10, 20, 30};

    p /= 5.0;

    ASSERT_EQUAL(p[0], 2);
    ASSERT_EQUAL(p[1], 4);
    ASSERT_EQUAL(p[2], 6);
}

void test_operator_scalar_modulo_equals()
{
    Point p{10, 21, 32};

    p %= 3.0;

    ASSERT_EQUAL(p[0], 1);
    ASSERT_EQUAL(p[1], 0);
    ASSERT_EQUAL(p[2], 2);
}

void test_operator_division_by_zero()
{
    Point p1{10, 20, 30};
    Point p2{2, 0, 5};

    ASSERT_THROW(
        p1 / p2,
        std::invalid_argument
    );
}

void test_operator_scalar_division_by_zero()
{
    Point p{1, 2, 3};

    ASSERT_THROW(
        p / 0.0,
        std::invalid_argument
    );
}
