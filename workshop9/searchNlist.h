/*
Student Name:    Jincheng Kuang
Seneca email:    jkuang10@myseneca.ca
Seneca ID:       152867164
Section:         OOP244 - NCC
Workshop:        Workshop 9 - LAB part
Submission Date: March 29, 2021

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"

using namespace std;

namespace sdds
{
	/**
	* parameters requirements:
	* 1. the first parameter is a reference to a Collection templated object to save the objects that have matched value with the fourth parameter
	* 2. the second parameter is an array of templated objects, the same type as the Collection type to be searched with the fourth parameter
	* 3. the third parameter type is int, the array length of the second parameter
	* 4. the fourth parameter is any type that can be used to match the value saved in the member of the second parameter
	*/
	template <typename T1, typename T2>
	bool search(Collection<T1>& collection, const T1* arr, const int len, const T2 key)
	{
		bool found = false;
		for (int i = 0; i < len; i++)
		{
			if (arr[i] == key)
			{
				collection.add(arr[i]);
				found = true;
			}
		}
		return found;
	}

	/**
	* parameters requirements:
	* 1. the first parameter type is const char* to be print as a title
	* 2. the second parameter is an array of templated objects
	* 3. the third parameter type is int, the array length of the second parameter
	*/
	template<typename T>
	void listArrayElements(const char* title, const T* arr, const int len)
	{
		cout << title << endl;
		for (int i = 0; i < len; i++)
		{
			cout << i + 1 << ": " << arr[i] << endl;
		}
	}
}

#endif