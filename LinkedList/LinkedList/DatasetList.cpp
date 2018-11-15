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

void DatasetList::Insertion(string tconst, string titleType,string primaryTitle,int startYear,string runtimeMinutes,string* genres) {

	DatasetNode *newNode = new DatasetNode(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres);
	
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
	cout << "Which type of attribute you want to delete?" << endl
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
			if (!isEmpty()) {
				string temp;
				cout << "What you want to delete ? " << endl;
				if (cin.peek() == '\n' || cin.peek() == '\r') {
					cin.get();
				}
				getline(cin, temp);

				for (DatasetNode *currNode = head, *prevNode = NULL; currNode;) {
					if (currNode->primaryTitle == temp) {
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
		case 6: {
			string* temp = new string[3];
			cout << "Please enter the GENRES(At most three) you want to search: " << endl
				<< "The first Genre (Enter \"null\" if don't have): ";
			cin >> temp[0];
			if (temp[0] != "null") {
				cout << "The second Genre (Enter \"null\" if don't have any more): ";
				cin >> temp[1];
				if (temp[1] != "null") {
					cout << "The thrid Genre (Enter \"null\" if don't have any more): ";
					cin >> temp[2];
				}
			}
			else {
				temp[0] = "\\N"; 
			}
			bool* arrayflag = new bool[3];
			for (DatasetNode *currNode = head, *prevNode = NULL; currNode;) {
				for (int i = 0; i < 3; i++) {
					arrayflag[i] = true;
				}
				if (temp[0] == "\\N") {
					/////////////////////////////
						if (currNode->genres[0] == temp[0]) {
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
					////////////////////////////
				}
				else {
					for (int i = 0; i < 3 && (temp[i] != "null"); i++) {
						bool tempflag = false;
						for (int j = 0; j < 3 && (currNode->genres[j] != " "); j++) {
							if (currNode->genres[j] == temp[i])
								tempflag = true;
						}
						if (!tempflag) {
							arrayflag[i] = tempflag;
						}
					}
					if (arrayflag[0] && arrayflag[1] && arrayflag[2]){
						///////////////////////////		
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
						///////////////////////////
					}
					else {
							prevNode = currNode;
							currNode = currNode->next;
						}
				}
			}
			flag = true;
			break;
		}
	}
	if (flag)
		cout << "Data deleted!" << endl;
	else
		cout << "Data not found!" << endl;
	

}

DatasetList DatasetList::Searching() {
	DatasetList tempList;
	cout << "Which type of attribute you want to search?" << endl
		<< "1) Code of the title" << endl
		<< "2) Type of the title" << endl
		<< "3) The Title" << endl
		<< "4) Release year of the title" << endl
		<< "5) Runtime of the title (in minutes)" << endl
		<< "6) Genres of the title" << endl;
	int choice; bool flag = false;
	while (!flag) {
		cin >> choice;
		switch (choice) {
		case 1:
		{
			cout << "Please enter the CODE you want to search: ";
			string code;
			cin >> code;
			for (DatasetNode *currNode = head; currNode; currNode = currNode->next) {
				if (currNode->tconst == code) {
					tempList.Insertion(code, currNode->titleType, currNode->primaryTitle, currNode->startYear, currNode->runtimeMinutes, currNode->genres);
					break;
				}
			}
			flag = !flag;
			break;
		}
		case 2:
		{
			cout << "Please enter the TYPE you want to search: ";
			string type;
			cin >> type;
			for (DatasetNode *currNode = head; currNode; currNode = currNode->next) {
				if (currNode->titleType == type) 
					tempList.Insertion(currNode->tconst, type, currNode->primaryTitle, currNode->startYear, currNode->runtimeMinutes, currNode->genres);
			}
			flag = !flag;
			break;
		}
		case 3:
		{
			string title;
			cout << "Please enter the TITLE you want to search: ";
			if (cin.peek() == '\n' || cin.peek() == '\r') {
				cin.get();
			}
			getline(cin, title);
			for (DatasetNode *currNode = head; currNode; currNode = currNode->next) {
				if (currNode->primaryTitle == title) 
					tempList.Insertion(currNode->tconst, currNode->titleType , currNode->primaryTitle, currNode->startYear, currNode->runtimeMinutes, currNode->genres);
			}
			flag = !flag;
			break;
		}
		case 4:
		{
			cout << "Please enter the YEAR you want to search: ";
			int year;
			cin >> year;
			for (DatasetNode *currNode = head; currNode; currNode = currNode->next) {
				if (currNode->startYear == year) 
					tempList.Insertion(currNode->tconst, currNode->titleType, currNode->primaryTitle, year, currNode->runtimeMinutes, currNode->genres);
			}
			flag = !flag;
			break;
		}
		case 5:
		{
			cout << "Please enter the RUNTIME(in Minutes) you want to search (Enter \"null\" if you don't know): ";
			string runtime;
			cin >> runtime;
			if (runtime == "null")
				runtime = "\\N";
			for (DatasetNode *currNode = head; currNode; currNode = currNode->next) {
				if (currNode->runtimeMinutes == runtime)
					tempList.Insertion(currNode->tconst, currNode->titleType, currNode->primaryTitle, currNode->startYear, runtime, currNode->genres);
			}
			flag = !flag;
			break;
		}
		case 6:
		{
			string* ngenres = new string[3];
			cout << "Please enter the GENRES(At most three) you want to search: " << endl
				<< "The first Genre (Enter \"null\" if don't have): ";
			cin >> ngenres[0];
			if (ngenres[0] != "null") {
				cout << "The second Genre (Enter \"null\" if don't have any more): ";
				cin >> ngenres[1];
				if (ngenres[1] != "null") {
					cout << "The thrid Genre (Enter \"null\" if don't have any more): ";
					cin >> ngenres[2];
				}
			}
			else 
				ngenres[0] = "\\N";
			bool* arrayflag = new bool[3];
			for (DatasetNode *currNode = head; currNode; currNode = currNode->next) {
				for (int i = 0; i < 3; i++)
					arrayflag[i] = true;
				if (ngenres[0] == "\\N") {
					if (currNode->genres[0] == "\\N")
						tempList.Insertion(currNode->tconst, currNode->titleType, currNode->primaryTitle, currNode->startYear, currNode->runtimeMinutes, currNode->genres);
				}
				else {
					for (int i = 0; i < 3 && (ngenres[i] != "null"); i++) {
						bool tempflag = false;
						for (int j = 0; j < 3 && (currNode->genres[j] != " "); j++) {
							if (currNode->genres[j] == ngenres[i]) 
								tempflag = true;
						}
						if (!tempflag)
							arrayflag[i] = tempflag;
					}
					if(arrayflag[0] && arrayflag[1] && arrayflag[2])
						tempList.Insertion(currNode->tconst, currNode->titleType, currNode->primaryTitle, currNode->startYear, currNode->runtimeMinutes, currNode->genres);
				}
			}
			flag = !flag;
			break;
		}
		default:
			cout << "We don't have this choice ! Please input again !" << endl;
		}
	}
	return tempList;
}

/*int DatasetList::Statistical() {

}*/

