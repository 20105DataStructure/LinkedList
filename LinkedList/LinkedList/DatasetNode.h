#include <string>
using namespace std;
class DatasetNode {
public:
	string tconst;
	string titleType;
	string primaryTitle;
	int startYear;
	string runtimeMinutes;
	string* genres;
	DatasetNode* next;

public:
	DatasetNode(string code, string Type, string Title, int YYYY, string mins, string* genres) {
		this->tconst = code;
		this->titleType = Type;
		this->primaryTitle = Title;
		this->startYear = YYYY;
		this->runtimeMinutes = mins;
		this->genres = genres;
		this->next = NULL;
	}
};