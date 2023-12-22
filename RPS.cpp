#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <limits>
#include <chrono>
#include <thread>
#include <conio.h>

#include "Art.h"
using namespace std;


class RockPaperScissorsGame {
public:
    int userScore = 0;
    int computerScore = 0;
    int userChoice;
    int computerChoice;
    

    void displayWelcomeMessage() {
        cout << Art::asciiTagIntro();
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");
    
        cout << Art::asciiTagOutro();
        this_thread::sleep_for(chrono::seconds(2));
        system("cls");
    
        cout << Art::asciiIntro();
        
        cout << "\n\n\t\t\t\t\t  Press [ENTER] to start";
        cin.ignore();

        system("cls");
    }

    void displayMenu() {
        int menuChoice;
        int selectedOption = 0;
        bool menuActive = true;

        while (menuActive) {
            system("cls");

            cout << Art::asciiTitle() << endl;

            if (selectedOption == 0) {
                std::cout << Art::asciiMenuPlay();
            } else if (selectedOption == 1) {  
                std::cout << Art::asciiMenuExit();
            }
            char input = _getch();

            switch (input) {
                case 'w':
                    selectedOption = (selectedOption - 1 + 2) % 2;
                    break;
                case 's':
                    selectedOption = (selectedOption + 1) % 2;
                    break;
                case '\r':
                    system("cls");
                    switch (selectedOption) {
                        case 0:
                            do {
                                if (selectedOption == 0) {
                                    getUserChoice();
                                    rockPaperScissorsShoot();
                                    generateComputerChoice();
                                    updateScores();


                                    bool menuActive = true;
                                    int tryAgain = 0;
                                    while (menuActive) {
                                        system("cls");

                                        if (tryAgain == 0) {
                                            std::cout << Art::asciiTryAgain();
                                        } else if (tryAgain == 1) {  
                                            std::cout << Art::asciiTryAgainNo();
                                        }
                                        
                                        char input = _getch();
                                        
                                        switch (input) {
                                            case 'w':
                                                tryAgain = (tryAgain - 1 + 2) % 2;
                                                break;
                                            case 's':
                                                tryAgain = (tryAgain + 1) % 2;
                                                break;
                                            case '\r':
                                                menuActive = false;
                                                system("cls");
                                                switch (tryAgain) {
                                                    case 0:
                                                        break;
                                                    case 1:
                                                        menuActive = false;
                                                        displayMenu();
                                                        break;
                                                }
                                                break;
                                        }
                                    }
                                } else if (menuChoice == 2) {
                                    cout << "Exiting the game. Thank you for playing!" << endl;
                                    break;
                                } else {
                                    cout << "Invalid choice. Please select a valid option." << endl;
                                }
                            } while (true);
                        case 1:
                            system("cls");
                            cout << Art::asciiExit();
                            this_thread::sleep_for(chrono::seconds(2));
                            menuActive = false;
                            exit(0);
                    }
                if (menuActive) {
                    std::cout << "\nPress any key to continue...";
                    _getch();
                }
                break;
            }
        }
        
    }

    void getUserChoice() {
        int selectedOption = 0;
        bool menuActive = true;
        while (menuActive) {
            system("cls");
            if (selectedOption == 0) {
                std::cout << Art::asciiPickRock();
            } else if (selectedOption == 1) {  
                std::cout << Art::asciiPickPaper();
            } else if (selectedOption == 2) {
                std::cout << Art::asciiPickScissors();
            }
            
            char input = _getch();
            switch (input) {
                case 'w':
                    selectedOption = (selectedOption - 1 + 3) % 3;
                    break;
                case 's':
                    selectedOption = (selectedOption + 1) % 3;
                    break;
                case '\r':
                    menuActive = false;
                    system("cls");
                    switch (selectedOption) {
                        case 0:
                            userChoice = selectedOption;
                            break;
                        case 1:
                            userChoice = selectedOption;
                            break;
                        case 2:
                            userChoice = selectedOption;
                            break;
                    }
                    break;
                if (menuActive) {
                    std::cout << "\nPress any key to continue...";
                    _getch();
                }
                break;
            }
        }

        while (userChoice < 0 || userChoice > 2) {
            cout << "Invalid Choice. Enter: ";
            cin >> userChoice;
        }
    }

