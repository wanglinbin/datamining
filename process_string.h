#ifndef _PROCESS_STRING_H_
#define _PROCESS_STRING_H
#include "include.h"
#endif
using namespace std;
bool exist_new_record(const string line_string);
bool author_record(const string line_string);
bool end_record(const string line_string);
string extract_author(const string line_string);
