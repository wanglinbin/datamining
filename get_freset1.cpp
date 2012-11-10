#include "get_freset1.h"
using namespace std;

void get_freset1(list<Author>& author_list,list<unsigned int>& unfre_authors_id)
{
    list<Author>::iterator it;
    it=author_list.begin();
    while(it!=author_list.end())
    {
        if(it->count<MIN_SUP)
        {
            list <Author>::iterator tmp;
            unfre_authors_id.push_back(it->id);
            tmp=it;
            it++;
            author_list.erase(tmp);
        }
        else
            it++;
    }
    unfre_authors_id.sort();
}
void delete_unuseful_record(vector<vector<unsigned int> >& record_list, list<unsigned int>& unfre_authors_id)
{
    vector<vector<unsigned int> >::iterator it_1;
    it_1=record_list.begin();
    int marker=0;
    while(it_1<record_list.end())
    {

        vector<unsigned int>::iterator it_2;
        int counter=0;
        int authors_sum=(*it_1).size();
        for(it_2=(*it_1).begin();it_2!=(*it_1).end();it_2++)
        {
            if(unfre_author(unfre_authors_id,*it_2,unfre_authors_id.size()))
                counter++;
        }
        if(counter>=authors_sum-1)
        {

            vector<vector<unsigned int> >::iterator tmp=it_1;
            it_1++;
            record_list.erase(tmp);
            marker++;
        }
        else
            it_1++;


    }
}

bool unfre_author(list<unsigned int>& unfre_authors_id,unsigned int id,int size)
{
    list<unsigned int>::iterator it=unfre_authors_id.begin();
    int min=1;
    int max=size;
    int mid=(min+max)/2;
    for(int i=0;i<mid-min;i++)
        it++;
    while(min<=max)
    {
        if(id==*it)
            return true;
        else if(id>*it)
        {
            min=mid+1;
            mid=(min+max)/2;
            if(min<=size)
             {
                for(int i=0;i<mid-min+1;i++)
                    it++;
             }
        }
        else
        {
            max=mid-1;
            mid=(min+max)/2;
             if(max>=1)
            {
                for(int i=0;i<max-mid+1;i++)
                    it--;
            }
        }
    }
    if(*it==id)
        return true;
    else
        return false;
}


