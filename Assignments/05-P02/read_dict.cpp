#include <iostream>
#include "JsonFacade.hpp"
#include <time.h>
#include <chrono> 
#include "Timer.hpp"
#include <algorithm>

using namespace std;

int theSearch(vector<string> v, string key);

int main(){
    srand(time(NULL));
    cout << "Flush" << endl;
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

    //test of sorting dect
    sort(keys.begin(),keys.end());
    
    // for (int i = 0; i < keys.size(); i++){
    //     cout << keys[i] << '\n';
    // }
    // cout << endl;

    int ndex = theSearch(keys, "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    string word = ndex >= 0 ? keys[ndex] : "not found.";
    cout << "Search: " << ndex << "... " << word << "\n";


    // cout<<keys.size()<<endl;
    // index = rand() % keys.size();
    // key = J.getKey(index);

    // cout<<key<<" = "<<J.getValue(key)<<endl;
}


int theSearch(vector<string> v, string key){
    int i = lower_bound(v.begin(), v.end(), key) - v.begin();
    if(v[i] != key) return -1;
    return i;
}