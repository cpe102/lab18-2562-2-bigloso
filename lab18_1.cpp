#include<iostream>
#include<cmath>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect A,Rect ??
	{  
	 	double x1=max(A.x,B.x);
	   	double x2=min(A.x+A.w,B.x+B.w);
	   	double x =x2-x1;

		double y1=min(A.y,B.y);
	   	double y2=max(A.y-A.h,B.y-B.h);
	   	double y =y1-y2;
	if(x*y >0)
	{
		return x*y;
	}else 
	{
		return 0;
	}
	  }
	
int main()
{
	Rect s1,s2;
	cout << "Please input Rect 1 (x y w h): ";
	cin  >>s1.x >>s1.y >>s1.w >>s1.h;
	cout << "Please input Rect 2 (x y w h): ";
	cin  >>s2.x >>s2.y >> s2.w >> s2.h;
	cout << "Overlap area =  "<< overlap(s1,s2);	
	return 0;
}