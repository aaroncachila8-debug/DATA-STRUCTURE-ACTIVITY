#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream> 
#include <random>


using namespace std;

// Menu functions
void learn();
void quiz();
void miniGames();
void rewards();
void exitProgram();

// learn functions
void datalearn();
void infolearn();
void rizallearn();
void discretelearn();
void stslearn();

//quiz function
void dataquiz();
void infoquiz();
void rizalquiz();
void discretequiz();
void stsquiz();

// mini game function
void wscramble();
void tictactoe();
void rockpaperscissor();

// tic tac toe
void tttoevscom();
void tttoe2pl();

void clearScreen() {
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif
}

void loading() {
    cout <<"\n\n\n\n\n\n\n\n\n\n";
cout << "\t\t\t ";
cout << "Loading";
for (int i = 0; i < 5; i++) {
cout << ".";
cout.flush();
this_thread::sleep_for(chrono::milliseconds(500));
}

}

void exiting() {
    cout <<"\n\n\n\n\n\n\n\n\n\n";
cout << "\t\t\t ";
cout << "Exiting";
for (int i = 0; i < 5; i++) {
cout << ".";
cout.flush();
this_thread::sleep_for(chrono::milliseconds(500));
}

}

void checking() {
    cout <<"\n\n\n\n\n\n\n\n\n\n";
cout << "\t\t\t ";
cout << "Checking";
for (int i = 0; i < 5; i++) {
cout << ".";
cout.flush();
this_thread::sleep_for(chrono::milliseconds(500));
}
}

void opening() {
    cout <<"\n\n\n\n\n\n\n\n\n\n";
cout << "\t\t\t ";
cout << "Opening the System";
for (int i = 0; i < 5; i++) {
cout << ".";
cout.flush();
this_thread::sleep_for(chrono::milliseconds(500));
}
}
void typewriter(string text, int delay_ms = 30) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
    cout << endl;
}


int points = 0;
int stars = 0;
bool WordScrambleUnlocked = false;
bool TicTacToeUnlocked = false;
bool RockPaperScissorsUnlocked = false;
bool hasReadData = false;
bool hasReadInfo= false;
bool hasReadRizal = false;
bool hasReadDiscrete= false;
bool hasReadSTS= false;
bool passeddata=false;
bool passedinfo=false;
bool passedrizal=false;
bool passeddiscrete=false;
bool passedsts=false;

// Function to convert points to stars (2 points = 1 star)
void convertPointsToStars() {
if (points >= 2) {
int convertibleStars = points / 2;
cout << "You have " << points << " points. You can convert to " << convertibleStars << " stars.\n";
cout << "How many stars do you want to convert? (Enter 0 to cancel): ";
int convertAmount;
cin >> convertAmount;
if (convertAmount > 0 && convertAmount <= convertibleStars) {
stars += convertAmount;
points -= convertAmount * 2;
cout << "Converted! You now have " << stars << " stars and " << points << " points.\n";
} else if (convertAmount > convertibleStars) {
cout << "\033[3;1;91mNot enough points!\033[0m\n";
}
} else {
cout << "\033[3;1;91mNot enough points to convert (need at least 2).\033[0m\n";
}
cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}

// Function to check and unlock mini games
void checkUnlocks() {
    cout<<"\033[3;1;92m";
if (stars >= 5 && !WordScrambleUnlocked) {
WordScrambleUnlocked = true;
cout << "Unlocked: Word Scramble!\n";
stars -= 5;
}
if (stars >= 15 && !TicTacToeUnlocked) {
TicTacToeUnlocked = true;
cout << "Unlocked: Tic Tac Toe!\n";
stars -= 15;
}
if (stars >= 25 && !RockPaperScissorsUnlocked) {
RockPaperScissorsUnlocked = true;
cout << "Unlocked: Rock Paper Scissors!\n";
stars -= 25;
cout<<"\033[0m";
}
}

void saveProgress() {
    ofstream file("progress.txt");
    if (file.is_open()) {
        file << points << endl;
        file << stars << endl;
        file << hasReadData<< endl;
        file << hasReadSTS<< endl;
        file<< hasReadDiscrete<< endl;
        file << hasReadRizal<< endl;
        file << hasReadInfo<< endl;
        file << passedsts << endl;
        file << passeddiscrete << endl;
        file << passedrizal << endl;
        file << passedinfo << endl;
        file << passeddata << endl;
        file << WordScrambleUnlocked << endl;
        file << TicTacToeUnlocked << endl;
        file << RockPaperScissorsUnlocked << endl;
        file.close();
        cout << "\033[3;1;92mProgress saved successfully!\033[0m\n";
    } else {
        cout << "\033[3;1;91mError saving progress.\033[0m\n";
    }
}

void loadProgress() {
    ifstream file("progress.txt");
    if (file.is_open()) {
        file >> points;
        file >> stars;
        file >> hasReadData;
        file >> hasReadSTS;
        file >> hasReadDiscrete;
        file >> hasReadRizal;
        file >> hasReadInfo;
        file >> passeddata;
        file >> passedinfo;
        file >> passedrizal;
        file >> passeddiscrete;
        file >> passedsts;
        file >> WordScrambleUnlocked;
        file >> TicTacToeUnlocked;
        file >> RockPaperScissorsUnlocked;
        file.close();
        string texts[] = {"\033[3;1;92mProgress loaded successfully!\033[0m\n"
        };
        for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
    typewriter(texts[i], 30);
}
    } else {
        string texts[] = {"\033[3;1;91mNo previous progress found. Starting fresh.\033[0m\n"
        };
        for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
    typewriter(texts[i], 30);
}
    }
}

