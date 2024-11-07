#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

#define SOFT_HYPHEN "\xc2\xad"
#define ZERO_WIDTH_SPACE "\xe2\x80\x8b"

int main(int argc,const char* argv[])
{
  if(argc != 2)
  {
    cout << ("usage: cmiyc <filename>") << endl;
    return 0;
  }
  ifstream fin(argv[1]);
  if(!fin)
  {
    cout << "error opening file!" << endl;
    return 0;
  }
  
  char ch;
  ofstream out("generated.txt");
  
  while(fin.get(ch))
  {
    switch(ch)
    {
      case 'A':
        out << "\xD0\x90"; // Cyrillic A
        break;
      case 'E':
        out << "\xD0\x95"; // Cyrillic E
        break;
      case 'O':
        out << "\xD0\x9E"; // Cyrillic O
        break;
      case 'P':
        out << "\xD0\xA0"; // Cyrillic P
        break;
      case 'C':
        out << "\xD0\xA1"; // Cyrillic C
        break;
      case 'K':
        out << "\xE2\x84\xAA"; //Kelvin sign
        break;
      case ';':
        out << "\xCD\xBE"; // Greek question mark
        break;
      case ':':
        out << "\xE2\x88\xB6"; // Ratio
        break;
      case 'V':
        out << "\xE2\x85\xA4"; // Roman five
        break;
      case ' ':
        out << ZERO_WIDTH_SPACE << ' ';
        break;
      default:
        out << ch << SOFT_HYPHEN;
    }
  }
  fin.close();
  out.close();
}
