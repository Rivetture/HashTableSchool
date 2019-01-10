#include <iostream>
#include <cstdlib>
#include <string>
#include "hash.h"
using namespace std;

/*
 * Hash Table 
 * Hash Table
 * Super Cool
 *
 * Hash Table
 * Hash Table
 * Let's have Fun!
 */

//For this assignment, you will implement a hash table.
//You must implement four different commands:
// INSERT - adds a number to the hash table
// SEARCH - tests to see if a number is in the hash table
// REMOVE - removes a number from the hash table
// CHANGE - if a number is in the hash table, removes it and replaces it with another number

/* Sample input 
INSERT 7
SEARCH 7
INSERT 9
INSERT 9
REMOVE 9
SEARCH 9
CHANGE 9 1
CHANGE 7 9
SEARCH 9
*/

/* Sample output
7 IN TABLE
9 NOT IN TABLE
9 IN TABLE
*/
void uppercaseify(string& mystr);

int main() {
	Hash<int,10000> table;
	string operation;
	int data;
	int changeData;
	while(cin){
		cin >> operation;
		uppercaseify(operation);
		if(!cin || cin.eof() || operation == "QUIT"){
		return 0;
		}
		if(operation == "PRINT"){
			table.print();
		}
		if(operation == "INSERT"){
			cin >> data;
			table.insert(data);
		}
		if(operation == "SEARCH"){
			cin >> data;
			table.search(data);
		}
		if(operation == "REMOVE"){
			cin >> data;
			table.remove(data);
		}
		if(operation == "CHANGE"){
			cin >> data;
			cin>> changeData;
			table.change(data,changeData);
		}
	}
	return 0;
}

void uppercaseify(string& mystr){
	for(auto& c: mystr)
		c = toupper(c);
}
//	table.insert(10);
//	table.search(10);
//	table.remove(10);
//	table.change(10);


