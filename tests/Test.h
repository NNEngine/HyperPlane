#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cmath>
#include <stdexcept>

#define ASSERT_TRUE(condition)                                      \
    do {                                                            \
        if (!(condition))                                           \
            throw std::runtime_error("Assertion failed: " #condition); \
    } while (0)

#define ASSERT_FALSE(condition)                                     \
    do {                                                            \
        if (condition)                                              \
            throw std::runtime_error("Assertion failed: " #condition); \
    } while (0)

#define ASSERT_EQUAL(a, b)                                          \
    do {                                                            \
        if ((a) != (b))                                              \
            throw std::runtime_error("Values are not equal");       \
    } while (0)

#define ASSERT_NEAR(a, b, epsilon)                                  \
    do {                                                            \
        if (std::fabs((a) - (b)) > (epsilon))                       \
            throw std::runtime_error(                              \
                "Values are not approximately equal"               \
            );                                                      \
    } while (0)

#define ASSERT_THROW(expression, exception_type)                    \
    do {                                                            \
        bool thrown = false;                                        \
        try {                                                       \
            expression;                                             \
        }                                                           \
        catch (const exception_type&)                               \
        {                                                           \
            thrown = true;                                          \
        }                                                           \
        if (!thrown)                                                \
            throw std::runtime_error(                              \
                "Expected exception was not thrown"                 \
            );                                                      \
    } while (0)

#endif
