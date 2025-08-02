#include <iostream>
#include<fstream>
#include<iomanip>

using namespace std;

const double PassingGrade = 70.0;
const int QuestionNum = 20;

void getGrades(char[], char[]);
int CheckGrades(char[], char[], char[], char[QuestionNum][2]);
void DisplayGrades(char[], char[QuestionNum][2], int);

int main()
{
  char AnswerKey[QuestionNum];
  char StudentKey[QuestionNum];
  char IncorrectAnswer[QuestionNum];
  char AnswerFeedback[QuestionNum][2];
  int IncorrectNum = 0;

  getGrades(AnswerKey, StudentKey);

  IncorrectNum = CheckGrades(AnswerKey, StudentKey, IncorrectAnswer, AnswerFeedback);

  DisplayGrades(IncorrectAnswer, AnswerFeedback, IncorrectNum);

  return 0;
}


void getGrades(char AnswerKey[], char StudentKey[])
{
  
}