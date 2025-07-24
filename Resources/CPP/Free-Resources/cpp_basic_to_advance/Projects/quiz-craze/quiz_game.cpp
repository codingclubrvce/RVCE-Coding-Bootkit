#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <limits>

#ifdef _WIN32
#include <Windows.h>
#else
#include <cstdlib>
#endif

using namespace std;
using namespace chrono;

struct Question
{
    string question, optionA, optionB, optionC, optionD, correctAnswer;
};

// Declare these variables outside runQuiz to make them accessible in the main function
float totalScore = 0;
int correctAnswers = 0;
int wrongAnswers = 0;
int unattemptedAnswers = 0;
time_point<high_resolution_clock> start, stop;

void displayQuestion(const Question &q)
{
    cout << q.question << "\n"
         << q.optionA << "\n"
         << q.optionB << "\n"
         << q.optionC << "\n"
         << q.optionD << endl;
}

vector<Question> readQuestions(const string &fileName)
{
    ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        cerr << "Error opening file." << endl;
        exit(1);
    }

    vector<Question> questions;
    string line;
    while (getline(inFile, line))
    {
        if (line.find("Question") != string::npos)
        {
            Question q;
            getline(inFile, q.question);
            getline(inFile, q.optionA);
            getline(inFile, q.optionB);
            getline(inFile, q.optionC);
            getline(inFile, q.optionD);
            getline(inFile, q.correctAnswer);
            questions.push_back(q);
        }
    }
    inFile.close();
    return questions;
}

int getQuizTimeLimit()
{
    int timeLimit;
    cout << "Choose quiz duration:\n1. 1 minute\n2. 2 minutes\n3. Custom time\nEnter your choice: ";
    cin >> timeLimit;

    switch (timeLimit)
    {
    case 1:
        return 60;
    case 2:
        return 120;
    case 3:
        cout << "Enter custom time limit in seconds: ";
        cin >> timeLimit;
        return timeLimit;
    default:
        cout << "Invalid choice. Using default time limit of 1 minute.\n";
        return 60;
    }
}

bool getNegativeMarkingOption()
{
    char choice;
    cout << "Do you want negative marking for wrong answers? (Y/N): ";
    cin >> choice;
    cout << endl;
    return (choice == 'Y' || choice == 'y');
}

void runQuiz(const vector<Question> &questions, const string &quizName, int quizTimeSeconds, bool enableNegativeMarking)
{
    totalScore = 0;
    correctAnswers = 0;
    wrongAnswers = 0;
    unattemptedAnswers = 0;
    cin.ignore();

    start = high_resolution_clock::now(); // Start the timer

    for (const auto &q : questions)
    {
        auto elapsed = duration_cast<seconds>(high_resolution_clock::now() - start).count();
        if (elapsed >= quizTimeSeconds)
        {
            cout << "Time's up! Quiz ended.\n";
            break;
        }

        displayQuestion(q);
        cout << "Enter your answer (A, B, C, or D): ";

        string userAnswer;
        getline(cin, userAnswer);

        if (userAnswer.size() == 1 && (userAnswer[0] == 'A' || userAnswer[0] == 'B' || userAnswer[0] == 'C' || userAnswer[0] == 'D'))
        {
            if (userAnswer[0] == q.correctAnswer[0])
            {
                cout << "Correct!" << endl;
                totalScore += 10;
                correctAnswers++;
            }
            else
            {
                cout << "Incorrect. The correct answer is: " << q.correctAnswer << endl;
                wrongAnswers++;
                if (enableNegativeMarking)
                {
                    totalScore -= 2.5; // 1/4 negative marking for each wrong answer
                }
            }
        }
        else
        {
            cout << "Invalid input. Please enter A, B, C, or D." << endl;
            unattemptedAnswers++;
        }

        cout << endl; // Leave a line after displaying each answer
    }

    stop = high_resolution_clock::now(); // Stop the timer
}

void displaySubjectMenu()
{
    cout << "\n\t\tSubject Menu\n\n1. Physics\n2. Chemistry\n3. C++\n4. Computer Science\n5. General Knowledge\n6. Indian Constitution\n\n";
}

int main()
{
    int mainMenuChoice, subjectChoice;
    int quizTimeLimit; // Move the declaration outside the switch statement
    bool enableNegativeMarking;
    system("cls");
    do
    {
        cout << "\n\t\tMAIN MENU\n\n1. Play Quiz\n2. Exit\n\nEnter your choice: ";
        cin >> mainMenuChoice;

        switch (mainMenuChoice)
        {
        case 1:
            system("cls"); // Clear the screen after the first menu choice
            displaySubjectMenu();
            cout << "Enter the number corresponding to the subject: ";
            cin >> subjectChoice;
            cout << "\n\n";

            system("cls");
            cout << "\t\tQuiz customizations\n\n";
            quizTimeLimit = getQuizTimeLimit(); // Move the assignment here
            cout << endl;
            enableNegativeMarking = getNegativeMarkingOption();
            system("cls");
            cout << "\t\tQUIZ STARTS NOW !!\n\n";

            switch (subjectChoice)
            {
            case 1:
                runQuiz(readQuestions("PHY.txt"), "Physics", quizTimeLimit, enableNegativeMarking);
                break;
            case 2:
                runQuiz(readQuestions("CHEM.txt"), "Chemistry", quizTimeLimit, enableNegativeMarking);
                break;
            case 3:
                runQuiz(readQuestions("C++.txt"), "C++", quizTimeLimit, enableNegativeMarking);
                break;
            case 4:
                runQuiz(readQuestions("CS.txt"), "Computer Science", quizTimeLimit, enableNegativeMarking);
                break;
            case 5:
                runQuiz(readQuestions("GK.txt"), "General Knowledge", quizTimeLimit, enableNegativeMarking);
                break;
            case 6:
                runQuiz(readQuestions("IC.txt"), "Indian Constitution", quizTimeLimit, enableNegativeMarking);
                break;
            default:
                cout << "Invalid subject choice. Please enter a number between 1 and 5.\n\n";
                break;
            }

            // Display Analysis Report after the quiz
            cout << "Do you want to see the Analysis Report? (Y/N): ";
            char reportChoice;
            cin >> reportChoice;
            if (reportChoice == 'Y' || reportChoice == 'y')
            {
                system("cls");
                cout << "\t\t   ANALYSIS REPORT\n";
                cout << "----------------------------------------------------\n";
                // You can include more details in the analysis report if needed

                cout << "\t\tCorrect Answers: " << correctAnswers << endl;
                cout << "\t\tWrong Answers: " << wrongAnswers << endl;
                cout << "\t\tUnattempted Answers: " << unattemptedAnswers << endl;
                cout << "\t\tTotal Score: " << totalScore << " points\n";
                cout << "\t\tTime Taken: " << duration_cast<seconds>(stop - start).count() << " seconds\n";
                cout << "----------------------------------------------------\n\n";
            }
            break;
        case 2:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter 1 or 2.\n\n";
            break;
        }

    } while (mainMenuChoice != 2);

    return 0;
}
