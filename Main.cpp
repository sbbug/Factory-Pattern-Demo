#include<iostream>
using namespace std;

//#define SIMPLE
#define ROBUST
//����һ������ͼ����
class Shape{
public:
    //���췽��
	Shape(){
		id = total++;
	}
	//����һ�����麯��
	virtual void draw() = 0;
protected:
	//����һ������id��
	int id;
	//����һ��static������ֻ����ʼ��һ��
	static int total;
};
int Shape::total = 0;   //���о�̬������ʼ��
//����һ��Բ��
class Circle :public Shape{
public:
	//��ʼ��Բ������ֻ��ģ��
	void draw(){
		cout << "Circle" << id << ":draw" << endl;
	}
};
//����һ����������
class Square :public Shape{
public:
	void draw(){
		cout << "square" << id << ":draw" << endl;
	}
};
//����һ����Բ
class Ellipse :public Shape{
public:
	void draw(){
		cout << "ellpise" << id << ":draw" << endl;
	}
};
//���������
class Rectangle :public Shape{
public:
	void draw(){
		cout << "rectangle" << id <<":draw"<< endl;
	}
};


//����һ�������ӿ�
class Factory{
public:
	virtual Shape* createCurvedInstance() = 0;
	virtual Shape* createStraightInstance() = 0;

};

//����һ�����й���
class SimpleShapeFactory : public Factory{
public:
	Shape *createCurvedInstance(){

		return new Circle;
	}
	Shape *createStraightInstance(){

		return new Square;
	}
};
//����һ�����й���
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

//ʹ�ú��ж�Ӧ��ѡȡ�ĸ�������������

#ifdef ROBUST
	Factory* factory = new RobustShapeFactory;
	
#elif defined SIMPLE
	Factory* factory = new SimpleShapeFactory;

#endif

	//����һ����״��
	Shape* shapes[3];
	//�������Ķ�����ڻ�����
	shapes[0] = factory->createCurvedInstance(); 
	shapes[1] = factory->createStraightInstance();
	shapes[2] = factory->createCurvedInstance();  

	//���÷������л���
	for (int i = 0; i < 3; i++){
		shapes[i]->draw();
	}

	getchar();
	return 0;
}