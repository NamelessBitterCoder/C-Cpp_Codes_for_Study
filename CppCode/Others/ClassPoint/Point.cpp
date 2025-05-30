#include<iostream>
#include<cmath>

using namespace std;

class Point
{
	public:
		void Set(double ix, double iy)  //设置坐标；
		{
			x = ix;
			y = iy; 
		}
		
		double xOffset()  //取y轴坐标分量； 错误 1 ：此函数应为取x轴坐标分量； 
		{
			return x;
		}
		
		double yOffset()  //取x轴坐标分量； 错误 2 ：此函数应为取y轴坐标分量
		{
			return y;
		}
		
		double angle()  //取点的极坐标；
		{
			return (180 / 3.14159) * atan2(y, x);
		}
		
		double radius()  //取点的极坐标半径； 
		{
			return sqrt(x * x + y * y);
		} 
		protected:
			double x;  //x轴分量；
			double y;  //y轴分量；	 
}; 

int main()
{
	Point p;
	double x, y;
	
	cout << "Enter x and y:\n";
	cin >> x >> y;
	
	p.Set(x, y);
	p.x += 5;  //错误 3：x是类中受保护的变量，不能在类以外使用； 
	p.y += 6;  //错误 4：y是类中受保护的变量，不能在类以外使用；
	cout << "angle = " << p.angle()
		 << ", radius = " << p.radius()
		 << ", x offset = " << p.xOffset()
		 << ", y offset = " << p.yOffset() << endl; 
	return 0;
} 
 
