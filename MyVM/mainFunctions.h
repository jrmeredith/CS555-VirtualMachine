#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include <string>
#include <fstream>

void welcome();
void pauseScreen();
bool isFile(const char *name);
void startProcess(const char *dir);
void userCommands(std::string dir);
void instructions();

#endif