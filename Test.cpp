#include <iostream>

#define LINUX
//#define Windows
using namespace std;

/*
����һ��������:��������
*/
class Widget{
public:
	virtual void draw() = 0;
};

//����һ��linux�µİ�ť��
class LinuxButton :public Widget{
public:
	void draw(){
		cout << "LinuxButton\n";
	}
};
//����һ��linux�µĲ˵���
class LinuxMenu :public Widget{
public:
	void draw(){
		cout << "LinuxMenu\n";
	}
};
//����һ��windows�µİ�ť��
class WindowsButton :public Widget{
public:
	void draw(){
		cout << "WindowsButton\n";
	}
};
//����һ��windows�µĲ˵���
class WindowsMenu :public Widget{
public:
	void draw(){
		cout << "WindowsMenu\n";
	}
};
//����һ������������
class Factory{
public:
	virtual Widget *create_button() = 0;
	virtual Widget *create_menu() = 0;
};
//����һ��linuxƽ̨�µĹ���
class LinuxFactory :public Factory{
public:
	Widget *create_button(){
		return new LinuxButton;
	}
	Widget *create_menu(){
		return new LinuxMenu;
	}
};
//����һ��windowsƽ̨�µĹ���
class WindowsFactory :public Factory{
public:
	Widget *create_button(){
		return new WindowsButton;
	}
	Widget *create_menu(){
		return new WindowsMenu;
	}
};

//����һ�������࣬
class Client{
private:
	Factory *factory;

public:
	//���췽��
	Client(Factory *f){
		factory = f;
	}
	//��ͼ����
	void draw(){
		Widget *w = factory->create_button();
		w->draw(); //��ʼ����
		display_window_one();
		display_window_two();

	}
	//��ʾ��ť��˵�
	void display_window_one(){
		Widget *w[] = {
			factory->create_button(),
			factory->create_menu()
		};
		w[0]->draw();
		w[1]->draw();
	}
	//��ʾ��ť��˵�
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

	//����һ����������
	Factory *factory;  
	//ʹ�ú궨���ж�ƽ̨�����
    #ifdef LINUX
	  factory = new LinuxFactory;
    #elif defined Windows
	  factory = new WindowsFactory;
    #endif
    
    //����һ�����������������
	Client *c = new Client(factory);
	//����
	c->draw();

	system("pause");
	return 0;
}