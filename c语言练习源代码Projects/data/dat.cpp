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
#include<iostream>   //cout��Ҫ
#include<string>
using namespace std; //cout��Ҫ
//����һ��ѧ����
class Student{
private:
	string name,gender;//���������ַ�������name,gender����¼�������Ա�
	int age;	//����һ�����͵��������
	double id;	//�����long��ѧ�ű���
public:
	void TestStudent();  //���캯�����ݳ�ʼ��
	void TestStudent( int age,double id,string name,string gender);
};
void Student::TestStudent(){//�ù��캯�����������г�ʼ��
	cout<<"���캯���ڳ�ʼ��ֵ��"<<endl;
	string name="Dany";//����
	string gender="��";//�Ա�
	int age=24;  //����
	double id=20172204063; //ѧ��
	cout<<"������"<<name<<"���Ա�"<<gender<<",���䣺"<<age<<"��ѧ�ţ�";
	cout.precision(15); //��������double���͵ľ���
	cout<<id<<endl;
}
void Student::TestStudent(int age,double id,string name,string gender){
	cout<<"������"<<name<<"���Ա�"<<gender<<",���䣺"<<age<<"��ѧ�ţ�";
	cout.precision(15); //��������double���͵ľ���
	cout<<id<<endl;
}
int main(){
	Student s;//����һ��student����s
	Student s1; //����һ��student����s1
	s.TestStudent();//����s������÷���TestStudent
	cout<<"��������ʱ��ֵ��"<<endl;
	s1.TestStudent(22,20162204063,"Day","��");//����s1������÷���TestStudent
	return 0;
}
