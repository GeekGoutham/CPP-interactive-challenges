#include"lsmod.h"
#include"hashtable.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<iterator>
#include<fstream>

using namespace std;

vector<string> split(string const &input) {
	istringstream buffer(input);
	vector<string> ret{istream_iterator<string>{buffer}, istream_iterator<string>{}};
//	ip_k = ret[1];
//	id_d = stoi(ret[2], nullptr, 10);
	return ret;
}

unsigned long unix_time(string &str_time){
	time_t rawtime;
	struct tm * timeinfo;
	int y, m, d, h, min, date;
	string buffer = str_time;
	
//	buffer = query_vec[3] + " " + query_vec[4];
	sscanf(buffer.c_str(), "%4d-%2d-%2d %2d:%2d", &y, &m, &d,
				&h, &min);

//	buffer = query_vec[5] + " " + query_vec[6];
//	sscanf(buffer.c_str(), "%4d-%2d-%2d %2d:%2d", &to_y, &to_m, &to_d, &to_h, &to_m);
	
	time(&rawtime);
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year   = y - 1900;
	timeinfo->tm_mon    = m - 1;    //months since January - [0,11]
	timeinfo->tm_mday   = d;          //day of the month - [1,31] 
	timeinfo->tm_hour   = h +1;         //hours since midnight - [0,23]
	timeinfo->tm_min    = min;          //minutes after the hour - [0,59]
	timeinfo->tm_sec    = 0; 
	date = mktime ( timeinfo );
	date -= (8 *60 *60);     //To compenstate for PST (GMT -8) , Code uses local time for struct
	
	return date;

}

void print_log(node *print_node, int id){
	if (id == print_node->id_a){
		cout << "(" << print_node->key << " " << print_node->id_a << " " << print_node->load_a << ") "; 
	}
	if (id == print_node->id_b){
                cout << "(" << print_node->key << " " << print_node->id_b << " " << print_node->load_b << ") ";
        }


}

int convert_int(string inp_str){
	return stoi(inp_str.c_str(), nullptr, 10);
}

unsigned long convert_ul(string const inp_str){
	return strtoul(inp_str.c_str(), nullptr, 0);
}

int main(int argc, char* argv[]){
	string line;
//	string dir = string("/home/geekgoutham/CPP-interactive-challenges/quantil/log");


	string inp_query, ip_key, buffer;
	int id;
	unsigned long ufrom_time, uto_time;
	hashtable table;
	if(argc < 2){
		cout << "The format to use is ./query.out <Path to directory of log>" <<endl;
	}
	else{
		cout << argv[1] <<endl<<"-------------------------"<<endl;
		string dir = argv[1];
	        vector<string> files = vector<string>();

        	directory ls;
        	ls.getfiles(dir,files);


//	        ifstream my_file;

        	for (unsigned int i = 0;i < files.size();i++) {
			cout << files[i] << endl;
			ifstream my_file;
			string name = dir + "/" + files[i];
	                my_file.open(name, ios::in);

        	        if (my_file.is_open()){
				while (getline (my_file,line)){
//					cout << line << endl;
					vector<string> tokens_ip = split(line);
					node* A = new node{tokens_ip[1],convert_int(tokens_ip[2]),convert_int(tokens_ip[4]),
        	                                        convert_int(tokens_ip[3]), convert_int(tokens_ip[5]),convert_ul(tokens_ip[0])};
					table.insert_item(A);
				}	
                	
			my_file.close();
			}		

        	else cout << "Unable to open file";

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
			vector<string> query_vec = split(inp_query);
			ip_key = query_vec[1];
			id = convert_int(query_vec[2]);
			buffer = query_vec[3] + " " + query_vec[4];
			ufrom_time = unix_time(buffer);
			buffer = query_vec[5] + " " + query_vec[6];
			uto_time = unix_time(buffer);
			

			linkedlist obj = table.get_item_key(ip_key);
//			if (obj == NULL) {cout << "No matching entry found"; continue;}
			
			node *match_ptr = obj.head;
			if (obj.head->log_time > uto_time) {cout<< "No logs found in the specified time frame"; continue;}
			else if((obj.head->log_time > ufrom_time) && (obj.head->log_time < uto_time)){
				while(match_ptr->log_time <= uto_time | match_ptr->next != NULL){
					print_log(match_ptr, id);
					match_ptr = match_ptr->next;
				}}
			else if((obj.head->log_time <= ufrom_time) && (obj.tail->log_time >= uto_time)){
				while(match_ptr->log_time == ufrom_time){ match_ptr = match_ptr->next;}
				while(match_ptr->log_time <= uto_time){
					print_log(match_ptr, id);
					match_ptr=match_ptr->next;
				}
			 }
		}
			
			
	

		cout<<">";
	}
}
	return 0;
}