int main() {
    opening();
    clearScreen();
    cout <<"\n\n\n\n\n\n\n\n\n\n";
cout << "\t\t\t ";
    string texts[] = { "WELCOME IN BRAINBATTLE!\n", "A sytem to train your brain, beat the quizzes and unlock the fun"
    };
    for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
    typewriter(texts[i], 30);
}
cout << "\nPress Enter to start...";
    cin.ignore(); 
    cin.get();   
clearScreen();
    loadProgress();
    clearScreen();
int choice;
do {
cout<<"\033[1;33m====================\t";
      cout << "MAIN MENU\t";
             cout<< "====================\033[0m\n";
cout << "\033[7mPoints: " << points << " | Stars: " << stars << "\n\n\033[0m";
cout << "\033[36m1. Learn\n";
cout << "2. Quiz\n";
cout << "3. Mini Games\n";
cout << "4. Rewards\n";
cout << "5. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
cout<<"\033[0m";
clearScreen();

if (choice != 5) {
loading();
clearScreen();
}

else {
exiting();
clearScreen();
}

if(cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "\033[3;1;90mInvalid choice!\033[0m\n";
        cout << "\nPress Enter to go back...";
        cin.get();
        clearScreen();
        continue; 
    }

switch(choice) {  
        case 1:  
            learn();  
            break;  
        case 2:  
            quiz();  
            break;  
        case 3:  
            miniGames();  
            break;  
        case 4:  
            rewards();  
            break;  
        case 5:  
            exitProgram();  
            break;  
        default:  
            cout << "\033[3;1;90mInvalid choice! Please try again.\n";  
            cout << "\nPress Enter to go back...\033[0m";
    cin.ignore(); 
    cin.get();    
    clearScreen();
    
    }  
} while(choice != 5);  
  
return 0;

}


void learn() {
int choice;
do {
cout<<"\033[1;35m====================\t";
      cout << "LEARN SECTION\t";
             cout<<"====================\n\033[0m";
cout << "\033[36m1. Data Structures\n";
cout << "2. Information Management\n";
cout << "3. Rizal\n";
cout << "4. Discrete Math\n";
cout << "5. STS\n";
cout << "6. Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cout<<"\033[0m";
    clearScreen();
    loading();
    clearScreen();

    if(cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "\033[3;31mInvalid choice!\n";
        cout << "\nPress Enter to go back...\033[0m";
        cin.get();
        clearScreen();
        continue; 
    }

    switch(choice) {  
        case 1:  
            datalearn();  
            break;  
        case 2:  
            infolearn();  
            break;  
        case 3:  
            rizallearn();  
            break;  
        case 4:  
            discretelearn();  
            break;  
        case 5:  
            stslearn();  
            break;  
        case 6:  
            return;  
        default:  
            cout << "\033[3;1;91mInvalid choice!\n";  
            cout << "\nPress Enter to go back...\033[0m";
            cin.ignore();
            cin.get();    
            clearScreen();
    }  
} while(choice != 6);
}

void datalearn() {
    clearScreen(); 
    cout<<"\033[1;32m====================\t";
      cout << "DATA STRUCTURE\t";
             cout<< "====================\n\033[0m";
             string texts[] = { "Definition:\n",
     "A Data Structure is a way of storing and organizing data in a computer\n", "so that it can be used efficiently. It helps programmers make\n", "algorithms faster and more reliable.\n\n", "Common Types:\n", "1. Array - Stores elements of the same type in contiguous memory.\n", "2. Linked List - A series of nodes connected by pointers.\n",
    "3. Stack - Follows Last In, First Out (LIFO).\n",
    "4. Queue - Follows First In, First Out (FIFO).\n", 
    "5. Tree - A hierarchical structure with nodes.\n", 
    "6. Graph - Collection of nodes and edges.\n", 
    "7. Hash Table - Stores key-value pairs for quick access.\n\n", 
    "Importance of Data Structures:\n", 
    "- Helps in efficient data access and storage.\n", 
    "- Makes algorithms faster and simpler.\n", 
"- Used in databases, operating systems, and networking.\n", 
    "- Reduces complexity and improves performance.\n\n"
                 
             };
    for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
    typewriter(texts[i], 30);
}

    
    
    if (!hasReadData){
    cout << "\033[3;1;92mYou earned +5 point! Current Points: " << points << "\n\033[0m";
    points += 5;
    hasReadData=true;

    }
    else{
        cout<< "\033[3;1;91mNo more points added after first read!\033[0m";
    }

    cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}
void infolearn() {
    clearScreen();
    cout<<"\033[1;94m====================\t";
      cout << "INFORMATION MANAGEMENT\t";
             cout<< "====================\033[0m\n";

    string texts[] = { 
    "1. Data vs Information:\n",
     "- Data: Raw, unprocessed facts (numbers, names, measurements).\n",
    "- Information: Processed and organized data that has meaning.\n\n",

    "2. Metadata:\n",
    "- Metadata is data that describes other data.\n",
    "  Example: Author of a file, creation date, keywords.\n\n", 

     "3. Database Management System (DBMS):\n", 
     "- A software used to create, organize, and manage databases.\n", 
    "  Examples: MySQL, Oracle, SQL Server, PostgreSQL.\n\n", 
    "4. Data Integrity:\n", 
     "- Ensuring that data in a database is accurate, consistent, and reliable.\n\n",
"5. Data Integration:\n",
    "- The process of combining data from different sources into a unified dataset.\n\n",
"6. Normalization:\n",
     "- The process of organizing data to reduce redundancy (duplication).\n\n",
"7. SQL Data Types:\n", 
    "- INT: Whole numbers (e.g., 1, 10)\n", 
     "- VARCHAR: Text (e.g., \"Hello\")\n", 
    "- DECIMAL: Decimal numbers (e.g., 3.14)\n", 
    "- DATE: Dates (e.g., 2023-11-15)\n\n", 
"8. Aggregate Functions:\n", 
    "- COUNT(): Counts the number of rows\n", 
    "- SUM(): Adds all values\n",
    "- AVG(): Computes average\n",
    "- MAX(): Largest value\n", 
    "- MIN(): Smallest value\n\n",

    "9. Single-user vs Multi-user databases:\n", 
     "- Single-user: Only one user can access database at a time.\n", 
    "- Multi-user: Multiple users can use database at the same time.\n\n"
    };
    
    for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
    typewriter(texts[i], 30);
}
    
    
    
    if (!hasReadInfo){
    cout << "\033[3;1;92mYou earned +5 point! Current Points: " << points << "\033[0m\n";
    points += 5;
    hasReadInfo=true;
    }
    else{
        cout<< "\033[3;1;91mNo more points added after first read!\033[0m";
    }

    
    cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}


