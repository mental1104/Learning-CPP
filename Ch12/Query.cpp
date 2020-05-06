#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<memory>
#include<set>
#include<sstream>
#include<fstream>

using namespace::std;
class QueryResult;

class TextQuery
{
public:
    using LineNo = vector<string>::size_type;//
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;//-------------------------------------

private:
    shared_ptr<vector<string>> file;//input
    map<string, shared_ptr<set<LineNo>>> wm;//map
};

TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while(getline(is,text)){
        file->push_back(text);
        int n = file->size()-1;//LineNo.
        istringstream line(text);

        string word;
        while(line >> word){
            auto &lines = wm[word];
            if(!lines)
                lines.reset(new set<LineNo>);
            lines->insert(n);
        }
    }//file -> map<word, frequency>
}

class QueryResult{
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);

    QueryResult(const string& s, 
                shared_ptr<set<TextQuery::LineNo>> p,
                shared_ptr<vector<string>> f)
        : sought(s), lines(p), file(f)
    {
    }

private:
    string sought;
    shared_ptr<set<TextQuery::LineNo>> lines;//line
    shared_ptr<vector<string>> file;//input
};

QueryResult
TextQuery::query(const string &sought) const
{
    static shared_ptr<set<LineNo>> nodata(new set<LineNo>);

    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}


std::ostream& print(std::ostream& os, const QueryResult& qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " " 
       << "times" << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 <<") "
           << *(qr.file->begin() + num) << endl;
    return os;
}


void runQueries(ifstream &infile)
{
    TextQuery tq(infile);

    while(true) {
        cout << "enter word to look for, or q to quit: ";
        string s;

        if(!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(){
    ifstream ifs("book.txt");
    runQueries(ifs);
    return 0;
}