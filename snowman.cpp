#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;

namespace ariel{

//the num
const int zero = 0;    //hat
const int one = 1;    //nose
const int two = 2;    //left eye
const int three = 3;  //right eye
const int four = 4;   //left arm
const int five = 5;   //right arm
const int six = 6;    //torso
const int seven = 7;  //base
const int eight = 8;  //stam


const vector<string> hat = {"_===_",
                            " ___ \n.....",
                            "   _ \n  /_\\",
                            " ___ \n(_*_)"};

const vector<string> noses = {",",
                              ".",
                              "_",
                              " "};

const vector<string> EyesLandR = {".",
                             "o",
                             "O",
                             "-"};

const vector<string> LArms = {"<",
                              "\\",
                              "/",
                              ""};

const vector<string> RArms = {">",
                              "/",
                              "\\",
                              ""};

const vector<string> torsos = {":",
                               "] [",
                               "> <",
                               "   "};

const vector<string> body = {":",
                             "\" \"",
                             "___",""};

//level 1 of the snowman
string printHead(char head){
        return hat[(head-'0')-1]+'\n' ;
}

string printNose(char nose){
        return noses[(nose -'0')-1];
}

//level 2 of the snowman
string printFace(char nose, char l_Eye,char r_Eye){
        string left = EyesLandR[(l_Eye-'0')-1];
        string right = EyesLandR[(r_Eye-'0')-1];
        return "("+left+printNose(nose)+right+")"+'\n';
}

//level 3 of the snowman
string makeTorso(char t){
        string torso = torsos[(t-'0')-1];
        string space = " ";
        if(torso == ":" || torso.empty()){
                 return "("+space+torso+space+")"+'\n';
        }
        return "("+torso+")"+'\n';
}

//level 4 of the snowman
string makeBase(char num){
        int base_i = (num-'0')-1;
        string space = " ";
        if (body[base_i] == ":"){
                return "("+space+body[base_i]+space+")";
        }
        if(body[base_i].empty()){
                return "("+space+body[base_i]+space+space+")";
        }
        return "("+body[base_i]+")";
}

string snowman(int num){
    //convert the num to array
    string numArr = to_string(num);
    //error msg
    string errorMsg= "Invalid code ";

    //check that it positive number
        if (num < 0) {
            throw out_of_range("the number must be positive!");
        }
     //check the length of the input - should be eight numbers
    if(numArr.length() < eight || numArr.length() > eight){
      throw  invalid_argument(errorMsg + "'" + to_string(num) + "'");
    }

    //check that all the eight numbers between 1-4
    for (int i = 0 ; i< numArr.length() ; i++){
        int a = numArr[i]-'0';
        if(a <1 || a > 4){
          throw  invalid_argument(errorMsg + "'" + to_string(num) + "'");
        }
    }

    //first level of the snowman
    string head = printHead(numArr[zero]);
    //second level of the snowman
    string EyeAndNose = printFace(numArr[one],numArr[two],numArr[three]);
    //third level of the snowman
    string torso = makeTorso(numArr[six]);
    //fourth level of the snowman
    string base = makeBase(numArr[seven]);

    //check left up arm:
    if (numArr[four] == '2'){
      EyeAndNose = LArms[(numArr[four]-'0')-1] + EyeAndNose;
    }
    //check right up arm:
    if (numArr[five] == '2'){
      EyeAndNose.erase(EyeAndNose.size() - 1);
      EyeAndNose += RArms[(numArr[five]-'0')-1] + '\n';
    }
    //check torso down left arm:
    if (numArr[four] == '1' || numArr[four] == '3' || numArr[four] == '4'){
      torso = LArms[(numArr[four]-'0')-1] + torso;
    }
    //check torso down right arm:
    if (numArr[five] == '1' || numArr[five] == '3' || numArr[five] == '4'){
      torso.erase(torso.size() - 1);
      torso += RArms[(numArr[five]-'0')-1]+'\n';
    }

    //final snowman
    string snowman = head+EyeAndNose+torso+base;
    return snowman;
  }


}