//
//  main.cpp
//  kadai_saisyu
//
//  Created by 江口昌利 on 2021/08/04.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Birthday{
  protected:
    string name;
    int YY;
    int MM;
    int DD;
    
public:
    void setName( string& newName){ name = newName;}
    string getName(){return name; }
    void setYY(int newYY){ YY= newYY;}
    int getYY() {return YY;}
    void setMM(int newMM){ MM= newMM;}
    int getMM() {return MM;}
    void setDD(int newDD){ DD= newDD;}
    int getDD() {return DD;}

};

bool less1(Birthday&a, Birthday&b){
    if(a.getYY() !=b.getYY())
        return a.getYY()>b.getYY();
    if(a.getMM() !=b.getMM())
        return a.getMM()>b.getMM();
    if(a.getDD() !=b.getDD())
        return a.getDD()>b.getDD();
    return a.getName()<b.getName();
}

void Zeller(int y,int m,int d){
    if (m==1){
        y=y-1;
        m=13;
    }else if(m==2){
        y=y-1;
        m=14;
    }
    int Y= y%100;
    
    int B = floor(26*(m+1)/10);
    int C = floor(Y/4);
    int D = 2*floor(y/100);
    int E = floor(y/400);
    
    int X;
    X = d + B + Y + C - D + E;
    int x = X%7;
    
    if (x==2){
        cout <<"月曜日"<< endl;
    }else if (x==3){
        cout <<"火曜日"<<endl;
    }else if (x==4){
        cout <<"水曜日"<<endl;
    }else if (x==5){
        cout <<"木曜日"<<endl;
    }else if (x==6){
        cout <<"金曜日"<<endl;
    }else if (x==0){
        cout <<"土曜日"<<endl;
    }else if (x==1){
        cout <<"日曜日"<<endl;
}
}
    

int main(){
    string NAME;
    int yy;
    int mm;
    int dd;
    int ninzu;
    string Q;
    ;
    cout<<"全て半角で入力してください"<<endl;
    cout<< "人数を入力してください"<<endl;
    cin >> ninzu;
    vector<Birthday> v;
    
    for(int i=0;i<=ninzu-1;){
        cout <<i+1<<"人目のニックネームを入力してください" <<endl;
        cin >> NAME;
        cout<<"生まれた年(西暦)を入力してください"<<endl;
        cin >> yy;
        cout <<i+1<<"人目の生まれた月を入力してください" <<endl;
        cin >> mm;
        cout <<i+1<< "人目の生まれた日を入力してください" <<endl;
        cin >> dd;
        
        cout << "入力はこれで間違いないですか?"<< endl << "はいならY,いいえならNと入力してください"<<endl;
    
        cin >> Q;
        if(Q == "Y"){
            
            v.emplace_back();
            v[i].setName(NAME);
            v[i].setYY(yy);
            v[i].setMM(mm);
            v[i].setDD(dd);
            
            Zeller(v[i].getYY(),v[i].getMM(),v[i].getDD());
            i += 1;
        }else if (Q == "N"){
             i=i;
        }
        
    }
    sort(v.begin(), v.end(), less1);
    cout<<"\n誕生日が遅い(若い)順に\n";
    for(int n=0;n<=v.size()-1;n++){
        cout<<v[n].getName()<<"さん\n";
    }
    cout<<"です.\n";
}
