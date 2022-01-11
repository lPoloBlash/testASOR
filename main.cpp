#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef  struct {
    string question;
    string answer;
    string op1, op2, op3;
} tQuestion;

typedef vector<tQuestion> tQuestions;

bool readFile (tQuestions &questions) {
    string line;
    ifstream myFile;
    string file;

    cout << "File: ";
    cin >> file;

    myFile.open(file);

    if (!myFile.is_open()) {
        cout << "File cannot be open";
        return false;
    }
    while (getline(myFile, line)) {

        if (line != "") {
            tQuestion node;
            string question;
            string answer;
            string op1, op2, op3;
            node.question = line;
            getline(myFile, node.op1);
            getline(myFile, node.op2);
            getline(myFile, node.op3);
            getline(myFile, node.answer);
            questions.push_back(node);
        }

    }

    myFile.close();
    return true;

}

void doTest (tQuestions questions, tQuestions &cQuestions, tQuestions &iQuestions, int &cA, int &nA, int &iA) {

    for (auto i = questions.begin(); i != questions.end(); ++i) {

        string answerUser;

        cout << "==============================================\n";
        cout << i->question << '\n';
        cout << i->op1 << '\n';
        cout << i->op2 << '\n';
        cout << i->op3 << '\n';
        cin >> answerUser;

        if (answerUser == i->answer) {
            cA += 1;
            cQuestions.push_back(*i);
        } else {
            if (answerUser == "w")
                nA += 1;
            else
                iA += 1;
            iQuestions.push_back(*i);
        }

        cout << "Correct answer: " << i->answer << '\n';

    }
    cout << "==============================================\n";
}

int main() {

    tQuestions questions;
    tQuestions correctAnswers;
    tQuestions incorrectAnswers;

    if (!readFile(questions))
        return -1;

    int opt;
    int correct = 0, incorrect = 0, noAnswer = 0;

    do {

        cout << "Choose an option:\n";
        cout << "1. Do test\n";
        if (noAnswer != 0)
            cout << "2. Do incorrect answers\n";
        correct = 0, incorrect = 0, noAnswer = 0;
        cin >> opt;

        if (opt == 1)
            doTest(questions, correctAnswers, incorrectAnswers, correct, incorrect, noAnswer);
        else if (opt == 2) {
            tQuestions aux;
            doTest(incorrectAnswers, correctAnswers, aux, correct, incorrect, noAnswer);
            incorrectAnswers = aux;
        }

        cout << "Correct: " << correct << endl;
        cout << "Incorrect: " << incorrect << endl;
        cout << "No answer: " << noAnswer << endl;

    } while (opt > 0 && opt < 3);



    return 0;
}
