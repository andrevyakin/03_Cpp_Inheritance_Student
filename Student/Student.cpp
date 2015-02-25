#include<iostream>
#include<string>
using namespace std;

class Student
{
	string name;				//ФИО
	int semesterHours;			//сдано предметов
	float average;				//Средняя оценка
public:
	
	//конструктор с параметрами	
	Student(string name, int semesterHours, float average) : name(name), semesterHours(semesterHours), average(average){}

	virtual ~Student(){}

	//Добавить пройденный предмет и посчитать средний бал
	void addCourse(float grade) { average = (average + grade) / ++semesterHours; }

	//Узнать сколько предметов пройдено
	int hours() const { return semesterHours; }

	//Узнать средний бал
	float gpa() const { return average; }

	//Скотт Мейерс рекомендует писать const везде, где только возможно, вот решил последовать совету гуру.
	virtual void print() const
	{
		cout << name << "\n Сдано предметов " << semesterHours << "\n Средняя оценка " << average << endl;
	}
};

class GraduateStudent : public Student
{
	int qualifierGrade;			//ученая степень/звание, или что у них там...
	string advisor;				//Научный руководитель
public:
	
	//конструктор с параметрами
	GraduateStudent(string name, int semesterHours, float average, int qualifierGrade, string advisor)
		: Student(name, semesterHours, average), qualifierGrade(qualifierGrade), advisor(advisor) {}
	
	//перегруженный конструктор с параметрами
	GraduateStudent(const Student & st, int qualifierGrade, string advisor)
		:Student(st), qualifierGrade(qualifierGrade), advisor(advisor) {}

	virtual ~GraduateStudent(){}

	int qualifier() const { return qualifierGrade; }

	virtual void print() const
	{
		Student::print();
		cout << " Ученая степень " << qualifierGrade << "\n Научный руководитель " << advisor << endl;
	}
};

 void main()
{
	setlocale(0, "");

	//Создаю студента Пупкина
	Student st("Пупкин", 0, 0);

	//Создаю аспиранта Пупкина, передавая в конструктор объект студента Пупкина
	GraduateStudent gs(st, 1, "Петров");

	//Создаю аспиранта Сидорова
	GraduateStudent Sidorov("Сидоров Иван", 0, 0, 0, "Данилов");
	cout << " Аспирант ";
	Sidorov.print();
	cout << endl;

	//Добавляю пару оценок студенту Пупкину
	st.addCourse(3);
	st.addCourse(5);

	//Добавляю оценку аспиранту Пупкину
	gs.addCourse(5);

	//Печатаю данные о студенте Пупкине
	cout << " Студент ";
	st.print();
	cout << endl;

	//Печатаю данные об аспиранте Пупкине
	cout << " Аспирант ";
	gs.print();
	cout << endl;

	//Вызываю функцию печати через указатель.
	const Student * pt = &st;
	cout << " Cтудент ";
	pt->print();
	cout << endl;

	//Полиморфизм. Создаю указатель типа "Студент" и присваиваю ему адрес аспиранта.
	const Student * gpt = &gs;
	//Если за указателем на студента "скрывается" аспирант, печатаю аспиранта, если нет, то ничего не печатаю
	if (const GraduateStudent *q = dynamic_cast <const GraduateStudent *> (gpt))
	{
		cout << " Аспирант ";
		q->print();
		cout << endl;
	}
	
	//Узнать сколько предметов сдал студент Пупкин и аспирант Пупкин
	cout << " Студент Пупкин сдал " << st.hours() << " предм." << endl;
	cout << " Аспирант Пупкин сдал " << gs.hours() << " предм." << endl << endl;
}