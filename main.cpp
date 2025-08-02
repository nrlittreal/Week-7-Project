#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int QuestionNum = 20;
const double PassingGrade = 70.0;

void getGrades(char[], char[]);
int CheckGrades(char[], char[], int[], char[QuestionNum][2]);
void DisplayGrades(int[], char[QuestionNum][2], int);

int main()
{
    char AnswerKey[QuestionNum];
    char StudentKey[QuestionNum];
    int IncorrectAnswer[QuestionNum];
    char AnswerFeedback[QuestionNum][2];
    int IncorrectNum = 0;

    getGrades(AnswerKey, StudentKey);

    IncorrectNum = CheckGrades(AnswerKey, StudentKey, IncorrectAnswer, AnswerFeedback);

    DisplayGrades(IncorrectAnswer, AnswerFeedback, IncorrectNum);

    return 0;
}

// Reads answers from files into arrays
void getGrades(char AnswerKey[], char StudentKey[])
{
    ifstream inputfile;

    inputfile.open("CorrectAnswers.txt");

    if (!inputfile)
    {
        cerr << "The AnswerKey file failed to open." << endl;
        exit(1);
    }

    for (int i = 0; i < QuestionNum; i++)
    {
        inputfile >> AnswerKey[i];
    }
    inputfile.close();

    inputfile.open("StudentAnswers.txt");

    if (!inputfile)
    {
        cerr << "The StudentKey file failed to open." << endl;
        exit(1);
    }

    for (int i = 0; i < QuestionNum; i++)
    {
        inputfile >> StudentKey[i];
    }
    inputfile.close();
}

// Compares answers and records incorrect responses
int CheckGrades(char AnswerKey[], char StudentKey[], int IncorrectAnswer[], char AnswerFeedback[QuestionNum][2])
{
    int IncorrectAmount = 0;

    for (int i = 0; i < QuestionNum; i++)
    {
        if (AnswerKey[i] != StudentKey[i])
        {
            AnswerFeedback[IncorrectAmount][0] = AnswerKey[i];
            AnswerFeedback[IncorrectAmount][1] = StudentKey[i];
            IncorrectAnswer[IncorrectAmount] = i + 1;
            IncorrectAmount++;
        }
    }

    return IncorrectAmount;
}

// Displays the results
void DisplayGrades(int IncorrectAnswer[], char AnswerFeedback[QuestionNum][2], int IncorrectNum)
{
    cout << fixed << setprecision(2);

    cout << "Exam Report:\n";
    cout << "Number of Incorrect Answers: " << IncorrectNum << endl;

    cout << "Missed Questions and Correct Answers:\n";
    cout << "Question\tCorrect Answer\tStudent Answer\n";

    for (int i = 0; i < IncorrectNum; i++)
    {
        cout << IncorrectAnswer[i] << "\t\t" << AnswerFeedback[i][0] << "\t\t" << AnswerFeedback[i][1] << endl;
    }

    double grade = (QuestionNum - IncorrectNum) / (double)QuestionNum * 100;

    cout << "Final Grade: " << grade << "%\n";

    if (grade >= PassingGrade)
    {
        cout << "Student passed the exam.\n";
    }
    else
    {
        cout << "Student failed the exam.\n";
    }
}
