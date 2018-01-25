#include<iostream>
using namespace std;

//#define SIMPLE
#define ROBUST
//定义一个抽象图形类
class Shape{
public:
    //构造方法
	Shape(){
		id = total++;
	}
	//定义一个纯虚函数
	virtual void draw() = 0;
protected:
	//定义一个对象id号
	int id;
	//定义一个static变量，只被初始化一次
	static int total;
};
int Shape::total = 0;   //类中静态变量初始化
//定义一个圆类
class Circle :public Shape{
public:
	//开始画圆，这里只是模拟
	void draw(){
		cout << "Circle" << id << ":draw" << endl;
	}
};
//定义一个正方形类
class Square :public Shape{
public:
	void draw(){
		cout << "square" << id << ":draw" << endl;
	}
};
//定义一个椭圆
class Ellipse :public Shape{
public:
	void draw(){
		cout << "ellpise" << id << ":draw" << endl;
	}
};
//定义矩形类
class Rectangle :public Shape{
public:
	void draw(){
		cout << "rectangle" << id <<":draw"<< endl;
	}
};


//定义一个工厂接口
class Factory{
public:
	virtual Shape* createCurvedInstance() = 0;
	virtual Shape* createStraightInstance() = 0;

};

//定义一个单列工厂
class SimpleShapeFactory : public Factory{
public:
	Shape *createCurvedInstance(){

		return new Circle;
	}
	Shape *createStraightInstance(){

		return new Square;
	}
};
//定义一个单列工厂
class RobustShapeFactory :public Factory{
public:
	Shape* createCurvedInstance(){

		return new Ellipse;
	}
	Shape* createStraightInstance(){
		return new Rectangle;
	}
};

int main(){

//使用宏判断应该选取哪个工厂进行生产

#ifdef ROBUST
	Factory* factory = new RobustShapeFactory;
	
#elif defined SIMPLE
	Factory* factory = new SimpleShapeFactory;

#endif

	//定义一个形状类
	Shape* shapes[3];
	//将生产的对象放在基类里
	shapes[0] = factory->createCurvedInstance(); 
	shapes[1] = factory->createStraightInstance();
	shapes[2] = factory->createCurvedInstance();  

	//调用方法进行绘制
	for (int i = 0; i < 3; i++){
		shapes[i]->draw();
	}

	getchar();
	return 0;
}