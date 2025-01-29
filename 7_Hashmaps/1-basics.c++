#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{ 

    unordered_map<string,int> m;

    pair<string,int> p=make_pair("nawed " ,1);

     m.insert(p);
     pair<string,int> pair2("shadab " , 2);
     m.insert(pair2);

     m["muzammil"]=3;

    //  for(auto i :m)
    //  {
    //     cout<<i.first<<" "<<i.second<<endl;
    //  }
  
//    unordered_map<string,int> :: iterator it=m.begin();

//    while(it!=m.end())
//    {
//        cout<<it->first<<" "<< it->second <<endl;
//        it++;
//    }

cout<<m.size();
// cout<<m.at("hello")<<endl;
// cout<<m["nawed"];
// cout<<m.count("hey");

m.erase("nawed");

     for(auto i :m)
     {
        cout<<i.first<<" "<<i.second<<endl;
     }

return 0;
}