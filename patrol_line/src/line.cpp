#include"line.hpp"
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

extern Point flag1,flag2;

double line_length(Point pt1,Point pt2){
    double length = pow(pow((pt1.x - pt2.x),2) + pow((pt1.y - pt2.y),2),0.5);
    return length;
}
void drawLine(Mat img,double rows,double cols,vector<Vec2f> lines){
    Point pt1,pt2,pt3,pt4,pt5,pt6,pt7,pt8;
    double linelength1 = 999999999;
    double linelength2 = 0;
    for(int i = 0;i < lines.size();i++){
        float distance = lines[i][0];
        float angle = lines[i][1];
        double cos_value = cos(angle);
        double sin_value = sin(angle);
        double x0 = distance*cos_value;
        double y0 = distance*sin_value;
        double length = max(rows,cols);

        pt1.x = cvRound(x0+length*(-sin_value));
        pt1.y = cvRound(y0+length*(cos_value));

        pt2.x = cvRound(x0-length*(-sin_value));
        pt2.y = cvRound(y0-length*(cos_value));

        if(line_length(pt1,pt2) < linelength1){
            pt3.x = pt1.x;
            pt3.y = pt1.y;
            pt4.x = pt2.x;
            pt4.y = pt2.y;
            linelength1 = line_length(pt1,pt2);
        }
        if(line_length(pt1,pt2) > linelength2){
            pt5.x = pt1.x;
            pt5.y = pt1.y;
            pt6.x = pt2.x;
            pt6.y = pt2.y;
            linelength2 = line_length(pt1,pt2);
        }
    }
    if(pt3.y * pt5.y < 0){
        Point t;
        t = pt5;
        pt5 = pt6;
        pt6 = t;
    }
    pt7.x = (pt3.x + pt5.x) / 2;
    pt7.y = (pt3.y + pt5.y) / 2;
    pt8.x = (pt4.x + pt6.x) / 2;
    pt8.y = (pt4.y + pt6.y) / 2;

    line(img,pt7,pt8,Scalar(255),5);

    flag1 = pt7;
    flag2 = pt8;
}