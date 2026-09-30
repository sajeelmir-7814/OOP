#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// ======================================================
// FILE HANDLING 
// ======================================================

class FileHandler
{
private:
    string fileName;

public:

  
    FileHandler(string name)
    {
        fileName = name;
    }


      void createAndWrite()
    {
        ofstream file(fileName.c_str());

        if (!file)
        {
            cout << "Error: File could not be created." << endl;
            return;
        }

        file << "This is the first line of the file." << endl;
        file << "This is the second line of the file." << endl;
        file << "This is the third line of the file." << endl;

        file.close();

        cout << "\nFile created and three lines written successfully." << endl;
    }


  

    void readFile()
    {
        ifstream file(fileName.c_str());

        if (!file)
        {
            cout << "Error: File could not be opened." << endl;
            return;
        }

        string line;

        cout << "\n========== FILE CONTENT ==========" << endl;

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }


 
    void appendStudentInfo(string name, string rollNumber)
    {
        ofstream file(fileName.c_str(), ios::app);

        if (!file)
        {
            cout << "Error: File could not be opened." << endl;
            return;
        }

        file << "Name: " << name << endl;
        file << "Roll Number: " << rollNumber << endl;

        file.close();

        cout << "\nName and Roll Number appended successfully." << endl;
    }




    int countLines()
    {
        ifstream file(fileName.c_str());

        if (!file)
        {
            cout << "Error: File could not be opened." << endl;
            return 0;
        }

        string line;
        int lineCount = 0;

        while (getline(file, line))
        {
            lineCount++;
        }

        file.close();

        return lineCount;
    }


   

    void copyFile(string destinationFile)
    {
        ifstream source(fileName.c_str());

        if (!source)
        {
            cout << "Error: Source file could not be opened." << endl;
            return;
        }

        ofstream destination(destinationFile.c_str());

        if (!destination)
        {
            cout << "Error: Destination file could not be created." << endl;
            source.close();
            return;
        }

        string line;

        while (getline(source, line))
        {
            destination << line << endl;
        }

        source.close();
        destination.close();

        cout << "\nFile content copied successfully to "
             << destinationFile << endl;
    }
};


// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    cout << "========================================" << endl;
    cout << "       FILE HANDLING LAB" << endl;
    cout << "========================================" << endl;



    FileHandler file("notes.txt");


   

    cout << "\n========== TASK 1 ==========" << endl;


    file.createAndWrite();


    file.readFile();


    
    string name;
    string rollNumber;

    cout << "\nEnter your name: ";
    getline(cin, name);

    cout << "Enter your roll number: ";
    getline(cin, rollNumber);


    file.appendStudentInfo(name, rollNumber);


   
    cout << "\n========== UPDATED FILE ==========" << endl;
    file.readFile();


   

    cout << "\n========== TASK 2 ==========" << endl;

    int totalLines = file.countLines();

    cout << "Total number of lines in notes.txt: "
         << totalLines << endl;


    // ==================================================

    cout << "\n========== TASK 3 ==========" << endl;


    cout << "Total lines before copying: "
         << file.countLines() << endl;

   
    file.copyFile("copy.txt");


   
    FileHandler copiedFile("copy.txt");

    cout << "\n========== COPIED FILE ==========" << endl;

    copiedFile.readFile();

    cout << "\nTotal lines in copy.txt: "
         << copiedFile.countLines() << endl;



    cout << "\n========================================" << endl;
    cout << "       ALL TASKS COMPLETED" << endl;
    cout << "========================================" << endl;

    return 0;
}
