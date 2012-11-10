#ifndef _PROCESS_FILE_H_
#define _PROCESS_FILE_H
#include "include.h"
#endif
using namespace std;
unsigned int find_existed_author(vector<Author> &author_list,string new_author_name);
void process_file(list<Author> &author_list_0,vector<vector<unsigned int> > &record_list_0);
unsigned int insert_author(list<Author>& author_list,Author new_author);
