#include "../includes/Arithmetic.h"
#include "Test.h"

void test_add()
{
    Point p1{1, 2, 3};
    Point p2{4, 5, 6};

    Point result = Add(p1, p2);

    ASSERT_EQUAL(result[0], 5);
    ASSERT_EQUAL(result[1], 7);
    ASSERT_EQUAL(result[2], 9);
}

void test_sub()
{
    Point p1{10, 20, 30};
    Point p2{4, 5, 6};

    Point result = Sub(p1, p2);

    ASSERT_EQUAL(result[0], 6);
    ASSERT_EQUAL(result[1], 15);
    ASSERT_EQUAL(result[2], 24);
}

void test_mul()
{
    Point p1{2, 3, 4};
    Point p2{5, 6, 7};

    Point result = Mul(p1, p2);

    ASSERT_EQUAL(result[0], 10);
    ASSERT_EQUAL(result[1], 18);
    ASSERT_EQUAL(result[2], 28);
}

void test_div()
{
    Point p1{10, 20, 30};
    Point p2{2, 4, 5};

    Point result = Div(p1, p2);

    ASSERT_EQUAL(result[0], 5);
    ASSERT_EQUAL(result[1], 5);
    ASSERT_EQUAL(result[2], 6);
}

void test_mod()
{
    Point p1{10, 21, 32};
    Point p2{3, 5, 7};

    Point result = Mod(p1, p2);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 1);
    ASSERT_EQUAL(result[2], 4);
}

void test_add_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{4, 5};

    ASSERT_THROW(
        Add(p1, p2),
        std::invalid_argument
    );
}

void test_sub_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{4, 5};

    ASSERT_THROW(
        Sub(p1, p2),
        std::invalid_argument
    );
}

void test_mul_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{4, 5};

    ASSERT_THROW(
        Mul(p1, p2),
        std::invalid_argument
    );
}

void test_div_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{4, 5};

    ASSERT_THROW(
        Div(p1, p2),
        std::invalid_argument
    );
}

void test_mod_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{4, 5};

    ASSERT_THROW(
        Mod(p1, p2),
        std::invalid_argument
    );
}

void test_division_by_zero()
{
    Point p1{10, 20, 30};
    Point p2{2, 0, 5};

    ASSERT_THROW(
        Div(p1, p2),
        std::invalid_argument
    );
}

void test_modulo_by_zero()
{
    Point p1{10, 20, 30};
    Point p2{2, 0, 5};

    ASSERT_THROW(
        Mod(p1, p2),
        std::invalid_argument
    );
}
