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
		cout << currNode->tconst << " " << currNode->titleType << " " << currNode->primaryTitle << " " << currNode->startYear << " " << currNode->runtimeMinutes << " ";
		for (int j = 0; j < 3; j++) {
			cout << currNode->genres[j] << " ";
		}
		cout << "\n";
	}
}

void DatasetList::Insertion(string tconst, string titleType,string peimaryTitle,int startYear,string runtimeMinutes,string* genres) {

	DatasetNode *newNode = new DatasetNode(tconst, titleType, peimaryTitle, startYear, runtimeMinutes, genres);
	
	// If empty list
	if (isEmpty()) {
		head = newNode;
	}
	else {   //If non-empty list
		DatasetNode *currNode = head;
		for (; currNode->next; currNode = currNode->next);  //moving currNode point at the last node
		currNode->next = newNode;
	}		
}

void DatasetList::Deletion() {

	int dataType;
	cout << "Which type of attribute you want to search?" << endl
		<< "1) Code of the title" << endl
		<< "2) Type of the title" << endl
		<< "3) The Title" << endl
		<< "4) Release year of the title" << endl
		<< "5) Runtime of the title (in minutes)" << endl
		<< "6) Genres of the title" << endl;
	cin >> dataType;
	cout << "\n";
	bool flag = false;

	switch(dataType){
		case 1:{
			if (!isEmpty()) {
				string temp;
				cout << "What you want to delete ? " << endl;
				cin >> temp;

				DatasetNode *currNode = head, *prevNode = NULL;
				for (; currNode && currNode->tconst != temp; currNode = currNode->next)
					prevNode = currNode;

				//If data found
				if (currNode) {
					if (prevNode == NULL)   //If the matched node is the first node
						head = currNode->next;
					else                    //If the matched node is not the first node
						prevNode->next = currNode->next;
					delete currNode;
					flag = true;
				}
			}
			else {
				cout << "The data is empty!" << endl;
			}
			break;
		}
		case 2: {
			if (!isEmpty()) {
				string temp;
				cout << "What you want to delete ? " << endl;
				cin >> temp;
				
				for (DatasetNode *currNode = head, *prevNode = NULL; currNode;) {
					if (currNode->titleType == temp) {
						if (currNode) {
							if (prevNode == NULL) 
								head = currNode->next;
							else                    
								prevNode->next = currNode->next;
							DatasetNode* rubbish = currNode;
							currNode = currNode->next;
							delete rubbish;
							flag = true;
						}
					}
					else {
						prevNode = currNode;
						currNode = currNode->next;
					}
				}
			}
			else {
				cout << "The data is empty!" << endl;
			}
			break;
		}
		case 3: {
			//primaryTitle

			break;
		}
		case 4: {
			if (!isEmpty()) {
				int temp;
				cout << "What you want to delete ? " << endl;
				cin >> temp;

				for (DatasetNode *currNode = head, *prevNode = NULL; currNode;) {
					if (currNode->startYear == temp) {
						if (currNode) {
							if (prevNode == NULL)
								head = currNode->next;
							else
								prevNode->next = currNode->next;
							DatasetNode* rubbish = currNode;
							currNode = currNode->next;
							delete rubbish;
							flag = true;
						}
					}
					else {
						prevNode = currNode;
						currNode = currNode->next;
					}
				}
			}
			else {
				cout << "The data is empty!" << endl;
			}
			break;
		}
		case 5: {
			if (!isEmpty()) {
				string temp;
				cout << "What you want to delete ? " << endl;
				cin >> temp;

				for (DatasetNode *currNode = head, *prevNode = NULL; currNode;) {
					if (currNode->runtimeMinutes == temp) {
						if (currNode) {
							if (prevNode == NULL)
								head = currNode->next;
							else
								prevNode->next = currNode->next;
							DatasetNode* rubbish = currNode;
							currNode = currNode->next;
							delete rubbish;
							flag = true;
						}
					}
					else {
						prevNode = currNode;
						currNode = currNode->next;
					}
				}
			}
			else {
				cout << "The data is empty!" << endl;
			}
			break;
		}
		case 6:{
			//array
			break;
		}
	}
	if (flag)
		cout << "Data deleted!" << endl;
	else
		cout << "Data not found!" << endl;
	

}
/*
DatasetList DatasetList::Searching() {
	
}

int DatasetList::Statistical() {

}*/

