#include <stdio.h>
#include <stdint.h>
#include <math.h>

using namespace std;

class Point
{
    private:
        double X_axis;
        double Y_axis;
    public:
        Point(double x_axis, double y_axis);
        double getX_axis();
        double getY_axis();        
};

Point::Point(double x_axis, double y_axis)
{
    this->X_axis = x_axis;
    this->Y_axis = y_axis;
}

double Point::getX_axis()
{
    return this->X_axis;
};
double Point::getY_axis()
{
    return this->Y_axis;
};

class Distance
{
    private:
        Point PointA;
        Point PointB;
    public:
        Distance(Point PointA, Point PointB) : PointA(PointA), PointB(PointB) {}
        double Cal_Distance()
        {
            double dx = PointA.getX_axis() - PointB.getX_axis();
            double dy = PointA.getY_axis() - PointB.getY_axis();
            return sqrt(dx*dx + dy*dy);
        }
};

class Area
{
    private:
        Point PointA;
        Point PointB;
        Point PointC;
    public:
        Area(Point PointA, Point PointB, Point PointC) : PointA(PointA), PointB(PointB), PointC(PointC) {}
        double Cal_Area()
        {
            Distance AB(PointA, PointB);
            Distance BC(PointB, PointC);
            Distance AC(PointA, PointC);
            double p = (AB.Cal_Distance() + BC.Cal_Distance() + AC.Cal_Distance()) / 2;
            double area = sqrt(p*(p-AB.Cal_Distance())*(p-BC.Cal_Distance())*(p-AC.Cal_Distance()));
            return area;
        }
};

int main()
{
    Point A(1,2);
    Point B(4,7);
    Point C(-2,3);
    Distance AB(A,B);
    Distance AC(A,C);
    Distance BC(B,C);
    printf("Distance AB: %f\n", AB.Cal_Distance());
    printf("Distance AC: %f\n", AC.Cal_Distance());
    printf("Distance BC: %f\n", BC.Cal_Distance());
    Area ABC(A,B,C);
    double area = ABC.Cal_Area();
    printf("Area ABC: %f\n", area);
    return 0;
}
