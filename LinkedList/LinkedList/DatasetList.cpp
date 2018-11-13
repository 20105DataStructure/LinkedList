#include <iostream>
#include "DatasetList.h"

using namespace std;

DatasetList::DatasetList() {
	head = NULL;
}

bool DatasetList::isEmpty() {
	return head == NULL ? true : false;
}

void DatasetList::PrintList() {
	
	for (DatasetNode *currNode = head; currNode; currNode = currNode->next) {
		cout << currNode->tconst << " " << currNode->titleType << " " << currNode->peimaryTitle << " " << currNode->startYear << " " << currNode->runtimeMinutes << " ";
		for (int j = 0; j < 3; j++) {
			cout << currNode->genres[j] << " ";
		}
		cout << "\n";
	}
}

void DatasetList::Insertion(string tconst, string titleType,string peimaryTitle,int startYear,string runtimeMinutes,string *genres) {

	DatasetNode *newNode = new DatasetNode(tconst, titleType, peimaryTitle, startYear, runtimeMinutes, genres);
	
	// If empty list
	if (isEmpty()) {
		head = newNode;
	}
	else {   //If non-empty list
		DatasetNode *currNode = head;
		for (; currNode->next; currNode = currNode->next);  //moving currNode point at the last node
		currNode->next = newNode;
		
		for (int j = 0; j < 3; j++) {
			cout << currNode->next->genres[j] << " ";
		}
	}		
	
}
/*
void DatasetList::Deletion() {

}

DatasetList DatasetList::Searching() {
	
}

int DatasetList::Statistical() {

}*/

