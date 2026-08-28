#include "../includes/Transformations.h"
#include "Test.h"

void test_translate()
{
    Point p{1, 2, 3};
    Point translation{4, 5, 6};

    Point result = translate(p, translation);

    ASSERT_EQUAL(result[0], 5);
    ASSERT_EQUAL(result[1], 7);
    ASSERT_EQUAL(result[2], 9);
}

void test_translate_dimension_mismatch()
{
    Point p{1, 2, 3};
    Point translation{4, 5};

    ASSERT_THROW(
        translate(p, translation),
        std::invalid_argument
    );
}

void test_uniform_scale()
{
    Point p{1, 2, 3};

    Point result = scaleu(p, 3);

    ASSERT_EQUAL(result[0], 3);
    ASSERT_EQUAL(result[1], 6);
    ASSERT_EQUAL(result[2], 9);
}

void test_non_uniform_scale()
{
    Point p{1, 2, 3};
    Point factors{2, 3, 4};

    Point result = scalenu(p, factors);

    ASSERT_EQUAL(result[0], 2);
    ASSERT_EQUAL(result[1], 6);
    ASSERT_EQUAL(result[2], 12);
}

void test_non_uniform_scale_dimension_mismatch()
{
    Point p{1, 2, 3};
    Point factors{2, 3};

    ASSERT_THROW(
        scalenu(p, factors),
        std::invalid_argument
    );
}

void test_reflect_origin()
{
    Point p{1, -2, 3};

    Point result = reflect_origin(p);

    ASSERT_EQUAL(result[0], -1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], -3);
}

void test_reflect_dimension()
{
    Point p{1, 2, 3};

    Point result = reflect_dimension(p, 1);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], -2);
    ASSERT_EQUAL(result[2], 3);
}

void test_reflect_dimension_first()
{
    Point p{1, 2, 3};

    Point result = reflect_dimension(p, 0);

    ASSERT_EQUAL(result[0], -1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], 3);
}

void test_reflect_dimension_last()
{
    Point p{1, 2, 3};

    Point result = reflect_dimension(p, 2);

    ASSERT_EQUAL(result[0], 1);
    ASSERT_EQUAL(result[1], 2);
    ASSERT_EQUAL(result[2], -3);
}

void test_reflect_dimension_invalid()
{
    Point p{1, 2, 3};

    ASSERT_THROW(
        reflect_dimension(p, 3),
        std::out_of_range
    );
}

void test_rotate_2d()
{
    Point p{1, 0};

    Point result = rotate(
        p,
        0,
        1,
        M_PI / 2.0
    );

    ASSERT_NEAR(result[0], 0.0, 1e-9);
    ASSERT_NEAR(result[1], 1.0, 1e-9);
}

void test_rotate_2d_180()
{
    Point p{1, 2};

    Point result = rotate(
        p,
        0,
        1,
        M_PI
    );

    ASSERT_NEAR(result[0], -1.0, 1e-9);
    ASSERT_NEAR(result[1], -2.0, 1e-9);
}

void test_rotate_3d_xy()
{
    Point p{1, 0, 5};

    Point result = rotate(
        p,
        0,
        1,
        M_PI / 2.0
    );

    ASSERT_NEAR(result[0], 0.0, 1e-9);
    ASSERT_NEAR(result[1], 1.0, 1e-9);
    ASSERT_NEAR(result[2], 5.0, 1e-9);
}

void test_rotate_3d_xz()
{
    Point p{1, 2, 0};

    Point result = rotate(
        p,
        0,
        2,
        M_PI / 2.0
    );

    ASSERT_NEAR(result[0], 0.0, 1e-9);
    ASSERT_NEAR(result[1], 2.0, 1e-9);
    ASSERT_NEAR(result[2], 1.0, 1e-9);
}

void test_rotate_3d_yz()
{
    Point p{5, 1, 0};

    Point result = rotate(
        p,
        1,
        2,
        M_PI / 2.0
    );

    ASSERT_NEAR(result[0], 5.0, 1e-9);
    ASSERT_NEAR(result[1], 0.0, 1e-9);
    ASSERT_NEAR(result[2], 1.0, 1e-9);
}

void test_rotate_same_dimension()
{
    Point p{1, 2, 3};

    ASSERT_THROW(
        rotate(p, 1, 1, M_PI / 2.0),
        std::invalid_argument
    );
}

void test_rotate_invalid_dimension()
{
    Point p{1, 2, 3};

    ASSERT_THROW(
        rotate(p, 0, 3, M_PI / 2.0),
        std::out_of_range
    );
}