    void rockPaperScissorsShoot() {
        generateComputerChoice();

        cout << Art::asciiRockStart() << endl;
        cout << Art::asciiDrawRock();
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");

        cout << Art::asciiRockMid() << endl;
        cout << Art::asciiDrawRock();
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");

        cout << Art::asciiRockStart() << endl;
        cout << Art::asciiDrawPaper();
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");

        cout << Art::asciiRockMid() << endl;
        cout << Art::asciiDrawPaper();
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");

        cout << Art::asciiRockStart() << endl;
        cout << Art::asciiDrawScissors();
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");

        cout << Art::asciiRockMid() << endl;
        cout << Art::asciiDrawScissors();
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");

        cout << Art::asciiRockMid() << endl;
        cout << Art::asciiDrawShoot();
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");



        
        switch (userChoice) {
            //rock
            case 0:
                switch (computerChoice) {
                    //rock vs rock
                    case 0:
                        cout << Art::asciiRockVSRock() << endl;
                        cout << Art::asciiRockVRock();
                        break;
                    //rock vs paper
                    case 1:
                        cout << Art::asciiRockVSPaper()<< endl;
                        cout << Art::asciiRockVPaper();
                        break;
                    //rock vs scissors
                    case 2:
                        cout << Art::asciiRockVSScissors()<< endl;
                        cout << Art::asciiRockVScissors();
                        break;
                }
                break;
            //paper
            case 1:
                switch (computerChoice) {
                    //paper vs rock
                    case 0:
                        cout << Art::asciiPaperVSRock() << endl;
                        cout << Art::asciiPaperVRock();
                        break;
                    //paper vs paper
                    case 1:
                        cout << Art::asciiPaperVSPaper() << endl;
                        cout << Art::asciiPaperVPaper();
                        break;
                    //paper vs scissors
                    case 2:
                        cout << Art::asciiPaperVSScissors() << endl;
                        cout << Art::asciiPaperVScissors();
                        break;
                }
                break;
            //scissors
            case 2:
                switch (computerChoice) {
                    //scissors vs rock
                    case 0:
                        cout << Art::asciiScissorsVSRock() << endl;
                        cout << Art::asciiScissorsVRock();
                        break;
                    //scissors vs paper
                    case 1:
                        cout << Art::asciiScissorsVSPaper() << endl;
                        cout << Art::asciiScissorsVPaper();
                        break;
                    //scissors vs scissors
                    case 2:
                        cout << Art::asciiScissorsVSScissors() << endl;
                        cout << Art::asciiScissorsVScissors();
                        break;
                }
                break;
        }
        this_thread::sleep_for(chrono::seconds(3));
        
        determineWinner();
        displayFinalScore();
        cout << "\n\n\t\t\t\t\t\t        Press [ENTER] to continue";
        cin.ignore();
    }

    void generateComputerChoice() {
        computerChoice = rand() % 3;
    }

    void determineWinner() {
        if (userChoice == computerChoice) {
            cout << Art::asciiDraw();
        } else if ((userChoice == 0 && computerChoice == 2) ||
                   (userChoice == 1 && computerChoice == 0) ||
                   (userChoice == 2 && computerChoice == 1)) {
            cout << Art::asciiPlayerWins();
            userScore++;
        } else {
            cout << Art::asciiComputerWins();
            computerScore++;
        }
    }

    void displayResults() {
        string choices[] = {"rock", "paper", "scissors"};
        cout << "Your choice: " << choices[userChoice] << endl;
        cout << "Computer's choice: " << choices[computerChoice] << endl;
    }

    void updateScores() {
        cout << "Score: Player - " << userScore << " - Computer " << computerScore << endl;
    }

    void displayFinalScore() {
        cout << "\n\n\t\t\t\t\t\t    Score: PLAYER - " << userScore << " | " << "COMPUTER - " << computerScore << endl;
    }
    RockPaperScissorsGame() {
        srand(time(0));
    }

    void start() {
        do {
            displayWelcomeMessage();
            displayMenu();
        } while (true);
        
    }

};

int main() {
    RockPaperScissorsGame game;
    game.start();

    return 0;
}
