#ifndef CP5_ex12_32_h
#define CP5_ex12_32_h

#include "ex12_22.h"
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <map>
#include <set>

class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<StrBlob> input;
    std::map<string, shared_ptr<std::set<StrBlob::size_type>>> result;
};

class QueryResult {
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(const string& s, shared_ptr<std::set<StrBlob::size_type>> set,
                shared_ptr<StrBlob> v)
        : word(s), nos(set), input(v)
    {
    }

private:
    string word;
    shared_ptr<std::set<StrBlob::size_type>> nos;
    shared_ptr<StrBlob> input;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif