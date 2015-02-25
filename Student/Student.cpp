#include<iostream>
#include<string>
using namespace std;

class Student
{
	string name;				//���
	int semesterHours;			//����� ���������
	float average;				//������� ������
public:
	
	//����������� � �����������	
	Student(string name, int semesterHours, float average) : name(name), semesterHours(semesterHours), average(average){}

	virtual ~Student(){}

	//�������� ���������� ������� � ��������� ������� ���
	void addCourse(float grade) { average = (average + grade) / ++semesterHours; }

	//������ ������� ��������� ��������
	int hours() const { return semesterHours; }

	//������ ������� ���
	float gpa() const { return average; }

	//����� ������ ����������� ������ const �����, ��� ������ ��������, ��� ����� ����������� ������ ����.
	virtual void print() const
	{
		cout << name << "\n ����� ��������� " << semesterHours << "\n ������� ������ " << average << endl;
	}
};

class GraduateStudent : public Student
{
	int qualifierGrade;			//������ �������/������, ��� ��� � ��� ���...
	string advisor;				//������� ������������
public:
	
	//����������� � �����������
	GraduateStudent(string name, int semesterHours, float average, int qualifierGrade, string advisor)
		: Student(name, semesterHours, average), qualifierGrade(qualifierGrade), advisor(advisor) {}
	
	//������������� ����������� � �����������
	GraduateStudent(const Student & st, int qualifierGrade, string advisor)
		:Student(st), qualifierGrade(qualifierGrade), advisor(advisor) {}

	virtual ~GraduateStudent(){}

	int qualifier() const { return qualifierGrade; }

	virtual void print() const
	{
		Student::print();
		cout << " ������ ������� " << qualifierGrade << "\n ������� ������������ " << advisor << endl;
	}
};

 void main()
{
	setlocale(0, "");

	//������ �������� �������
	Student st("������", 0, 0);

	//������ ��������� �������, ��������� � ����������� ������ �������� �������
	GraduateStudent gs(st, 1, "������");

	//������ ��������� ��������
	GraduateStudent Sidorov("������� ����", 0, 0, 0, "�������");
	cout << " �������� ";
	Sidorov.print();
	cout << endl;

	//�������� ���� ������ �������� �������
	st.addCourse(3);
	st.addCourse(5);

	//�������� ������ ��������� �������
	gs.addCourse(5);

	//������� ������ � �������� �������
	cout << " ������� ";
	st.print();
	cout << endl;

	//������� ������ �� ��������� �������
	cout << " �������� ";
	gs.print();
	cout << endl;

	//������� ������� ������ ����� ���������.
	const Student * pt = &st;
	cout << " C������ ";
	pt->print();
	cout << endl;

	//�����������. ������ ��������� ���� "�������" � ���������� ��� ����� ���������.
	const Student * gpt = &gs;
	//���� �� ���������� �� �������� "����������" ��������, ������� ���������, ���� ���, �� ������ �� �������
	if (const GraduateStudent *q = dynamic_cast <const GraduateStudent *> (gpt))
	{
		cout << " �������� ";
		q->print();
		cout << endl;
	}
	
	//������ ������� ��������� ���� ������� ������ � �������� ������
	cout << " ������� ������ ���� " << st.hours() << " �����." << endl;
	cout << " �������� ������ ���� " << gs.hours() << " �����." << endl << endl;
}