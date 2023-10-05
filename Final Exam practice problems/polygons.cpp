#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;
};

class Polygon {
    private:
        Point* vertices;
        int numVertices;

    public:
    //default constructor 
    Polygon() : vertices(nullptr), numVertices(0) {}
    //destructor
    ~Polygon() {
        delete[] vertices;
    }
    //copy constructor
    Polygon(const Polygon& poly) : vertices(nullptr), numVertices(poly.numVertices) {
        if (numVertices > 0) {
        vertices = new Point[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            vertices[i] = poly.vertices[i];
        }
        }
    }
    //copy assignment constructor
    Polygon& operator=(const Polygon& poly) {
        if (this != &poly) {
        delete[] vertices;
        numVertices = poly.numVertices;
        if (numVertices > 0) {
            vertices = new Point[numVertices];
            for (int i = 0; i < numVertices; ++i) {
            vertices[i] = poly.vertices[i];
            }
        }
        }
        return *this;
    }

    void addVertex(int x, int y) {
        Point* newVertices = new Point[numVertices + 1];
        for (int i = 0; i < numVertices; ++i) {
        newVertices[i] = vertices[i];
        }
        newVertices[numVertices] = {x, y};
        delete[] vertices;
        vertices = newVertices;
        ++numVertices;
    }

    Point* getVertices() const {
        return vertices;
    }

    int getNumVertices() const {
        return numVertices;
    }

    void print() {
        for (int i = 0; i < numVertices; ++i) {
        std::cout << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i < numVertices - 1) {
            std::cout << ", ";
        }
        }
        std::cout << std::endl;
    }
    //perimeter method
    double computePerimeter() const {
    double perimeter = 0.0;
    for (int i = 0; i < numVertices; ++i) {
      int dx = vertices[(i + 1) % numVertices].x - vertices[i].x;
      int dy = vertices[(i + 1) % numVertices].y - vertices[i].y;
      perimeter += std::sqrt(dx * dx + dy * dy);
    }
    return perimeter;
    }
    //area method
    double computeArea() const {
    double area = 0.0;
    for (int i = 0; i < numVertices; ++i) {
      int x1 = vertices[i].x;
      int y1 = vertices[i].y;
      int x2 = vertices[(i + 1) % numVertices].x;
      int y2 = vertices[(i + 1) % numVertices].y;
      area += (x1 * y2 - x2 * y1);
    }
    return std::abs(area) / 2.0;
    }
};

    int main() {
    Polygon p1;
    p1.addVertex(1, 2);
    p1.addVertex(2, 5);
    p1.addVertex(3, 4);
    p1.addVertex(3, 3);

    Polygon p2(p1);
    p2.addVertex(3, 2);

    Polygon p3;
    p3 = p1;
    p3.addVertex(2, 2);

    p1.print();
    p2.print();
    p3.print();
    double perimeter = p1.computePerimeter();
    std::cout << "Perimeter of p1: " << perimeter << std::endl;
    double area = p1.computeArea();
    std::cout << "Area of p1: " << area << std::endl;

    return 0;
    }
