/**
 *   @file: numlist.cc
 * @author: Hunter Stout
 *   @date: 1/28/2022
 *  @brief: Number list implementation file.
 */

#include "numlist.h"
#include <fstream>
#include <string>
using namespace std;

// Constructor
NumList::NumList(){
	used = 0;
}

//Helpers
void NumList::insert(int num){
	if(used < CAPACITY){
		data[used] = num;
		used++;
	}
	else{
		cout << "Error. List capacity has been reached.\n" ;
	}
}

void NumList::load_from_file(){
	char fileInput;
	string dataInput;

	//User input.
	cout << "Which file would you like to organize? (1, 2, 3)\n";
	cout << "1. larger.dat\n" << "2. smaller.dat\n" << "3. Other file\n";
	cin >> fileInput;

	//Opens chosen file.
	if (fileInput == '1') {
		ins.open("larger.dat");
		fileName = "larger.dat";
	}
	else if (fileInput == '2') {
		ins.open("smaller.dat");
		fileName = "smaller.dat";
	}
	else if (fileInput == '3') {
		cout << "Please enter a file name (ex: lab2.txt): ";
		cin >> fileName;
		ins.open(fileName);
	}
	else {
		cout << "Please enter either 1, 2, or 3. Have a nice day!\n";
		exit (0);
	}

	//Stream fail check.
    if (ins.fail()) {
        cout << "\nError we could not locate this file. Try again!\n";
        exit (0);
	}
	cout << "\nNow organizing " << fileName << "\n\n";

	//Loads array.
	getline(ins, dataInput);
	while (!ins.eof()) {
		data[used] = stoi(dataInput);
		used++;
		getline(ins, dataInput);
	}
	ins.close();

	//Changes filename for potential output.
	int placeholder = fileName.find(".");
	fileName.insert(placeholder, "sorted");
}


void NumList::save_to_file(){

	outs.open(fileName);
	//Stream fail check.
    if (outs.fail()) {
        cout << "\nError we could not locate this file. Try again!\n";
        exit (0);
	}

	//Output.
	for (int j = 0; j < used; j++) {
		outs << data[j] << endl;
	}
	cout << "\nData saved to " << fileName << ".\n";
	outs.close();
}

void NumList::see_all()const{
	if(used == 0){
	    cout<<"Empty list.\n";
	}
	else{
		cout << endl;
	    for(size_t i = 0; i<used; ++i)
		cout << data[i] << endl;
	}
}

int NumList::get_item(size_t index)const{
	if(index < used){
		return data[index];
	}
	else{
		return -1;
	}
}
	
void NumList::b_sort(){
    bool done = false;
    int j;
    int tmp;
    while(!done){
		done = true;
		for(j = 0; j < used - 1; ++j){
			if(data[j] < data[j + 1]){
			tmp = data[j];
			data[j] = data[j + 1];
			data[j + 1] = tmp;
			done = false;
			}
		}
    }
}