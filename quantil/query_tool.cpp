#include"lsmod.h"
#include"hashtable.h"
#include<iostream>
#include<string>
#include<sstream>
#include<iterator>

using namespace std;

vector<string> split(string const &input, string &ip_k, int &id_d) {
	istringstream buffer(input);
	vector<string> ret{istream_iterator<string>{buffer}, istream_iterator<string>{}};
	ip_k = ret[1];
	id_d = stoi(ret[2], nullptr, 10);
	return ret;
}

unsigned long unix_time(vector<string> query_vec){
	time_t rawtime;
	struct tm * timeinfo;
	int from_y, from_m, from_d, from_h, from_min, to_y, to_m, to_d, to_h, to_min;
	string buffer;
	
	buffer = query_vec[3] + " " + query_vec[4];
	sscanf(buffer.c_str(), "%4d-%2d-%2d %2d:%2d", &from_y, &from_m, &from_d,
				&from_h, &from_min);

	buffer = query_vec[5] + " " + query_vec[6];
	sscanf(buffer.c_str(), "%4d-%2d-%2d %2d:%2d", &to_y, &to_m, &to_d, &to_h, &to_m);
	
	time(&rawtime);
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year   = year - 1900;
	timeinfo->tm_mon    = month - 1;    //months since January - [0,11]
	timeinfo->tm_mday   = day;          //day of the month - [1,31] 
	timeinfo->tm_hour   = hour +1;         //hours since midnight - [0,23]
	timeinfo->tm_min    = min;          //minutes after the hour - [0,59]
	timeinfo->tm_sec    = 0; 
	date = mktime ( timeinfo );
	date -= (8 *60 *60);     //To compenstate for PST (GMT -8) , Code uses local time for struct
	

}

int main(int argc, char* argv[]){

/*	string dir = string("/home/geekgoutham/CPP-interactive-challenges/quantil/log");
	vector<string> files = vector<string>();

	directory ls;
	ls.getfiles(dir,files);

	for (unsigned int i = 0;i < files.size();i++) {
		cout << files[i] << endl;
	}
*/
/*
	node *A = new node{"192.168.0.1",1469448000,NULL};
	hashtable table;
	table.insert_item(A);
	linkedlist obj = table.get_item_key("192.168.0.1");
	cout << obj.head->log_time << endl;
*/	

	string inp_query, ip_key;
	int id;
	if(argc < 2){
		cout << "The format to use is ./query.out <Path to directory of log>" <<endl;
	}
	else{
		cout << argv[1] <<endl<<"-------------------------"<<endl;
		string dir = argv[1];
	        vector<string> files = vector<string>();

        	directory ls;
        	ls.getfiles(dir,files);

        	for (unsigned int i = 0;i < files.size();i++) {
                	cout << files[i] << endl;
        	}
	}
	cout<<"Entering interative query tool. Query examples are listed below" <<endl;
	cout<<"  >QUERY 192.168.1.10 1 2014-10-31 00:00 2014-10-31 00:05 " <<endl;
	cout<<"  >exit "<<endl;
	cout<<">";
	while (getline(cin,inp_query)){
		//cout<<inp_query<<endl;
		if (inp_query == "exit" | inp_query == "EXIT")
			break;
		else if(inp_query == "" | inp_query == " ") {cout<<">"; continue;}
		else{
			split(inp_query, ip_key, id);
			
		}

		cout<<">";
	}
	return 0;
}
