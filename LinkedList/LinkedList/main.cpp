#include "DatasetList.h"
void UI(){
	int choice = 0;
	DWORD t1, t2;
	DatasetList List;
	/////
	cout << "Which function you want to use ?" << endl
		<< "1) Insertion" << endl
		<< "2) Deletion" << endl
		<< "3) Searching" << endl
		<< "4) Statistical" << endl
		<< "5) Exit" << endl
		<< "Please input the number (1-5) : ";
	cin >> choice;
	switch (choice) {
		case 1: {	
			string tconst;
			string titleType;
			string primaryTitle;
			int startYear;
			string runtimeMinutes;
			string Genres;
			ifstream file("DataSetTest.txt");

			t1 = GetTickCount();
			////
			t2 = GetTickCount();
			printf("Lasting Time: %lfsec\n", (t2 - t1) / 1000.0);
			break;
		}
		case 2: {
			t1 = GetTickCount();
			List.Deletion();
			t2 = GetTickCount();
			printf("Lasting Time: %lfsec\n", (t2 - t1) / 1000.0);
			break;
		}
		case 3: {
			t1 = GetTickCount(); 
			DatasetList SearchList = List.Searching();
			if (!SearchList.isEmpty())
				SearchList.PrintList();
			else
				cout << "No record has been search !" << endl;
			t2 = GetTickCount();
			printf("Lasting Time: %lfsec\n", (t2 - t1) / 1000.0);
			break;
		}
		case 4: {
			t1 = GetTickCount();
			cout << List.Statistical() << endl;
			t2 = GetTickCount();
			printf("Lasting Time: %lfsec\n", (t2 - t1) / 1000.0);
			break;
		}
		case 5: {
			break;
		}
		default: {
			break;
		}
	}
}

int main()
{
	UI();
	system("pause");
	return 0;
}