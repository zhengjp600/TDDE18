#ifndef EDITOR_H
#define EDITOR_H
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

class editor
{
private:
  std::vector<std::string> text;
  std::vector<std::string> argument;
  std::string file_name;
  std::map<std::string, int> dictionary;
  void checkArg(int argc) const; // Done
  void executeArg(std::string const &Arg);
  void readArg(std::string const &Arg, std::string &flag, std::string &parameter);
  void readFile();                                             // Done
  void writeFile();                                            // Done
  int longestWord(std::vector<std::string> *const text) const; // Done
  void createDictionary();                                     // Done
  void print();                                                // Done
  void table();                                                // Done
  void frequency();                                            // Done
  void substitute(std::string const &parameter);               // Done
  void remove(std::string const &parameter);                   // Done

public:
  editor(int argc, char **argv);
  ~editor();
  void executeProgram(std::vector<std::string> &argument);
};

#endif