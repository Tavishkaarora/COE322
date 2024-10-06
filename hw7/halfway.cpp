#include <iostream>
#include <string>
#include <sstream>

//define the Point class
class Point {
private:
    double x, y;

public:
    //constructor to initialize a point
    Point(double x_c = 0.0, double y_c = 0.0) : x(x_c), y(y_c) {}

    //overload the + operator for adding two points
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    //overload the * operator for scaling a point
    Point operator*(double scale) const {
        return Point(x * scale, y * scale);
    }

    //method to find the halfway point
    Point halfway(const Point& other) const {
        return (*this + other) * 0.5;
    }

    //method to convert variable type to string
    std::string ret_string() const {
        std::ostringstream oss;
        oss << "(" << x << ", " << y << ")";
        return oss.str();
    }
};

//testing point class in main
int main() {
    Point p(1.0, 2.2);
    Point q(3.4, 5.6);

    // Calculate halfway point
    Point h = p.halfway(q);

    // Output the points and halfway point
    std::cout << "Point p: " << p.ret_string() << std::endl;
    std::cout << "Point q: " << q.ret_string() << std::endl;
    std::cout << "Halfway point: " << h.ret_string() << std::endl;

    return 0;
}
