#include <iostream>
#include "JsonFacade.hpp"
#include <time.h>
#include <chrono> 
#include "timer.hpp"

using namespace std;

int main(){
    Timer T;
    T.Start();
    JsonFacade J("dict_w_defs.json");   // create instance of json class
    T.End(); 
    double s = T.Seconds();
    long m = T.MilliSeconds();

    cout <<s << " seconds" <<endl;
    cout <<m << " milli" <<endl;
    int index = 0;                      // 
    string key;                         // key variable to access json object

    vector<string> keys = J.getKeys();
    
    cout<<keys.size()<<endl;
    index = rand() % keys.size();
    key = J.getKey(index);

    cout<<key<<" = "<<J.getValue(key)<<endl;
}