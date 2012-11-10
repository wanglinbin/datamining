#ifndef _GET_FRESET2_H_
#define _GET_FRESET2_H
#include "include.h"
#include <algorithm>
#endif

void generate_candidate_itemset2(list<Author>& author_list,vector<vector<unsigned int> >& candidates_list);
bool candidate_exist(vector<unsigned int> candidate,vector<unsigned int> record);
void get_freset2(vector<vector<unsigned int> >& record_list,list<Author>& author_list, vector<vector<unsigned int> >& fre_itemset2);
