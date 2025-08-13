
#include<iostream>
#include<cstring>
using namespace std;

const int SIZE = 80;
//thids is used for fixed size

class String{
    protected:
    char str[SIZE];
    //make character array

    public:
    String(){
        str[0] = '\0';
//when string is empty

    }
    String(const char* s){
        strcpy(str, s);
        //if string is too long it unsafe ,overflow

    }
    void display(){
        cout<<str;
    }

    int length(){
        return strlen(str);
        //give lenght of string text
    }

};
//make drived class for if length of string too long then it cut extra string
class Pstring: public String{

    public:
    Pstring(const char* s){
        //if string is ttoo long cut it to set the actual length
        if(strlen(s) >= SIZE){
            strncpy(str, s, SIZE - 1);
            str[SIZE-1] = '\0';
        }else{
            strcpy(str, s);
        }
    }
};
int main(){
    Pstring s1("I am interesting in Business");
    cout<<"s1:";
    s1.display();
    cout<<"Length:"<< s1.length()<<"\n";

    Pstring s2("The old String class keeps text in a fixed array char str[SZ]. If we put a very long text, it can overflow. We must make a child class Pstring that never overflows.");
    cout<<"s2:";
    s2.display();
    cout<<"length:"<<s2.length()<<"\n";

    return 0;
}