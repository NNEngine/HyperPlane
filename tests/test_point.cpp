#include "../includes/Point.h"
#include "Test.h"

void test_construction()
{
    Point p{1, 2, 3};

    ASSERT_EQUAL(p.dimensions(), 3);
    ASSERT_EQUAL(p.get(0), 1);
    ASSERT_EQUAL(p.get(1), 2);
    ASSERT_EQUAL(p.get(2), 3);
}


void test_vector_construction()
{
    std::vector<double> values{1.5, 2.5, 3.5};

    Point p(values);

    ASSERT_EQUAL(p.dimensions(), 3);
    ASSERT_EQUAL(p.get(0), 1.5);
    ASSERT_EQUAL(p.get(1), 2.5);
    ASSERT_EQUAL(p.get(2), 3.5);
}


void test_indexing()
{
    Point p{10, 20, 30};

    ASSERT_EQUAL(p[0], 10);
    ASSERT_EQUAL(p[1], 20);
    ASSERT_EQUAL(p[2], 30);

    p[1] = 100;

    ASSERT_EQUAL(p[1], 100);
}


void test_const_indexing()
{
    const Point p{10, 20, 30};

    ASSERT_EQUAL(p[0], 10);
    ASSERT_EQUAL(p[1], 20);
    ASSERT_EQUAL(p[2], 30);
}


void test_invalid_index()
{
    Point p{1, 2, 3};

    ASSERT_THROW(p[3], std::out_of_range);
}


void test_iteration()
{
    Point p{1, 2, 3};

    double sum = 0;

    for (double value : p)
    {
        sum += value;
    }

    ASSERT_EQUAL(sum, 6);
}


void test_dimensions()
{
    Point p{1, 2, 3, 4, 5};

    ASSERT_EQUAL(p.dimensions(), 5);
}


void test_unary_minus()
{
    Point p{1, -2, 3};

    Point result = -p;

    ASSERT_EQUAL(result[0], -1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], -3);
}
