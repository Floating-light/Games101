#include<cmath>
#include<Eigen/Core>
#include<Eigen/Dense>
#include<iostream>

Eigen::Vector3f rotationAndTransform(Eigen::Vector3f input, float rotation, Eigen::Vector2f translation)
{
    Eigen::Matrix3f tranform;
    tranform << cos(rotation), -sin(rotation), translation.x(),
        sin(rotation), cos(rotation), translation.y(),
        0, 0, 1;
    return tranform * input;
}

int main() {

    // Basic Example of cpp
    std::cout << "Example of cpp \n";
    float a = 1.0, b = 2.0;
    std::cout << a << std::endl;
    std::cout << a / b << std::endl;
    std::cout << std::sqrt(b) << std::endl;
    std::cout << std::acos(-1) << std::endl;
    std::cout << std::sin(30.0 / 180.0 * acos(-1)) << std::endl;

    // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f, 2.0f, 3.0f);
    Eigen::Vector3f w(1.0f, 0.0f, 0.0f);
    // vector output
    std::cout << "Example of output \n";
    std::cout << v << std::endl;
    // vector add
    std::cout << "Example of add \n";
    std::cout << v + w << std::endl;
    // vector scalar multiply
    std::cout << "Example of scalar multiply \n";
    std::cout << v * 3.0f << std::endl;
    std::cout << 2.0f * v << std::endl;
    // vector dot multiply
    std::cout << "Example of vector dot multiply \n"
        << v.dot(w) << std::endl;
    // vector corss multiply
    std::cout << "Example of vector corss multiply \n"
        << v.cross(w) << std::endl
        << "w �� v\n"  
        << w.cross(v) << std::endl;
    // Example of matrix
    std::cout << "Example of matrix \n";
    // matrix definition
    Eigen::Matrix3f i, j;
    i << 1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0,
        4.0, 6.0, 5.0,
        9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \n";
    std::cout << i << std::endl;
    // matrix add i + j
    std::cout << "matrix add \n"
        << i + j << std::endl;

    // matrix scalar multiply i * 2.0
    std::cout << "scalar multiply\n"
        << i * 2.0 << std::endl;
    // matrix multiply i * j
    std::cout << "matrix multiply\ni*j\n"
        << i * j << "\nj*i\n"
        << j * i << std::endl;
    // matrix multiply vector i * v
    std::cout << "matrix multiply vector i * v\n"
        << i * v << std::endl;

    std::cout << "assignment:\n"
        << rotationAndTransform(Eigen::Vector3f(2, 1, 1), 3.1415 / 4.0, Eigen::Vector2f(1, 2));

    return 0;
}