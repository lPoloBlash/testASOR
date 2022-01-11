#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {

    string line;
    ifstream myFile;
    string file;

    cout << "Name file: ";
    cin >> file;

    myFile.open(file);

    if (myFile.is_open())
        cout << "Todo ok.\n";
    else
        return -1;

    int correct = 0, incorrect = 0, noAnswer = 0;

    cout << "==============================================\n";

    while (getline(myFile, line)) {

        if (line != "") {
            string question;
            string answer;
            string op1, op2, op3;
            question = line;
            getline(myFile, op1);
            getline(myFile, op2);
            getline(myFile, op3);
            getline(myFile, answer);

            cout << question << '\n';
            cout << op1 << '\n';
            cout << op2 << '\n';
            cout << op3 << '\n';

            cout.flush();
            string answerUser;
            cin >> answerUser;

            if (answerUser == answer)
                correct += 1;
            else if (answerUser == "w")
                noAnswer += 1;
            else
                incorrect += 1;

            cout << "Correct answer: " << answer << '\n';
            cout << "==============================================\n";
        }

    }

    myFile.close();

    cout << "Correct: " << correct << endl;
    cout << "Incorrect: " << incorrect << endl;
    cout << "No answer: " << noAnswer << endl;

    return 0;
}
