#include "../includes/Vectors.h"
#include "Test.h"

void test_dot()
{
    Point p1{1, 2, 3};
    Point p2{4, 5, 6};

    double result = dot(p1, p2);

    ASSERT_NEAR(result, 32.0, 1e-9);
}

void test_dot_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{4, 5};

    ASSERT_THROW(
        dot(p1, p2),
        std::invalid_argument
    );
}

void test_magnitude()
{
    Point p{3, 4};

    double result = magnitude(p);

    ASSERT_NEAR(result, 5.0, 1e-9);
}

void test_magnitude_nd()
{
    Point p{1, 2, 2, 4};

    double result = magnitude(p);

    ASSERT_NEAR(result, 5.0, 1e-9);
}

void test_normalization()
{
    Point p{3, 4};

    Point result = normalization(p);

    ASSERT_NEAR(result[0], 0.6, 1e-9);
    ASSERT_NEAR(result[1], 0.8, 1e-9);

    ASSERT_NEAR(magnitude(result), 1.0, 1e-9);
}

void test_normalization_zero_vector()
{
    Point p{0, 0, 0};

    ASSERT_THROW(
        normalization(p),
        std::invalid_argument
    );
}

void test_angle()
{
    Point p1{1, 0};
    Point p2{0, 1};

    double result = angle(p1, p2);

    ASSERT_NEAR(result, M_PI / 2.0, 1e-9);
}

void test_angle_same_direction()
{
    Point p1{1, 2, 3};
    Point p2{2, 4, 6};

    double result = angle(p1, p2);

    ASSERT_NEAR(result, 0.0, 1e-9);
}

void test_angle_opposite_direction()
{
    Point p1{1, 2, 3};
    Point p2{-1, -2, -3};

    double result = angle(p1, p2);

    ASSERT_NEAR(result, M_PI, 1e-9);
}

void test_angle_zero_vector()
{
    Point p1{0, 0, 0};
    Point p2{1, 2, 3};

    ASSERT_THROW(
        angle(p1, p2),
        std::invalid_argument
    );
}

void test_projection()
{
    Point p1{3, 4};
    Point p2{1, 0};

    Point result = projection(p1, p2);

    ASSERT_NEAR(result[0], 3.0, 1e-9);
    ASSERT_NEAR(result[1], 0.0, 1e-9);
}

void test_projection_nd()
{
    Point p1{1, 2, 3};
    Point p2{1, 1, 1};

    Point result = projection(p1, p2);

    ASSERT_NEAR(result[0], 2.0, 1e-9);
    ASSERT_NEAR(result[1], 2.0, 1e-9);
    ASSERT_NEAR(result[2], 2.0, 1e-9);
}

void test_projection_zero_vector()
{
    Point p1{1, 2, 3};
    Point p2{0, 0, 0};

    ASSERT_THROW(
        projection(p1, p2),
        std::invalid_argument
    );
}

void test_rejection()
{
    Point p1{3, 4};
    Point p2{1, 0};

    Point result = rejection(p1, p2);

    ASSERT_NEAR(result[0], 0.0, 1e-9);
    ASSERT_NEAR(result[1], 4.0, 1e-9);
}

void test_rejection_nd()
{
    Point p1{1, 2, 3};
    Point p2{1, 1, 1};

    Point result = rejection(p1, p2);

    ASSERT_NEAR(result[0], -1.0, 1e-9);
    ASSERT_NEAR(result[1], 0.0, 1e-9);
    ASSERT_NEAR(result[2], 1.0, 1e-9);
}

void test_direction()
{
    Point p1{1, 2};
    Point p2{4, 6};

    Point result = direction(p1, p2);

    ASSERT_NEAR(result[0], 0.6, 1e-9);
    ASSERT_NEAR(result[1], 0.8, 1e-9);

    ASSERT_NEAR(magnitude(result), 1.0, 1e-9);
}

void test_direction_identical_points()
{
    Point p1{1, 2, 3};
    Point p2{1, 2, 3};

    ASSERT_THROW(
        direction(p1, p2),
        std::invalid_argument
    );
}

void test_vector_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{4, 5};

    ASSERT_THROW(
        projection(p1, p2),
        std::invalid_argument
    );

    ASSERT_THROW(
        rejection(p1, p2),
        std::invalid_argument
    );
}
