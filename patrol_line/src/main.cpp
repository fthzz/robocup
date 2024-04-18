#include"picture.hpp"

using namespace std;
using namespace cv;

Point flag1,flag2;

int main(){
    Picture src1;
    src1.Patrol_line();
    auto a = src1.angle;
    auto b = src1.distance;
    printf("图像src1的白线与竖直方向的角度为%lf度\n",a);
    printf("图像src1的白线矫正后与中间竖直直线的距离为%lf像素\n",b); 
    return 0;
}