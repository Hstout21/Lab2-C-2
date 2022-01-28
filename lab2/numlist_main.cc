/**
 *   @file: numlist_main.cc
 * @author: Hunter Stout
 *   @date: 1/28/2022
 *  @brief: Number list main file.
 */

#include "numlist.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {

    NumList n;
    char y_or_n;
    int number;

    //Loads array.
    n.load_from_file();

    //Add data.
    cout << "Would you like to add a number to the data? (y/n): ";
    cin >> y_or_n;
    if (y_or_n == 'Y' || y_or_n == 'y') {
        cout << "\nPlease type the number you would like to add: ";
        cin >> number;
        n.insert(number);
        cout << "\nSuccessfully added " << number << ".\n";

        //Add another number
        while (y_or_n == 'Y' || y_or_n == 'y') {
            cout << "\nWould you like to add another number? (y/n): ";
            cin >> y_or_n;
            if (y_or_n == 'Y' || y_or_n == 'y') {
                cout << "\nPlease type the number you would like to add: ";
                cin >> number;
                n.insert(number);
                cout << "\nSuccessfully added " << number << ".\n";
            }
        }
    }

    //Sorts data.
    n.b_sort();

    //Output (cout).
    n.see_all();

    //Output (ofstream).
    cout << "\nWould you like to output results to " << n.get_fn() << " (y/n): ";
    cin >> y_or_n;
    if (y_or_n == 'Y' || y_or_n == 'y') {
        n.save_to_file();
    }

    return 0;
}