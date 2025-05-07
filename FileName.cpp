#include <iostream>
#include <cmath>
#define M_PI 3.1415926
using namespace std;

class Geometric_shape {
public:
    virtual void Show() = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Circle : public Geometric_shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void Show() { cout << "圆形"; }
    double perimeter() { return 2 * M_PI * radius; }
    double area() { return M_PI * radius * radius; }
    double volume() { return 0; }
};

class Rectangle : public Geometric_shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void Show() { cout << "矩形"; }
    double perimeter() { return 2 * (width + height); }
    double area() { return width * height; }
    double volume() { return 0; }
};

class Triangle : public Geometric_shape {
private:
    double a, b, c;
public:
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {}
    void Show() { cout << "三角形"; }
    double perimeter() { return a + b + c; }
    double area() {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    double volume() { return 0; }
};

class Box : public Geometric_shape {
private:
    double length, width, height;
public:
    Box(double l, double w, double h) : length(l), width(w), height(h) {}
    void Show() { cout << "长方体"; }
    double perimeter() { return 4 * (length + width + height); }
    double area() { return 2 * (length * width + width * height + height * length); }
    double volume() { return length * width * height; }
};

class Cylinder : public Geometric_shape {
private:
    double radius, height;
public:
    Cylinder(double r, double h) : radius(r), height(h) {}
    void Show() { cout << "圆柱体"; }
    double perimeter() { return 2 * M_PI * radius; }
    double area() { return 2 * M_PI * radius * (radius + height); }
    double volume() { return M_PI * radius * radius * height; }
};

class Cone : public Geometric_shape {
private:
    double radius, height;
public:
    Cone(double r, double h) : radius(r), height(h) {}
    void Show() { cout << "圆锥体"; }
    double perimeter() { return M_PI * radius; }
    double area() { return M_PI * radius * (radius + sqrt(height * height + radius * radius)); }
    double volume() { return (1.0 / 3) * M_PI * radius * radius * height; }
};

class T_pyramid : public Geometric_shape {
private:
    double base, side1, side2, height;
public:
    T_pyramid(double b, double s1, double s2, double h) : base(b), side1(s1), side2(s2), height(h) {}
    void Show() { cout << "三棱锥"; }
    double perimeter() { return base + side1 + side2; }
    double area() { return 0.5 * base * height; }
    double volume() { return (1.0 / 3) * base * height; }
};

class T_prism : public Geometric_shape {
private:
    double base, side1, side2, height;
public:
    T_prism(double b, double s1, double s2, double h) : base(b), side1(s1), side2(s2), height(h) {}
    void Show() { cout << "三棱柱"; }
    double perimeter() { return 2 * (base + side1 + side2); }
    double area() { return base * height + 0.5 * base * side1 + 0.5 * base * side2; }
    double volume() { return base * height; }
};



int main()
{
    Geometric_shape* gs[] = { new Circle(10),
    new  Rectangle(6,8),
    new  Triangle(3,4,5),
    new  Box(6,8,3),
    new   Cylinder(10,3),
    new  Cone(10,3),
    new  T_pyramid(3,4,5,3),
    new  T_prism(3,4,5,3) };
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        gs[i]->Show();
        cout << endl;
    }
    for (i = 0; i < 8; i++)
    {
        gs[i]->Show();
        cout << endl;
    }
    cout << "平面图形：" << endl;
    for (i = 0; i < 3; i++)
    {
        cout << "图形周长：" << gs[i]->perimeter() << '\t';
        cout << "图形面积：" << gs[i]->area() << '\t';
        cout << "图形体积：" << gs[i]->volume() << endl;
    }
    cout << "立体图形：" << endl;
    for (i = 3; i < 8; i++)
    {
        cout << "图形底周长：" << gs[i]->perimeter() << '\t';
        cout << "图形底面积：" << gs[i]->area() << '\t';
        cout << "图形体积  ：" << gs[i]->volume() << endl;
    }
    return 0;
} 