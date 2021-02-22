/* Add your name here */
    
#include <iostream>
#include <cstdlib>  // contains the rand() and srand() function 
#include <ctime>    // time() function
#include <vector>
#include <fstream> 
#include <climits>
using namespace std;


int main()
{
    srand(time(0)); // initialize random seed generator to current time: 
				// needed to generate a different sequence of random numbers
					// each time you run your program

    // Add your code to play the dice game here
    cout << "Welcome to the dice game!!!" << endl;
    cout << "To begin press y" << endl;
    string userInput;
    string roll;
    int num1;
    int num2;
    int sum1;
    int sum2;
    int playersPoint;
    int nrProblems = 0;
    int nrCProblems = 0;
    int nrICProblems = 0;
    int rollNr = 0;
    cin >> userInput;
    if ((userInput != "y") && (userInput != "Y") && (userInput != "N") && (userInput != "n")){
        cout << "Please select Y to begin or press N to end game" << endl;
        cin >> userInput;
    }else if((userInput == "y") || (userInput == "Y")){

        while ((userInput == "y") || (userInput == "Y")){
            nrProblems++;
            rollNr++;
            num1 = ((rand()%6) + 1);
            num2 = ((rand()%6) + 1);
            cout << "your numbers are: " << num1 << " " <<num2 << endl;
            sum1 = num1 + num2;
        
        
            if ((sum1 == 7) || (sum1 == 11)){
                nrCProblems++;
                cout << "Your sum is " << sum1 << " " << "YOU WIN" << endl;
                cout << "do you want to play again? Y for yes or any other key for no" << endl;
                cin >> userInput;
                if ((userInput != "y") && (userInput != "Y")){
                    break;
                }
                else if(userInput == "y" || userInput == "Y"){
                    continue;
                }
            }
            else if ((sum1 == 2) || (sum1 == 3) || (sum1 == 12)){
                nrICProblems++;
                cout << "Your sum is " << sum1 << " " << " YOU LOSE" << endl;
                cout << "do you want to play again? Y for yes or any other key for no" << endl;
                cin >> userInput;
                if ((userInput != "y") && (userInput != "Y")){
                    break;
                }
                else if(userInput == "y" || userInput == "Y"){
                    continue;
                }
            }
            else {
                playersPoint = sum1;
                cout << "Your points are now " << playersPoint << endl;
                cout << "Please roll again: press r" << endl;
                cin >> roll;
                if ((roll != "r") && (roll != "R")) {
                    cout << "incorrect input, please press r" << endl;
                    cin >> roll;
                }
                if ((roll == "r") || (roll == "R")){
                    rollNr++;
                    num1 = ((rand()%6) + 1);
                    num2 = ((rand()%6) + 1);
                    cout << "your numbers are: " << num1 << " " <<num2 << endl;
                    sum2 = num1 + num2;
                    cout << "your sum is: " << sum2 << endl;
                }
                while ((sum2 != 7) && (sum2 != playersPoint)){
                    cout << "Please roll again: press r" << endl;
                    cin >> roll;
                    if ((roll != "r") && (roll != "R")) {
                        cout << "incorrect input, please press r" << endl;
                        cin >> roll;
                    }
                    if ((roll == "r") || (roll == "R")){
                        rollNr++;
                        num1 = ((rand()%6) + 1);
                        num2 = ((rand()%6) + 1);
                        cout << "your numbers are: " << num1 << " " <<num2 << endl;
                        sum2 = num1 + num2;
                        cout << "Your original points is " << playersPoint << endl;
                        cout << "your sum is: " << sum2 << endl;
                    }
                }
            }
            if (sum2 == 7){
                nrICProblems++;
                cout << "your points were: " << sum2 << " YOU LOSE" << endl;
                cout << "do you want to play again? Y for yes or any other key for no" << endl;
                cin >> userInput;
                if ((userInput != "y") && (userInput != "Y")){
                    break;
                }
                else if(userInput == "y" || userInput == "Y"){
                    continue;
                }
            }

            if (playersPoint == sum2){
                nrCProblems++;
                cout << "Your points were: " << sum2 << " YOU WIN" << endl;
                cout << "do you want to play again? Y for yes or any other key for no" << endl;
                cin >> userInput;
                if ((userInput != "y") && (userInput != "Y")){
                    break;
                }
                else if(userInput == "y" || userInput == "Y"){
                    continue;
                }
            }


        }
    }else{
        cout << "Game over" << endl;
    }
    if (userInput != "y" && userInput != "Y"){
        cout << "You played " << nrProblems << " games," << "You won " << nrCProblems << " games," << "You lost " << nrICProblems << " games!" << " You rolled " << rollNr << " times!" << endl;

    }
     

}


