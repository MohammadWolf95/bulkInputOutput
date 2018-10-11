#include "observer.h"
#include <iostream>
#include <cstring>

void Observer::print_obs(){
    if(m_vector.size()==0)
        return;
    std::string str = "bulk: ";
    for(auto it = m_vector.begin();it!=m_vector.end();++it){
        if(it==m_vector.end()-1){
            str+=*it;
            std::cout<<str<<std::endl;
        }
        else
            str+=(*it+", ");
    }
    print_to_file(str);
    m_vector.clear();
}

/*void Observer::remove_space(std::string &str){
    char* token;
    token = std::strtok((char*)str.c_str(), " ");
    int count = 0;
    while( token != NULL ) {
        if(count>0){
            ///ошибка
            std::cout<<"Error: More than one command is entered"<<std::endl;
            str="";
            return;
        }
        //cout<<token<<endl;
        str = token;
        token = strtok(NULL, " ");
        ++count;
    }
    if((str.find('{')!=std::string::npos||str.find('}')!=std::string::npos)&&str.size()>1){
        std::cout<<"Error: The command have symbol ""{"" or ""}"""<<std::endl;
        str="";
        return;
    }
}*/
