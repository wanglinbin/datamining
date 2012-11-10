
#include "include.h"
#include "process_file.h"
#include "get_freset1.h"
#include "get_freset2.h"
using namespace std;


int main()
{

   vector<vector<unsigned int> > record_list;
   list<Author> author_list;
   process_file(author_list,record_list);
   //list<Author>::iterator it_a;
   cout<<author_list.size()<<endl;
   cout<<record_list.size()<<endl;
   list<unsigned int> unfre_authors_id;
   get_freset1(author_list,unfre_authors_id);
   cout<<unfre_authors_id.size()<<endl;
   delete_unuseful_record(record_list,unfre_authors_id);
   cout<<record_list.size()<<endl;
   //vector<vector<unsigned int> >candidates_list;
   //generate_candidate_itemset2(author_list,candidates_list);
  // cout<<candidates_list.size()<<endl;
   vector<vector<unsigned int> >fre_itemset2;
   get_freset2(record_list,author_list,fre_itemset2);
   cout<<fre_itemset2.size()<<endl;
   ofstream fout("fre_itemset2");
   vector<vector<unsigned int> >::iterator it;
   for(it=fre_itemset2.begin();it<fre_itemset2.end();it++)
       fout<<(*it)[0]<<" "<<(*it)[1]<<endl;
 /* for(it_a=author_list.begin();it_a!=author_list.end();it_a++)
   {
        cout<<it_a->name<<" "<<it_a->count<<endl;
   }*/
   /*cout<<"********************"<<endl;
   vector<vector<unsigned int> >::iterator it_b;
   for(it_b=record_list.begin();it_b!=record_list.end();it_b++)
   {
        vector<unsigned int>::iterator it_c;
        for(it_c=(*it_b).begin();it_c!=(*it_b).end();it_c++)
            cout<<*it_c<<" ";
        cout<<endl;

   }*/
        //cout<<it_a->name<<i<<endl;
  /*ifstream infile("/home/gezi/Project/data_mining/dblp.xml");
    string line_string;
   int count_line=0;
   vector<string> file;
    while(getline(infile,line_string)&&count_line<200)
    {
        cout<<line_string<<endl;
        //file.push_back(line_string);
        //if(author_record(line_string)){
        //cout<<extract_author(line_string)<<endl;}
        count_line++;
    }*/




    return 0;
}