void rizallearn() {
    clearScreen();
    cout<<"\033[1;34m====================\t";
      cout << "RIZAL\t";
             cout<< "====================\033[0m\n";

    string texts[] = {
         "Birth and Early Life:\n", 
    "- Jose Rizal was born on June 19, 1861, in Calamba, Laguna.\n", 
    "- He grew up in a loving and educated family.\n", 
    "- He studied in Biñan and Manila, showing exceptional intelligence.\n\n", 

    " Education and Studies Abroad:\n",
     "- Rizal went to Europe to continue his studies due to discrimination at UST.\n",
     "- He studied medicine, philosophy, arts, and humanities.\n\n",

    "Literary Works:\n",
     "1. Noli Me Tangere (1887) - Exposed social injustices.\n",
    "2. El Filibusterismo (1891) -Continued advocacy for reforms.\n",
    "3. Mi Último Adiós (1896) - Poem written before his execution.\n",
    "- Also wrote poems, essays, and letters promoting patriotism.\n\n",

     "Reform Movements:\n",
     "- Joined the Propaganda Movement in Europe.\n",
    "- Founded La Liga Filipina in 1892 to promote unity and education.\n\n",

     "Exile and Later Life:\n",
    "- Rizal was exiled to Dapitan from 1892 to 1896.\n",
     "- In Dapitan, he taught, practiced medicine, and worked on community projects.\n\n",

     "Death and Legacy:\n",
    "- Rizal was executed on December 30, 1896, in Luneta, Manila.\n", 
     "- His writings inspired nationalism and independence.\n", 
    "- December 30 is celebrated as Rizal Day.\n\n"
    };
    
    for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
    typewriter(texts[i], 30);
}

    
    
    if (!hasReadRizal){
    cout << "\033[3;1;92mYou earned +5 point! Current Points: " << points << "\033[0m\n";
    points += 5;
    hasReadRizal=true;
    }
    else{
        cout<< "\033[3;1;91mNo more points added after first read!\033[0m";
    }

    cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}

void discretelearn() {
    clearScreen();
    cout<<"\033[1;95m====================\t";
      cout << "DISCRETE MATH\t";
             cout<< "====================\033[0m\n";

    string texts[] = {
         "Relation:\n",
    "A relation is a set of ordered pairs connecting elements from one set (domain) to another (range).\n",
    "Example: {(1,2), (2,3), (3,4)}\n\n",

     "Function:\n",
     "A function is a relation where each input has exactly one output.\n"
     "Example: {(1,2), (2,3), (3,4)} - Valid Function\n", 
    "Non-example: {(1,2), (2,3), (1,3)} - Not a function\n\n", 

     "Sequence:\n", 
    "An ordered list of numbers.\n",
    "- Arithmetic: difference between terms is constant (d).\n", 
     "  Example: 3, 7, 11, 15 (d = 4)\n",
     "- Geometric: multiplied by constant ratio (r).\n", 
    "  Example: 3, 6, 12, 24 (r = 2)\n\n",

     "Binary Numbers:\n",
    "Binary uses only 0s and 1s.\n"
    "Example: 1010 is valid; 234 is NOT binary.\n\n", 

    "Proposition:\n", 
    "A statement that is either TRUE or FALSE, but not both.\n",
    "Example of True: 2 + 2 = 4\n",
     "Example of False: The sky is green\n\n",

     "Truth Table:\n", 
     "Shows all possible inputs and outputs of logical operations.\n", 
    "Useful in logic and designing circuits.\n\n"
    };
    for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
    typewriter(texts[i], 30);
}

    
    
    if (!hasReadDiscrete){
    cout << "\033[3;1;92mYou earned +5 point! Current Points: " << points << "\033[0m\n";
    points += 5;
    hasReadDiscrete=true;
    }
    else{
        cout<< "\033[3;1;91mNo more points added after first read!\033[0m";
    }

    cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}

void stslearn() {
    clearScreen();
    cout<<"\033[1;93m ====================\t";
      cout << "STS\t";
             cout<< "====================\033[0m\n";

    string texts[] = {
        "Main Goal of Science:\n",
    "- To understand the natural world through observation and reasoning.\n\n", 

    "Technology:\n", 
     "- The application of scientific knowledge to solve problems.\n\n", 

    "Positive Effects of Technology:\n", 
     "- Faster communication, access to education, medical advances.\n\n", 

     "Society's Influence on Science and Technology:\n", 
    "- Society creates needs and challenges that drive innovation.\n\n", 

     "Ethical Issues in Technology:\n", 
       "- Data privacy, responsible AI use, environmental responsibility.\n\n", 

    "Relationship Between Science and Technology:\n", 
    "- Science discovers principles; technology applies them.\n\n", 

    "Examples of Technology Improving Life:\n", 
    "- Printing press, medical devices, transportation.\n\n",

     " Negative Effects of Technology:\n", 
    "- Pollution, deforestation, resource overuse.\n\n", 

    " Responsible Use of Technology:\n", 
    "- Using it to help others and protect nature.\n\n", 

     " Importance of STS:\n", 
    "- Helps people make responsible decisions about science and technology.\n\n"
    };
    
    for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
    typewriter(texts[i], 30);
}

    
    
    if (!hasReadSTS){
    cout << "\033[3;1;92mYou earned +5 point! Current Points: " << points << "\033[0m\n";
    points += 5;
    hasReadSTS=true;
    }
    else{
        cout<< "\033[3;1;91mNo more points added after first read!\033[0m";
    }

    cout << "\nPress Enter to go back...";
   cin.ignore(); 
    cin.get();    
    clearScreen();;
}

