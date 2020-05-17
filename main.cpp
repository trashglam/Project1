#include <iostream>
#include <random>
using namespace std;

//global - idk
unsigned int remGuesses;


string wordBank[20] = {"memory", "array", "interpreter", "process", "integer", "file", "double", "thread", "string", "float", "argument", "structure", "character", "byte", "debugger", "index", "function", "compiler", "class", "pointer"};

//choose word from word bank
int randInt(int low, int high) {
  random_device rd;
  default_random_engine generator{rd()};
  uniform_int_distribution<int> distribution(low,high);
  return distribution(generator);
}



int main() {
  //I really don't know what this part is but it was in the example 
  //pretty sure this contains the code to select the secret word to be guessed, and whether the secret word will be displayed -j
  cout << "Debug? [y/n] ";
  char deb;
  cin >> deb;
  int sec = randInt(1, 20);
  string sword = wordBank[sec];
  if (deb == 'y') {
    cout << "Secret: " << sword << endl;
  }
  
  //difficulty selection
 cout << "'e' for easy, 'i' for intermediate, 'h' for hard" << endl << "> ";
 char diff;
 cin >> diff;
   if (diff == 'e') 
   {
      cout << "Guesses: 15" << endl;
      remGuesses = 15;
    }
     if (diff == 'i') 
     {
      cout << "Guesses: 10" << endl;
      remGuesses = 10;
    } 
     if (diff == 'h') 
     {
      cout << "Guesses: 5" << endl;
      remGuesses = 5;
      }
  while (diff != 'e' && diff != 'i' && diff != 'h') 
  {
    cout << "Invalid difficulty." << endl;
    cout << "'e' for easy, 'i' for intermediate, 'h' for hard" << endl << "> "; 
    cin >> diff;
    
  }

  //dashes for secret word
  int wordLen = sword.length();
  for (int i = 1; i <= wordLen; i++) {
    cout << "-";
  }
  cout << endl;

//guessing characters
//can't get the loop to continue back up for more than one guess
  string guess; 
  cin >> guess;
  int foundd = sword.find(guess) + 1; 
  size_t found = sword.find(guess);
 
  while (remGuesses > 0) {   cout << "Guesses: " << remGuesses << endl;
    if (guess == "solve") 
    {
    cout << "Solve" << endl << "> ";
    string solution; 
    cin >> solution;
    if (solution ==sword) {
      cout << "You Won!";
break;
    }

    }
    if (guess.length() > 1 && guess != "solve") {
    cout << "Guess is too many letters." << endl;
    }
    continue;
   
    if (foundd != string::npos) 
  {
    cout << "Found a '" << guess << "'!" << endl;
    for (int n = 1; n <= wordLen; ++n) 
    {
      while (n == foundd) {
        cout << guess;
        
      }
      
      cout << "-";
      break;
    }
    cout << endl;
    } else if (foundd == string::npos) {
      cout << "Did not find a '" << guess << "'..." << endl;
      remGuesses--;
      cout << "Guesses: " << remGuesses << endl;
    }
    break;
    continue;
    //if (remGuesses > 0) {
   // cout << "Guesses: " << remGuesses << endl;
   // continue;
    }
  
  
  

}