/*! A log query tool that takes directory of logs as input.
 *
 *
 *An interactive log query tool that takes in a directory of logs as input. The logs should be in format "<unixtime> <ip address> <cpu_id> <cpu_load> <cpu_id> <cpu_load>" 
 *Primary commands the tools takes are 
 *	a. query <ip addr> <id> <from date> <to date>
 *		from and to dates to be in format YYYY-MM-DD hh:mm
 *	b. exit
 *
 *Code uses hashtable of linkedlist to store the log data. The hashtable eases the retrival complexity to O(1).
 *linkedlist used has a tail pointer, to decrease complexity for insert from O(n) to O(1).
 *
 *Program details:
 *
 *Author     : Vignesh Goutham Ganesh
 *Email      : vigneshgoutham@outlook.com
 *Date       : 29 July, 2016
 *Language   : C++
 *Compiler   : gcc version 5.4.0 20160609
 *pkgversion : Ubuntu 5.4.0-6ubuntu1~16.04.1
 *Target     : x86_64-linux-gnu
 *OS         : Ubuntu 16.04 LTS
 *
*/

#include"lsmod.h"
#include"hashtable.h"
#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<iterator>
#include<fstream>

using namespace std;


/*! Class with functions to assist parse the query, find logs and print the logs */
class query_functions{
public:
	vector<string> split(string const &);
	unsigned long unix_time(string const &);
	string unix_read_time(const time_t);
	void search_logs(const string &, hashtable &,const unsigned long &, const unsigned long &, const int &);
	void print_log(node*, int);
	int convert_int(string);
	unsigned long convert_ul(string const);
	void parse_files(const string &, hashtable &, string const &);

}; //class query_functions

/*! Split function splits the query into induvidual tokens based on delimiter - whitespace*/
vector<string> query_functions::split(string const &input) {

	istringstream buffer(input);
	vector<string> ret{istream_iterator<string>{buffer}, istream_iterator<string>{}}; //< uses whitespace as delimiter and copies words to vector 
	return ret;
}

/*! Converts human redable gregorian date time to unix time */
unsigned long query_functions::unix_time(string const &str_time){

	time_t rawtime; /**< Gets local time */
	struct tm * timeinfo; /**< struct tm to be used as template for readable time holder */
	int y, m, d, h, min, date;
	string buffer = str_time;
	
	sscanf(buffer.c_str(), "%4d-%2d-%2d %2d:%2d", &y, &m, &d,
				&h, &min);

	
	time(&rawtime);
	timeinfo = localtime ( &rawtime ); // gets localtime for struct template 
	timeinfo->tm_year   = y - 1900;
	timeinfo->tm_mon    = m - 1;    // months since January - [0,11] 
	timeinfo->tm_mday   = d;        // day of the month - [1,31] 
	timeinfo->tm_hour   = h +1;     // hours since midnight - [0,23] 
	timeinfo->tm_min    = min;      // minutes after the hour - [0,59] 
	timeinfo->tm_sec    = 0; 
	date = mktime ( timeinfo );
	date -= (8 *60 *60);            // To compenstate for PST (GMT -8) , Code uses local time for struct 
	
	return date;

}

/*! Converts unix time to human readable gregorian date time format */
string query_functions::unix_read_time(const time_t rawtime){

	struct tm * dt;
	char buffer [30];
	dt = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%2y-%2m-%2d %2H:%2M", dt); // Uses struct tm as template and converts unixtime to readable date time 
	return string(buffer);
}

/*! Searches the hashtable and the value linkedlist for matching logs */
void query_functions::search_logs(const string &ip_k, hashtable &table,const unsigned long &ufrom_time, const unsigned long &uto_time, const int &id){

	linkedlist obj = table.get_item_key(ip_k);

	if(obj.head == NULL) { cout << "No logs for the specified IP address found" <<endl; return; } 
	if(!((obj.head->id_a == id) || (obj.head->id_b == id))) { cout << "No logs for the specified CPU ID found" << endl; return; }
	node *match_ptr = obj.head;
		
	if (ufrom_time > uto_time) { cout << "From time must be before to time" << endl; return; }  // validates inpute query from and to time 

	if ((obj.head->log_time > uto_time) || (obj.tail->log_time < ufrom_time)) {cout<< "No logs found in the specified time frame"; return;}
	
	
        if(obj.head->log_time > ufrom_time){		// If query time is before the earliest time recorded in logs 
		cout << "------------------Available logs-----------------------" << endl;
                while(match_ptr->log_time <= uto_time){
			print_log(match_ptr, id);
                        match_ptr = match_ptr->next;
			if(match_ptr == NULL) return;
                }
        }
        else if(obj.head->log_time <= ufrom_time){  // If query time is after the earliest time recorded in logs
                while(match_ptr->log_time != ufrom_time){ match_ptr = match_ptr->next;}
                while(match_ptr->log_time <= uto_time){
                        print_log(match_ptr, id);
                        match_ptr=match_ptr->next;
			if(match_ptr == NULL) return;
                }
        }

}


