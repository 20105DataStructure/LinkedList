#include "DatasetList.h"
void UI(){
	string choice = "0";
	DWORD t1, t2;
	DatasetList List;
	/////
	while (true) {
		cout << "Which function you want to use ?" << endl
			 << "1) Insertion"					   << endl
			 << "2) Deletion"					   << endl
			 << "3) Searching"					   << endl
			 << "4) Statistical"				   << endl
			 << "5) Exit"						   << endl
			 << "Please input the number (1-5) : ";
		cin >> choice;
		system("cls");
		switch (choice[0]) {
		case '1': {
				string filename;
				int startYear;
				string tconst, titleType, primaryTitle, runtimeMinutes, Genres;

				cout << "Please enter the name of the text file you want to insert (e.g. \"test.txt\" ): ";
				

				ifstream file;
				if (cin.peek() == '\n' || cin.peek() == '\r') {
					cin.get();
				}
				getline(cin, filename);
				file.open(filename);

				t1 = GetTickCount();

				while (file.good()) {
					string *genres = new string[3];
					for (int i = 0; i < 3; i++)
						genres[i] = " ";
					getline(file, tconst, '\t');
					getline(file, titleType, '\t');
					getline(file, primaryTitle, '\t');
					file >> startYear >> runtimeMinutes;
					getline(file, Genres);

					int pos1 = 1, pos2, i = 0;
					size_t n = count(Genres.begin(), Genres.end(), ',');
					if (n > 0) {
						pos1 = Genres.find("\"") + 1;
						for (; i < (signed)n; i++) {
							pos2 = Genres.find(",", pos1);
							genres[i] = Genres.substr(pos1, pos2 - pos1);
							pos1 = pos2 + 1;
						}
					}
					pos2 = Genres.find("\"", pos1);
					genres[i] = Genres.substr(pos1, pos2 - pos1);
					List.Insertion(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres);

					if (file.eof())
						file.close();
				}

				t2 = GetTickCount();

				printf("Lasting Time: %lfsec\n", (t2 - t1) / 1000.0);
				break;
			}
			case '2': {
				t1 = GetTickCount();
				List.Deletion();
				t2 = GetTickCount();
				printf("Lasting Time: %lfsec\n", (t2 - t1) / 1000.0);
				break;
			}
			case '3': {
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
			case '4': {
				t1 = GetTickCount();
				cout << List.Statistical() << endl;
				t2 = GetTickCount();
				printf("Lasting Time: %lfsec\n", (t2 - t1) / 1000.0);
				break;
			}
			case '5': {
				exit(0);
				break;
			}
			default: {
				cout << "Sorry ! We do not have this choice !"
					<< "Please Input again ! \n\n";
				break;
			}
		}
	}
}

int main()
{
	UI();
	system("pause");
	return 0;
}