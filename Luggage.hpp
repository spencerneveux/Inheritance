//Spencer Neveux
//282(Inheritance)
//12/6/18

#ifndef Luggage_hpp
#define Luggage_hpp
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;
//Base Class Luggage
class Luggage {
protected:
    string type;
public:
    Luggage() {};
    ~Luggage() {}
    string getType() {return type;}
    virtual double volume() = 0;
    virtual void display() {cout << type << ": " << volume() << endl;}
};

// Box Class
class Box:public Luggage {
private:
    double width, height, length;
public:
    double volume() {
        return width * height * length;
    }
    Box(double w, double h, double l) {
        type = "Box";
        width = w;
        height = h;
        length = l;
    }
};

// Sphere Class
class Sphere:public Luggage {
private:
    double radius;
public:
    Sphere(double r) {
        type = "Sphere";
        radius = r;
    }
    double volume() {
        return ((4/3) * (M_PI) * (radius*radius*radius));
    }
};

//Cube Class
class Cube:public Luggage {
private:
    double side;
public:
    Cube(double s) {
        type = "Cube";
        side = s;
    }
    double volume() {
        return (side*side*side);
    }
};

//Pyramid Class
class Pyramid:public Luggage {
private:
    double length, width, height;
public:
    Pyramid(double l, double w, double h) {
        type = "Pyramid";
        length = l;
        width = w;
        height = h;
    }
    double volume() {
        return (length * width * height) / 3;
    }
};

//Cylinder Class
class Cylinder:public Luggage {
private:
    double radius, length;
public:
    Cylinder(double r, double l) {
        type = "Cylinder";
        radius = r;
        length = l;
    }
    double volume() {
        return (M_PI * (radius*radius) * length);
    }
};

//Ungula Class
class Ungula:public Luggage {
private:
    double radius, height;
public:
    Ungula(double r, double h) {
        type = "Ungula";
        radius = r;
        height = h;
    }
    double volume() {
        return (2 * (radius * radius) * height) / 3;
    }
};

//Barrel Class
class Barrel:public Luggage {
private:
    double height, midDiameter, topDiameter;
public:
    Barrel(double h, double mD, double tD) {
        type = "Barrel";
        height = h;
        midDiameter = mD;
        topDiameter = tD;
    }
    double volume() {
        return (M_PI * height * (2 * (midDiameter * midDiameter) + (topDiameter*topDiameter)))/12;
    }
};

//Frustrum of Cone class
class Frustrum:public Luggage {
private:
    double height, topD, bottomD;
public:
    Frustrum(double h, double tD, double bD) {
        type = "Frustrum";
        height = h;
        topD = tD;
        bottomD = bD;
    }
    double volume() {
        return (M_PI * height * ( (bottomD*bottomD) + (bottomD*topD) + (topD * topD) ))/ 12;
    }
};

#endif /* Luggage_hpp */
