#ifndef GENERAL_H
#define GENERAL_H

// Class for a general member (could be Student or Faculty)

#include <string>
using namespace std;

class General {
    public:
        General();
        General(string name, string id, string level);
        ~General();
        string GetName();
        string GetId();
        string GetLevel();
        void PrintInfo();

        string name;
        string id;
        string level;
};

/*
General()

Default constructor for
General object.

Param: n/a
Return: n/a
*/
General::General() {
    name = "NULL";
    id = "NULL";
    level = "NULL";
}

/*
General()

Overloaded constructor for 
General object. Sets name,
id, and level.

Param: string name, string id, string level
Return: n/a
*/
General::General(string name, string id, string level) {
    this->name = name;
    this->id = id;
    this->level = level;
}

/*
~General()

Destructor for General
class. Does nothing.

Param: n/a
Return: n/a
*/
General::~General() {}

/*
GetName()

Returns name of
student/faculty
(inherited).

Param: n/a
Return: string name
*/
string General::GetName() {
    return name;
}

/*
GetId()

Returns id of
student/faculty
(inherited).

Param: n/a
Return: string id
*/
string General::GetId() {
    return id;
}

/*
GetLevel()

Returns level of
student/faculty
(inherited).

Param: n/a
Return: string level
*/
string General::GetLevel() {
    return level;
}

#endif
