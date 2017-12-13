#include "includeme.h"

/* Reads commands from .txt file */
vector<string> load_commands(){
  vector<string>comm_list;
  ifstream fs;
  string command;
  fs.open("command_list.txt");

  while(getline(fs, command)){
    comm_list.push_back(command);
  }

  fs.close();
  return comm_list;
}

/* Takes care of everything concerning the validity of commands */
bool check_command(const string& command,const vector<string>&list){
  int spaces,exists;
  if((spaces = space_count(command))!=0)
    return false;

  if ((exists = check_existence(command,list))==false)
    return false;

  return true;
}


/* Counts spaces */
int space_count(const string& verify){
  int nspaces = 0;

  for (int i=0; i<verify.size();i++)
    if(verify[i] == ' ')
      nspaces++;

  return nspaces;
}

/* Checks if the command exists in the command_list.txt file */
bool check_existence(const string& command,const vector<string>&list){
  for(int i= 0;i<list.size();i++){
    if(command == list[i])
      return true;
  }
  return false;
}