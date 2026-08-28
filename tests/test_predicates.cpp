#include "../includes/Predicates.h"
#include "Test.h"

void test_is_zero()
{
    Point p{0, 0, 0};

    ASSERT_TRUE(is_zero(p));
}

void test_is_not_zero()
{
    Point p{0, 0, 1};

    ASSERT_FALSE(is_zero(p));
}

void test_is_unit()
{
    Point p{1, 0, 0};

    ASSERT_TRUE(is_unit(p));
}

void test_is_unit_nd()
{
    Point p{0.5, 0.5, 0.5, 0.5};

    ASSERT_TRUE(is_unit(p));
}

void test_is_not_unit()
{
    Point p{1, 1, 0};

    ASSERT_FALSE(is_unit(p));
}

void test_is_parallel()
{
    Point p1{1, 2, 3};
    Point p2{2, 4, 6};

    ASSERT_TRUE(is_parallel(p1, p2));
}

void test_is_parallel_opposite()
{
    Point p1{1, 2, 3};
    Point p2{-2, -4, -6};

    ASSERT_TRUE(is_parallel(p1, p2));
}

void test_is_not_parallel()
{
    Point p1{1, 2, 3};
    Point p2{1, 2, 4};

    ASSERT_FALSE(is_parallel(p1, p2));
}

void test_parallel_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{1, 2};

    ASSERT_THROW(
        is_parallel(p1, p2),
        std::invalid_argument
    );
}

void test_parallel_zero_vector()
{
    Point p1{0, 0, 0};
    Point p2{1, 2, 3};

    ASSERT_THROW(
        is_parallel(p1, p2),
        std::invalid_argument
    );
}

void test_is_perpendicular()
{
    Point p1{1, 0};
    Point p2{0, 1};

    ASSERT_TRUE(is_perpendicular(p1, p2));
}

void test_is_perpendicular_nd()
{
    Point p1{1, 2, 3};
    Point p2{2, -1, 0};

    ASSERT_TRUE(is_perpendicular(p1, p2));
}

void test_is_not_perpendicular()
{
    Point p1{1, 2};
    Point p2{3, 4};

    ASSERT_FALSE(is_perpendicular(p1, p2));
}

void test_perpendicular_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{1, 2};

    ASSERT_THROW(
        is_perpendicular(p1, p2),
        std::invalid_argument
    );
}
