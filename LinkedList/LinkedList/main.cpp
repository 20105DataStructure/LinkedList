#include "DatasetNode.h"
#include "DatasetList.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

int main()
{	
	DatasetList List;
	string tconst;
	string titleType;
	string peimaryTitle;
	int startYear;
	string runtimeMinutes;
	string Genres;
	string *genres = new string [3];

	ifstream file("DataSetTest.txt");
	while (file.good()) {
		getline(file, tconst, '\t');
		getline(file, titleType, '\t');
		getline(file, peimaryTitle,'\t');
		file >> startYear >> runtimeMinutes;
		getline(file, Genres);

		int pos1 = 1, pos2, i = 0;
		size_t n = count(Genres.begin(), Genres.end(), ',');
		if (n > 0) {
			pos1 = Genres.find("\"") + 1;
			for (; i < n;i++) {
				pos2 = Genres.find(",", pos1);
				genres[i] = Genres.substr(pos1, pos2 - pos1);
				pos1 = pos2 + 1;
			}
		}
		pos2 = Genres.find("\"", pos1);
		genres[i] = Genres.substr(pos1, pos2 - pos1);
		for (int i = 0; i < 3; i++) 
			genres[i] = "";

		if(file.eof())
			file.close();

		List.Insertion(tconst, titleType, peimaryTitle, startYear, runtimeMinutes, genres);
	}

	system("pause");
	return 0;
}