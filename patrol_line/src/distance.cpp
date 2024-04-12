#include"distance.hpp"

using namespace std;
using namespace cv;

double getDistance(Mat picture,Point flag1,Point flag2){
    double k,b,x0,y0;
    double son1,mother1,son2,mother2,distance1,distance2;
    double angle,degree;
    flag1.x = -1 * flag1.x;
    flag2.x = -1 * flag2.x;
    //printf("falg1:%d %d\n",flag1.x,flag1.y);
    //printf("falg2:%d %d\n",flag2.x,flag2.y);
    k = (flag2.y - flag1.y) / (flag2.x - flag1.x);
    b = flag1.y - k * flag1.x;
    //printf("k:%lf \n",k);
    //printf("b:%lf \n",b);
    x0 = -1 * (picture.rows / 2);
    y0 = picture.cols / 2;
    //printf("x0:%lf \n",x0);
    //printf("y0:%lf \n",y0);
    son1 = abs(k * x0 - y0 + b);
    mother1 = pow(1+pow(k,2),0.5);
    //printf("son1:%lf \n",son1);
    //printf("mother1:%lf \n",mother1);
    distance1 = son1 / mother1;
    son2 = abs(1 / k);
    mother2 = pow(1+pow(1/k,2),0.5);
    angle = acos(son2 / mother2);
    degree = angle * 180.0 / M_PI;
    //printf("另一个角度为%lf 度\n",degree);
    distance2 = distance1 * sin(angle);
    return distance2;
}