// #include <fstream>
// #include <windows.h>
#include "Typography.h"

using namespace std;

char getCh();

void mainMenu();
void orderMenu();
void deleteOrderMenu();

void inputOrdersFromFile(Typography& typography);
void outOrdersInFile(const Typography& typography);
void outOrderOnScreen(const Typography& typography);

void order(Typography& typography);
void orderBook(Typography& typography);
void orderPoster(Typography& typography);
void orderBusinessCard(Typography& typography);

void deleteOrder(Typography& typography);
bool deleteBook(Typography& typography);
bool deletePoster(Typography& typography);
bool deleteBusinessCard(Typography& typography);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Typography typography;
	char ch;
		
	cout << "����� ����������!" << endl << endl;
	mainMenu();
	while ((ch = getCh()) != '6')
	{
		switch (ch)
		{
		case '1':
			order(typography);
			break;
		case '2':
			deleteOrder(typography);
			break;
		case '3':
			outOrderOnScreen(typography);
			break;
		case '4':
			inputOrdersFromFile(typography);
			break;
		case '5':
			outOrdersInFile(typography);
			break;
		}
		mainMenu();
	}
		
	cout << "�� ��������!" << endl;
	return 0;
}

void order(Typography& typography)
{
	char ch;
	orderMenu();
	while ((ch = getCh()) != '4')
	{
		switch (ch)
		{
		case'1':
			orderBook(typography);
			break;
		case'2':
			orderPoster(typography);		
			break;
		case'3':
			orderBusinessCard(typography);
			break;
		}
		cout << "��� ����� ��������!" << endl << endl;
		orderMenu();
	}	
}

void orderBusinessCard(Typography& typography)
{
	BusinessCard businessCard;
	String string;

	cout << "������� ���: " << endl;
	cin >> string;
	cout << endl;
	businessCard.ChangeName(string);

	cout << "������� �������: " << endl;
	cin >> string;
	cout << endl;
	businessCard.ChangeSurname(string);

	cout << "������� ������: " << endl;
	cin >> string;
	cout << endl;
	businessCard.ChangeService(string);

	cout << "������� ����� ��������: " << endl;
	cin >> string;
	cout << endl;
	businessCard.ChangePhoneNumber(string);

	typography.AddBusinessCard(businessCard);

}
void orderPoster(Typography& typography)
{
	Poster poster;
	String string;

	cout << "������� ��� �������: " << endl;
	cin >> string;
	cout << endl;
	poster.ChangeTypePoster(string);

	typography.AddPoster(poster);
}

void orderBook(Typography& typography)
{
	Book book;
	String string;

	cout << "������� �������� �����: " << endl;
	cin >> string;
	cout << endl;
	book.ChangeNameBook(string);

	cout << "������� ��� ������: " << endl;
	cin >> string;
	cout << endl;
	book.ChangeNameAuthor(string);

	cout << "������� ������� ������: " << endl;
	cin >> string;
	cout << endl;
	book.ChangeSurnameAuthor(string);

	cout << "������� ���������� ����: " << endl;
	cin >> string;
	cout << endl;
	book.ChangeNumberBooks(string);

	typography.AddBook(book);

}

void deleteOrder(Typography& typography)
{
	bool successDelete;
	char ch;
	deleteOrderMenu();
	while ((ch = getCh()) != '4')
	{
		switch (ch)
		{
		case'1':
			successDelete = deleteBook(typography);
			break;
		case'2':
			successDelete = deletePoster(typography);
			break;
		case'3':
			successDelete = deleteBusinessCard(typography);
			break;
		}

		if(successDelete)
			cout << "��� ����� �����!" << endl << endl;
		else 
			cout << "��� �� ������!" << endl << endl;
		deleteOrderMenu();
	}
}

bool deleteBook(Typography& typography)
{
	char temp[String::CINLIM];
	cout << "������� �������� ��������� �����:" << endl;
	cin.getline(temp, String::CINLIM);
	cout << endl;
	return typography.DeleteBook(temp);
}

bool deletePoster(Typography& typography)
{
	char temp[String::CINLIM];
	cout << "������� ��� ���������� �������:" << endl;
	cin.getline(temp, String::CINLIM);
	cout << endl;
	return typography.DeletePoster(temp);
}

bool deleteBusinessCard(Typography& typography)
{
	char temp[String::CINLIM];
	cout << "������� �������� ������ ��������� �������:" << endl;
	cin.getline(temp, String::CINLIM);
	cout << endl;
	return typography.DeleteBusinessCard(temp);
}

void outOrderOnScreen(const Typography& typography)
{
	cout << "���� ������: " << endl << endl;
	cout << typography;
}

void inputOrdersFromFile(Typography& typography)
{	
	ifstream file("input/Orders.txt");
	file >> typography;	
	file.close();
}

void outOrdersInFile(const Typography& typography)
{	
	ofstream file("input/Orders.txt");
	file << typography;
	file.close();
}

void mainMenu()
{	
	cout << "�������� ����� ����:" << endl;
	cout << "1 - �������� �����" << endl;
	cout << "2 - ������� �����" << endl;
	cout << "3 - ���������� ������" << endl;
	cout << "4 - ��������� ������ �� �����" << endl;
	cout << "5 - ��������� ������ � ����" << endl;
	cout << "6 - ��������� ���������" << endl;
	cout << endl;
}

void orderMenu()
{
	cout << "�������� ����� ����:" << endl;
	cout << "1 - �������� �����" << endl;
	cout << "2 - �������� ������" << endl;
	cout << "3 - �������� �������" << endl;
	cout << "4 - ��������� ���������� �������" << endl;
	cout << endl;
}

void deleteOrderMenu()
{
	cout << "�������� ����� ����:" << endl;
	cout << "1 - ������� �����" << endl;
	cout << "2 - ������� ������" << endl;
	cout << "3 - ������� �������" << endl;
	cout << "4 - ��������� �������� �������" << endl;
	cout << endl;
}

char getCh()
{
	char ch;
	cin.get(ch);
	cout << endl;
	while (getchar() != '\n') 
		continue;
	return ch;
}