void quiz() {
int choice;
do {
cout<<"\033[1;37m====================\t";
      cout << "QUIZ SECTION\t";
             cout<< "====================\n\033[0m";
cout << "\033[39m1. Data Structures Quiz\n";
cout << "2. Information Management Quiz\n";
cout << "3. Rizal Quiz\n";
cout << "4. Discrete Math Quiz\n";
cout << "5. STS Quiz\n";
cout << "6. Back to Main Menu\n";
cout << "Enter your choice: ";
cin >> choice;
cout << "\033[0m";
clearScreen();
loading();
clearScreen();

if(cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid choice!\n";
        cout << "\nPress Enter to go back...";
        cin.get();
        clearScreen();
        continue; 
    }

switch(choice) {  
        case 1:  
            dataquiz();  
            break;  
        case 2:  
            infoquiz();  
            break;  
        case 3:  
            rizalquiz();  
            break;  
        case 4:  
            discretequiz();  
            break;  
        case 5:  
            stsquiz();  
            break;  
        case 6:  
            return;  
        default:  
            cout << "Invalid choice!\n";  
            system("pause");  
    }  
} while(choice != 6);

}

void dataquiz() {
    if(passeddata){
        cout<< "\033[3;1;91m\n\n\n\n\nYou already passed this quiz!";
        cout<<"You cannot take this quiz again!\n";
        cout << "\nPress Enter to go back...\033[0m";
    cin.ignore(); 
    cin.get();    
    clearScreen();
    return;
    }
    
    int score = 0;
    char answer;

    cout<<"\033[1;91m====================\t";
      cout << "DATA STRUCTURES QUIZ\t";
             cout<< "====================\033[0m\n";

    cout << "1. Which data structure follows LIFO?\n";
    cout << "A. Queue\nB. Stack\nC. Array\nD. Tree\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n2. Which allows adding/removing only at one end?\n";
    cout << "A. Stack\nB. Queue\nC. Linked List\nD. Graph\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'A') score++;
    

    cout << "\n3. Best for hierarchical relationships?\n";
    cout << "A. Array\nB. Queue\nC. Tree\nD. Stack\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;

    cout << "\n4. In a queue, the first deleted element is:\n";
    cout << "A. Inserted first\nB. Inserted last\nC. Middle element\nD. Never inserted\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'A') score++;
    

    cout << "\n5. Which uses nodes connected by pointers?\n";
    cout << "A. Array\nB. Linked List\nC. Stack\nD. Tree\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n6. Which is non-linear?\n";
    cout << "A. Stack\nB. Queue\nC. Tree\nD. Array\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    

    cout << "\n7. A graph is made up of:\n";
    cout << "A. Nodes and edges\nB. Stacks and queues\nC. Arrays and trees\nD. Memory and pointers\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'A') score++;
    

    cout << "\n8. Hash Table stores data using:\n";
    cout << "A. Pointers\nB. Index\nC. Key-value pairs\nD. Arrays\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    

    cout << "\n9. Which operation is NOT possible in a stack?\n";
    cout << "A. Push\nB. Pop\nC. Peek\nD. Enqueue\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'D') score++;
    

    cout << "\n10. Fastest for searching (if implemented well)?\n";
    cout << "A. Linked List\nB. Array\nC. Hash Table\nD. Queue\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    clearScreen();
    checking();
    clearScreen();
    
    cout << "\033[7m\nQuiz Finished! You scored " << score << "/10.\033[0m\n";
    if (score >= 7) { 
        cout << "\033[3;1;92mGreat! +10 points\033[0m\n"; 
        points += 10;
        passeddata=true;
    } else {
        cout << "\033[3;1;91mKeep practicing!\n\033[0m";
    }
    cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
    
}
void infoquiz() {
    if(passedinfo){
        cout<< "\033[3;1;91\n\n\n\n\nYou already passed this quiz!";
        cout<<"You cannot take this quiz again!\n";
        cout << "\nPress Enter to go back...\033[0m";
    cin.ignore(); 
    cin.get();    
    clearScreen();
    return;
    }
    int score = 0;
    char answer;

    cout<<"\033[1;95m====================\t";
      cout << "INFORMATION MANAGEMENT\t";
             cout<< "====================\033[0m\n";

    cout << "1. Raw facts and figures are called:\n";
    cout << "A. Information\nB. Data\nC. Metadata\nD. Schema\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n2. Information is:\n";
    cout << "A. Raw facts\nB. Processed data with meaning\nC. Physical storage\nD. Instructions\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n3. Metadata describes:\n";
    cout << "A. Characteristics of data\nB. Data combination\nC. Data cleaning\nD. Data storage\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'A') score++;
    

    cout << "\n4. DBMS is:\n";
    cout << "A. Hardware for data\nB. Software for managing databases\n";
    cout << "C. Programming language\nD. Storage device\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n5. Feature ensuring accuracy and consistency:\n";
    cout << "A. Data Security\nB. Data Integrity\nC. Data Analysis\nD. Data Independence\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n6. Function returning total value:\n";
    cout << "A. COUNT()\nB. SUM()\nC. AVG()\nD. MAX()\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    
    cout << "\n7. Type of database supporting multiple users?\n";
    cout << "A. Single-user\nB. Centralized\nC. Multi-user\nD. Workgroup\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    

    cout << "\n8. SQL data type for whole numbers?\n";
    cout << "A. FLOAT\nB. VARCHAR\nC. INT\nD. DECIMAL\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    

    cout << "\n9. Combining data from multiple sources is called?\n";
    cout << "A. Data Cleaning\nB. Data Integration\nC. Data Transformation\nD. Data Analysis\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n10. Normalization is:\n";
    cout << "A. Encrypting data\nB. Organizing data to reduce redundancy\n";
    cout << "C. Backing up files\nD. Data cleaning\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    clearScreen();
    checking();
    clearScreen();

    cout << "\033[7m\nYour score: " << score << "/10\n\033[0m";
    if (score >= 7) { points += 10; cout << "\033[3;92Great! +10 points\033[0m\n"; 
        passedinfo=true;
    }
    else{
        cout << "\033[3;1;91mKeep practicing!\033[0m\n";
    }

    cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}

