#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Picture{
public:
    double getAngle(Mat picture,Point flag1,Point flag2);
    double getDistance(Mat picture,Point flag1,Point flag2);
    double line_length(Point pt1,Point pt2);
    void drawLine(Mat img,double rosw,double cols,vector<Vec2f> line);

    double angle,distance;
};