#include "DatasetNode.h"

class DatasetList {
public:
	DatasetNode* head;
public:
	DatasetList();
	bool isEmpty();
	void PrintList();
	void Insertion(string, string, string, int, string, string*);
	void Deletion();
	/*DatasetList Searching();
	int Statistical();*/
};
