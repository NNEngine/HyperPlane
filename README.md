# HyperPlane

**HyperPlane** is a lightweight C++ library for working with **N-dimensional points and vectors**.

The project started as an OOP-focused C++ project around a 2D Cartesian plane and evolved into a general-purpose N-dimensional vector mathematics library.

It provides a simple `Point` abstraction backed by `std::vector<double>`, along with arithmetic, vector mathematics, distances, transformations, predicates, coordinate manipulation, mathematical functions, aggregation, and operator overloading.

---

## Features

### Point

Create points in any number of dimensions:

```cpp
Point p{1, 2, 3, 4, 5};
```

Access coordinates:

```cpp
std::cout << p[0];

p[2] = 10;
```

Iterate over coordinates:

```cpp
for (double value : p)
{
    std::cout << value << '\n';
}
```

---

### Arithmetic

Component-wise arithmetic between points:

```cpp
Point p1{1, 2, 3};
Point p2{4, 5, 6};

Point a = p1 + p2;
Point s = p1 - p2;
Point m = p1 * p2;
Point d = p1 / p2;
Point r = p1 % p2;
```

Dimension mismatches are detected and reported through exceptions.

---

### Scalar Operations

Apply a scalar to every coordinate:

```cpp
Point p{1, 2, 3};

Point a = p + 5;
Point s = p - 5;
Point m = p * 5;
Point d = p / 5;
Point r = p % 5;
```

---

### Vector Mathematics

Includes common vector operations:

* Dot product
* Magnitude
* Normalization
* Angle between vectors
* Projection
* Rejection
* Direction vector

Example:

```cpp
Point p1{1, 2, 3};
Point p2{4, 5, 6};

double d = dot(p1, p2);
double m = magnitude(p1);

Point n = normalization(p1);
Point projection_ = projection(p1, p2);
```

---

### Distances & Norms

Supported distance calculations include:

* Euclidean distance
* Manhattan distance
* Chebyshev distance
* Minkowski distance
* Point-to-origin distance
* Hyperplane distance

Norms include:

* L1
* L2
* L∞
* Lp

Example:

```cpp
double euclidean = P2PD(p1, p2);
double manhattan = P2PManhattan(p1, p2);
double chebyshev = P2PChebyshev(p1, p2);
double minkowski = P2PMinkowski(p1, p2, 3);
```

---

### Transformations

Perform geometric transformations on N-dimensional points:

```cpp
Point p{1, 2, 3};

Point translated = translate(p, Point{10, 20, 30});
Point scaled = scaleu(p, 2);
Point reflected = reflect_origin(p);
```

Rotation can be performed in any two dimensions:

```cpp
Point rotated = rotate(p, 0, 1, angle);
```

---

### Aggregation

Calculate properties across all coordinates:

```cpp
double sum = aggr_sum(p);
double product = aggr_product(p);
double minimum = aggr_min(p);
double maximum = aggr_max(p);
double mean = aggr_mean(p);
```

---

### Predicates

Vector predicates include operations such as:

```cpp
is_zero(p);
is_unit(p);
is_parallel(p1, p2);
is_perpendicular(p1, p2);
```

---

### Coordinate Manipulation

Coordinates can be added, removed, inserted, or combined:

```cpp
Point a = append_coordinate(p, 10);
Point b = prepend_coordinate(p, 10);
Point c = insert_coordinate(p, 1, 10);
Point d = remove_coordinate(p, 1);
```

Points can also be concatenated.

---

### Mathematical Functions

Coordinate-wise mathematical functions are provided for operations such as:

```cpp
func_abs(p);
func_sqrt(p);
func_cbrt(p);
func_pow(p, 2);
func_exp(p);
func_log(p);
func_log10(p);

func_sin(p);
func_cos(p);
func_tan(p);

func_asin(p);
func_acos(p);
func_atan(p);

func_floor(p);
func_ceil(p);
func_round(p);
```

---

## Operator Overloading

The library provides natural C++ syntax for vector arithmetic:

```cpp
Point p1{1, 2, 3};
Point p2{4, 5, 6};

Point result = p1 + p2;

p1 += p2;

Point scaled = p1 * 2;

p1 *= 2;

Point inverted = -p1;
```

---

## Project Structure

```text
hyper_plane/
│
├── includes/
│   ├── Point.h
│   ├── Arithmetic.h
│   ├── Scalar.h
│   ├── Comparison.h
│   ├── Distances.h
│   ├── Vectors.h
│   ├── Transformations.h
│   ├── Aggregate.h
│   ├── Functions.h
│   ├── Predicates.h
│   ├── Coordinates.h
│   └── utility.h
│
├── src/
│   ├── Point.cpp
│   ├── Arithmetic.cpp
│   ├── Scalar.cpp
│   ├── Comparison.cpp
│   ├── Distances.cpp
│   ├── Vectors.cpp
│   ├── Transformations.cpp
│   ├── Aggregate.cpp
│   ├── Functions.cpp
│   ├── Predicates.cpp
│   ├── Coordinates.cpp
│   └── utility.cpp
│
├── tests/
│   ├── Test.h
│   ├── main.cpp
│   └── test_*.cpp
│
├── main.cpp
├── CMakeLists.txt
└── README.md
```

---

## Building

HyperPlane uses **CMake**.

### Clone

```bash
git clone https://github.com/NNEngine/HyperPlane.git
cd HyperPlane
```

### Configure

```bash
mkdir build
cd build
cmake ..
```

### Build

```bash
cmake --build .
```

This builds:

```text
libHyperPlane.a
hyper_plane
test_runner
```

---

## Running

Run the example program:

```bash
./hyper_plane
```

Run the test suite:

```bash
./test_runner
```

Or use CTest:

```bash
ctest --output-on-failure
```

---

## Testing

HyperPlane currently has **159 automated tests** covering the library's functionality, including normal operations, invalid inputs, dimension mismatches, and mathematical edge cases.

Current test status:

```text
Total : 159
Passed: 159
Failed: 0

All tests passed!
```

---

## Design

The central abstraction is:

```cpp
class Point
{
private:
    std::vector<double> coordinates;
};
```

A `Point` represents a position/vector in an arbitrary-dimensional Euclidean space.

For example:

```text
Point{1, 2}          → R²
Point{1, 2, 3}       → R³
Point{1, 2, 3, 4}    → R⁴
Point{...}           → Rⁿ
```

The library deliberately keeps the core representation simple and uses separate modules for different categories of operations.

---

## Requirements

* C++17 or newer
* CMake 3.16 or newer
* A C++ compiler supporting C++17

---

## License

This project is licensed under the **MIT License**.

