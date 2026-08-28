#include "../includes/Aggregate.h"
#include "Test.h"

void test_aggr_sum()
{
    Point p{1, 2, 3, 4};

    double result = aggr_sum(p);

    ASSERT_EQUAL(result, 10);
}

void test_aggr_sum_negative()
{
    Point p{-1, -2, -3};

    double result = aggr_sum(p);

    ASSERT_EQUAL(result, -6);
}

void test_aggr_product()
{
    Point p{2, 3, 4};

    double result = aggr_product(p);

    ASSERT_EQUAL(result, 24);
}

void test_aggr_product_zero()
{
    Point p{2, 0, 4};

    double result = aggr_product(p);

    ASSERT_EQUAL(result, 0);
}

void test_aggr_min()
{
    Point p{5, -2, 10, 3};

    double result = aggr_min(p);

    ASSERT_EQUAL(result, -2);
}

void test_aggr_max()
{
    Point p{5, -2, 10, 3};

    double result = aggr_max(p);

    ASSERT_EQUAL(result, 10);
}

void test_aggr_mean()
{
    Point p{2, 4, 6, 8};

    double result = aggr_mean(p);

    ASSERT_EQUAL(result, 5);
}

void test_aggr_mean_fraction()
{
    Point p{1, 2};

    double result = aggr_mean(p);

    ASSERT_NEAR(result, 1.5, 1e-9);
}

void test_aggregate_decimal_values()
{
    Point p{1.5, 2.5, 3.5};

    ASSERT_NEAR(aggr_sum(p), 7.5, 1e-9);
    ASSERT_NEAR(aggr_product(p), 13.125, 1e-9);
    ASSERT_NEAR(aggr_min(p), 1.5, 1e-9);
    ASSERT_NEAR(aggr_max(p), 3.5, 1e-9);
    ASSERT_NEAR(aggr_mean(p), 2.5, 1e-9);
}
