//
// Created by fabio on 3/13/16.
//

#include "vector3.h"

template<typename T>
math::Vector3<T>::Vector3()
{
    coords[0] = 0;
    coords[1] = 0;
    coords[2] = 0;
}

template<typename T>
math::Vector3<T>::Vector3(const T& x, const T& y, const T& z)
{
    coords[0] = x;
    coords[1] = y;
    coords[2] = z;
}

template<typename T>
math::Vector3<T> math::Vector3<T>::operator+(const Vector3<T>& other) const
{
    return Vector3<T>(this->coords[0] + other.coords[0], this->coords[1] + other.coords[1],
                      this->coords[2] + other.coords[2]);
}

template<typename T>
math::Vector3<T> math::Vector3<T>::operator-(const Vector3<T>& other) const
{
    return Vector3<T>(this->coords[0] - other.coords[0], this->coords[1] - other.coords[1],
                      this->coords[2] - other.coords[2]);
}

template<typename T>
math::Vector3<T> math::Vector3<T>::operator*(const T& value) const
{
    return Vector3<T>(this->coords[0] * value, this->coords[1] * value, this->coords[2] * value);
}

template<typename T>
math::Vector3<T> math::Vector3<T>::normalized() const
{
    T magnitude = this->magnitude();

    return math::Vector3<T>(this->coords[0] / magnitude, this->coords[1] / magnitude, this->coords[2] / magnitude);
}

template<typename T>
T math::Vector3<T>::magnitude() const
{
    return sqrtf((float) (pow(this->coords[0], 2) + pow(this->coords[1], 2) + pow(this->coords[2], 2)));
}

template<typename T>
bool math::Vector3<T>::operator==(const Vector3<T>& other) const
{
    return this->coords[0] == other.coords[0] && this->coords[1] == other.coords[1] &&
           this->coords[2] == other.coords[2];
}

template<typename T>
const T& math::Vector3<T>::x() const
{
    return this->coords[0];
}

template<typename T>
const T& math::Vector3<T>::y() const
{
    return this->coords[1];
}

template<typename T>
const T& math::Vector3<T>::z() const
{
    return this->coords[2];
}

template
struct math::Vector3<int>;

template
struct math::Vector3<float>;

