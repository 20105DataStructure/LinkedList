#include "DatasetList.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream> 
#include <Windows.h>
#include <time.h>

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

	while (file.good()) {
		string *genres = new string[3];
		for (int i = 0; i < 3; i++)
			genres[i] = " ";
		getline(file, tconst, '\t');
		getline(file, titleType, '\t');
		getline(file, primaryTitle,'\t');
		file >> startYear >> runtimeMinutes;
		getline(file, Genres);

		int pos1 = 1, pos2, i = 0;
		size_t n = count(Genres.begin(), Genres.end(), ',');
		if (n > 0) {
			pos1 = Genres.find("\"") + 1;
			for (; i < (signed)n;i++) {
				pos2 = Genres.find(",", pos1);
				genres[i] = Genres.substr(pos1, pos2 - pos1);
				pos1 = pos2 + 1;
			}
		}
		pos2 = Genres.find("\"", pos1);
		genres[i] = Genres.substr(pos1, pos2 - pos1);
		List.Insertion(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres);

		if(file.eof())
			file.close();


	}

	List.PrintList();

	
	//Test Deletion()
	cout << "\n";
	List.Deletion();
	List.PrintList();

	/*DatasetList SearchList = List.Searching();
	if (!SearchList.isEmpty())
		SearchList.PrintList();
	else
		cout << "No record has been search !" << endl;*/
	system("pause");
	return 0;
}