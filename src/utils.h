#ifndef UTILS_H
#define UTILS_H

#include <cstring>
#include <iostream>

void remove_space(std::string &str){
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
}

#endif // UTILS_H
