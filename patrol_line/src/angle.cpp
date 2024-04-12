#include"angle.hpp"

using namespace std;
using namespace cv;

double getAngle(Mat picture,Point flag1,Point flag2){
    Point flag3;
    if(flag1.y < flag2.y){
        Point t;
        t = flag1;
        flag1 = flag2;
        flag2 = t;
    }
    flag3.x = flag2.x - flag1.x;
    flag3.y = flag2.y - flag1.y;
    double son = -(flag3.y);
    double mother = pow(pow(flag3.x,2)+pow(flag3.y,2),0.5);
    double angle = acos(son/mother);
    double degree = angle * 180.0 / M_PI;
    return degree;
}