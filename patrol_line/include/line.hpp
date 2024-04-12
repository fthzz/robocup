#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

double line_length(Point pt1,Point pt2);

void drawLine(Mat img,double rosw,double cols,vector<Vec2f> line);