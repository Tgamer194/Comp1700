#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "stringmanip.hpp"
using namespace std;

struct Contact {
	string lastName, firstName, phone, email;
}; 

void storeContacts(ifstream& fin, vector<Contact>& contacts, int& count) {
	string last, first, phone, email;
	string line;
	count = 0;
	while (getline(fin, line)) {
		istringstream sin(line);
		Contact contact;
		getline(sin, last, ',');
		getline(sin, first, ',');
		getline(sin, phone, ',');
		getline(sin, email);
		contact.lastName = last;
		contact.firstName = first;
		contact.phone = phone;
		contact.email = email;
		contacts.push_back(contact);
		count++;
	}
}

bool checkExistingContacts(const string& first, const string& last, const vector<Contact>& contacts) {
	string lowerFirst = lowercase(first);
	string lowerLast = lowercase(last);
	for (int i = 0; i < contacts.size(); ++i) {
		string lowerContactFirst = lowercase(contacts[i].firstName);
		string lowerContactLast = lowercase(contacts[i].lastName);
		if (lowerContactFirst == lowerFirst && lowerContactLast == lowerLast) {
			return true;
		}
	}
	return false;
}

bool findContact(Contact& contact, string f, string l) {
	 return contact.firstName == f;
	 return contact.lastName == l;
}

void addContact(vector<Contact>& contacts) {
	Contact contact;
	string input;
	string clean;
	bool valid = true;
	cout << "Last Name:\n";
	getline(cin, input);
	clean = trim(input);
	if (clean == "") {
		cout << "Invalid contact data\n";
		valid = false;
	}
	string lastName = clean;
	if (valid) {
		contact.lastName = clean;
		cout << "First Name:\n";
		getline(cin, input);
		clean = trim(input);
		if (clean == "") {
			cout << "Invalid contact data\n";
			valid = false;
		}
		string firstName = clean;
		if (valid) {
			bool exists = checkExistingContacts(firstName, lastName, contacts);
			if (exists) {
				cout << "\nAdd contact failed: contact already exists\n\n";
				return;
			}
			contact.firstName = clean;
			cout << "Phone:\n";
			getline(cin, input);
			clean = trim(input);
			contact.phone = clean;
			cout << "Email:\n";
			getline(cin, input);
			clean = trim(input);
			contact.email = clean;
			contacts.push_back(contact);
			cout << "\nContact added\n\n";
		}
	}
}

void updateContact(vector<Contact>& contacts, const vector<string>& words) {
	string input;
	string clean;
	cout << "Last Name:\n";
	getline(cin, input);
	clean = trim(input);
	if (clean == "") {
		cout << "Invalid contact data\n";
		return;
	}
	string last = clean;
	cout << "First Name:\n";
	getline(cin, input);
	clean = trim(input);
	if (clean.empty()) {
		cout << "Invalid contact data\n";
		return;
	}
	string first = clean;
	string lowerFirst = lowercase(first);
	string lowerLast = lowercase(last); 
	auto i = find_if(contacts.begin(), contacts.end(), [&](const Contact& c) {
		return lowercase(c.firstName) == lowerFirst &&
			lowercase(c.lastName) == lowerLast;
		});
	if (i == contacts.end()) {																//not in test cases
		cout << "\nUpdate contact failed: contact does not exist\n\n";
		return;
	}
	cout << "Phone:\n";
	getline(cin, input);
	clean = trim(input);
	i->phone = clean;
	cout << "Email:\n";
	getline(cin, input);
	clean = trim(input);
	i->email = clean;
	cout << "\nContact updated\n\n";
}

void showContact(const vector<Contact>& contacts, string first, string last) {
	string firstOG = first;
	string lastOG = last;
	first  = trim(first);
	last = trim(last);
	string lowerFirst = lowercase(first);
	string lowerLast = lowercase(last);
	auto i = find_if(contacts.begin(), contacts.end(),[&](const Contact& c) {
		return lowercase(c.firstName) == lowerFirst &&
			lowercase(c.lastName) == lowerLast;
		});
	if (i == contacts.end()) {
		cout << firstOG << " " << lastOG << " not found\n\n";
		return;
	}
	cout << "Last Name:  ";
	cout << i->lastName << "\n";
	cout << "First Name: ";
	cout << i->firstName << "\n";
	cout  << "Phone:      ";
	cout << i->phone << "\n";
	cout << "Email:      ";
	cout << i->email << "\n\n";
}

