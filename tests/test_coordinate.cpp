#include "../includes/Coordinates.h"
#include "Test.h"

void test_append_coordinate()
{
    Point p{1, 2, 3};

    Point result = append_coordinate(p, 4);

    ASSERT_EQUAL(result.dimensions(), 4);
    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], 3);
    ASSERT_EQUAL(result[3], 4);
}

void test_prepend_coordinate()
{
    Point p{1, 2, 3};

    Point result = prepend_coordinate(p, 0);

    ASSERT_EQUAL(result.dimensions(), 4);
    ASSERT_EQUAL(result[0], 0);
    ASSERT_EQUAL(result[1], 1);
    ASSERT_EQUAL(result[2], 2);
    ASSERT_EQUAL(result[3], 3);
}

void test_insert_coordinate_middle()
{
    Point p{1, 2, 3};

    Point result = insert_coordinate(p, 1, 99);

    ASSERT_EQUAL(result.dimensions(), 4);
    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 99);
    ASSERT_EQUAL(result[2], 2);
    ASSERT_EQUAL(result[3], 3);
}

void test_insert_coordinate_beginning()
{
    Point p{1, 2, 3};

    Point result = insert_coordinate(p, 0, 99);

    ASSERT_EQUAL(result.dimensions(), 4);
    ASSERT_EQUAL(result[0], 99);
    ASSERT_EQUAL(result[1], 1);
    ASSERT_EQUAL(result[2], 2);
    ASSERT_EQUAL(result[3], 3);
}

void test_insert_coordinate_end()
{
    Point p{1, 2, 3};

    Point result = insert_coordinate(p, 3, 99);

    ASSERT_EQUAL(result.dimensions(), 4);
    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], 3);
    ASSERT_EQUAL(result[3], 99);
}

void test_insert_coordinate_invalid()
{
    Point p{1, 2, 3};

    ASSERT_THROW(
        insert_coordinate(p, 4, 99),
        std::out_of_range
    );
}

void test_remove_coordinate_middle()
{
    Point p{1, 2, 3, 4};

    Point result = remove_coordinate(p, 1);

    ASSERT_EQUAL(result.dimensions(), 3);
    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 3);
    ASSERT_EQUAL(result[2], 4);
}

void test_remove_coordinate_beginning()
{
    Point p{1, 2, 3};

    Point result = remove_coordinate(p, 0);

    ASSERT_EQUAL(result.dimensions(), 2);
    ASSERT_EQUAL(result[0], 2);
    ASSERT_EQUAL(result[1], 3);
}

void test_remove_coordinate_end()
{
    Point p{1, 2, 3};

    Point result = remove_coordinate(p, 2);

    ASSERT_EQUAL(result.dimensions(), 2);
    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 2);
}

void test_remove_coordinate_invalid()
{
    Point p{1, 2, 3};

    ASSERT_THROW(
        remove_coordinate(p, 3),
        std::out_of_range
    );
}

void test_concatenate()
{
    Point p1{1, 2};
    Point p2{3, 4, 5};

    Point result = concatenate(p1, p2);

    ASSERT_EQUAL(result.dimensions(), 5);
    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], 3);
    ASSERT_EQUAL(result[3], 4);
    ASSERT_EQUAL(result[4], 5);
}

void test_concatenate_empty()
{
    Point p1{};
    Point p2{1, 2, 3};

    Point result = concatenate(p1, p2);

    ASSERT_EQUAL(result.dimensions(), 3);
    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], 3);
}
