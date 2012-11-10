#include "process_file.h"
#include "process_string.h"
using namespace std;
void process_file(list<Author> &author_list,vector<vector<unsigned int> > &record_list)
{
    ifstream infile("/home/gezi/Project/data_mining/dblp.xml");
    string line_string;
    double count_line=0;
    bool detect_record_identifier=true;
    bool detect_author_identifier=false;
    bool detect_endrec_identifier=false;
    vector<unsigned int> new_record;
    Author new_author;
    vector <Author> authors_tmp;
    while(getline(infile,line_string)&&record_list.size()<50000)
    {
        count_line++;
        if(detect_record_identifier)
        {
            if(exist_new_record(line_string))
            {
                detect_record_identifier=false;
                detect_author_identifier=true;
                detect_endrec_identifier=true;
            }
        }
        if(detect_author_identifier&&detect_endrec_identifier)
        {
           if(author_record(line_string))
            {
                new_author.name=extract_author(line_string);
                new_author.count=1;
                new_author.id=author_list.size()+1+authors_tmp.size();
                authors_tmp.push_back(new_author);
                //unsigned int same_id=find_existed_author(author_list,new_author.name);
            }
            else if(end_record(line_string))
            {
                detect_record_identifier=true;
                detect_author_identifier=false;
                detect_endrec_identifier=false;
                if(authors_tmp.size()>1)
                {
                    while(!authors_tmp.empty())
                    {
                        Author author_should_record=authors_tmp.back();
                        authors_tmp.pop_back();
                        unsigned int same_id=insert_author(author_list,author_should_record);
                         if(same_id==0)
                            new_record.push_back(author_should_record.id);
                        else
                            new_record.push_back(same_id);
                    }
                    record_list.push_back(new_record);
                }
                new_record.clear();
                authors_tmp.clear();
            }
        }
    }
    cout<<count_line<<endl;

}

unsigned int find_existed_author(vector<Author> &author_list,string new_author_name)
{
    vector<Author>::iterator it;
    //it=author_list.begin();
    for(it=author_list.begin();it!=author_list.end();it++)
    {
        if(it->name.compare(new_author_name)==0)
        {
            it->count++;
            return it->id;
        }
    }
    return 0;
}

unsigned int insert_author(list<Author>& author_list,Author new_author)
{

    list<Author>::iterator pointer;
    pointer=author_list.begin();
    int size=(int)author_list.size();
    if(size==0)
    {
        author_list.push_back(new_author);
        return 0;
    }
    int compare_result;
    int min=1;
    int max=size;
    int mid=(min+max)/2;
    for(int i=0;i<mid-min;i++)
        pointer++;
    while(min<=max)
    {
        compare_result=new_author.name.compare(pointer->name);
        if(compare_result==0)
        {
            pointer->count++;
            return pointer->id;
        }
        else if(compare_result<0)
        {
            max=mid-1;
            mid=(max+min)/2;
            if(max>=1)
            {
                for(int i=0;i<max-mid+1;i++)
                    pointer--;
            }
        }
        else
        {
             min=mid+1;
             mid=(max+min)/2;
             if(min<=size)
             {
                for(int i=0;i<mid-min+1;i++)
                    pointer++;
           }
        }

    }
    compare_result=new_author.name.compare(pointer->name);
    if(compare_result==0)
    {
            pointer->count++;
            return pointer->id;
    }
    else if(compare_result<0)
        author_list.insert(pointer,new_author);


    else

        author_list.insert(++pointer,new_author);
    return 0;

}
