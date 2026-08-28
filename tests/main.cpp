#include <iostream>
#include <string>

#include "test_point.cpp"
#include "test_arithmetic.cpp"
#include "test_scalar.cpp"
#include "test_comparison.cpp"
#include "test_distances.cpp"
#include "test_vectors.cpp"
#include "test_transformations.cpp"
#include "test_aggregate.cpp"
#include "test_functions.cpp"
#include "test_predicates.cpp"
#include "test_coordinate.cpp"
#include "test_operator.cpp"

struct TestCase
{
    const char* name;
    void (*function)();
};

int main()
{
    TestCase tests[] =
    {
        // Point
        {"Point Construction", test_construction},
        {"Point Vector Construction", test_vector_construction},
        {"Point Indexing", test_indexing},
        {"Point Const Indexing", test_const_indexing},
        {"Point Invalid Index", test_invalid_index},
        {"Point Iteration", test_iteration},
        {"Point Dimensions", test_dimensions},
        {"Point Unary Minus", test_unary_minus},

        // Arithmetic
        {"Addition", test_add},
        {"Subtraction", test_sub},
        {"Multiplication", test_mul},
        {"Division", test_div},
        {"Modulo", test_mod},

        {"Addition Dimension Mismatch", test_add_dimension_mismatch},
        {"Subtraction Dimension Mismatch", test_sub_dimension_mismatch},
        {"Multiplication Dimension Mismatch", test_mul_dimension_mismatch},
        {"Division Dimension Mismatch", test_div_dimension_mismatch},
        {"Modulo Dimension Mismatch", test_mod_dimension_mismatch},

        {"Division By Zero", test_division_by_zero},
        {"Modulo By Zero", test_modulo_by_zero},

        // Scalar
        {"Scalar Addition", test_scalar_add},
        {"Scalar Subtraction", test_scalar_sub},
        {"Scalar Multiplication", test_scalar_mul},
        {"Scalar Division", test_scalar_div},
        {"Scalar Modulo", test_scalar_mod},
        {"Scalar Division By Zero", test_scalar_division_by_zero},
        {"Scalar Modulo By Zero", test_scalar_modulo_by_zero},

        // Comparison
        {"Greater Than", test_gt},
        {"Less Than", test_lt},
        {"Equal To", test_et},
        {"Not Equal To", test_net},
        {"Greater Than Or Equal", test_gte},
        {"Less Than Or Equal", test_lte},
        {"Comparison Dimension Mismatch", test_comparison_dimension_mismatch},

        // Distances
        {"Point To Point Distance", test_p2pd},
        {"Point To Origin Distance", test_p2od},
        {"Manhattan Distance", test_manhattan_distance},
        {"Chebyshev Distance", test_chebyshev_distance},
        {"Minkowski Distance", test_minkowski_distance},
        {"Minkowski Manhattan", test_minkowski_manhattan},
        {"Minkowski Invalid Parameter", test_minkowski_invalid_parameter},
        {"L1 Norm", test_norm_l1},
        {"L2 Norm", test_norm_l2},
        {"LInf Norm", test_norm_linf},
        {"Lp Norm", test_norm_lp},
        {"Lp Invalid Parameter", test_norm_lp_invalid_parameter},
        {"Hyperplane Distance", test_hyperplane_distance},
        {"Hyperplane Zero Normal", test_hyperplane_zero_normal},
        {"Distance Dimension Mismatch", test_distance_dimension_mismatch},

        // Vectors
        {"Dot Product", test_dot},
        {"Dot Product Dimension Mismatch", test_dot_dimension_mismatch},
        {"Magnitude", test_magnitude},
        {"N-D Magnitude", test_magnitude_nd},
        {"Normalization", test_normalization},
        {"Normalization Zero Vector", test_normalization_zero_vector},
        {"Angle", test_angle},
        {"Angle Same Direction", test_angle_same_direction},
        {"Angle Opposite Direction", test_angle_opposite_direction},
        {"Angle Zero Vector", test_angle_zero_vector},
        {"Projection", test_projection},
        {"N-D Projection", test_projection_nd},
        {"Projection Zero Vector", test_projection_zero_vector},
        {"Rejection", test_rejection},
        {"N-D Rejection", test_rejection_nd},
        {"Direction", test_direction},
        {"Direction Identical Points", test_direction_identical_points},
        {"Vector Dimension Mismatch", test_vector_dimension_mismatch},

        // Transformations
        {"Translation", test_translate},
        {"Translation Dimension Mismatch", test_translate_dimension_mismatch},
        {"Uniform Scaling", test_uniform_scale},
        {"Non-Uniform Scaling", test_non_uniform_scale},
        {"Non-Uniform Scaling Dimension Mismatch",
            test_non_uniform_scale_dimension_mismatch},
        {"Reflection Origin", test_reflect_origin},
        {"Reflection Dimension", test_reflect_dimension},
        {"Reflection First Dimension", test_reflect_dimension_first},
        {"Reflection Last Dimension", test_reflect_dimension_last},
        {"Reflection Invalid Dimension", test_reflect_dimension_invalid},
        {"2D Rotation", test_rotate_2d},
        {"2D Rotation 180", test_rotate_2d_180},
        {"3D XY Rotation", test_rotate_3d_xy},
        {"3D XZ Rotation", test_rotate_3d_xz},
        {"3D YZ Rotation", test_rotate_3d_yz},
        {"Rotation Same Dimension", test_rotate_same_dimension},
        {"Rotation Invalid Dimension", test_rotate_invalid_dimension},

        // Aggregation
        {"Aggregate Sum", test_aggr_sum},
        {"Aggregate Sum Negative", test_aggr_sum_negative},
        {"Aggregate Product", test_aggr_product},
        {"Aggregate Product Zero", test_aggr_product_zero},
        {"Aggregate Min", test_aggr_min},
        {"Aggregate Max", test_aggr_max},
        {"Aggregate Mean", test_aggr_mean},
        {"Aggregate Mean Fraction", test_aggr_mean_fraction},
        {"Aggregate Decimal Values", test_aggregate_decimal_values},

        // Functions
        {"Function Abs", test_func_abs},
        {"Function Sqrt", test_func_sqrt},
        {"Function Cbrt", test_func_cbrt},
        {"Function Pow", test_func_pow},
        {"Function Exp", test_func_exp},
        {"Function Log", test_func_log},
        {"Function Log10", test_func_log10},
        {"Function Sin", test_func_sin},
        {"Function Cos", test_func_cos},
        {"Function Tan", test_func_tan},
        {"Function Asin", test_func_asin},
        {"Function Acos", test_func_acos},
        {"Function Atan", test_func_atan},
        {"Function Floor", test_func_floor},
        {"Function Ceil", test_func_ceil},
        {"Function Round", test_func_round},

        // Predicates
        {"Is Zero", test_is_zero},
        {"Is Not Zero", test_is_not_zero},
        {"Is Unit", test_is_unit},
        {"Is Unit N-D", test_is_unit_nd},
        {"Is Not Unit", test_is_not_unit},
        {"Is Parallel", test_is_parallel},
        {"Is Parallel Opposite", test_is_parallel_opposite},
        {"Is Not Parallel", test_is_not_parallel},
        {"Parallel Dimension Mismatch", test_parallel_dimension_mismatch},
        {"Parallel Zero Vector", test_parallel_zero_vector},
        {"Is Perpendicular", test_is_perpendicular},
        {"Is Perpendicular N-D", test_is_perpendicular_nd},
        {"Is Not Perpendicular", test_is_not_perpendicular},
        {"Perpendicular Dimension Mismatch",
            test_perpendicular_dimension_mismatch},

        // Coordinate
        {"Append Coordinate", test_append_coordinate},
        {"Prepend Coordinate", test_prepend_coordinate},
        {"Insert Coordinate Middle", test_insert_coordinate_middle},
        {"Insert Coordinate Beginning", test_insert_coordinate_beginning},
        {"Insert Coordinate End", test_insert_coordinate_end},
        {"Insert Coordinate Invalid", test_insert_coordinate_invalid},
        {"Remove Coordinate Middle", test_remove_coordinate_middle},
        {"Remove Coordinate Beginning", test_remove_coordinate_beginning},
        {"Remove Coordinate End", test_remove_coordinate_end},
        {"Remove Coordinate Invalid", test_remove_coordinate_invalid},
        {"Concatenate", test_concatenate},
        {"Concatenate Empty", test_concatenate_empty},

        // Operators
        {"Operator Addition", test_operator_add},
        {"Operator Subtraction", test_operator_sub},
        {"Operator Multiplication", test_operator_mul},
        {"Operator Division", test_operator_div},
        {"Operator Modulo", test_operator_mod},

        {"Operator Scalar Addition", test_operator_scalar_add},
        {"Operator Scalar Subtraction", test_operator_scalar_sub},
        {"Operator Scalar Multiplication", test_operator_scalar_mul},
        {"Operator Scalar Division", test_operator_scalar_div},
        {"Operator Scalar Modulo", test_operator_scalar_mod},

        {"Operator Unary Minus", test_operator_unary_minus},
        {"Operator Unary Plus", test_operator_unary_plus},

        {"Operator Plus Equals", test_operator_plus_equals},
        {"Operator Minus Equals", test_operator_minus_equals},
        {"Operator Multiply Equals", test_operator_multiply_equals},
        {"Operator Divide Equals", test_operator_divide_equals},
        {"Operator Modulo Equals", test_operator_modulo_equals},

        {"Operator Scalar Plus Equals",
            test_operator_scalar_plus_equals},
        {"Operator Scalar Minus Equals",
            test_operator_scalar_minus_equals},
        {"Operator Scalar Multiply Equals",
            test_operator_scalar_multiply_equals},
        {"Operator Scalar Divide Equals",
            test_operator_scalar_divide_equals},
        {"Operator Scalar Modulo Equals",
            test_operator_scalar_modulo_equals},

        {"Operator Division By Zero",
            test_operator_division_by_zero},
        {"Operator Scalar Division By Zero",
            test_operator_scalar_division_by_zero}
    };

    const std::size_t total =
        sizeof(tests) / sizeof(tests[0]);

    std::size_t passed = 0;
    std::size_t failed = 0;

    std::cout << "==============================\n";
    std::cout << "     N-D VECTOR LIBRARY TESTS\n";
    std::cout << "==============================\n\n";

    for (std::size_t i = 0; i < total; i++)
    {
        try
        {
            tests[i].function();

            std::cout << "[PASS] "
                      << tests[i].name
                      << '\n';

            passed++;
        }
        catch (const std::exception& e)
        {
            std::cout << "[FAIL] "
                      << tests[i].name
                      << " -> "
                      << e.what()
                      << '\n';

            failed++;
        }
        catch (...)
        {
            std::cout << "[FAIL] "
                      << tests[i].name
                      << " -> Unknown exception\n";

            failed++;
        }
    }

    std::cout << "\n==============================\n";
    std::cout << "Total : " << total << '\n';
    std::cout << "Passed: " << passed << '\n';
    std::cout << "Failed: " << failed << '\n';
    std::cout << "==============================\n";

    if (failed == 0)
    {
        std::cout << "\nAll tests passed! ✓\n";
        return 0;
    }

    std::cout << "\nSome tests failed.\n";
    return 1;
}
