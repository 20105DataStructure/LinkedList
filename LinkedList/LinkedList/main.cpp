#include "DatasetList.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream> 
#include <Windows.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>

using namespace std;
int main()
{
	DatasetList List;
	string tconst;
	string titleType;
	string primaryTitle;
	int startYear;
	string runtimeMinutes;
	string Genres;

	ifstream file("DataSetTest.txt");

	//Insertion
	DWORD tt1, tt2;
	tt1 = GetTickCount();
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
	tt2 = GetTickCount();
	printf("Lasting Time: %lfsec\n", (tt2 - tt1) / 1000.0);

	//Deletion:

	cout << "\n";
	DWORD t1, t2;
	t1 = GetTickCount();
	List.Deletion();
	t2 = GetTickCount();
	printf("Lasting Time: %lfsec\n", (t2 - t1) / 1000.0);

	//List.PrintList();

	//Searching

	DWORD t11, t22;
	t11 = GetTickCount();

	DatasetList SearchList = List.Searching();
	if (!SearchList.isEmpty())
		SearchList.PrintList();
	else
		cout << "No record has been search !" << endl;

	t22 = GetTickCount();
	printf("Lasting Time: %lfsec\n", (t22 - t11) / 1000.0);


	//Statistical

	DWORD t111, t222;
	t111 = GetTickCount();
	cout << List.Statistical() << endl;
	t222 = GetTickCount();
	printf("Lasting Time: %lfsec\n", (t222 - t111) / 1000.0);


	system("pause");
	return 0;
}