#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#define SIZE 30000

using namespace std;

int read(string, string[SIZE], int);
void print(string[SIZE], int);

int main()
{
	
	string path;
	string word[SIZE];
	int i = 0;
	int count = 0;
	do{
		cout << "Enter the input file path or -1 to stop input: ";
		cin >> path;
		
		if(path == "-1") break;
		
		i = read(path, word, i);
		count++;
		
	} while(1);
	
	print(word, i);
	
	system("cls");
	
	cout << "The file merged successfully!" << endl;
	cout << "Total input files.....: " << count << endl;
	cout << "Total words appended..: " << i << endl;
	
	system("pause");
	return 0;
}

int read(string path, string word[SIZE], int i)
{
	ifstream cFile;
	string temp;
	
	cFile.open(path);
	
	if(cFile.is_open())
	{
		while(!cFile.eof()){
			if(i >= SIZE){
				break;
			}
			cFile >> temp;
			word[i] = temp;
			i++;
		}
		cout << "There are a total of " << i << " words in the dict" << endl;
		cFile.close();
	} else {
		cout << "Error opening the file" << endl;
	}
	
	return i;
}

void print(string word[SIZE], int i)
{
	fstream pFile;
	string path;
	
	do{	
		cout << "Enter the output file path: ";
		cin >> path;
		
		pFile.open(path, fstream::app);
		
		if(pFile.is_open())
		{
			for(int j = 0; j < i; j++){
				pFile << word[j] << endl;
			}
			pFile.close();
		} else {
			cout << "Error opening the file" << endl;
		}
		
	} while(!pFile.is_open());
	
}
