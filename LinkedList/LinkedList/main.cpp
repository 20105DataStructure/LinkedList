//#include "DatasetNode.h"
#include <string>
#include <iostream>
#include <fstream> 

using namespace std;

int main()
{
	//ifs >> tconst >> titleType >> peimaryTitle >> startYear >> runtimeMinutes >> genres
	string tconst;
	string titleType;
	string peimaryTitle;
	int startYear;
	int runtimeMinutes;
	string genres;

	ifstream file("DataSetTest.txt");
	while (file.good()) {
		getline(file, tconst, '\t');
		getline(file, titleType, '\t');
		getline(file, peimaryTitle,'\t');
		file >> startYear >> runtimeMinutes;
		getline(file, genres, '\t');

		cout << tconst << '\t' << titleType << '\t' << peimaryTitle << '\t' << startYear << '\t';
		if (runtimeMinutes == 0)
			cout << "\\N";
		else
			cout << runtimeMinutes;
		cout << '\t' << genres << endl;
		if(file.eof())
			file.close();
	}
	system("pause");
	return 0;
}