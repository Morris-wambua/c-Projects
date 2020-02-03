#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<unistd.h>

static const std::string jpg = "jpg";
static const std::string jpeg = "jpeg";
static const std::string gif = "gif";


int download(std::string inUrl, std::string outHtmlFile) {
  using namespace std;
  string wget = "wget ";
  string cmd = wget + " -O " + outHtmlFile + " " + inUrl + " > /dev/null 2>&1";
  int status = system(cmd.c_str());
  return status;
}

bool compareCaseInsensitive(const std::string& s1, const std::string& s2) {
  if (s1.size() != s2.size()) {
    return false;
  }
  int thesize = s1.size();
  for(int i = 0; i < thesize; i++) {
    if (tolower(s1[i]) != tolower(s2[i])) {
      return false;
    }
  }
  return true;
}

bool findLink(std::string& file, int tagsize, int i, std::string& link) {
  using namespace std;
  char terminator;
  if (file[i + tagsize] == '\"') {
    terminator = '\"';
  } else {
    terminator = ' ';
  }
  int j = i + tagsize + 1;
  while(file[j] != terminator) {
    j++;
  }
  if (terminator == '\"') {
    link = file.substr(i + tagsize + 1, j - i - tagsize - 1);
  } else {
    link = file.substr(i + tagsize + 1, j - i - tagsize - 2);
  }
  int pos = link.find_last_of('.');
  if (pos != link.npos) {
    string ext = link.substr(pos + 1);
    if (compareCaseInsensitive(ext, jpg) ||
        compareCaseInsensitive(ext, jpeg) ||
        compareCaseInsensitive(ext, gif)) {
      return true;
    }
  }
  return false;
}

int main(int argc, char** argv) {
  using namespace std;
  stringstream htmlCode;
  string theUrl = "http://www.enseignement.polytechnique.fr/";
  string outFile = "index.html";
  const char* openFile;
  if (argc < 2) {
    download(theUrl, outFile);
    openFile = outFile.c_str();
  } else {
    openFile = argv[1];
  }
  ifstream ifs(openFile);
  if (!ifs) {
    cerr << "error: cannot open file " << openFile << endl;
    exit(1);
  }
  char c;
  while(!ifs.eof()) {
    ifs.get(c);
    htmlCode << c;
  }
  ifs.close();

  string file = htmlCode.str();
  string tag1 = "href=";
  string tag2 = "src=";
  string key1;
  string key2;
  int fileLength = file.size();
  string link;
  char terminator;
  for(int i = 0; i < fileLength; i++) {
    key1 = file.substr(i, tag1.size());
    if (compareCaseInsensitive(key1, tag1)) {
      if (findLink(file, tag1.size(), i, link)) {
        cout << link << endl;
      }
    }
    key2 = file.substr(i, tag2.size());
    if (compareCaseInsensitive(key2, tag2)) {
      if (findLink(file, tag2.size(), i, link)) {
        cout << link << endl;
      }
    }
  }

  return 0;
}
