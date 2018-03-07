#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

struct Station// вокзал
{
	enum time { // перечислление
		Monday = 1, Tuesday, Wednesday, Thuesday, Friday, Saturday, Sunday
	};
	
	Station() // конструктор, который вызывается при каждом создании нового объекта структуры
	{
		Name_number = 0;
		Arrival_time = "";
		Destination = "";// пункт назначения
		follow_days = "";//дни следования 
		Parking_time = ""; // время стоянки
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
	cout << "|***           Вокзал              ***|\n";
	cout << "|-------------------------------------|" << endl;
	cout << "| Выберите нужный вам пункт!          |" << endl;
	cout << "| 1. Ввод данных о рейсе              |" << endl;
	cout << "| 2. Вывод данных о рейсах            |" << endl;
	cout << "| 3. Сортировка по номеру поезда      |" << endl;
	cout << "| 4. Поиск рейса по номеру поезда     |" << endl;
	cout << "| 5. Поиск рейса по понкту назначения |" << endl;
	cout << "| 6. Изменить рейс                    |" << endl;
	cout << "| 7. Удалить рейс из списка           |" << endl;
	cout << "| 8. Сортировка по номеру поезда      |" << endl;
	cout << "|_____________________________________|" << endl;
	cout << "|  Хотите выйти? ЖМИ 'Q' !!1          |" << endl;
	cout << "|_____________________________________|" << endl;	

}

bool Check(int size) 
{
	if (!size) 
	{
		cout << "Список не заполнен!\n";
		return true;
	}
	else
		return false;
}

void InputElement(Station &A, int Poss)
{
	int r = 0;
	cout << "Номер поезда: №";
	cin >> r; A.Name_number = r; // использоование битовых полей
	cout << "-----------------\n";
	cout << "Пункт назначения: ";
	cin >> A.Destination;
	cout << "-----------------\n";
	cout << "Дни следования: ";
	cin >> A.follow_days;
	cout << "-----------------\n";
	cout << "Время прибывания: ";
	cin >> A.Arrival_time;
	cout << "-----------------\n";
	cout << "Время стоянки: ";
	cin >> A.Parking_time;
	cout << "-----------------\n";
	

}

void OutputElement(Station A, int P) 
{
	cout << P + 1 << ")Номер поезда: " << A.Name_number << endl;
	cout << "Пункт назначения: " << A.Destination << endl;
	cout << "Дни следования:: " << A.follow_days << endl;
	cout << "Время прибывания: " << A.Arrival_time << endl;
	cout << "Время стоянки: " << A.Parking_time << endl;
	cout << "Дни регистрации: " << A.Monday << " " << A.Friday << endl;
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
	cout << "*** Рейс добавлен! ***\n";
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
	cout << "Для поиска введите номер поезда: №";
	cin >> NumberTrain;
	if (Check(size)) return;
	for (int i = 0; i < size; i++)
	{
		if (NumberTrain == A[i].Name_number)
			OutputElement(A[i], i);
		else
			cout << "Такого поезда у нас нету!\n";
	}
}

void SearchDestination(Station *A, int size)
{
	string Word;
	cout << "Для поиска введите пункт назначения: ";
	cin >> Word;
	if (Check(size)) return;
	for (int i = 0; i < size; i++) 
	{
		if (Word == A[i].Destination) 
			OutputElement(A[i], i);
		else
			cout << "В " << Word << " рейсов нету!\n";
	}
}

void Change(Station *A, int size) {
	int ChangeNumber;
	cout << "Введите номер поезда, что бы изменить его №";
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
//	for (int i = 0; i < size; i++) { cout << "Рейс №" << i + 1 << " --- " << A[i].Name_number << endl; }
//	cout << "-----------------------------------------------------\n";
//	int NameDelete;
//	int PossDelete = -1;
//	cout << "\nВведите номер поезда, который хотите удалить: ";
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
//	cout << "\n***** Рейс удален! *****\n";
//}

void DeleteElement(Station *A, int &size) {
		if (Check(size)) return;
		cout << "-----------------------------------------------------\n";
		for (int i = 0; i < size; i++) { cout << "Рейс №" << i + 1 << " --- " << A[i].Name_number << endl; }
		cout << "-----------------------------------------------------\n";
		int NameDelete;
		int PossDelete = -1;
		cout << "\nВведите номер поезда, который хотите удалить: ";
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
		cout << "\n***** Рейс удален! *****\n";
	}

