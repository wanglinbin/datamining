#ifndef _GET_FRESET1_H_
#define _GET_FRESET1_H_
#include "include.h"
#endif
using namespace std;
void get_freset1(list<Author>& author_list,list<unsigned int>& unfre_authors_id);
void delete_unuseful_record(vector<vector<unsigned int> >& record_list, list<unsigned int>& unfre_authors_id);
bool unfre_author(list<unsigned int>& unfre_authors_id,unsigned int id,int size);
