#include "../includes/Scalar.h"
#include "Test.h"

void test_scalar_add()
{
    Point p{1, 2, 3};

    Point result = Adds(p, 5);

    ASSERT_EQUAL(result[0], 6);
    ASSERT_EQUAL(result[1], 7);
    ASSERT_EQUAL(result[2], 8);
}

void test_scalar_sub()
{
    Point p{10, 20, 30};

    Point result = Subs(p, 5);

    ASSERT_EQUAL(result[0], 5);
    ASSERT_EQUAL(result[1], 15);
    ASSERT_EQUAL(result[2], 25);
}

void test_scalar_mul()
{
    Point p{1, 2, 3};

    Point result = Muls(p, 5);

    ASSERT_EQUAL(result[0], 5);
    ASSERT_EQUAL(result[1], 10);
    ASSERT_EQUAL(result[2], 15);
}

void test_scalar_div()
{
    Point p{10, 20, 30};

    Point result = Divs(p, 5);

    ASSERT_EQUAL(result[0], 2);
    ASSERT_EQUAL(result[1], 4);
    ASSERT_EQUAL(result[2], 6);
}

void test_scalar_mod()
{
    Point p{10, 21, 32};

    Point result = Mods(p, 3);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 0);
    ASSERT_EQUAL(result[2], 2);
}

void test_scalar_division_by_zero()
{
    Point p{1, 2, 3};

    ASSERT_THROW(
        Divs(p, 0),
        std::invalid_argument
    );
}

void test_scalar_modulo_by_zero()
{
    Point p{1, 2, 3};

    ASSERT_THROW(
        Mods(p, 0),
        std::invalid_argument
    );
}
