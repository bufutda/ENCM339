// writemat10E.cpp
// ENCM 339 Fall 2015 Lab 10 Exercise E

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>   // for isdigit
#include <climits>  // for INT_MAX

using namespace std;

bool get_pos_int(const char *s, int& n);
// REQUIRES: s points to the beginning of a C-style string.
// PROMISES:
//   If the string represents an int value >= 1, that value
//   is copied into n, and true is returned.  Otherwise, n
//   is unchanged, and false is returned.

int main(int argc, char **argv)
{
  if (argc != 4) {
    cerr << argv[0] << ": args should be NROW NCOL FILENAME" << endl;
    exit(1);
  }
  int nrow, ncol;
  if (!get_pos_int(argv[1], nrow) || !get_pos_int(argv[2], ncol)) {
    cerr << argv[0] << ": NROW and NCOL must be positive ints" << endl;
    exit(1);
  }

  ofstream out(argv[3], ios::binary);
  if (out.fail()) {
    cerr << argv[0] << ": could not open " 
	 << argv[3] << " for output." << endl;
    exit(1);
  }
  
  cout << "Writing " << nrow << " X " << ncol
       << " test matrix to binary file " << argv[3] << " ... " << endl;
  int *mat_data = new int[nrow * ncol];
  for (int r = 0; r < nrow; r++)
    for (int c = 0; c < ncol; c++)
      mat_data[r * ncol + c] = 100000 * (r + 1) + 2 * c + 1;
  out.write(reinterpret_cast<const char*>(&nrow), sizeof(int));
  out.write(reinterpret_cast<const char*>(&ncol), sizeof(int));
  out.write(reinterpret_cast<const char*>(mat_data), 
	    nrow * ncol * sizeof(int));
  out.close();

  return 0;
}

bool get_pos_int(const char *s, int& n)
{
  int len;
  for (len = 0; s[len] != '\0'; len++)
    if (!std::isdigit(s[len]))
      return false;
  if (len >= 11)
    return false;
  long long int lli = atoll(s);
  if (lli == 0 || lli > INT_MAX)
    return false;
  n = int(lli);
  return true;
}
