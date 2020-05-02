

string make_plural(size_t ctr, const string& word, const string &ending){
    return (ctr > 1)? word +ending : word;
}

const string& shorterString(const string &s1, const string &s2){
    return s1.size()<=s2.size()?s1:s2;
}

