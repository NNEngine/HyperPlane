#include <iostream>

#include "./includes/Point.h"
#include "./includes/Arithmetic.h"
#include "./includes/Scalar.h"
#include "./includes/Comparison.h"
#include "./includes/Distances.h"
#include "./includes/Vectors.h"
#include "./includes/Transformations.h"
#include "./includes/Aggregate.h"
#include "./includes/Functions.h"
#include "./includes/Predicates.h"
#include "./includes/Coordinates.h"

int main()
{
    // =========================================================
    // Point
    // =========================================================

    std::cout << "========== Point ==========\n";

    Point p1{1, 2, 3};
    Point p2{4, 5, 6};

    std::cout << "P1 = ";
    p1.print_point();

    std::cout << "P2 = ";
    p2.print_point();

    std::cout << "Dimensions: "
              << p1.dimensions() << "\n";


    // =========================================================
    // Arithmetic
    // =========================================================

    std::cout << "\n========== Arithmetic ==========\n";

    std::cout << "P1 + P2 = ";
    (p1 + p2).print_point();

    std::cout << "P1 - P2 = ";
    (p1 - p2).print_point();

    std::cout << "P1 * P2 = ";
    (p1 * p2).print_point();

    std::cout << "P2 / P1 = ";
    (p2 / p1).print_point();

    std::cout << "P2 % P1 = ";
    (p2 % p1).print_point();


    // =========================================================
    // Scalar Operations
    // =========================================================

    std::cout << "\n========== Scalar ==========\n";

    double scalar = 2.0;

    std::cout << "Scalar: " << scalar << "\n";

    std::cout << "P1 + scalar = ";
    (p1 + scalar).print_point();

    std::cout << "P1 - scalar = ";
    (p1 - scalar).print_point();

    std::cout << "P1 * scalar = ";
    (p1 * scalar).print_point();

    std::cout << "P1 / scalar = ";
    (p1 / scalar).print_point();


    // =========================================================
    // Comparisons
    // =========================================================

    std::cout << "\n========== Comparison ==========\n";

    std::cout << "P1 > P2 = ";
    gt(p1, p2).print_point();

    std::cout << "P1 < P2 = ";
    lt(p1, p2).print_point();

    std::cout << "P1 == P2 = ";
    et(p1, p2).print_point();

    std::cout << "P1 != P2 = ";
    net(p1, p2).print_point();

    std::cout << "P1 >= P2 = ";
    gte(p1, p2).print_point();

    std::cout << "P1 <= P2 = ";
    lte(p1, p2).print_point();


    // =========================================================
    // Distances
    // =========================================================

    std::cout << "\n========== Distances ==========\n";

    std::cout << "Euclidean distance: "
              << P2PD(p1, p2) << "\n";

    std::cout << "Distance from origin: "
              << P2OD(p1) << "\n";

    std::cout << "Manhattan distance: "
              << P2PManhattan(p1, p2) << "\n";

    std::cout << "Chebyshev distance: "
              << P2PChebyshev(p1, p2) << "\n";

    std::cout << "Minkowski distance (p=3): "
              << P2PMinkowski(p1, p2, 3) << "\n";


    // =========================================================
    // Vector Operations
    // =========================================================

    std::cout << "\n========== Vector Operations ==========\n";

    std::cout << "Dot product: "
              << dot(p1, p2) << "\n";

    std::cout << "Magnitude P1: "
              << magnitude(p1) << "\n";

    std::cout << "Normalized P1: ";
    normalization(p1).print_point();

    std::cout << "Angle between P1 and P2: "
              << angle(p1, p2)
              << " radians\n";

    std::cout << "Projection of P1 onto P2: ";
    projection(p1, p2).print_point();

    std::cout << "Rejection of P1 from P2: ";
    rejection(p1, p2).print_point();

    std::cout << "Direction P1 -> P2: ";
    direction(p1, p2).print_point();


    // =========================================================
    // Transformations
    // =========================================================

    std::cout << "\n========== Transformations ==========\n";

    Point translation{10, 20, 30};

    std::cout << "Translated P1: ";
    translate(p1, translation).print_point();

    std::cout << "Uniform scale: ";
    scaleu(p1, 2).print_point();

    Point factors{2, 3, 4};

    std::cout << "Non-uniform scale: ";
    scalenu(p1, factors).print_point();

    std::cout << "Reflection about origin: ";
    reflect_origin(p1).print_point();

    std::cout << "Reflection about dimension 1: ";
    reflect_dimension(p1, 1).print_point();

    std::cout << "Rotation in dimensions 0-1: ";
    rotate(p1, 0, 1, 3.14159265358979323846 / 2)
        .print_point();


    // =========================================================
    // Aggregation
    // =========================================================

    std::cout << "\n========== Aggregation ==========\n";

    std::cout << "Sum: "
              << aggr_sum(p1) << "\n";

    std::cout << "Product: "
              << aggr_product(p1) << "\n";

    std::cout << "Minimum: "
              << aggr_min(p1) << "\n";

    std::cout << "Maximum: "
              << aggr_max(p1) << "\n";

    std::cout << "Mean: "
              << aggr_mean(p1) << "\n";


    // =========================================================
    // Predicates
    // =========================================================

    std::cout << "\n========== Predicates ==========\n";

    Point zero{0, 0, 0};
    Point unit{1, 0, 0};

    std::cout << "P1 is zero: "
              << is_zero(p1) << "\n";

    std::cout << "Zero is zero: "
              << is_zero(zero) << "\n";

    std::cout << "Unit is unit: "
              << is_unit(unit) << "\n";

    std::cout << "P1 parallel P2: "
              << is_parallel(p1, p2) << "\n";

    std::cout << "P1 perpendicular P2: "
              << is_perpendicular(p1, p2) << "\n";


    // =========================================================
    // Coordinate Manipulation
    // =========================================================

    std::cout << "\n========== Coordinates ==========\n";

    std::cout << "Original: ";
    p1.print_point();

    std::cout << "Append 10: ";
    append_coordinate(p1, 10).print_point();

    std::cout << "Prepend 10: ";
    prepend_coordinate(p1, 10).print_point();

    std::cout << "Insert 10 at index 1: ";
    insert_coordinate(p1, 1, 10).print_point();

    std::cout << "Remove index 1: ";
    remove_coordinate(p1, 1).print_point();


    // =========================================================
    // Mathematical Functions
    // =========================================================

    std::cout << "\n========== Mathematical Functions ==========\n";

    Point values{1, 4, 9};

    std::cout << "Values: ";
    values.print_point();

    std::cout << "sqrt: ";
    func_sqrt(values).print_point();

    std::cout << "abs: ";
    func_abs(Point{-1, -2, -3}).print_point();

    std::cout << "pow(x, 2): ";
    func_pow(values, 2).print_point();


    std::cout << "\n========== Done ==========\n";

    return 0;
}
