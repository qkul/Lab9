#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

struct Station// ������
{
	enum time { // �������������
		Monday = 1, Tuesday, Wednesday, Thuesday, Friday, Saturday, Sunday
	};
	
	Station() // �����������, ������� ���������� ��� ������ �������� ������ ������� ���������
	{
		Name_number = 0;
		Arrival_time = "";
		Destination = "";// ����� ����������
		follow_days = "";//��� ���������� 
		Parking_time = ""; // ����� �������
	}

	
	string  Arrival_time, Parking_time, follow_days, Destination;	
	 unsigned int Name_number :10 ;
};
union Day {
	int miles; 
	long meters;
} walk;

void HeadMenu();
int AnalysisOfClick();
void OutputElement(Station A, int P);
void InputElement(Station &A, int Poss);
void OutputList(Station *A, int size);
void AddElement(Station *&A, int &size);
void SortNumber(Station *A, int size);
void SortDestination(Station *A, int size);
void SearchNumber(Station *A, int size);
void SearchDestination(Station *A, int size);
void Change(Station *A, int size);
void DeleteElement(Station *A, int &size);

int main()
{
	int comm, N = 0;
	Station *TrainStation = new Station[N];
	setlocale(0, "rus");
	do {
		system("cls");
		HeadMenu();
		comm = AnalysisOfClick();
		system("cls");
		if (comm == 1)
			AddElement(TrainStation, N);
		if (comm == 2)
			OutputList(TrainStation, N);
		if (comm == 3)
			SortNumber(TrainStation, N);
		if (comm == 4)
			SearchNumber(TrainStation, N);
		if (comm == 5)
			SearchDestination(TrainStation, N);
		if (comm == 6)
			Change(TrainStation, N);
		if (comm == 7)
			DeleteElement(TrainStation, N);
		if (comm == 8)
			SearchDestination(TrainStation, N);
		_getch();
	} while (comm);
	return 0;
}

int AnalysisOfClick()
{
	switch (_getch())
	{
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case 'q': return 0;
		default: return -1;
	}
}

void HeadMenu() {
	
	
	cout << "_______________________________________" << endl ;
	cout << "|***           ������              ***|\n";
	cout << "|-------------------------------------|" << endl;
	cout << "| �������� ������ ��� �����!          |" << endl;
	cout << "| 1. ���� ������ � �����              |" << endl;
	cout << "| 2. ����� ������ � ������            |" << endl;
	cout << "| 3. ���������� �� ������ ������      |" << endl;
	cout << "| 4. ����� ����� �� ������ ������     |" << endl;
	cout << "| 5. ����� ����� �� ������ ���������� |" << endl;
	cout << "| 6. �������� ����                    |" << endl;
	cout << "| 7. ������� ���� �� ������           |" << endl;
	cout << "| 8. ���������� �� ������ ������      |" << endl;
	cout << "|_____________________________________|" << endl;
	cout << "|  ������ �����? ��� 'Q' !!1          |" << endl;
	cout << "|_____________________________________|" << endl;	

}

bool Check(int size) 
{
	if (!size) 
	{
		cout << "������ �� ��������!\n";
		return true;
	}
	else
		return false;
}

void InputElement(Station &A, int Poss)
{
	int r = 0;
	cout << "����� ������: �";
	cin >> r; A.Name_number = r; // �������������� ������� �����
	cout << "-----------------\n";
	cout << "����� ����������: ";
	cin >> A.Destination;
	cout << "-----------------\n";
	cout << "��� ����������: ";
	cin >> A.follow_days;
	cout << "-----------------\n";
	cout << "����� ����������: ";
	cin >> A.Arrival_time;
	cout << "-----------------\n";
	cout << "����� �������: ";
	cin >> A.Parking_time;
	cout << "-----------------\n";
	

}

void OutputElement(Station A, int P) 
{
	cout << P + 1 << ")����� ������: " << A.Name_number << endl;
	cout << "����� ����������: " << A.Destination << endl;
	cout << "��� ����������:: " << A.follow_days << endl;
	cout << "����� ����������: " << A.Arrival_time << endl;
	cout << "����� �������: " << A.Parking_time << endl;
	cout << "��� �����������: " << A.Monday << " " << A.Friday << endl;
	_getch();
}

