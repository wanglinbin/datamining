#ifndef _PROCESS_STRING_H
#define _PROCESS_STRING_H

#include "process_string.h"

#endif

using namespace std;

//判断一行字符是否是一个记录的开始
bool exist_new_record(const string line_string)
{
    //string identifier;
    size_t found_artical=line_string.find("<article mdate");
    if(found_artical!=string::npos&&int(found_artical)==0){
        return true;
    }
    else
    {
        size_t found_www=line_string.find("<www mdate");
        if(found_www!=string::npos&&int(found_www)==0)
            return true;
        else
        {
            size_t found_book=line_string.find("<book mdate");
            if(found_book!=string::npos&&int(found_book)==0)
                return true;
            else
            {
                size_t found_inproceedings=line_string.find("<inproceedings mdate");
                if(found_inproceedings!=string::npos&&int(found_inproceedings)==0)
                    return true;
            }
        }
    }
    return false;
}

//判断某一行是否为一条记录的结束
bool end_record(const string line_string)
{
    size_t found_artical=line_string.find("</article>");
    if(found_artical!=string::npos&&int(found_artical)==0){
        return true;
    }
    else
    {
        size_t found_www=line_string.find("</www>");
        if(found_www!=string::npos&&int(found_www)==0)
            return true;
        else
        {
            size_t found_book=line_string.find("</book>");
            if(found_book!=string::npos&&int(found_book)==0)
                return true;
            else
            {
                size_t found_inproceedings=line_string.find("</inproceedings>");
                if(found_inproceedings!=string::npos&&int(found_inproceedings)==0)
                    return true;
            }
        }
    }
    return false;
}


//判断某一行是否为Author记录行
bool author_record(const string line_string)
{
    size_t found_author=line_string.find("<author>");
    if(found_author!=string::npos&&int(found_author)==0)
        return true;
    return false;
}

string extract_author(const string line_string)
{
    string result;
    size_t length=line_string.size()-17;
    result=line_string.substr(8,length);
    return result;
}