void rizalquiz() {
    if(passedrizal){
        cout<< "\033[3;1;91m\n\n\n\n\nYou already passed this quiz!";
        cout<<"You cannot take this quiz again!\n";
        cout << "\nPress Enter to go back...\033[0m";
    cin.ignore(); 
    cin.get();    
    clearScreen();
    return;
    }
    int score = 0;
    char answer;

    cout<<"\033[1;38m====================\t";
      cout << "RIZAL QUIZ\t";
             cout<< "====================\033[0m\n";
    cout << "1. Where was Jose Rizal born?\n";
    cout << "A. Manila\nB. Calamba, Laguna\nC. Biñan, Laguna\nD. Bulacan\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n2. Title of Rizal’s first novel?\n";
    cout << "A. El Filibusterismo\nB. Mi Último Adiós\nC. Noli Me Tangere\nD. To the Filipino Youth\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    

    cout << "\n3. Why did Rizal study in Europe?\n";
    cout << "A. Escape revolution\nB. Adventure\nC. Discrimination at UST\nD. Forced by parents\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    

    cout << "\n4. What movement did Rizal join?\n";
    cout << "A. Katipunan\nB. Propaganda Movement\nC. La Liga Filipina\nD. La Solidaridad\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n5. What organization did Rizal establish in 1892?\n";
    cout << "A. Katipunan\nB. KKK\nC. Propaganda\nD. La Liga Filipina\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'D') score++;
    

    cout << "\n6. Where was Rizal exiled?\n";
    cout << "A. Spain\nB. Hong Kong\nC. Dapitan\nD. Mindoro\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    

    cout << "\n7. Poem before execution?\n";
    cout << "A. To the Flowers\nB. Mi Último Adiós\nC. Kundiman\nD. Sa Aking Mga Kabata\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n8. When is Rizal Day?\n";
    cout << "A. June 12\nB. August 21\nC. December 30\nD. November 30\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    

    cout << "\n9. Main goal of Noli Me Tangere?\n";
    cout << "A. Promote war\nB. Show abuses peacefully\nC. Teach Filipino\nD. Inspire migration\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n10. Why is Rizal a national hero?\n";
    cout << "A. Founded Katipunan\nB. Was president\nC. Writings inspired independence\nD. Led army\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    clearScreen();
    checking();
    clearScreen();

    cout << "\033[7m\nYour score: " << score << "/10\033[0m\n";
    if (score >= 7) { points += 10; cout << "\033[3;92mNice! +10 points\033[0m\n"; 
        passedrizal=true;
    }
    else{ 
        cout << "\033[3;1;90mTry again!\033[0m\n";
    }

    cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();
    clearScreen();
}

void discretequiz() {
    if(passeddiscrete){
        cout<< "\033[3;1;91m\n\n\n\n\nYou already passed this quiz!";
        cout<<"You cannot take this quiz again!\n";
        cout << "\nPress Enter to go back...\033[0m";
    cin.ignore(); 
    cin.get();    
    clearScreen();
    return;
    }
    int score = 0;
    char answer;

    cout<<"\033[1;35m====================\t";
      cout << "DISCRETE MATH QUIZ\t";
             cout<< "====================\033[0m\n";

    cout << "1. Which of the following is a relation?\n";
    cout << "A. {(1,2), (2,3), (3,4)}\nB. 1 + 2 = 3\nC. x + y = 5\nD. 5\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'A') score++;
    

    cout << "\n2. Which relation is a function?\n";
    cout << "A. {(1,2), (2,3), (1,3)}\nB. {(1,2), (2,3), (3,4)}\n";
    cout << "C. {(1,2), (2,4), (2,3)}\nD. {(3,3), (3,3)}\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n3. A sequence is:\n";
    cout << "A. A group of colors\nB. An ordered list of elements\n";
    cout << "C. A single number\nD. A sentence\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n4. An arithmetic sequence has:\n";
    cout << "A. A constant difference\nB. A constant ratio\n";
    cout << "C. No pattern\nD. Random numbers\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'A') score++;
    

    cout << "\n5. A geometric sequence has:\n";
    cout << "A. A constant difference\nB. A constant ratio\n";
    cout << "C. A variable difference\nD. No pattern\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n6. 3, 7, 11, 15 is:\n";
    cout << "A. Geometric\nB. Arithmetic\nC. Random\nD. None\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n7. Which is a geometric sequence?\n";
    cout << "A. 2,4,6,8\nB. 1,3,5,7\nC. 3,6,12,24\nD. 5,8,11,14\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    

    cout << "\n8. Which is a valid binary number?\n";
    cout << "A. 1010\nB. 234\nC. 12\nD. 9\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'A') score++;
    

    cout << "\n9. A proposition is:\n";
    cout << "A. Always true\nB. Always false\n";
    cout << "C. A sentence that can be true or false\nD. A question\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    

    cout << "\n10. A truth table shows:\n";
    cout << "A. Only inputs\nB. Only outputs\n";
    cout << "C. All inputs and outputs\nD. None of the above\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'C') score++;
    clearScreen();
    checking();
    clearScreen();

    cout << "\033[7m\nQuiz Finished! You scored " << score << "/10.\033[0m\n";

    if (score >= 7) {
        cout << "\033[3;1;92mGreat work! +10 points\033[0m\n";
        points += 10;
        passeddiscrete=true;
    } else {
        cout << "\033[3;1;91mKeep practicing!\033[0m\n";
    }

    cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}
