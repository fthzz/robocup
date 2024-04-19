#include "patrol.hpp"

using namespace std;
using namespace cv;

double Patrol::getAngle(Point pt1, Point pt2) {
    Point pt3;
    if(pt1.y < pt2.y){
        Point t;
        t = pt1;
        pt1 = pt2;
        pt2 = t;
    }
    pt3.x = pt2.x - pt1.x;
    pt3.y = pt2.y - pt1.y;
    double son = -(pt3.y);
    double mother = pow(pow(pt3.x, 2) + pow(pt3.y, 2), 0.5);
    double angle = acos(son / mother);
    double degree = angle * 180.0 / M_PI;
    return degree;
}

double Patrol::getDistance(Mat picture,Point pt1,Point pt2){
    double k,b,x0,y0;
    double son1,mother1,son2,mother2,distance1,distance2;
    double angle,degree;
    pt1.x = -1 * pt1.x;
    pt2.x = -1 * pt2.x;
    k = (pt2.y - pt1.y) / (pt2.x - pt1.x);
    b = pt1.y - k * pt1.x;
    x0 = -1 * (picture.rows / 2);
    y0 = picture.cols / 2;
    son1 = abs(k * x0 - y0 + b);
    mother1 = pow(1+pow(k,2),0.5);
    distance1 = son1 / mother1;
    son2 = abs(1 / k);
    mother2 = pow(1+pow(1/k,2),0.5);
    angle = acos(son2 / mother2);
    degree = angle * 180.0 / M_PI;
    distance2 = distance1 * sin(angle);
    return distance2;
}

double Patrol::line_Length(Point pt1,Point pt2){
    double length = pow(pow((pt1.x - pt2.x),2) + pow((pt1.y - pt2.y),2),0.5);
    return length;
}

void Patrol::drawLine(Mat img,double rows,double cols,vector<Vec2f> lines){
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

        if(line_Length(pt1,pt2) < linelength1){
            pt3.x = pt1.x;
            pt3.y = pt1.y;
            pt4.x = pt2.x;
            pt4.y = pt2.y;
            linelength1 = line_Length(pt1,pt2);
        }
        if(line_Length(pt1,pt2) > linelength2){
            pt5.x = pt1.x;
            pt5.y = pt1.y;
            pt6.x = pt2.x;
            pt6.y = pt2.y;
            linelength2 = line_Length(pt1,pt2);
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

    this -> flag1 = pt7;
    this -> flag2 = pt8;
}

void Patrol::Prosess(Mat &src){
    Mat img;
    resize(src,img,Size(0,0),0.2,0.2,INTER_LINEAR);
    Mat img1,img2,kernel;
    threshold(img,img1,200,255,THRESH_BINARY);
    kernel = getStructuringElement(MORPH_RECT,Size(5,5));
    morphologyEx(img1,img1,MORPH_OPEN,kernel);
    morphologyEx(img1,img1,MORPH_CLOSE,kernel);
    threshold(img1,img2,10,200,THRESH_BINARY);
    vector<Vec2f>lines1;
    vector<Vec2f>lines2;
    HoughLines(img2,lines1,1,CV_PI/180,300);
    drawLine(img2,img2.rows,img2.cols,lines1);
    this -> img = img2;
}

void Patrol::patrolLine(Mat &src) {
    Prosess(src);
    this -> angle = getAngle(flag1,flag2);
    this -> distance = getDistance(img,flag1,flag2);
}