/*! Prints the logs found after submitting the query to the program */
void query_functions::print_log(node *print_node, int id){

	if (id == print_node->id_a){
		cout << "(" << unix_read_time(print_node->log_time + 25200) <<" CPU load = " << print_node->load_a <<"% ) " << endl; 
	}

	if (id == print_node->id_b){
                cout << "(" << unix_read_time(print_node->log_time + 25200) <<" CPU load = " << print_node->load_b <<"% ) " << endl;
        }


}

/*! Converts integers in string datatype to proper integer datatype */
int query_functions::convert_int(string inp_str){

	return stoi(inp_str.c_str(), nullptr, 10); // function that converts string to int or other forms of number representation depending on indicated base; 10 used here for decimal 
}

/*! Converts ul integers in string datatype to proper ul int datatype  */
unsigned long query_functions::convert_ul(string const inp_str){

	return strtoul(inp_str.c_str(), nullptr, 0); // function that converts string to unsigned long int 
}

/*! Parses the list of files in the input directory and stores them in a hashtable for easy search upon query */
void query_functions::parse_files(const string &file_n, hashtable &tab, string const &dir_n){

	ifstream my_file;
        string line, name = dir_n + "/" + file_n;
        my_file.open(name, ios::in);

        if (my_file.is_open()){
        while (getline (my_file,line)){
		vector<string> tokens_ip = split(line);
                node* A = new node{tokens_ip[1],convert_int(tokens_ip[2]),convert_int(tokens_ip[4]),
                                   convert_int(tokens_ip[3]), convert_int(tokens_ip[5]),convert_ul(tokens_ip[0])};
                tab.insert_item(A);    // Inserting nodes into hashtable 
        	}

       my_file.close();
       }

     else cout << "Unable to open file";

}

/*! Main program - gets input from user, performs files parsing, gets input performs query log search and prints them to stdout */
int main(int argc, char* argv[]){

	string line, inp_query, ip_key, buffer;
	int id;
	unsigned long ufrom_time, uto_time;

	hashtable table;
	query_functions qf;
	directory ls;

	if(argc < 2){
		cout << "The format to use is ./query.out <Path to directory of log>" <<endl;
	}
	else{
		cout << argv[1] <<endl<<"-------------------------"<<endl;
		string dir = argv[1];
	        vector<string> files = vector<string>();

        	ls.getfiles(dir,files);



        	for (unsigned int i = 0;i < files.size();i++) {
			qf.parse_files(files[i], table, dir);
			cout << files[i] << endl;
		}
	
		cout<<"Entering interative query tool. Query examples are listed below" <<endl;
		cout<<"  >QUERY 192.168.0.1 1 2016-7-25 00:00 2016-7-25 00:05 " <<endl;
		cout<<"  >exit "<<endl << endl;
		cout<<">";
		while (getline(cin,inp_query)){    // Takes in queries from stdin 
			if ((inp_query == "exit") || (inp_query == "EXIT"))
				return 0;
			else if((inp_query == "") || (inp_query == " ")) { cout<<">"; continue; }

			else{
				vector<string> query_vec = qf.split(inp_query);
				if (query_vec.size() != 7) { cout << "Please follow the pattern given in example" << endl << ">"; continue; }
				if(!((query_vec[0] =="query")||(query_vec[0] =="QUERY"))){ cout << " Only QUERY and exit commands are allowed" << endl << ">" ;  continue;}

				ip_key = query_vec[1];              // Splits the queries into tokens 
				id = qf.convert_int(query_vec[2]);
				buffer = query_vec[3] + " " + query_vec[4];
				ufrom_time = qf.unix_time(buffer);
				buffer = query_vec[5] + " " + query_vec[6];
				uto_time = qf.unix_time(buffer);
			
				qf.search_logs(ip_key, table,ufrom_time, uto_time, id);

			}	
	

			cout<<">";
		}
	}
	
	return 0;
}
