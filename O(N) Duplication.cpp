#include <iostream>
#include <algorithm>

/*
O(N) Removal of Duplicated Characters and replacement with $, along with sending new characters to back
ex. AAABBBCCCDDD -> A$$B$$C$$D$$ -> ABCD$$$$$$$$ while only iterating through once
Created by Presto-Creator, UW-Stout
12/10/2021
*/

using namespace std;

void printList(char[], const int);
void removeDuplicatedChars(char[], const int);

int main()
{

	const int NUMLIST = 1000;
	char myCharList[NUMLIST];

	srand(time(NULL));

	//char test[16] = { 'A','A','A','B','B','C','D','D','D','E','E','E','F','F','F','\n' };
	
	for (int i = 0; i < NUMLIST-1; ++i) //randomize array
	{
		myCharList[i] = ('A' + rand() % 26);
	}
	myCharList[NUMLIST - 1] = '\n';
	
	sort(myCharList, myCharList + (NUMLIST-1)); // sort O(logn), also ignored the \n at the end

	printList(myCharList, NUMLIST);//print list before removing duplicates
	cout << endl << endl << endl;

	removeDuplicatedChars(myCharList, NUMLIST);

	printList(myCharList, NUMLIST);//print list afterremoving duplicates
	return 0;
}

void printList(char list[], const int size)
{
	int count = 0;
	while (list[count] != '\n')
	{
		cout << list[count] << endl;
		++count;
	}

}

void removeDuplicatedChars(char list[], const int size)
{
	//precondition: list[] must be sorted, a proper char array (\n at the end) and size must be accurate otherwise function will not work.

	int count = 1;
	int numletters = 0;
	char beginning = list[0];

	for (int i = 0; i < size-1; ++i) // iterate through the array
	{
		while (list[i] == list[i + count] && list[i + count] != '\n' && list[i] != '$') // if duplicate and not at end and not already duplicated character
		{
			list[i + count] = '$';
			count++;
		}

		if (list[i] != '\n') //if not at the end
		{
			list[numletters] = list[i]; // move current letter to beginning
			++numletters;
			if (i > 0) // if the current spot is not the first letter
			{
				list[i] = '$';
			}
			i += count - 1; // jump to next letter, this is key to keeping this function O(N), as you only go through the array once
			count = 1;
		}
	}
	
	
	/*
	* //this is my first attempt, included to show my original thought process.
	for (int i = 0; i < size; ++i) // iterate through array and replace duplicates with $'s, O(N) as it only iterates through array once
	{
		while (list[i] == list[i + count] && list[i] != '$') // while the current character equals the one being checked and is not already changed
		{
			list[i + count] = '$';
			++count;
		}
		if (i != 0)
		{
			list[i] = '$';
		}
		if (list[placeholder] != 'Z')
		{
			list[placeholder] = list[i + count];
		}
		 // set the next character to the beginning (B moved to next to A, C moved to next to B, etc)
		list[i + count] = '$';
		placeholder++;
		
		i += count; // skip to the next character (from A to B, B to C, etc)
		//list[i - 1] = '$';
		count = 1;
		
	}

	*/

	cout << endl << "Duplication Removed!" << endl;
	
}
