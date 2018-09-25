#include "subject.h"

void Subject::set_str(std::string str){
    obs->remove_space(str);
    if(str!="")
        obs->update(str);
}

void Subject::notyfy(){
    for(auto&i:m_views){
        i->switch_obs();
        if(i->lock)
            obs = i;
    }
}

size_t &Subject::get_time(){
    return _fixedTime = clock();
}

void Subject::createFile(std::string name){
    outfile.open(name, std::fstream::in | std::fstream::out | std::fstream::app);
    outfile<<"input | output"<<std::endl;
    outfile<<"------|-------"<<std::endl;
}

void Subject::closeFile(){
    if(outfile.is_open())
        outfile.close();
}
