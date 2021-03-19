#include <iostream>
#include <random>
#include <stdlib.h>

using namespace std;

string board[3][3] = {{"1A", "1B", "1C"} , {"2A", "2B", "2C"}, {"3A", "3B", "3C"}};

char current_marker;
int current_player;

void drawBoard();
bool placeMarker(string a);
int champion();
void change_player();
void game();
bool computerTurn(int current_player);
int humanMove(string a);
int playAgain();

//draws board
void drawBoard ()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "-----------\n";
}

// turns input string into board move
int humanMove(string a) {

    int slot;

    if (a == "1A") {
        slot = 1;
    }
    if (a == "1B") {
        slot = 2;
    }
    if (a == "1C") {
        slot = 3;
    }
    if (a == "2A") {
        slot = 4;
    }
    if (a == "2B") {
        slot = 5;
    }
    if (a == "2C") {
        slot = 6;
    }
    if (a == "3A") {
        slot = 7;
    }
    if (a == "3B") {
        slot = 8;
    }
    if (a == "3C") {
        slot = 9;
    }
    return slot;
}


//function to place marks on board
bool placeMarker(int slot) {

    int row = slot / 3;
    int col;

    if(slot % 3 == 0) {
        row = row - 1;
        col = 2;
    }
    else {
        col = slot % 3 - 1;
    }
    if(board[row][col] != "X" &&board[row][col] != "O") {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

//checks for champion
int champion()
{
    for (int i = 0; i < 3; i++)
    {
        // rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return current_player;
        }
        // columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return current_player;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return current_player;
    }

    return 0;

}

//switches from human to computer
void change_player()
{
    if (current_marker == 'O')
    {
        current_marker = 'X';
    } else {
        current_marker = 'O';
    }
    if (current_player == 1)
    {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

//checks if it is the computers turn
bool computerTurn(int current_player)
{
    if (current_player == 2)
    {
        return 1;
    } else {
        return 0;
    }
}

//flips coin to decide who goes first
int coinFlip()
{
    current_player = rand() % 2 + 1;
    return current_player;
}

//game and intro
void game()
{

    char coin;

    cout << "************************************" << endl;
    cout << "* Welcome to the human vs computer *" << endl;
    cout << "* ------  TIC TAC TOE GAME! -----  *" << endl;
    cout << "* This game costs a nickel to play *" << endl;
    cout << "*  type the number '5' to insert a *"<<endl;
    cout << "*    nickel and play the game.     *"<<endl;
    cout << "* We will also flip that nickel to *" << endl;
    cout << "*       decide who goes first      *"  << endl;
    cout << "************************************" << endl;

    cin >> coin;

    if (coin == '5') {
        current_player = coinFlip();
    }

    else {
        cout << "press '5' on your device to flip a coin" << endl;
    }

    char marker_player1 = 'X';

    if (current_player == 1) {
        cout << "Human goes first" << endl;
        drawBoard();
    }
    else if (current_player == 2) {
        cout << "The computer goes first" << endl;
    }

    current_marker = marker_player1;

    int player_won;

    for(int i = 0; i < 9; i++)
    {
        string a;
        int slot;

        if(computerTurn(current_player) == 0) {
            cout << "Human's turn! enter a slot" << endl;
            drawBoard();
            cin >> a;
            slot = humanMove(a);
        }
        if (computerTurn(current_player) == 1)
        {

            slot = rand() % 9 + 1;
            string b = "hello";

            if (slot == 1) {
                b = "1A";
            }
            if (slot == 2) {
                b = "1B";
            }
            if (slot == 3){
                b = "1C";
            }
            if (slot == 4) {
                b = "2A";
            }
            if (slot == 5) {
                b = "2B";
            }
            if (slot == 6){
                b = "2C";
            }
            if (slot == 7) {
                b = "3A";
            }
            if (slot == 8) {
                b = "3B";
            }
            if (slot == 9){
                b = "3C";
            }

            cout << "The computer chose slot " << b << endl;
        }

        if (slot < 1 || slot > 9) {
            cout << "Whoops! THAT SPOT IS TAKEN" << endl;
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Try again! THAT SPOT IS TAKEN!" << endl;
            i--;
            continue;
        }

        player_won = champion();

        if (player_won == 1) {
            cout << "Congratulations human, you are the champ! You were able to beat modern technology!"<< endl;
            break;
        }
        if (player_won == 2)
        {
            cout << "No surprise here, THE COMPUTER IS THE CHAMPION! Better luck next time!"<< endl;
            break;
        }

        change_player();
    }
    if (player_won == 0)
    {
        cout << "Well that was uneventful...TIE GAME" << endl;
        }
}

//allows player to play again
int playAgain()
{
    char a;
    cout << "Would you like to play the game again? type Y for yes and N to quit" << endl;
    cin >> a;
    if (a == 'Y') {
        game();
    }
    else {
        exit(0);
    }
}
//main function
int main()
{
    game();
    playAgain();
}
