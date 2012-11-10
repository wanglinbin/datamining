#include "get_freset2.h"
using namespace std;
void generate_candidate_itemset2(list<Author>& author_list,vector<vector<unsigned int> >& candidates_list)
{
    //得到频繁一项集的id
    vector<unsigned int>fre_itemset1;
    list<Author>::iterator it;
    for(it=author_list.begin();it!=author_list.end();it++)
        fre_itemset1.push_back((*it).id);
    //生成所有可能的频繁二项集
    vector<unsigned int>::iterator it_1;
    vector<unsigned int> candidate(2);
    for(it_1=fre_itemset1.begin();it_1<fre_itemset1.end();it_1++)
    {
        vector<unsigned int>::iterator it_2=it_1+1;
        while(it_2<fre_itemset1.end())
        {

            candidate[0]=*it_1;
            candidate[1]=*it_2;
            candidates_list.push_back(candidate);
            it_2++;
        }
    }
}

void get_freset2(vector<vector<unsigned int> > &record_list,list<Author> &author_list, vector<vector<unsigned int> >&fre_itemset2)
{
    vector<vector<unsigned int> >candidates_list;
    generate_candidate_itemset2(author_list,candidates_list);
    vector<vector<unsigned int> >::iterator it;
    vector<int> candidate_counter;
    for(it=candidates_list.begin();it<candidates_list.end();it++)
    {
        int counter=0;
        vector<vector<unsigned int> >::iterator it_rec;
        for(it_rec=record_list.begin();it_rec<record_list.end();it_rec++)
        {
            if(candidate_exist(*it,*it_rec))
                counter++;
        }
        candidate_counter.push_back(counter);
    }
    //删除所有的非频繁项集
    for(unsigned int i=0;i<candidate_counter.size();i++)
    {
        vector<vector<unsigned int> >::iterator it_candi;
        if(candidate_counter[i]>=MIN_SUP_SET2)
        {
            fre_itemset2.push_back(candidates_list[i]);
        }
    }


}

//判断一个candidate是否包含在某条记录中
bool candidate_exist(vector<unsigned int> candidate,vector<unsigned int> record)
{
    for(int i=0;i<1;i++)
    {
        vector<unsigned int>::iterator result=find(record.begin(),record.end(),candidate[0]);
        if(result==record.end())
            return false;
    }
    return true;
}

