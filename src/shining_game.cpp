#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function prototypes
void introduction();
int getInput(const map<int, string> &choices);
void roomOne(int choice);
void roomTwo(int choice);
void roomThree(int choice);
void roomFour(int choice);
void gameOver();

int main()
{
  introduction();
  int choice = getInput({{1, "Enter the hotel"}, {2, "Leave the hotel"}});
   if (choice == 2)
  {
    gameOver();
    return 0;
  }
  roomOne(choice);

  return 0;
}

void introduction()
{
  cout << "Welcome to the Shining game!" << endl;
  cout << "You find yourself in front of the haunted Overlook Hotel." << endl;
  cout << R"(
       __|__
      /=====\
     /=======\
    /=========\
   /====/=\====\
  /====/===\====\
 /====/=====\====\
|_|==|=======|==|_|
|_|==|=======|==|_|
|_|==|=+___+=|==|_|
|_|==|=|   |=|==|_|
|_|==|=|   |=|==|_|
|_|==|=|___|=|==|_|)"
       << endl;
}

int getInput(const map<int, string> &choices)
{
  int choice = 0;

  cout << "|What would you like to do?" << endl;
  for (const auto &[key, value] : choices)
  {
    cout << key << ". " << value << endl;
  }

  while (choices.find(choice) == choices.end())
  {
    cout << "|Enter a valid choice: ";
    cin >> choice;
  }

  return choice;
}

void roomOne(int choice)
{

  cout << "You enter the hotel lobby and see the reception desk. You're here to be the caretaker for the winter." << endl;
  cout << R"(
  ______________
 /_============_\
 |_  |  |  |   _| 
 |_  |  |  |   _|
 |_  |  |  |   _|
 |___|__|__|__|_|)"
       << endl;
  choice = getInput({{1, "Go to the bar"}, {2, "Check in at the reception desk"}});
  roomTwo(choice);
}

void roomTwo(int choice)
{
  if (choice == 1)
  {
    cout << "You enter the empty bar and feel a sudden chill. You decide to check in at the reception desk instead." << endl;
  }

  cout << "You meet the hotel manager who gives you a tour, including the infamous Room 237." << endl;
  choice = getInput({{1, "Explore Room 237"}, {2, "Continue the tour"}});

  if (choice == 1)
  {
    gameOver();
    return;
  }

  roomThree(choice);
}

void roomThree(int choice)
{
  cout << "The manager shows you the boiler room and explains that it needs to be checked regularly." << endl;
  cout << R"(
  ________
 /        \
|          |
|  .----.  |
|  |    |  |
|__|____|__|)"
       << endl;
  choice = getInput({{1, "Go to your living quarters"}, {2, "Return to the lobby"}});

  roomFour(choice);
}

void roomFour(int choice)
{
  if (choice == 2)
  {
    cout << "You return to the lobby and start getting bored throwing a ball against a wall, you go to your living quarters." << endl;
  }
  cout << "You settle into your living quarters with your family and begin your caretaking duties." << endl;
  cout << "As days go by, you start to feel the hotel's sinister influence affecting you and your family." << endl;
  cout << "The hotel's dark power eventually drives you mad, and you chase your family with an axe." << endl;
  choice = getInput({{1, "Try to fight the madness"}, {2, "Give in to the madness"}});

  if (choice == 1)
  {
    cout << "You struggle to fight the madness, and in the end, your family manages to escape the hotel. You remain trapped inside, a victim of the hotel's dark influence." << endl;
  }
  else
  {
    cout << "You fully succumb to the madness, and the hotel consumes you and your family." << endl;
  }

  gameOver();
}

void gameOver()
{
  cout << "Game Over. More coming soon!" << endl;
}