void OutputList(Station *A, int size) 
{
	if (Check(size)) return;
	for (int i = 0; i < size; i++) { OutputElement(A[i], i); }
}

void AddElement(Station *&A, int &size)
{
	Station NewStation;
	InputElement(NewStation, size);
	Station *NewArray = new Station[size + 1];
	for (int i = 0; i < size; i++) { NewArray[i] = A[i]; }
	NewArray[size] = NewStation;
	size++;
	delete[]A;
	A = NewArray;
	cout << "*** ���� ��������! ***\n";
}

void SortNumber(Station *A, int size)
{
	
	if (Check(size)) return;
	Station temp;
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size - 1; j++) 
		{
			if (A[j].Name_number >	A[j + 1].Name_number) 
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++) { OutputElement(A[i], i); }
}

void SortDestination(Station *A, int size)
{
	if (Check(size)) return;
	Station temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (A[j].Destination > A[j + 1].Destination)
				swap(A[j], A[j + 1]);
		}
	}
	for (int i = 0; i < size; i++) { OutputElement(A[i], i); }
}

void SearchNumber(Station *A, int size) 
{
	int NumberTrain;
	cout << "��� ������ ������� ����� ������: �";
	cin >> NumberTrain;
	if (Check(size)) return;
	for (int i = 0; i < size; i++)
	{
		if (NumberTrain == A[i].Name_number)
			OutputElement(A[i], i);
		else
			cout << "������ ������ � ��� ����!\n";
	}
}

void SearchDestination(Station *A, int size)
{
	string Word;
	cout << "��� ������ ������� ����� ����������: ";
	cin >> Word;
	if (Check(size)) return;
	for (int i = 0; i < size; i++) 
	{
		if (Word == A[i].Destination) 
			OutputElement(A[i], i);
		else
			cout << "� " << Word << " ������ ����!\n";
	}
}

void Change(Station *A, int size) {
	int ChangeNumber;
	cout << "������� ����� ������, ��� �� �������� ��� �";
	cin >> ChangeNumber;
	if (Check(size)) return;
	for (int i = 0; i < size; i++) {
		if (ChangeNumber == A[i].Name_number) {

			InputElement(A[i], i);
		}
	}
}

//void DeleteElement(Station *&A, int &size) {
//	if (Check(size)) return;
//	cout << "-----------------------------------------------------\n";
//	for (int i = 0; i < size; i++) { cout << "���� �" << i + 1 << " --- " << A[i].Name_number << endl; }
//	cout << "-----------------------------------------------------\n";
//	int NameDelete;
//	int PossDelete = -1;
//	cout << "\n������� ����� ������, ������� ������ �������: ";
//	cin >> NameDelete;
//	for (int i = 0; i < size; i++)
//	{
//		if (NameDelete == A[i].Name_number)
//		{
//			PossDelete = i;
//			break;
//		}
//	}
//	if (PossDelete == -1) { cout << "\n***  ***\n"; return; }
//	Station *NewArray = new Station[size - 1];
//	for (int i = 0, k = 0; i < size; i++)
//	{
//		if (i != PossDelete) NewArray[k++] = A[i];
//	}
//	size--;
//	delete[]A;
//	A = NewArray;
//	cout << "\n***** ���� ������! *****\n";
//}

void DeleteElement(Station *A, int &size) {
		if (Check(size)) return;
		cout << "-----------------------------------------------------\n";
		for (int i = 0; i < size; i++) { cout << "���� �" << i + 1 << " --- " << A[i].Name_number << endl; }
		cout << "-----------------------------------------------------\n";
		int NameDelete;
		int PossDelete = -1;
		cout << "\n������� ����� ������, ������� ������ �������: ";
		cin >> NameDelete;
		for (int i = 0; i < size; i++)
		{
			if (NameDelete == A[i].Name_number)
			{
				PossDelete = i;
				break;
			}
		}
		if (PossDelete == -1) { cout << "\n***  ***\n"; return; }
		for (int i = PossDelete; i < size - 1; i++) { A[i] = A[i + 1]; }
		size--;
		cout << "\n***** ���� ������! *****\n";
	}

