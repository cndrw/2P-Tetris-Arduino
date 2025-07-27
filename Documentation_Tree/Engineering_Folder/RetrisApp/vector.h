#ifndef VECTOR_H
#define VECTOR_H

/**
* @brief Data type that holds an x and a y value
*/
typedef struct Vector
{
  int8_t x, y;

  Vector operator+(const Vector& other)
  {
    Vector result = {this->x + other.x, this->y + other.y};
    return result;
  }

  Vector& operator*=(const int8_t value)
  {
        x *= value;
        y *= value;
        return *this;
  }
};

#endif
