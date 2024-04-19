#include "patrol.hpp"

using namespace std;
using namespace cv;

Point flag1,flag2;

int main(){
    Patrol patrol;
    auto src = imread("src1.jpg");
    patrol.patrolLine(src);
    auto a = patrol.angle;
    auto b = patrol.distance;
    printf("图像src1的白线与竖直方向的角度为%lf度\n",a);
    printf("图像src1的白线矫正后与中间竖直直线的距离为%lf像素\n",b); 
    return 0;
}