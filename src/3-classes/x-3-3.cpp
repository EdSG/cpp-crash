#include <iostream>
#include <cmath>

class Point
{
  private:

    const float _x;
    const float _y;

    Point(const float x, const float y):_x(x),_y(y) { }

  public:

    static Point cartesian(const float x, const float y)
    {
      return Point(x, y);
    }

    static Point polar(const float r, const float t)
    {
      const float x = r * std::cos(t);
      const float y = r * std::sin(t);

      return Point(x, y);
    }

    friend std::ostream& operator<<(std::ostream& out, Point const& p)
    {
      return out << "Point(" << p._x << "," << p._y << ")";
    }

};


int main(int argc, char **argv, char **envp)
{
  Point p1 = Point::cartesian(5.7, 1.2);
  Point p2 = Point::polar(5.7, 1.2);

  std::cout << p1 << std::endl;
  std::cout << p2 << std::endl;

  return 0;
}

