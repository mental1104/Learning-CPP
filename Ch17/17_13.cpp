#include "17_11.h"
#include <iostream>

int main()
{
    QuizResponses<10> simple_quiz_answers("1100110101");

    QuizResponses<100> complicated_quiz_answers;
    complicated_quiz_answers.answer(1, true);
    complicated_quiz_answers.answer(2, false);
    complicated_quiz_answers.answer(3, true);

    QuizResponses<10> simple_quiz_correct("1010101010");
    std::cout << simple_quiz_answers.score(simple_quiz_correct) << std::endl;
}