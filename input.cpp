/*
    Understanding input: cin, getline
*/

#include <iostream>
#include <vector>
#include <fstream> 
#include <climits>
using namespace std;

int main()
{

    ofstream output_file;           // output_file = is an output stream object that sends a stream of chars from the program into an output file
    output_file.open("out_lab2_2_answers"); // open an outpuf file where output_file will send data. 
    vector<string> array_values;    // declares an empty vector of strings
    array_values.push_back("10");   // add "10" 
    array_values.push_back("4.5");  // add "4.5"
    array_values.push_back("abc"); 
    array_values.push_back("a");

    int val;  // declare an integer variable int

    cout << "Code for Q1" << endl;
    for (int i = 0; i < array_values.size(); i++)
    {
        cout << "\tEnter the value " << array_values.at(i) << endl;
    
        cout << "\tEnter an int "; 
        cin >> val; 

        cout << "\n\tCheck fail flag in cin " <<  cin.fail() << endl;
        cout << "\tYou entered " << val << endl << endl;
    }

    // cin = is a stream object that takes characters from the keyboard and extracts data according 
    //       to the type of the variable in your program.
    //      = If it cannot extract the type specified in your program (in our case an integer), it might leave
    //      characters in the stream, which will conflict with future cin statements.
    
    // See whether the cin buffer is empty or not
    cin.clear();        // set all error flags to false
    string s;
    getline(cin, s);    // extracts characters from cin into the string object s
                        // getline = is a function defined in the <string> class
                        // check its definition at: http://www.cplusplus.com/reference/string/string/getline/ 
    cout << "Check what is left unread in the cin buffer: " << s << endl;
    cout << "Nr. characters left unred in cin buffer: " << s.length() << endl;
  

    output_file << "\nQ1: (cin only) What happens when you run the code above? Explain why" << endl;
    string answer = "I entered 10 and the flag is false, but when I enter 4.5 it still sets the flag to false and it extracts the value 4, \n and it continues to loop without accepting any other values "; // enter your answer in between ""
    output_file << "Answer Q1: " << answer << endl;

    cout << "\nCode for Q2 and Q3" << endl;
     //uncomment when you get to Q2 and Q3.5
    
    for (int i = 0; i < array_values.size(); i++)
    {
        cout << "\tEnter the value " << array_values.at(i) << endl;
        cout << "\tEnter an int "; 
        cin >> val;

        cout << "\n\tCheck fail flag in cin " <<  cin.fail()<< endl;

        string s; 
        getline(cin,s);
        cout << "\tCheck what is left unread in the cin buffer: Length =" << s.length() 
             << "\tString " << s << endl;
        if (cin.fail())
        {
            cin.clear(); // clears the flags   
            cin.ignore(INT_MAX,'\n'); // ignore all characters from cin until new line '\n'
            cout << "\tERROR: The value you entered is not an integer. Try again." << endl;
        }
        
        cout << "\tYou entered " << val << endl << endl;
    }  
    

    output_file << "\nQ2: (cin + fail+ignore) What happens when you run the code above? Explain why." << endl;
    answer = "I entered 10 and it set the fail flag to false, then I entered 4.5 and it set the flag to false, but it shows that.5 was unread in the buffer \n, for abc and a it sets the fail flag to true and explains it is not an integer"; // enter your answer in between ""
    output_file << "Answer Q2: " << answer << endl;

    output_file << "\nQ3: Is the problem of reading an integer value solved? Explain your reasoning." << endl;
    answer = "No, because for 4.5 it set the flag to false and it extracted 4 without saying it is not an integer"; // enter your answer in between ""
    output_file << "Answer Q3: " << answer << endl;

    cout << "\nCode for Q4" << endl;
    // uncomment when you get to Q4
  
    /*for (int i = 0; i < array_values.size(); i++)
    {
        cout << "\tEnter the value " << array_values.at(i) << endl;
        cout << "\tEnter an int "; 
        string s;
        getline(cin,s);     // read a line of input from the cin buffer - 
                            // up to and including '\n'
        val = stoi(s);  // stoi = converts a string into an integer 
                            // read more at http://www.cplusplus.com/reference/string/stoi/?kw=stoi
        cout << "\tYou entered " << val << endl << endl;
    } */ 

    output_file << "\nQ4: (getline only) What happens when you run the code above? Explain why." << endl;
    answer = "It allows you to enter the value for 10 and displays it, \n I then was able to enter 4.5 but it showed I entered 4, \n and then when I entered abc the program displayed an error message thrown by stoi function and then it terminates"; // enter your answer in between ""
    output_file << "Answer Q4: " << answer << endl;

    // Comment the for loop for Q4 above - leave the answer to Q4
    
    cout << "\nCode for Q5" << endl;
    for (int i = 0; i < array_values.size(); i++)
    {
        cout << "\tEnter the value " << array_values.at(i) << endl;
        cout << "\tEnter an int "; 
        string s;
        getline(cin,s); 
 
        try{   // read more about exceptions at https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
            val = stoi(s);
        }
        catch(const std::invalid_argument& ia)
        {
            cerr << "\tInvalid argument: " << ia.what() << '\n';
        }
        cout << "\tYou entered " << val << endl << endl;
    }
    cout << "\n\tCheck fail flag in cin " <<  cin.fail()<< endl;
    output_file << "\nQ5: (getline+stoi) What happens when you run the code above? Explain why." << endl;
    answer = "when you run the code you are able to enter 10 and it displays 10, then I entered 4.5, but it displays 4. Then when you enter abc and a then the program displays 4 and the error message from stoi. This is because the try and catch exception catches error and displays the message but it does not stop the program."; // enter your answer in between ""
    output_file << "Answer Q5: " << answer << endl;

    //6. Q6 Add code to enter integer values from the keyboard correctly = accept only 10, not 4.5, abc or a
    cout << "\nCode for Q6" << endl;
    for (int i = 0; i < array_values.size(); i++)
    {
        cout << "\tEnter the value " << array_values.at(i) << endl;
        cout << "\tEnter an int ";
        string s;
        getline(cin, s);
        bool floatingPoint = false;
        for (int x = 0; x < s.length(); x++){
            if ((s[x] == '.') || (s[x] == '/')){
                floatingPoint = true;
                cout << "\tIncorrect, you entered:" << s << endl;
                break;
            }
        }
        if (floatingPoint == false){
            try{   // read more about exceptions at https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
                val = stoi(s);
                cout << "\tCorrect, you entered: " << s << endl;
            
            }
            catch(const std::invalid_argument& ia)
            {
                cerr << "\tIncorrect, you entered: " << s << '\n';
            }
        }


        // add your code - it should ask you to type the value you see at line 134. 
        // it should display "Correct 10 " when you enter 10; 
        // it should display "Incorrect ", followed by the value you entered, for the rest of of the values 
        // (4.5, abc or a) 
        // YOUR CODE NEEDS TO DETECT that 4.5 is not an integer
    }
    output_file << "\nQ6: Explain your method to validate integer values entered" << endl;
    answer = "My method to validate integer values entered is to have the user input the value,\n then the input will be stored in a vairable s, after this\n the string s will be looped through to check if there is a decimal point or fraction present.\n if there is the code will print out it is incorrect and the value of s. If it does not find anything in the loop, the code will attempt to change the string to an integer and if it can it print it is correct and the value.\n if it cannot the code will print it is incorrect and the value you entered."; // enter your answer in between ""
    output_file << "Answer Q6: " << answer << endl;
    output_file.close();

}
