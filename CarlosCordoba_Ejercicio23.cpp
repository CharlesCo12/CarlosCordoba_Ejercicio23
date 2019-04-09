#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
 
string lee(string filename);
void split(const string& s, char c, vector<string>& v);

int main () {
  string filename;
  string filename1;
  filename = "valores_x.txt";
  filename1 = "valores_y.txt";
  string dataX=lee(filename);
  string dataY=lee(filename1);
  vector<string> datosX;
  vector<string> datosY;
    
  split(dataX,';',datosX);
  split(dataY,';',datosY);
  double x=0.0;
  double y=0.0;
  for (int i = 0; i < datosX.size()-1; ++i) {
      x=x+stod(datosX[i]);
      y=y+stod(datosY[i]);
   }
   cout<< "Suma de X" << endl;
   cout << x << endl;
   cout<< "Suma de Y" << endl;
   cout << y << endl;
  return 0;
}

string lee(string filename){
  ifstream infile; 
  string line;
  string data;
  infile.open(filename); 
  getline(infile, line);
  while(infile){
    data = data + line + ';';
    getline(infile, line);
  }
    
  return data;  
  infile.close();
}
void split(const string& s, char c,
           vector<string>& v) {
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}