void listContacts(const vector<Contact>& contacts) {
	if (contacts.empty()) {
		cout << "No contacts found\n\n";
		return;
	}
	for (auto i : contacts) {
		cout << i.firstName << " " << i.lastName << "\n";
	}
	cout << "\n";
	return;
}

void sortContacts(vector<Contact>& contacts, string by) {
	by = lowercase(by);
	stable_sort(contacts.begin(), contacts.end(), [&](const Contact& a, const Contact& b) {
		if (by == "last") {
			return lowercase(a.lastName) < lowercase(b.lastName);
		}
		if (by == "first") {
			return lowercase(a.firstName) < lowercase(b.firstName);
		}
		return false;
	});
	cout << "Contacts sorted\n\n";
}

void findContact(const vector<Contact>& contacts, string find) {
	find = trim(find);
	string pattern = lowercase(find);
	bool found = false;
	for (int i = 0; i < contacts.size(); ++i) {
		string lowerFirst = lowercase(contacts[i].firstName);
		string lowerLast = lowercase(contacts[i].lastName);
		string phone = contacts[i].phone;
		string lowerEmail = lowercase(contacts[i].email);
		if (lowerFirst.find(pattern) != string::npos ||
			lowerLast.find(pattern) != string::npos ||
			phone.find(pattern) != string::npos ||
			lowerEmail.find(pattern) != string::npos) 
		{
			found = true;
			cout << contacts[i].firstName << " " << contacts[i].lastName << "\n";
		}
	}
	cout << "\n";
	if (!found) {
		cout << "No contacts found\n\n";
	}
}

void saveFile(const vector<Contact>& contacts) {
	ofstream fout("contacts.csv");
	fout << "Last Name,First Name,Phone,Email\n";
	for (int i = 0; i < contacts.size(); ++i) {
		fout << contacts[i].lastName << "," <<
			contacts[i].firstName << "," <<
			contacts[i].phone << "," <<
			contacts[i].email << "\n";
	}
	cout << "Saved contacts.csv\n\n";
}

bool quit = false;

void checkCommand(vector<Contact>& contacts, const vector<string>& words) {
	string commandUpper = uppercase(words[0]);

	if (words.size() == 1 && commandUpper == "ADD") {
		addContact(contacts);
	}
	else if (words.size() == 3 && commandUpper == "SHOW") {
		showContact(contacts, words[1], words[2]);
	}
	else if (words.size() == 1 && commandUpper == "UPDATE") {
		updateContact(contacts, words);
	}
	else if (words.size() == 1 && commandUpper == "LIST") {
		listContacts(contacts);
	}
	else if (words.size() == 2 && commandUpper == "SORT") {
		sortContacts(contacts, words[1]);
	}
	else if (words.size() == 2 && commandUpper == "FIND") {
		findContact(contacts, words[1]);
	}
	else if (words.size() == 1 && commandUpper == "SAVE") {
		saveFile(contacts);
	}
	else if (words.size() == 1 && commandUpper == "QUIT") {
		quit = true;
		return;
	}
	else {
		cout << "Command not recognized\n\n";
	}
}

void readInputs(vector<Contact>& contacts) {
	string line;
	string word;
	while (getline(cin, line)) {
		vector<string> words;
		istringstream sin(line);
		while (sin >> quoted(word)) {
			words.push_back(word);
		}
		if (words.size() != 0) {
			checkCommand(contacts, words);
		}
		if (quit) {
			return;
		}
	}

}

int main() {
	int count;
	bool newList = false;
	vector<Contact> contacts;
	string header;
	ifstream fin("contacts.csv");

	if (!fin) {
		cout << "Could not open contacts.csv\nStarting new contacts list\n\n";
		newList = true;
	}
	else {
		getline(fin, header);

		if (header != "Last Name,First Name,Phone,Email") {
			cout << "File contacts.csv has invalid format\n";
			return -1;
		}

		if (!newList) {
			storeContacts(fin, contacts, count);
			cout << "Read " << count << " contacts from contacts.csv\n\n";
		}
	}
	readInputs(contacts);
	return 0;
}