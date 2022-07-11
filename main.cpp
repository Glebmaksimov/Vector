#include "Declarations.h"
int main() {

    Vector<int> v(11,3);

    cout<<v<<endl;
    v.push_back(1);
    cout<<v<<endl;
    v.push_back(2);
    cout<<v<<endl;

    Vector<int> v1(v);

    cout<<v1<<endl;

    if(v == v1)cout<<"[--Equal--]"<<endl;
    if(v != v1)cout<<"[--Not Equal--]"<<endl;

    Vector<int> v2{1,2,3,4,5,6,7};
    for (int i = 0; i < 4; ++i) {
        v2.push_back(i);
    }
    cout<<v2<<endl;
    v2.pop_back();
    cout<<v2<<endl;

    Vector<int> v3;
    v3 = v2;
    cout<<v3<<endl;
    v3.erase(3);
    cout<<v3<<endl;
    v3.insert(5,78);
    cout<<v3<<endl;


    cout<<endl<<endl;
    Vector<int> r;
    for (int i = 1; i < 22; ++i) {
        r.push_back(i);
        cout<<r<<endl;
    }

    Vector<int> v4;
    try{
        v4.pop_back();
    }catch(const std::string& er){
        cout<<er<<endl;
    }

    return 0;
}
