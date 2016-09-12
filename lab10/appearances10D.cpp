// appearances10D.cpp
// ENCM 339 Fall 2015 Lab 10 Exercise D

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>  // This is for the sort function.
#include <cstdlib>
#include <cctype>     // For isspace.


using std::cin; using std::cout; using std::cerr;
using std::endl;
using std::string;
using std::size_t;

void try_to_get_name(const char *prompt_part, string& name);
// Prompts user to supply a file name with string found
// by prompt_part inserted into the prompt. If input succeeds,
// the file name is written into the parameter name.

string trim(const string& src);
// Returns a string based on src, with leading and trailing whitespace
// removed.

int main()
{
  string in_file_name;
  try_to_get_name("input", in_file_name);
  std::ifstream ifs(in_file_name.c_str());
  if (ifs.fail()) {
    cerr << "\nCould not open " << in_file_name << " for input!" << endl;
    std::exit(1);
  }
  std::vector<int> v;
  int input_number;
  while (true) {
    ifs >> input_number;
    if (ifs.fail())  // Note: Reason for fail not checked.
      break;
    v.push_back(input_number);
  }
  ifs.close();

  string out_file_name;
  try_to_get_name("output", out_file_name);
  std::ofstream ofs(out_file_name.c_str());
  if (ofs.fail()) {
    cerr << "\nCould not open " << out_file_name << " for output!" << endl;
    std::exit(1);
  }

  // Sort vector from smallest to largest. This uses the sort function
  // template in the <algorithm> library header.
  std::sort(v.begin(), v.end());


  // BEGIN code to write to the output file.
  // (This code is very slightly defective!)

  // Because v is now sorted, all appearances of any given value will
  // have consecutive indexes within v.  That makes it easy to count
  // how many times the value appears within v.

  int value_to_print = v.at(0);
  int appearance_count = 1;
  for (size_t i = 1; i < v.size(); i++) {
    if (v.at(i) == value_to_print)
      appearance_count++;
    else {
      ofs << value_to_print << ' ' << appearance_count << endl;
      value_to_print = v.at(i);
      appearance_count = 1;
    }
    //if (i == v.size() - 1)
    //    ofs << value_to_print << ' ' << appearance_count << endl;
  }
  //ofs << value_to_print << ' ' << appearance_count << endl;

  // END code to write to the output file.

  ofs.close();
  return 0;
}

void try_to_get_name(const char *prompt_part, string& name)
{
  cout << "Please enter the name of the " << prompt_part
       << " file:" << endl;
  getline(cin, name);
  if (cin.fail()) {
    cerr << "\nError trying to read file name!" << endl;
    std::exit(1);
  }
  name = trim(name);
}

string trim(const string& src)
{
  size_t src_len = src.length();
  size_t first_nws = 0;
  while (first_nws < src_len && std::isspace(src[first_nws]))
    first_nws++;

  if (first_nws == src_len) // Nothing but whitespace in src?
    return string();	    // Return empty string.

  size_t last_nws = src_len - 1;
  while (std::isspace(src[last_nws]))
    last_nws--;
  return string(src, first_nws, last_nws + 1 - first_nws);
}
