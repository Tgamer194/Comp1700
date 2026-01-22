#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <cctype>

using namespace std;

string toUpperCopy(const string& s) {
	string t = s;
	for (int i = 0; i < t.size(); ++i) {
		t[i] = toupper(t[i]);
	}
	return t;
}

string newSearch() {
	string search;
	getline(cin, search);
	return search;
}

void headerSkip(ifstream& fin) {
	string header;
	while (getline(fin, header)) {
		if (!header.empty() && header[0] == '-') {
			break;
		}
	}
}

string whatBook(const string& line) {
	string book;
	if (line.size() >= 6) {
		book = line.substr(6);
	}
	else {
		book = "";
	}
	return book;
}

int whatChapter(const string line) {
	size_t comma = line.rfind(',');
	if (comma != string::npos) {
		int chapter = 0;
		istringstream sin(line.substr(comma + 1));
		sin >> chapter;
		return chapter;
	}
	return 0;
}

string concatenate(string& line, ifstream& fin) {
	string secondLine;
	string verseText;
	if (line.size() >= 8) {
		verseText = line.substr(8);
	}

	while (fin && fin.peek() == ' ') {
		verseText += ' ';
		getline(fin, secondLine);
		if (secondLine.size() >= 8) {
			verseText += secondLine.substr(8);
		}
		else {
			verseText += secondLine;
		}
	} 
	return verseText;
}

bool findSearch(const string verseText, const string search) {
	if (search.empty()) return false;
	string t = verseText;
	for (int i = 0; i < t.size(); i++) {
		t[i] = tolower(t[i]);
	}
	string n = search;
	for (int i = 0; i < n.size(); i++) {
		n[i] = tolower(n[i]);
	}
	size_t from = 0;
	while (true) {
		size_t pos = t.find(n, from);
		if (pos == string::npos) return false;
		size_t end = pos + n.size();
		bool leftOk = (pos == 0) || !isalpha(t[pos - 1]);
		bool rightOk = (end >= t.size()) || !isalpha(t[end]);
		if (leftOk && rightOk) {
			return true;
		}
		from = pos + 1;
	}
	
}

void printFound(ofstream& fout, const string book, const int chapter, const int verse) {
	fout << "- " << book << " " << chapter << ":" << verse << "\n";
}

void scanLines(
	ifstream& fin,
	ofstream& fout,
	string& book,
	string& verseText,
	int& chapter,
	int& verse,
	const string search,
	int& added){
	string line;
	bool found = false;
	while (getline(fin, line)) {
		if (line.empty()) continue;
		if (line.rfind("Book: ", 0) == 0) {
			book = whatBook(line);
		}
		if (line.rfind("Chapter: ", 0) == 0) {
			chapter = whatChapter(line);
		}
		if (isdigit(line[0])) {
			verse = 0;
			if (line.size() >= 7) {
				istringstream vin(line.substr(4, 3));
				vin >> verse;
			}
			verseText = concatenate(line, fin);
			bool found = findSearch(verseText, search);
			if (found) {
			printFound(fout, book, chapter, verse);
			added += 1;
			}
			continue;
		}
	}
}

int main() {
	string book;
	string search;
	string verseText;
	int chapter;
	int verse;
	int added;
	ifstream fin("bible.txt");
	if (!fin) {
		cout << "Could not open \"bible.txt\"\n";
		return 0;
	}
	search = newSearch();
	ofstream fout("concordance.txt", ios::app);
	if (!fout) {
		cout << "Could not open \"concordance.txt\"\n";
		return 0;
	}
	string searchUpper = toUpperCopy(search);
	fout << "\"" << searchUpper << "\"\n";
	cout << "Searching...\n";

	headerSkip(fin);
	added = 0;
	scanLines(fin, fout, book, verseText, chapter, verse, search, added);

	if (added == 0) {
		fout << "- Not found\n";
	}
	fout << "\n";
	cout << "Added " << added << " verses\n";


}