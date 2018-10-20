#include "subject.h"
#include "staticblock.h"
#include "dynamicblock.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    try{
        if(argc<=1)
            throw argc;
        string str;
        char*p;
        size_t N = strtol(argv[1],&p,10);
        Subject sub;
        StaticBlock b_obs(&sub, N);
        DynamicBlock d_obs(&sub);
        //bool first_cycle = true;
        //sub.createFile(std::to_string(model_sub->get_fixed_time())+".log");
        while(getline(cin, str)){
            sub.get_time();
            sub.set_str(str);
            //first_cycle = false;
        }
        sub.closeFile();
    }
    catch(int&i){
        cout<<"Error: argc = "<<i<<endl;
    }
}