void stsquiz() {
    if(passedsts){
        cout<< "\033[3;1;91m\n\n\n\n\nYou already passed this quiz!";
        cout<<"You cannot take this quiz again!\n";
        cout << "\nPress Enter to go back...\033[0m";
    cin.ignore(); 
    cin.get();    
    clearScreen();
    return;
    }
    int score = 0;
    char answer;

    cout<<"\033[1;40m====================\t";
      cout << "STS QUIZ\t";
             cout<< "====================\033[0m\n";

    cout << "1. Main goal of science?\n";
    cout << "A. Make money\nB. Understand natural world\nC. Entertain\nD. Build machines\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n2. What is technology?\n";
    cout << "A. Same as science\nB. Applying science to solve problems\nC. Only gadgets\nD. Study of stars\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    
    cout << "\n3. Positive effect of technology?\n";
    cout << "A. Pollution\nB. Faster communication\nC. Cyberbullying\nD. Deforestation\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n4. Society influences technology by:\n";
    cout << "A. Creating new needs\nB. Avoiding tools\nC. Banning inventions\nD. Ignoring science\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'A') score++;
    

    cout << "\n5. Ethical issue in technology:\n";
    cout << "A. Photosynthesis\nB. Data privacy\nC. Gravity\nD. Rain\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n6. Relationship of science and technology:\n";
    cout << "A. Not related\nB. Science provides knowledge, tech applies it\nC. Tech older\nD. Depends only on tradition\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n7. Which improved life?\n";
    cout << "A. Printing press\nB. Pollution\nC. Deforestation\nD. Weapons\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'A') score++;
    

    cout << "\n8. Negative effect of technology:\n";
    cout << "A. Reforestation\nB. Pollution & waste\nC. Clean energy\nD. Awareness\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n9. Responsible use of technology?\n";
    cout << "A. Ignore nature\nB. Use it to help others and protect nature\nC. Total dependence on tech\nD. Avoid science\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    

    cout << "\n10. Why study STS?\n";
    cout << "A. Exploit resources\nB. Understand impact responsibly\nC. Ban science\nD. Stop progress\nYour answer: ";
    cin >> answer;
    if (toupper(answer) == 'B') score++;
    clearScreen();
    checking();
    clearScreen();

    cout << "\033[7m\nYour score: " << score << "/10\033[0m\n";
    if (score >= 7) { points += 10; cout << "\033[3;92mGreat job! +10 points\n\033[0m"; 
        passedsts=true;
    }
    else{
        cout << "\033[3;1;91mKeep learning!\033[0m\n";
    }

    cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}

// Mini Games menu
void miniGames() {
int choice;
do {
cout<<"\033[1;36m====================\t";
      cout << "MINI GAMES SECTION\t";
             cout<< "====================\033[0m\n";
cout << "\033[94m1. Word Scramble";
if (WordScrambleUnlocked) cout << " (Unlocked!)";
cout << "\n";
cout << "2. Tic Tac Toe";
if (TicTacToeUnlocked) cout << " (Unlocked!)";
cout << "\n";
cout << "3. Rock Paper Scissors";
if (RockPaperScissorsUnlocked) cout << " (Unlocked!)";
cout << "\n";
cout << "4. Back to Main Menu\n";
cout << "Enter your choice: ";
cin >> choice;
cout<<"\033[0m";
clearScreen();
loading();
clearScreen();

if(cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "\033[3;31mInvalid choice!\n";
        cout << "\nPress Enter to go back...\033[0m";
        cin.get();
        clearScreen();
        continue; 
    }

switch(choice) {  
        case 1:  
            if (WordScrambleUnlocked) {  
                wscramble();  
            } else {  
                cout << "\033[3;1;90mWord Scramble is locked! Unlock with 5 stars.\033[3;31m\n";  
                cin.ignore(); 
    cin.get();    
    clearScreen();
            }  
            break;  
        case 2:  
            if (TicTacToeUnlocked) {  
                tictactoe();  
            } else {  
                cout << "\033[3;1;90mTic Tac Toe is locked! Unlock with 15 stars.\033[3;0m\n";  
                cin.ignore(); 
    cin.get();    
    clearScreen();
                
            }  
            break;  
        case 3:  
            if (RockPaperScissorsUnlocked) {  
                rockpaperscissor();  
            } else {  
                cout << "\033[3;1;90mRock Paper Scissors is locked! Unlock with 25 stars.\033[0m\n";  
                cin.ignore(); 
    cin.get();    
    clearScreen();
                
            }  
            break;  
        case 4:  
            return;  
        default:  
            cout << "\033[3;31mInvalid choice!\033[0m\n";  
            cin.ignore(); 
    cin.get();    
    clearScreen();;
    }  
} while(choice != 4);

}

