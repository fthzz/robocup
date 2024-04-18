#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Picture{
public:
    double getAngle(Point flag1,Point flag2);
    double getDistance(Mat picture,Point flag1,Point flag2);
    double line_Length(Point pt1,Point pt2);
    void drawLine(Mat img,double rosw,double cols,vector<Vec2f> line);
    void Prosess();
    void Patrol_line();

    Mat img;
    Point flag1,flag2; 
    double angle,distance;
};