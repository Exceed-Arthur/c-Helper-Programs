#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;


const string ogFileName = "itoven_file_list_one.txt";
const string newFileName = "itoven_file_list_NEW.txt";


void SplitString(string s, vector<string> &v){

	string temp = "";
	for(int i=0;i<s.length()-1;++i){
    int j = i + 1;
		if (s[i] == ',' && s[j] == ' ') {
			v.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(s[i]);
		}

	}
	v.push_back(temp);
}

void PrintVector(vector<string> v){
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<endl;
	cout<<"\n";
}

bool StringContains(string s, string t) {
  return boost::algorithm::contains(s, t);
}

void FilterVector(vector<string> &v, string filterPhrase){
  vector<string> heapVector;
  for(int i=0;i<v.size();++i) {
    cout << endl << i;
		if (StringContains(v.at(i), filterPhrase)) {
      //v.erase(std::next(v.begin(), i), std::next(v.begin(), i+1));
      heapVector.push_back(v.at(i));
      cout << v.at(i) << endl;
    }
  }
  v = heapVector;
}



int main()
{

  // Initialize array of pointer
  const char* scaleNames[7] = { "Phrygian", "Dorian", "Lydian", "Locrian",
                            "Harmonic Minor", "Natural Minor", "Melodic Minor"};
  const char* keyNames[23] = { "A", "Ab", "A#","B", "Bb", "B#","C", "Cb", "C#",
               "D", "Db", "D#","E", "Eb", "E#","F", "Fb", "F#","G", "Gb", "G#"};
  const char* signatureNames[8] = { "Two Two", "Two Four","Three Four", "Four Two", "Four Four","Four Eight", "Five Four",
                            "Five Eight"};

  std::ifstream ifs(ogFileName); // Incoming File Stream
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) ); // Copy to std::string
  vector<string> iTovenObjectList;
  SplitString(content, iTovenObjectList); // Split after delimiter to std::vector<int> v;
  vector<string> phrygianLiteralVector = iTovenObjectList;
  FilterVector(phrygianLiteralVector, "Phrygian");

  vector<string> dorianLiteralVector = iTovenObjectList;
  FilterVector(dorianLiteralVector, "Dorian");

  vector<string> locrianLiteralVector = iTovenObjectList;
  FilterVector(locrianLiteralVector, "Locrian");

  vector<string> lydianLiteralVector = iTovenObjectList;
  FilterVector(lydianLiteralVector, "Lydian");

  vector<string> harmonicMinorLiteralVector = iTovenObjectList;
  FilterVector(harmonicMinorLiteralVector, "Harmonic Minor");

  vector<string> naturalMinorLiteralVector = iTovenObjectList;
  FilterVector(naturalMinorLiteralVector, "Natural Minor");

  vector<string> melodicMinorLiteralVector = iTovenObjectList;
  FilterVector(melodicMinorLiteralVector, "Melodic Minor");

  PrintVector(phrygianLiteralVector);
  PrintVector(dorianLiteralVector);
  PrintVector(locrianLiteralVector);
  PrintVector(lydianLiteralVector);
  PrintVector(harmonicMinorLiteralVector);
  PrintVector(naturalMinorLiteralVector);
  PrintVector(melodicMinorLiteralVector);



  return 0;
}