void wscramble() {
    vector<string> words = {"program", "studies", "learnings", "quizzes", "creates"};
    string word = words[rand() % words.size()];
    std::string scrambled = word;  

auto rng = std::default_random_engine(static_cast<unsigned>(time(0)));
std::shuffle(scrambled.begin(), scrambled.end(), rng);

while (scrambled == word) { 
    std::shuffle(scrambled.begin(), scrambled.end(), rng);
}
for (int i = 0; i < 4; i++) {
    typewriter(words[i], 30);
}


    cout<<"\033[1;93m====================\t";
      cout <<"WORD SCRAMBLE GAME\t";
             cout<< "====================\033[0m\n";
    cout << "Unscramble this word: " << scrambled << endl;

    string guess;
    do {
        cout << "\033[7mYour guess: ";
        cin >> guess;
        cout<<"\033[0m";

        if (guess != word) {
            cout << "\033[3;31mIncorrect! Try again.\033[0m\n";
        }
            

    } while (guess != word);
       cout << "\033[3;92mCorrect! The word is: " << word;
       cout<<"\n";
       points+= 2;
    cout<<"Congratulations! +2 points\n\n";
    cout<< "\033[0m";
    
    

cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}
    
void tictactoe() {
int choice;
cout<<"\033[1;35m====================\t";
      cout << "TIC TAC TOE\t";
             cout<< "====================\033[0m\n";
cout << "\033[34m1. Vs Computer\n";
cout << "2. 2 Players\n";
cout << "3. Back\n";
cout << "Enter choice: ";
cin >> choice;
cout<<"\033[0m";
clearScreen();
loading();
clearScreen();

if(cin.fail()) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "\033[3;31Invalid choice!\n";
        cout << "\nPress Enter to go back...\033[3;31m";
        cin.get();
        clearScreen();
        
    }

switch(choice) {  
    case 1:  
        tttoevscom();  
        break;  
    case 2:  
        tttoe2pl();  
        break;  
    case 3:  
        return;  
    default:  
        cout << "\033[3;31mInvalid!\033[0m\n";  
        
}

}

void tttoevscom() {
char boardArr[3][3] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'}
};

auto displayBoard = [&]() {  
    cout << "\033[7m\n TIC TAC TOE (vs Computer)\n\n";  
    cout << "Player (X)  -  Computer (O)\n\n\033[0m";  
    cout<< "\033[35m";
    cout << "     |     |     \n";  
    cout << "  " << boardArr[0][0] << "  |  " << boardArr[0][1] << "  |  " << boardArr[0][2] << "\n";  
    cout << "_____|_____|_____\n";  
    cout << "     |     |     \n";  
    cout << "  " << boardArr[1][0] << "  |  " << boardArr[1][1] << "  |  " << boardArr[1][2] << "\n";  
    cout << "_____|_____|_____\n";  
    cout << "     |     |     \n";  
    cout << "  " << boardArr[2][0] << "  |  " << boardArr[2][1] << "  |  " << boardArr[2][2] << "\n";  
    cout << "     |     |     \n\n";  
    cout<<"\033[0m";
};  

auto checkWinner = [&]() -> char {  
    for (int i = 0; i < 3; i++)  
        if (boardArr[i][0] == boardArr[i][1] && boardArr[i][1] == boardArr[i][2])  
            return boardArr[i][0];  
    for (int i = 0; i < 3; i++)  
        if (boardArr[0][i] == boardArr[1][i] && boardArr[1][i] == boardArr[2][i])  
            return boardArr[0][i];  
    if (boardArr[0][0] == boardArr[1][1] && boardArr[1][1] == boardArr[2][2]) return boardArr[0][0];  
    if (boardArr[0][2] == boardArr[1][1] && boardArr[1][1] == boardArr[2][0]) return boardArr[0][2];  
    return 'N';  
};  

auto isDraw = [&]() -> bool {  
    for (int i = 0; i < 3; i++)  
        for (int j = 0; j < 3; j++)  
            if (boardArr[i][j] != 'X' && boardArr[i][j] != 'O')  
                return false;  
    return true;  
};  

auto computerMove = [&]() {  
    for (int i = 0; i < 3; i++)  
        for (int j = 0; j < 3; j++)  
            if (boardArr[i][j] != 'X' && boardArr[i][j] != 'O') {  
                char temp = boardArr[i][j];  
                boardArr[i][j] = 'O';  
                if (checkWinner() == 'O') return;  
                boardArr[i][j] = temp;  
            }  

    for (int i = 0; i < 3; i++)  
        for (int j = 0; j < 3; j++)  
            if (boardArr[i][j] != 'X' && boardArr[i][j] != 'O') {  
                char temp = boardArr[i][j];  
                boardArr[i][j] = 'X';  
                if (checkWinner() == 'X') {  
                    boardArr[i][j] = 'O';  
                    return;  
                }  
                boardArr[i][j] = temp;  
            }  

    int move;  
    do {  
        move = rand() % 9;  
    } while (boardArr[move / 3][move % 3] == 'X' || boardArr[move / 3][move % 3] == 'O');  

    boardArr[move / 3][move % 3] = 'O';  
};  

int choice;  
char mark;  

while (true) {  
    displayBoard();  

    cout << "\033[7mPlayer, enter your choice: ";  
    cin >> choice;  
    cout<<"\033[0m";

    int row = (choice - 1) / 3;  
    int col = (choice - 1) % 3;  
    clearScreen();

    if (choice >= 1 && choice <= 9 && boardArr[row][col] != 'X' && boardArr[row][col] != 'O') {  
        boardArr[row][col] = 'X';  
    } else {  
        cout << "\033[3;31mInvalid move! Try again.\033[0m\n";  
        continue;  
    }  

    if (checkWinner() == 'X') {  
        displayBoard();  
        cout << "\033[3;92m==> You win! +15 points\033[0m\n";  
        points += 15;  
        break;  
    }  

    if (isDraw()) {  
        displayBoard();  
        cout << "\033[3;31m==> Draw Game!\033[0m\n";  
        break;  
    }  

    computerMove();  

    if (checkWinner() == 'O') {  
        displayBoard();  
        cout<<"\n";
        cout << "\033[3;31m==> Computer wins!\033[0m\n";  
        break;  
    }  

    if (isDraw()) {  
        displayBoard();  
        cout<<"\n";
        cout << "\033[3;31m==> Draw Game!\033[0m\n";  
        break;  
    }  
}  

