///Header file for list files in a directory code


#ifndef LSMOD_H
#define LSMOD_H
#include<string>
#include<vector>
using namespace std;

/*! Class that has functionalities to list the files in a given directory */
class directory{
public:
	int getfiles (string dir, vector<string> &files);
}; // class directory

#endif //LSMOD_H definition
