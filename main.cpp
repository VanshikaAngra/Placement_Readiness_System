#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class Student
{
public:

    string name;
    string email;

    float cgpa;
    float aptitude;
    float coding;
    float technical;
    float communication;

    int projects;
    int certifications;
    int internships;

    float attendance;
    float interview;

    float readinessScore;

    string status;
    string career;

    void input()
    {
        cout << "\n========================================\n";
        cout << "       STUDENT PLACEMENT DETAILS\n";
        cout << "========================================\n";

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Email: ";
        getline(cin, email);

        cout << "Enter CGPA (0-10): ";
        cin >> cgpa;

        cout << "Enter Aptitude Score (0-100): ";
        cin >> aptitude;

        cout << "Enter Coding Score (0-100): ";
        cin >> coding;

        cout << "Enter Technical Knowledge (0-100): ";
        cin >> technical;

        cout << "Enter Communication Score (0-100): ";
        cin >> communication;

        cout << "Enter Number of Projects: ";
        cin >> projects;

        cout << "Enter Number of Certifications: ";
        cin >> certifications;

        cout << "Enter Number of Internships: ";
        cin >> internships;

        cout << "Enter Attendance (%): ";
        cin >> attendance;

        cout << "Enter Interview Score (0-100): ";
        cin >> interview;
    }

    void calculateScore()
    {
        float cgpaScore = (cgpa / 10) * 100;

        float projectScore = projects * 20;

        if (projectScore > 100)
            projectScore = 100;

        float certificationScore = certifications * 20;

        if (certificationScore > 100)
            certificationScore = 100;

        float internshipScore = internships * 25;

        if (internshipScore > 100)
            internshipScore = 100;

        readinessScore =
            cgpaScore * 0.15 +
            aptitude * 0.15 +
            coding * 0.15 +
            technical * 0.15 +
            communication * 0.10 +
            projectScore * 0.08 +
            certificationScore * 0.05 +
            internshipScore * 0.07 +
            attendance * 0.05 +
            interview * 0.05;

        if (readinessScore >= 80)
        {
            status = "Placement Ready";
        }
        else if (readinessScore >= 60)
        {
            status = "Almost Ready";
        }
        else
        {
            status = "Needs Improvement";
        }
    }

    void recommendCareer()
    {
        if (coding >= 80 && technical >= 75)
        {
            career = "Software Developer";
        }
        else if (aptitude >= 80 && technical >= 70)
        {
            career = "Data Analyst";
        }
        else if (technical >= 80)
        {
            career = "System / Network Engineer";
        }
        else if (coding >= 70)
        {
            career = "Web Developer";
        }
        else
        {
            career = "IT Support / Associate";
        }
    }

    void showRecommendations()
    {
        cout << "\n========================================\n";
        cout << "        IMPROVEMENT RECOMMENDATIONS\n";
        cout << "========================================\n";

        bool found = false;

        if (aptitude < 70)
        {
            cout << "- Practice quantitative and logical aptitude.\n";
            found = true;
        }

        if (coding < 70)
        {
            cout << "- Improve programming and problem-solving skills.\n";
            found = true;
        }

        if (technical < 70)
        {
            cout << "- Improve DBMS, OS, networking and technical subjects.\n";
            found = true;
        }

        if (communication < 70)
        {
            cout << "- Improve communication and presentation skills.\n";
            found = true;
        }

        if (projects < 2)
        {
            cout << "- Build at least two practical projects.\n";
            found = true;
        }

        if (certifications < 2)
        {
            cout << "- Complete relevant technical certifications.\n";
            found = true;
        }

        if (internships < 1)
        {
            cout << "- Gain practical internship experience.\n";
            found = true;
        }

        if (attendance < 75)
        {
            cout << "- Improve academic attendance.\n";
            found = true;
        }

        if (interview < 70)
        {
            cout << "- Practice mock interviews.\n";
            found = true;
        }

        if (!found)
        {
            cout << "- Excellent profile. Keep practicing and applying.\n";
        }
    }

    void display()
    {
        cout << "\n========================================\n";
        cout << "       PLACEMENT READINESS RESULT\n";
        cout << "========================================\n";

        cout << "Name              : " << name << endl;
        cout << "Email             : " << email << endl;
        cout << "CGPA              : " << cgpa << endl;
        cout << "Aptitude          : " << aptitude << "%" << endl;
        cout << "Coding            : " << coding << "%" << endl;
        cout << "Technical         : " << technical << "%" << endl;
        cout << "Communication     : " << communication << "%" << endl;
        cout << "Projects          : " << projects << endl;
        cout << "Certifications    : " << certifications << endl;
        cout << "Internships       : " << internships << endl;
        cout << "Attendance        : " << attendance << "%" << endl;
        cout << "Interview         : " << interview << "%" << endl;

        cout << "\n----------------------------------------\n";

        cout << fixed << setprecision(2);

        cout << "Readiness Score   : "
             << readinessScore << "%" << endl;

        cout << "Placement Status  : "
             << status << endl;

        cout << "Recommended Career: "
             << career << endl;

        showRecommendations();
    }
};


void saveStudent(Student s)
{
    ofstream file("students.txt", ios::app);

    if (!file)
    {
        cout << "\nUnable to open file.\n";
        return;
    }

    file << s.name << "|"
         << s.email << "|"
         << s.cgpa << "|"
         << s.aptitude << "|"
         << s.coding << "|"
         << s.technical << "|"
         << s.communication << "|"
         << s.projects << "|"
         << s.certifications << "|"
         << s.internships << "|"
         << s.attendance << "|"
         << s.interview << "|"
         << s.readinessScore << "|"
         << s.status << "|"
         << s.career
         << "\n";

    file.close();

    cout << "\nStudent data saved successfully.\n";
}


void displayAll()
{
    ifstream file("students.txt");

    if (!file)
    {
        cout << "\nNo student records found.\n";
        return;
    }

    string line;

    cout << "\n========================================\n";
    cout << "          SAVED STUDENT RECORDS\n";
    cout << "========================================\n";

    int count = 0;

    while (getline(file, line))
    {
        cout << "\n" << ++count << ". " << line << endl;
    }

    file.close();
}


int main()
{
    vector<Student> students;

    int choice;

    do
    {
        cout << "\n\n";
        cout << "========================================\n";
        cout << "   PLACEMENT READINESS PREDICTION\n";
        cout << "========================================\n";

        cout << "\n1. Add Student Assessment";
        cout << "\n2. Display Current Students";
        cout << "\n3. View Saved Records";
        cout << "\n4. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Student s;

            s.input();

            s.calculateScore();

            s.recommendCareer();

            students.push_back(s);

            s.display();

            saveStudent(s);
        }

        else if (choice == 2)
        {
            if (students.empty())
            {
                cout << "\nNo students added in current session.\n";
            }
            else
            {
                for (int i = 0; i < students.size(); i++)
                {
                    students[i].display();
                }
            }
        }

        else if (choice == 3)
        {
            displayAll();
        }

        else if (choice == 4)
        {
            cout << "\nThank you for using the system!\n";
        }

        else
        {
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}