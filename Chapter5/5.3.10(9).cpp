#include <iostream>
#include <sstream>//just for beauty output
#include <iomanip>//just for beauty output
#include <string>
#include <math.h>
using namespace std;
class Point2D{
    public:  
        Point2D(double x, double y)
        {
            this -> x = x;
            this -> y = y;
        };
        string toString()
        {
            ostringstream out;
            out << "x = " << setprecision(7) << x << ", y = " << setprecision(7) << y;
            return out.str();
        };
        double getX()
        {
            return x;
        }
        double getY()
        {
            return y;
        }
    private:
        double x;
        double y;
};
class Line2D{
    public:
        Line2D(double slope, double y_intercept)
        {
            this -> slope = slope;
            this -> y_intercept = y_intercept;
        }
        Line2D(Point2D pointA, Point2D pointB)   
        {
            if (pointA.getX() == pointB.getX())
            {
                slope = 0;
                y_intercept = pointB.getX();
            }
            else if (pointA.getY() == pointB.getY())
            {
                slope = 0;
                y_intercept = 0;
                y = pointB.getY();
            }
            else
            {
                slope = (pointA.getY() - pointB.getY()) / (pointA.getX() - pointB.getX());
                y_intercept = (pointA.getX() * pointB.getY() - pointA.getY() * pointB.getX()) / (pointA.getX() - pointB.getX());
            }
        }        
        string toString()
	    {
	        ostringstream out;
	        if(slope == 0 && y_intercept != 0)
	            out << "x = " << setprecision(7) << y_intercept;
	        else if (slope != 0 && y_intercept == 0)
	            out << "y = "<< setprecision(7) << slope << "x";
	        else if (slope == 0 && y_intercept == 0)
	            out << "y = "<< setprecision(7) << y;
	        else
                out << "y = "<< setprecision(7) << slope << "x + " << setprecision(7) << y_intercept;
            return out.str();
	    }
    private:
        double slope;
        double y_intercept;
        double y = 0;
};
int main()
{
    double x1, y1, x2, y2, slope, intercept;
    cout << "Input please the 1-st point's coordinates: ";
    cin >> x1 >> y1;
    cout << "Input please the 2-st point's coordinates: ";
    cin >> x2 >> y2;
    Point2D p1(x1, y1), p2(x2, y2);
    Line2D l1(p1, p2);
    cout << l1.toString() << endl;
    cout << "Input slope ";
    cin >> slope;
    cout << "Input please intercept: ";
    cin >> intercept;
    Line2D l2(slope, intercept);
    cout << l2.toString() << endl;
    return 0;
}
