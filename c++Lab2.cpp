#include <iostream>
#include <windows.h>
using namespace std;

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

struct Homeaddress {
	int postcode;
	char country[53];
	char region[30];
	char district[30];
	char town[100];
	char street[30];
	short home;
	short apartment;
};

struct Schoolboy {
	char F[56];
	char I[56];
	char O[56];
	short Sex;
	char nationality[30];
	short height;
	short weight;
	Date birthday;
	long long number;
	Homeaddress address;
	char School[60];
	short klass;
};

Schoolboy* AddStruct(Schoolboy* Obj, const int amount);
void setData(Schoolboy* Obj, const int amount);
void showData(const Schoolboy* Obj, const int amount);

int main()
{
	Schoolboy* OurSchoolboy = 0;
	int schoolAmount = 0;
	int YesOrNot = 0;

	do
	{
		OurSchoolboy = AddStruct(OurSchoolboy, schoolAmount);
		setData(OurSchoolboy, schoolAmount);

		schoolAmount++;

		cout << "Add schoolboy? (1 - yes, 0 - no): ";
		cin >> YesOrNot;
		cin.get();
	} while (YesOrNot != 0);

	showData(OurSchoolboy, schoolAmount);

	delete[] OurSchoolboy;
	return 0;
}

Schoolboy* AddStruct(Schoolboy* Obj, const int amount)
{
	if (amount == 0)
	{
		Obj = new Schoolboy[amount + 1];
	}
	else
	{
		Schoolboy* tempObj = new Schoolboy[amount + 1];

		for (int i = 0; i < amount; i++)
		{
			tempObj[i] = Obj[i];
		}
		delete[] Obj;

		Obj = tempObj;
	}
	return Obj;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setData(Schoolboy* Obj, const int amount)
{
	cout << " Input F: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Obj[amount].F, 56);

	cout << " Input I: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Obj[amount].F, 56);

	cout << " Input O: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Obj[amount].F, 56);

	do
	{
		cout << " Input your gender(1 - Man , 2 - Woman): ";
		cin >> Obj[amount].Sex;
	} while (Obj[amount].Sex > 2 || Obj[amount].Sex > 1);

	cout << " Input nationality: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Obj[amount].nationality, 30);

	cout << " Input height: ";
	cin >> Obj[amount].height;
	if (Obj[amount].height < 0)
		Obj[amount].height = Obj[amount].height * -1;

	cout << " Input weight:";
	cin >> Obj[amount].weight;
	if (Obj[amount].weight < 0)
		Obj[amount].weight = Obj[amount].weight * -1;

	do
	{
		cout << " Input your birthday(day/month/year): ";
		cin >> Obj[amount].birthday.day >> Obj[amount].birthday.month >> Obj[amount].birthday.year;
	} while (!Obj[amount].birthday.isCorrect());

	cout << " Input Number of phone: ";
	cin >> Obj[amount].number;
	if (Obj[amount].number < 0)
		Obj[amount].number = Obj[amount].number * -1;

	cout << " Input home address: " << endl;
	cout << " Postcode: ";
	cin >> Obj[amount].address.postcode;
	if (Obj[amount].address.postcode < 0)
		Obj[amount].address.postcode = Obj[amount].address.postcode * -1;

	cout << " Country: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Obj[amount].address.country, 53);

	cout << " Region: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Obj[amount].address.region, 30);

	cout << " District: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Obj[amount].address.district, 30);

	cout << " Town: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Obj[amount].address.town, 100);

	cout << " Street: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Obj[amount].address.street, 30);

	cout << " Home(number): ";
	cin >> Obj[amount].address.home;
	if (Obj[amount].address.home < 0)
		Obj[amount].address.home = Obj[amount].address.home * -1;

	cout << " Apartment: ";
	cin >> Obj[amount].address.apartment;
	if (Obj[amount].address.apartment < 0)
		Obj[amount].address.apartment = Obj[amount].address.apartment * -1;

	cout << " School: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(Obj[amount].School, 60);

	do
	{
		cout << " Klass: ";
		cin >> Obj[amount].klass;
	} while (Obj[amount].klass > 11 || Obj[amount].klass < 1);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(const Schoolboy* Obj, const int amount)
{	
	for (int i = 0; i < amount; i++)
	{
		cout << " First Name: " << Obj[i].F << " Second Name: " << Obj[i].I << " Last Name: " << Obj[i].O << endl;
		if (Obj[i].Sex == 1)
			cout << " Gender: Man " << endl;
		else if (Obj[i].Sex == 2)
			cout << " Gender: Woman " << endl;
		cout << " Natinality: " << Obj[i].nationality << endl;
		cout << " Height: " << Obj[i].height << endl;
		cout << " Weight " << Obj[i].weight << endl;
		cout << " Birthday: " << Obj[i].birthday.day << "." << Obj[i].birthday.month << "." << Obj[i].birthday.year << endl;
		cout << " Number of phone: " << Obj[i].number << endl;
		cout << " Home address:\n " << " Postcode:" << Obj[i].address.postcode << " Country:" << Obj[i].address.country << " Region:" << Obj[i].address.region << " District:" << Obj[i].address.district << endl << "  Town:" << Obj[i].address.town << " Street:" << Obj[i].address.street << " Home:" << Obj[i].address.home << " Apartment:" << Obj[i].address.apartment << endl;
		cout << " School: " << Obj[i].School << endl;
		cout << " Klass " << Obj[i].klass << endl;
	}
}