#ifndef VEC2_H
#define VEC2_H

namespace chess {

class Vec2
{
public:
  Vec2(int p_x, int p_y)
    : x(p_x),
      y(p_y)
  {
  }

  Vec2& operator=(const Vec2& other)
  {
    x = other.x;
    y = other.y;
    return *this;
  }

  Vec2& operator+=(const Vec2& other)
  {
    x += other.x;
    y += other.y;
    return *this;
  }

  Vec2& operator-=(const Vec2& other)
  {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  Vec2& operator*=(int scalar)
  {
    x *= scalar;
    y *= scalar;
    return *this;
  }


  int x;
  int y;
};

inline Vec2 operator+(Vec2 lhs, const Vec2& rhs)
{
  return lhs+=rhs;
}

inline Vec2 operator-(Vec2 lhs, const Vec2& rhs)
{
  return lhs-=rhs;
}

inline Vec2 operator*(Vec2 lhs, int scalar)
{
  return lhs*=scalar;
}

inline bool operator==(const Vec2 lhs, const Vec2 rhs)
{
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

} // namespace chess.

#endif //  VEC2_H
