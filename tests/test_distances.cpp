#include "../includes/Distances.h"
#include "Test.h"

void test_p2pd()
{
    Point p1{1, 2, 3};
    Point p2{4, 6, 3};

    double result = P2PD(p1, p2);

    ASSERT_NEAR(result, 5.0, 1e-9);
}

void test_p2od()
{
    Point p{3, 4};

    double result = P2OD(p);

    ASSERT_NEAR(result, 5.0, 1e-9);
}

void test_manhattan_distance()
{
    Point p1{1, 2, 3};
    Point p2{4, 6, 5};

    double result = P2PManhattan(p1, p2);

    ASSERT_NEAR(result, 9.0, 1e-9);
}

void test_chebyshev_distance()
{
    Point p1{1, 2, 3};
    Point p2{4, 8, 5};

    double result = P2PChebyshev(p1, p2);

    ASSERT_NEAR(result, 6.0, 1e-9);
}

void test_minkowski_distance()
{
    Point p1{1, 2};
    Point p2{4, 6};

    // p = 2 → Euclidean distance
    double result = P2PMinkowski(p1, p2, 2);

    ASSERT_NEAR(result, 5.0, 1e-9);
}

void test_minkowski_manhattan()
{
    Point p1{1, 2};
    Point p2{4, 6};

    // p = 1 → Manhattan distance
    double result = P2PMinkowski(p1, p2, 1);

    ASSERT_NEAR(result, 7.0, 1e-9);
}

void test_minkowski_invalid_parameter()
{
    Point p1{1, 2};
    Point p2{3, 4};

    ASSERT_THROW(
        P2PMinkowski(p1, p2, 0.5),
        std::invalid_argument
    );
}

void test_norm_l1()
{
    Point p{-1, 2, -3, 4};

    double result = NormL1(p);

    ASSERT_NEAR(result, 10.0, 1e-9);
}

void test_norm_l2()
{
    Point p{3, 4};

    double result = NormL2(p);

    ASSERT_NEAR(result, 5.0, 1e-9);
}

void test_norm_linf()
{
    Point p{-2, 5, -9, 4};

    double result = NormLInf(p);

    ASSERT_NEAR(result, 9.0, 1e-9);
}

void test_norm_lp()
{
    Point p{3, 4};

    // L2 norm
    double result = NormLp(p, 2);

    ASSERT_NEAR(result, 5.0, 1e-9);
}

void test_norm_lp_invalid_parameter()
{
    Point p{1, 2, 3};

    ASSERT_THROW(
        NormLp(p, 0.5),
        std::invalid_argument
    );
}

void test_hyperplane_distance()
{
    /*
        Hyperplane:

        x + y = 0

        normal = (1, 1)
        c = 0

        Point = (3, 4)

        distance = |3 + 4| / sqrt(1² + 1²)
                 = 7 / sqrt(2)
    */

    Point p{3, 4};
    Point normal{1, 1};

    double result = P2Hyperplane(p, normal, 0);

    ASSERT_NEAR(result, 7.0 / std::sqrt(2.0), 1e-9);
}

void test_hyperplane_zero_normal()
{
    Point p{1, 2};
    Point normal{0, 0};

    ASSERT_THROW(
        P2Hyperplane(p, normal, 0),
        std::invalid_argument
    );
}

void test_distance_dimension_mismatch()
{
    Point p1{1, 2, 3};
    Point p2{4, 5};

    ASSERT_THROW(
        P2PD(p1, p2),
        std::invalid_argument
    );

    ASSERT_THROW(
        P2PManhattan(p1, p2),
        std::invalid_argument
    );

    ASSERT_THROW(
        P2PChebyshev(p1, p2),
        std::invalid_argument
    );

    ASSERT_THROW(
        P2PMinkowski(p1, p2, 2),
        std::invalid_argument
    );
}
