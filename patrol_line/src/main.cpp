#include"picture.hpp"

using namespace std;
using namespace cv;

Point flag1,flag2;

int main(){
    Mat img = imread("the position of the picture",0);
    resize(img,img,Size(0,0),0.2,0.2,INTER_LINEAR);
    Mat img1,img2,kernel;
    threshold(img,img1,200,255,THRESH_BINARY);
    kernel = getStructuringElement(MORPH_RECT,Size(5,5));
    morphologyEx(img1,img1,MORPH_OPEN,kernel);
    morphologyEx(img1,img1,MORPH_CLOSE,kernel);
    threshold(img1,img2,10,200,THRESH_BINARY);
    vector<Vec2f>lines1;
    vector<Vec2f>lines2;
    HoughLines(img2,lines1,1,CV_PI/180,300);
    Picture src;
    src.drawLine(img2,img2.rows,img2.cols,lines1);
    imshow("img2",img2);
    waitKey(0);
    src.angle = src.getAngle(img2,flag1,flag2);
    src.distance = src.getDistance(img2,flag1,flag2);
    printf("当前图片白线与y方向的偏离角度为 %lf 度\n",src.angle);
    printf("图片竖直后白线与y轴的距离为 %lf 像素",src.distance);
    return 0;
}