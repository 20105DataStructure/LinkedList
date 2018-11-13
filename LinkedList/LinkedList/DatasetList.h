#include "DatasetNode.h"

class DatasetList {
public:
	DatasetNode* head;
public:
	DatasetList();
	bool isEmpty();
	void PrintList();
	void Insertion(string tconst, string titleType, string peimaryTitle, int startYear, string runtimeMinutes, string *genres);
	void Deletion();
	DatasetList Searching();
	int Statistical();
};
