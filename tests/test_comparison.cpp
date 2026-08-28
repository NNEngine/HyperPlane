#include "../includes/Comparison.h"
#include "Test.h"

void test_gt()
{
    Point p1{5, 2, 8};
    Point p2{3, 4, 8};

    Point result = gt(p1, p2);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 0);
    ASSERT_EQUAL(result[2], 0);
}

void test_lt()
{
    Point p1{5, 2, 8};
    Point p2{3, 4, 8};

    Point result = lt(p1, p2);

    ASSERT_EQUAL(result[0], 0);
    ASSERT_EQUAL(result[1], 1);
    ASSERT_EQUAL(result[2], 0);
}

void test_et()
{
    Point p1{5, 2, 8};
    Point p2{5, 3, 8};

    Point result = et(p1, p2);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 0);
    ASSERT_EQUAL(result[2], 1);
}

void test_net()
{
    Point p1{5, 2, 8};
    Point p2{5, 3, 9};

    Point result = net(p1, p2);

    ASSERT_EQUAL(result[0], 0);
    ASSERT_EQUAL(result[1], 1);
    ASSERT_EQUAL(result[2], 1);
}

void test_gte()
{
    Point p1{5, 2, 8};
    Point p2{5, 4, 8};

    Point result = gte(p1, p2);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 0);
    ASSERT_EQUAL(result[2], 1);
}

void test_lte()
{
    Point p1{5, 2, 8};
    Point p2{5, 4, 8};

    Point result = lte(p1, p2);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 1);
    ASSERT_EQUAL(result[2], 1);
}

void test_comparison_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{1, 2};

    ASSERT_THROW(
        gt(p1, p2),
        std::invalid_argument
    );

    ASSERT_THROW(
        lt(p1, p2),
        std::invalid_argument
    );

    ASSERT_THROW(
        et(p1, p2),
        std::invalid_argument
    );

    ASSERT_THROW(
        net(p1, p2),
        std::invalid_argument
    );

    ASSERT_THROW(
        gte(p1, p2),
        std::invalid_argument
    );

    ASSERT_THROW(
        lte(p1, p2),
        std::invalid_argument
    );
}
