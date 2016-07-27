#include"lsmod.h"
#include"hashtable.h"
#include<iostream>

using namespace std;

int main(){

/*	string dir = string("/home/geekgoutham/CPP-interactive-challenges/log");
	vector<string> files = vector<string>();

	directory ls;
	ls.getfiles(dir,files);

	for (unsigned int i = 0;i < files.size();i++) {
		cout << files[i] << endl;
	}
*/

	node *A = new node{"192.168.0.1",1469448000,NULL};
	hashtable table;
	table.insert_item(A);
	linkedlist obj = table.get_item_key("192.168.0.1");
	cout << obj.head->log_time << endl;
	return 0;
}
