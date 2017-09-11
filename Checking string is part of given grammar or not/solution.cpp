#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <sstream>
using namespace std;
bool possible;
vector < vector<string> > rule;
string result;
string to_str(int i){
    ostringstream str;
    str<<i;
    return str.str();
}
int check(string base,string goal,string seq){
    string seq1 = seq;
    //cout<<"base"<<endl<<base<<"  "<<goal<<endl;
    while(possible){
        for(int i=0;i<rule.size();i++){

            int k = 0;
            while(base[k]==goal[k]){
                    k++;
                    //cout<<"matched..."<<k<<endl;
            }
            //cout<<k<<endl;
            //cout<<base.substr(k,k+1)<<endl;
            if(rule[i][0][0]==base[k]){
                //cout<<k<<"     "<<i+1<<endl;

                string based = base;
                //cout<<"old  :"<<base<<" ";

                based.erase(k,1);
                //cout<<"erased: "<<based<<" --";

                based.insert(k,rule[i][1]);
                int j = 0;

                seq1 += to_str(k+1) + " " + to_str(i+1) + " ";

                while(based[j]==goal[j] && j<based.length() && islower(based[j])){
                    j++;
                }


                //cout<<based<<" "<<j<<endl;
                //cout<<j<<endl;
                if(based == goal){
                    result = seq1;
                    possible = false;
                    //cout<<seq<<endl<<endl<<endl;
                    return 0;
                }
                if(seq1.length()){
                    //cout<<seq1<<"  j "<<j<<endl;
                    //cout<<based<<endl;
                    if(!islower(based[j]) && based.length()<=goal.length()+1){
                        //cout<<based<<"  "<<goal<<endl;
                        check(based,goal,seq1);
                    }
                    else
                        seq1 = seq;
                }
                else{
                    return 1;
                }
            }
            seq1 = seq;
        }
        //cout<<"-1 -1"<<endl;
        return 1;
    }
    return 1;
}

int main(){
    //vector< vector<string> > rule;
    vector< string > r;
    rule.clear();
    string line,g,b;
    ifstream input ("q1.txt",ios::in);
    ofstream output ("out.txt",ios::trunc);
    if(input.is_open()){
        while(getline(input,line)){
            if(line[0]<='z' && line[0]>='a'){
                unsigned int i;
                for(i = 0; line[i] != ' '; i++){
                }
                g = line.substr(0,i);
                b = line.substr(i+1);
                possible = true;
                //cout<<base<<endl;
                check(b,g,"");
                if(possible == false){
                    result += "0 0";
                    cout<<result<<endl;
                    output<<result<<"\n";
                }
                else{
                    cout<<"-1 -1"<<endl;
                    output<<"-1 -1\n";
                }
            }else{
                r.clear();
                r.push_back(line.substr(0,1));
                r.push_back(line.substr(5));
                rule.push_back(r);
                //cout<<line.substr(5);
            }
        }
    }
    input.close();
    output.close();
    return 0;
}
