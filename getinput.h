#ifndef GETINPUT_H
#define GETINPUT_H
#define READLINE_LIBRARY

#include <iostream>
#include <string>

#include "readline.h"
#include "history.h"

using namespace std;

void getinput(string& input, const string& promt = ">> ", const string& history_file = ".history");

#endif