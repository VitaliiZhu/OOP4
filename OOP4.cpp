#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;
float PI = 3.14;
class Cube {
public:
    Cube(double side) : side(side) {}

    double getVolume() const {
        return pow(side, 3);
    }

    double getSurfaceArea() const {
        return 6 * pow(side, 2);
    }

    void info(ostream& out) const {
        out << "Cube: " << endl;
        out << " Side: " << side << endl;
        out << " Volume: " << getVolume() << endl;
        out << " Surface Area: " << getSurfaceArea() << endl;
    }

private:
    double side;
};

class Sphere {
public:
    Sphere(double radius) : radius(radius) {}

    double getVolume() const {
        return (4.0 / 3.0) * PI * pow(radius, 3);
    }

    double getSurfaceArea() const {
        return 4 * PI * pow(radius, 2);
    }

    void info(ostream& out) const {
        out << "Sphere: " << endl;
        out << " Radius: " << radius << endl;
        out << " Volume: " << getVolume() << endl;
        out << " Surface Area: " << getSurfaceArea() << endl;
    }

private:
    double radius;
};

class SphereInCube : public Cube, public Sphere {
public:
    SphereInCube(double side) : Cube(side), Sphere(side / 2) {}

    void info(ostream& out) const {
        Cube::info(out);
        Sphere::info(out);
    }
};

int main() {
    SphereInCube obj(10); // Example with cube side 10
    ofstream fout("output.txt");

    if (!fout) {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    obj.info(fout);
    fout.close();

    cout << "Object information written to file output.txt" << endl;

    return 0;
}
