#include"lsmod.h"

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int directory::getfiles (string dir, vector<string> &files){
	DIR *dp;
	struct dirent *dir_p;
	if((dp = opendir(dir.c_str())) == NULL) {
		cout << "Error(" << errno << ") opening " << dir << endl;
		return errno;
	}

	while ((dir_p = readdir(dp)) != NULL) {
		files.push_back(string(dir_p->d_name));
	}
	closedir(dp);
	return 0;
}
	
