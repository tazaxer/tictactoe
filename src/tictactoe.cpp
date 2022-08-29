//
//  main.cpp
//  tictactoe
//
//  Created by Dennis Gyftakis on 29/8/22.
//

#include <iostream>
using namespace std;

string name1;
string name2;
char place[3][3] = {{'7','8','9'}, {'4','5','6'}, {'1','2','3'}};
int row;
int column;
char token = 'X';
bool tieGame = false;

void printStructure() {
    cout<< "    |    |    \n";
    cout<< " "<<place[0][0]<<"  | "<<place[0][1]<<"  | "<<place[0][2]<<" \n";
    cout<< "____|____|____\n";
    cout<< "    |    |    \n";
    cout<< " "<<place[1][0]<<"  | "<<place[1][1]<<"  | "<<place[1][2]<<" \n";
    cout<< "____|____|____\n";
    cout<< "    |    |    \n";
    cout<< " "<<place[2][0]<<"  | "<<place[2][1]<<"  | "<<place[2][2]<<" \n";
    cout<< "    |    |    \n";
    
}

bool checkWinOrDraw() {
    for (int i = 0; i < 3; i++) {
        if ((place[i][0]==place[i][1] && place[i][0]==place[i][2]) /*horizontal*/ || (place[0][i]==place[1][i] && place[0][i]==place[2][i]) /*vertical*/ ) return true;
    }
    
    if ((place[1][1]==place[2][2] && place[1][1]==place[0][0]) /*diagonal like (\) */ || (place[2][0]==place[1][1] && place[2][0]==place[0][2]) /*diagonal like (/) */ ) return true;
    
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (place[i][j] == 'X' || place[i][j] == 'O') {
                count++;
            }
        }
    }
    
    if (count == 9) {
        tieGame = true;
    }
    
    return false;
}

void getChoice() {
    int digit;
    
    cout<<"Please choose a number ("<<(token=='X'? name1 : name2)<<"'s turn): ";
    cin>>digit;
    cout<<"You entered: "<<digit<<"\n";
    
    switch (digit) {
        case 7:
            row = 0;
            column = 0;
            break;
        case 8:
            row = 0;
            column = 1;
            break;
        case 9:
            row = 0;
            column = 2;
            break;
        case 4:
            row = 1;
            column = 0;
            break;
        case 5:
            row = 1;
            column = 1;
            break;
        case 6:
            row = 1;
            column = 2;
            break;
        case 1:
            row = 2;
            column = 0;
            break;
        case 2:
            row = 2;
            column = 1;
            break;
        case 3:
            row = 2;
            column = 2;
            break;
        default:
            cout << "Invalid option!\n";
            getChoice();
            break;
    }
    
    if (token == 'X' && place[row][column] != 'X' && place[row][column] != 'O') {
        place[row][column] = 'X';
        printStructure();
        if (checkWinOrDraw()) {
            cout << name1 << " is the winner!\n";
            exit(0);
        } else if (tieGame) {
            cout << "Tie!\n";
            exit(0);
        }
        token = 'O';
    } else if (token == 'O' && place[row][column] != 'X' && place[row][column] != 'O') {
        place[row][column] = 'O';
        printStructure();
        if (checkWinOrDraw()) {
            cout << name2 << " is the winner!\n";
            exit(0);
        } else if (tieGame) {
            cout << "Tie\n";
            exit(0);
        }
        token = 'X';
    } else {
        printStructure();
        cout << "This place is already taken!\n";
        getChoice();
    }
    
    getChoice();
}

int main(int argc, const char * argv[]) {
    cout << "Hey, welcome to Tic Tac Toe by Dennis Gyftakis!\n";
    cout << "What's the name of the first player: ";
    cin >> name1;
    cout << "Hello " << name1 << ", you'll play with X!\n";
    cout << "What's the name of the second player: ";
    cin >> name2;
    cout << "Hello " << name2 << ", you'll play with O!\n";
    
    
    printStructure();
    getChoice();
    
    return 0;
}
