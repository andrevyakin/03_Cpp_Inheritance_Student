#include<iostream>
#include<string>
using namespace std;

class Passport
{
	string No;			//����� � ����� ��������
	string Surname;		//�������
	string Given;		//���, ��������
	string DateBirth;	//���� ��������
	string PlaceBirth;	//����� ��������
	string DateIssue;	//���� ������
	string Authority;	//�����, ������� �����
public:
	Passport() : No(""), Surname(""), Given(""), DateBirth(""), PlaceBirth(""), DateIssue(""), Authority("") {}
	
	Passport(string No, string Surname, string Given, string DateBirth, string PlaceBirth, string DateIssue, string Authority) :
		No(No), Surname(Surname), Given(Given), DateBirth(DateBirth), PlaceBirth(PlaceBirth), DateIssue(DateIssue), Authority(Authority) {}
	
	friend istream& operator>>(istream& is, Passport& P);
	friend ostream& operator<<(ostream& os, const Passport& P);
};

class ForeignPassport : private Passport //�������� ������ ���������
{
	string Type;		//���
	string CodeState;	//��� ������
	string Sex;			//���
	string Visas;		//����
public:
	ForeignPassport() :Passport(), Type(""), CodeState(""), Sex(""), Visas(""){}
	ForeignPassport(string No, string Surname, string Given, string DateBirth, string PlaceBirth, string DateIssue, string Authority, string Type, string CodeState, string Sex, string Visas) :
		Passport(No, Surname, Given, DateBirth, PlaceBirth, DateIssue, Authority), Type(Type), CodeState(CodeState), Sex(Sex), Visas(Visas){}
	ForeignPassport(const Passport &P, string Type, string CodeState, string Sex, string Visas) :
		Passport(P), Type(Type), CodeState(CodeState), Sex(Sex), Visas(Visas){}
		
	void Print()const
	{
		cout << "\nType\t" << Type << "\nCodeState\t" << CodeState << "\nSex\t" << Sex << "\nVisas\t" << Visas << endl;
	}
};

//���� ������ ����� ����� ��� "��������"
istream& operator>>(istream&is, Passport&P)
{
	cout << "Set No\t";
	is >> P.No;
	cout << "Set Surname\t";
	is >> P.Surname;
	cout << "Set Given\t";
	is >> P.Given;
	cout << "Set Date of Birth\t";
	is >> P.DateBirth;
	cout << "Set Place of Birth\t";
	is >> P.PlaceBirth;
	cout << "Set Date Issue\t";
	is >> P.DateIssue;
	cout << "Set Authority\t";
	is >> P.Authority;
	return is;
}
//����� ������ ����� ����� ��� "��������"
ostream& operator<<(ostream&os, const Passport&P)
{
	cout << "No\t";
	os << P.No;
	cout << "\nSurname\t";
	os << P.Surname;
	cout << "\nGiven\t";
	os << P.Given;
	cout << "\nDate of Birth\t";
	os << P.DateBirth;
	cout << "\nPlace of Birth\t";
	os << P.PlaceBirth;
	cout << "\nDate Issue\t";
	os << P.DateIssue;
	cout << "\nAuthority\t";
	os << P.Authority;
	cout << endl;
	return os;
}

void main()
{
	Passport P;
	cin >> P;
	cout << P;

	ForeignPassport FP (P, "123", "234", "3456", "567");
	cout << P;
	FP.Print();
}