cout << "\nPress Enter to go back...";
cin.ignore(); 
cin.get();    
clearScreen();
}


void tttoe2pl() {
char boardArr[3][3] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'}
};

auto displayBoard = [&]() {  
    cout << "\033[7m\n TIC TAC TOE \n\n";  
    cout << "Player 1 (X)  -  Player 2 (O)\n\n\033[0m"; 
    cout<<"\033[35m";
    cout << "     |     |     \n";  
    cout << "  " << boardArr[0][0] << "  |  " << boardArr[0][1] << "  |  " << boardArr[0][2] << "\n";  
    cout << "_____|_____|_____\n";  
    cout << "     |     |     \n";  
    cout << "  " << boardArr[1][0] << "  |  " << boardArr[1][1] << "  |  " << boardArr[1][2] << "\n";  
    cout << "_____|_____|_____\n";  
    cout << "     |     |     \n";  
    cout << "  " << boardArr[2][0] << "  |  " << boardArr[2][1] << "  |  " << boardArr[2][2] << "\n";  
    cout << "     |     |     \n\n";  
    cout <<"\033[0m";
};  

auto checkWinner = [&]() -> bool {  
      
    for (int i = 0; i < 3; i++)  
        if (boardArr[i][0] == boardArr[i][1] && boardArr[i][1] == boardArr[i][2])  
            return true;  

      
    for (int i = 0; i < 3; i++)  
        if (boardArr[0][i] == boardArr[1][i] && boardArr[1][i] == boardArr[2][i])  
            return true;  

      
    if (boardArr[0][0] == boardArr[1][1] && boardArr[1][1] == boardArr[2][2]) return true;  
    if (boardArr[0][2] == boardArr[1][1] && boardArr[1][1] == boardArr[2][0]) return true;  

    return false;  
};  

auto isDraw = [&]() -> bool {  
    for (int i = 0; i < 3; i++)  
        for (int j = 0; j < 3; j++)  
            if (boardArr[i][j] != 'X' && boardArr[i][j] != 'O')  
                return false;  
    return true;  
};  

int player = 1;  
int choice;  
char mark;  

while (true) {  
    displayBoard();  
    player = (player % 2) ? 1 : 2;  
    mark = (player == 1) ? 'X' : 'O';  

    cout << "\033[7mPlayer " << player << ", enter your choice: ";  
    cin >> choice; 
    cout<<"\033[0m";

    int row = (choice - 1) / 3;  
    int col = (choice - 1) % 3;  

    if (choice >= 1 && choice <= 9 && boardArr[row][col] != 'X' && boardArr[row][col] != 'O') {  
        boardArr[row][col] = mark;  
    } else {  
        cout << "\033[3;31mInvalid move! Try again.\033[0m\n";  
        continue;  
    }  

    if (checkWinner()) {  
        displayBoard();  
        cout << "\033[3;92m==> Player " << player << " wins! +15 points\033[0m\n";  
        points += 15;  
        break;  
    }  

    if (isDraw()) {  
        displayBoard();  
        cout << "\033[3;31m==> Draw Game!\033[0m\n";  
        break;  
    }  

    player++;  
}  

cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}


void rockpaperscissor() {
srand(time(0));
string choices[3] = {"Rock", "Paper", "Scissors"};
cout << "\033[7mRock Paper Scissors: Choose (1) Rock (2) Paper (3) Scissors\033[0m\n";
int user;
cin >> user;
int comp = rand() % 3 + 1;
cout << "\033[7mComputer chose: " << choices[comp-1] << "\0m\n";
if (user == comp) {
cout << "\033[3;31mDraw!\033[0m\n";
} else if ((user == 1 && comp == 3) || (user == 2 && comp == 1) || (user == 3 && comp == 2)) {
cout << "\033[3;92mYou win! +10 points\033[0m\n";
points += 10;
} else {
cout << "\033[3;1;91mYou lose!\033[0m\n";
}
cout << "\nPress Enter to go back...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}

void rewards() {
int choice;
do {
cout<<"\033[1;94M====================\t";
      cout << "REWARDS\t";
             cout<< "====================\033[0m\n";
cout << "\033[7mPoints: " << points << " | Stars: " << stars << "\033[0m\n\n";

cout << "\033[95mUnlocks:\n";  
    cout << "- Word Scramble: " << (WordScrambleUnlocked ? "Unlocked" : "Requires 5 stars") << "\n";  
    cout << "- Tic Tac Toe: " << (TicTacToeUnlocked ? "Unlocked" : "Requires 15 stars") << "\n";  
    cout << "- Rock Paper Scissors: " << (RockPaperScissorsUnlocked ? "Unlocked" : "Requires 25 stars") << "\n\n";  

    cout << "1. Convert Points to Stars\n";  
    cout << "2. Check Unlocks\n";  
    cout << "3. Back\n";  

    cout << "Enter choice: ";  
    cin >> choice;    
    cout<<"\033[0m";

    clearScreen();  
    loading();  
    clearScreen();  

    switch (choice) {  
        case 1:  
            convertPointsToStars();  
            checkUnlocks();  
            break;  
        case 2:  
            checkUnlocks();  
            cout << "\033[3;92mChecked.\n";  
            cout << "\nPress Enter to go back...\033[0m";
    cin.ignore(); 
    cin.get();    
    clearScreen();    
            break;  
        case 3:  
            return;  
        default:  
            cout << "\033[3;31mInvalid!\033[0m\n";  
               
    }  
}while (choice != 3);

}

void exitProgram() {
    saveProgress();
    cout << "\033[7mFinal Score: " << points << " points | " << stars << " stars.\033[0m\n";

    string texts[] = {
        "\nThank you for visiting. Goodbye! See you next time.\n"
    };

   for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
    typewriter(texts[i], 30);
}
    
}