#include <iostream>

#define LINUX
//#define Windows
using namespace std;

/*
定义一个抽象类:窗口器件
*/
class Widget{
public:
	virtual void draw() = 0;
};

//定义一个linux下的按钮类
class LinuxButton :public Widget{
public:
	void draw(){
		cout << "LinuxButton\n";
	}
};
//定义一个linux下的菜单类
class LinuxMenu :public Widget{
public:
	void draw(){
		cout << "LinuxMenu\n";
	}
};
//定义一个windows下的按钮类
class WindowsButton :public Widget{
public:
	void draw(){
		cout << "WindowsButton\n";
	}
};
//定义一个windows下的菜单类
class WindowsMenu :public Widget{
public:
	void draw(){
		cout << "WindowsMenu\n";
	}
};
//创建一个工厂抽象类
class Factory{
public:
	virtual Widget *create_button() = 0;
	virtual Widget *create_menu() = 0;
};
//定义一个linux平台下的工厂
class LinuxFactory :public Factory{
public:
	Widget *create_button(){
		return new LinuxButton;
	}
	Widget *create_menu(){
		return new LinuxMenu;
	}
};
//定义一个windows平台下的工厂
class WindowsFactory :public Factory{
public:
	Widget *create_button(){
		return new WindowsButton;
	}
	Widget *create_menu(){
		return new WindowsMenu;
	}
};

//创建一个代理类，
class Client{
private:
	Factory *factory;

public:
	//构造方法
	Client(Factory *f){
		factory = f;
	}
	//绘图方法
	void draw(){
		Widget *w = factory->create_button();
		w->draw(); //开始绘制
		display_window_one();
		display_window_two();

	}
	//显示按钮与菜单
	void display_window_one(){
		Widget *w[] = {
			factory->create_button(),
			factory->create_menu()
		};
		w[0]->draw();
		w[1]->draw();
	}
	//显示按钮与菜单
	void display_window_two(){
		Widget *w[] = {
			factory->create_menu(),
			factory->create_button()
		};
		w[0]->draw();
		w[1]->draw();
	}
};

int main(){

	//定义一个工厂对象
	Factory *factory;  
	//使用宏定义判断平台相关性
    #ifdef LINUX
	  factory = new LinuxFactory;
    #elif defined Windows
	  factory = new WindowsFactory;
    #endif
    
    //定义一个代理对象，用来生产
	Client *c = new Client(factory);
	//绘制
	c->draw();

	system("pause");
	return 0;
}