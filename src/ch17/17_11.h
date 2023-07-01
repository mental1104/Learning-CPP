#ifndef ex17_11h
#define ex17_11h

#include <bitset>
#include <string>

using size = std::size_t;
template <size N> class QuizResponses {
public:
    QuizResponses() = default;
    QuizResponses(const std::string& s) : answers(s) {}

   
    void answer(size n, bool v) { answers.set(n - 1, v); }

    
    size score(const QuizResponses& correct)
    {
        return (this->answers ^ correct.answers).flip().count() * 1.0 / N * 100;
    }

private:
    std::bitset<N> answers;
};

#endif