/**
 *   @file: numlist.h
 * @author: Hunter Stout
 *   @date: 1/28/2022
 *  @brief: Number list header file.
 */
#ifndef NUMLIST_H
#define NUMLIST_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

class NumList{
    public:

	//Public objects:
	static const size_t CAPACITY = 100;
	
	//Default constructor:

    /**
    * NumList - Default constructor.
    */
	NumList();

	//Getters:

    /**
    * size - Getter for used object.
    * @return - Used.
    */
	size_t size()const {return used;}

    /**
    * get_fn - Getter for fileName.
    * @return - fileName.
    */
	std::string get_fn()const {return fileName;}

	//Helpers:

	/**
    * insert - Allows user to insert numbers into the data.
    * @num - User selected number.
    */
	void insert(int num);

	/**
    * load_from_file - Loads data from the file into the array.
    */
	void load_from_file();

    /**
    * save_to_file - Outputs data from the sorted array.
    */
	void save_to_file();

    /**
    * b_sort - Sorts raw data inside the array.
    */
	void b_sort();

    /**
    * get_item - Grabs specific number from array.
    * @h - Array place value.
    * @return - Selected number.
    */
	int get_item(size_t index)const;

    /**
    * see_all - Outputs array for cout.
    */
	void see_all()const;

    private:

	std::ifstream ins;
	std::ofstream outs;
	std::string fileName;
	int data[CAPACITY];
	size_t used;
};

#endif