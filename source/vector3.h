//
// Created by fabio on 3/13/16.
//

#ifndef SYNTHETIC_CAM_SAMPLE_VECTOR3_H
#define SYNTHETIC_CAM_SAMPLE_VECTOR3_H

#include <math.h>
#include <iostream>

namespace math
{
    template<typename T>
    struct Vector3
    {
        T coords[3];

        Vector3();

        Vector3(const T& x, const T& y, const T& z);

        const T& x() const;

        const T& y() const;

        const T& z() const;

        Vector3<T> operator+(const Vector3<T>& other) const;

        Vector3<T> operator-(const Vector3<T>& other) const;

        Vector3<T> operator*(const T& value) const;

        bool operator==(const Vector3<T>& other) const;

        Vector3<T> normalized() const;

        T magnitude() const;
    };
}

#endif //SYNTHETIC_CAM_SAMPLE_VECTOR3_H
