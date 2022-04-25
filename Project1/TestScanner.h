//filename TestScanner.h
#include <string>
#include "Scanner.h"
#ifndef TESTSCANNER_H
#define TESTSCANNER_H
using namespace std;
class TestScanner
{
private:
Scanner scan;

public:

void useScanner(const std::string filename);

};

#endif