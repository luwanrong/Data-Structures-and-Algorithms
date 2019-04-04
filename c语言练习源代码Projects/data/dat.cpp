/*class Date
{
private:
	int year,month,day;
public:
	Date(int y,int m,int d);
	void print();
};
#include"iostream"
using namespace std;
#include"date.h"
int main()
{
	Date today(2010,3,1);
	cout<<"today is: ";
	today.print();
	return 0;
}
void Date::Date(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
}
void Date::print()
{
	cout<<year<<"-"<<month<<"-"<<day<<endl;
}*/
#include<iostream>   //cout需要
#include<string>
using namespace std; //cout需要
//定义一个学生类
class Student{
private:
	string name,gender;//定义两个字符串变量name,gender，记录姓名和性别
	int age;	//定义一个整型的年龄变量
	double id;	//定义个long型学号变量
public:
	void TestStudent();  //构造函数数据初始化
	void TestStudent( int age,double id,string name,string gender);
};
void Student::TestStudent(){//用构造函数将变量进行初始化
	cout<<"构造函数内初始化值："<<endl;
	string name="Dany";//姓名
	string gender="男";//性别
	int age=24;  //年龄
	double id=20172204063; //学号
	cout<<"姓名："<<name<<"，性别："<<gender<<",年龄："<<age<<"，学号：";
	cout.precision(15); //用于设置double类型的精度
	cout<<id<<endl;
}
void Student::TestStudent(int age,double id,string name,string gender){
	cout<<"姓名："<<name<<"，性别："<<gender<<",年龄："<<age<<"，学号：";
	cout.precision(15); //用于设置double类型的精度
	cout<<id<<endl;
}
int main(){
	Student s;//创建一个student对象s
	Student s1; //创建一个student对象s1
	s.TestStudent();//对象s对象调用方法TestStudent
	cout<<"创建对象时赋值："<<endl;
	s1.TestStudent(22,20162204063,"Day","男");//对象s1对象调用方法TestStudent
	return 0;
}
