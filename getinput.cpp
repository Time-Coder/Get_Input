#include <getinput.h>
#include <fstream>

bool isvalid(const string& input)
{
	if(input.empty())
	{
		return false;
	}

	for(string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if(*it != ' ' && *it != '\t' && *it != '\n' && *it != '\r' && *it != '\0')
		{
			return true;
		}
	}

	return false;
}

void getinput(string& input, const string& promt, const string& history_file_name)
{
	#ifndef __linux__
		cout << promt << endl;
		getline(cin, input);
	#endif
	
	ifstream history_file_in(history_file_name.data());
	if(!history_file_in)
	{
		ofstream history_file_out(history_file_name.data());
		history_file_out << endl;
		history_file_out.close();
	}
	history_file_in.close();

	read_history(history_file_name.data());
	input = readline(promt.data());
	if(isvalid(input))
	{
	    add_history(input.data());
	    append_history(1, history_file_name.data());
	}
	history_truncate_file(history_file_name.data(), 20);
	clear_history();
}