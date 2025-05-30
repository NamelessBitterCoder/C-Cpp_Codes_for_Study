#include<iostream>
#include<cmath>

using namespace std;

class Point
{
	public:
		void Set(double ix, double iy)  //�������ꣻ
		{
			x = ix;
			y = iy; 
		}
		
		double xOffset()  //ȡy����������� ���� 1 ���˺���ӦΪȡx����������� 
		{
			return x;
		}
		
		double yOffset()  //ȡx����������� ���� 2 ���˺���ӦΪȡy���������
		{
			return y;
		}
		
		double angle()  //ȡ��ļ����ꣻ
		{
			return (180 / 3.14159) * atan2(y, x);
		}
		
		double radius()  //ȡ��ļ�����뾶�� 
		{
			return sqrt(x * x + y * y);
		} 
		protected:
			double x;  //x�������
			double y;  //y�������	 
}; 

int main()
{
	Point p;
	double x, y;
	
	cout << "Enter x and y:\n";
	cin >> x >> y;
	
	p.Set(x, y);
	p.x += 5;  //���� 3��x�������ܱ����ı�����������������ʹ�ã� 
	p.y += 6;  //���� 4��y�������ܱ����ı�����������������ʹ�ã�
	cout << "angle = " << p.angle()
		 << ", radius = " << p.radius()
		 << ", x offset = " << p.xOffset()
		 << ", y offset = " << p.yOffset() << endl; 
	return 0;
} 
 
