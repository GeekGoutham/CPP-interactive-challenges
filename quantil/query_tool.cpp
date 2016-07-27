#include"lsmod.h"
#include<iostream>

using namespace std;

int main(){

	string dir = string("/home/geekgoutham/CPP-interactive-challenges/log");
	vector<string> files = vector<string>();

	directory ls;
	ls.getfiles(dir,files);

	for (unsigned int i = 0;i < files.size();i++) {
		cout << files[i] << endl;
	}

	
	return 0;
}
