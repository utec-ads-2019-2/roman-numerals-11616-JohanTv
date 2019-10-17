#include <iostream>
#include <string>
#include <map>
using namespace std;

string phrase;
int valueNumeric;
map<char,int> numRoman{{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};

void printInNumRoman(){
    int resultado = 0;
    for (int i = 0; i < phrase.size(); ) {
        if(i != phrase.size()-1 && numRoman[phrase[i+1]] > numRoman[phrase[i]]){
            resultado+= numRoman[phrase[i+1]] - numRoman[phrase[i]];
            i+=2;
        }
        else{
            resultado+=numRoman[phrase[i]];
            i+=1;
        }
    }
    cout<<resultado<<endl;
}

void printThousands(){
    for(int i = valueNumeric/1000; i > 0 ; --i){
        cout<<"M";
    }
    valueNumeric%=1000;
}

void printHundreds(){
    int Hundreds = valueNumeric/100;

    if(Hundreds == 4) cout<<"CD";
    else if(Hundreds == 9) cout<<"CM";
    else{
        if(Hundreds > 3) {
            cout<<"D";
            Hundreds-=5;
        }
        for(int i = Hundreds; i > 0; --i)
            cout<<"C";
    }

    valueNumeric%=100;
}

void printTens(){
    int Tens = valueNumeric/10;

    if(Tens == 4) cout<<"XL";
    else if(Tens == 9) cout<<"XC";
    else{
        if(Tens > 3) {
            cout<<"L";
            Tens-=5;
        }
        for(int i = Tens; i > 0; --i)
            cout<<"X";
    }

    valueNumeric%=10;
}

void printUnits(){
    int Units = valueNumeric;

    if(Units == 4) cout<<"IV";
    else if(Units == 9) cout<<"IX";
    else{
        if(Units > 3) {
            cout<<"V";
            Units-=5;
        }
        for(int i = Units; i > 0; --i)
            cout<<"I";

    }

}

void printInNum(){
    printThousands();
    printHundreds();
    printTens();
    printUnits();
}

int main() {
    
    while(cin>>phrase){
        if(isdigit(phrase[0])){
            valueNumeric = stoi(phrase);
            printInNum();
            cout<<endl;
        }
        else printInNumRoman();
    }
    
    return 0;
}
