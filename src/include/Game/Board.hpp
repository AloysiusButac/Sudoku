#include "Board.h"

/////////////////////////////////////////////////////
/// TODO: Revise the get ROW, COL, and BLOCK functions
/////////////////////////////////////////////////////

std::array<int, 9> Board::getRow(int x, int y) {
    std::array<int, 9> row;
    for(int i = 0; i < 9; i++) {
        row[i] = board[i][y];
    }
    return row;
}
std::array<int, 9> Board::getCol(int x, int y) {
    std::array<int, 9> col;
    for(int i = 0; i < 9; i++) {
        col[i] = board[x][i];
    }
    return col;
}
std::array<int, 9> Board::getBlock(int x, int y) {
    // TODO: Fix logic
    std::vector<int> tmp;
    std::array<int, 9> blk;

    // int sq_index = y*9 + x;

    for(int i = 0; i < 81; i++) {
        if(i % 9 / 3 == y / 3 && i / 9 / 3 == x / 3) { // WACKY MATH
            tmp.push_back(board[i/9][i%9]);
        }
    }
    std::move(tmp.begin(), tmp.begin()+9, blk.begin());
    
    /* DEBUG STUFF */
    std::cout << "\n     -> Coord: [" << x << ", " << y << "] ";
    std::cout << " Value [" << board[x][y] << "] ";
    std::cout << " Block: [ ";
    for(auto n : blk) {
        std::cout << n << " ";
    }
    std::cout << " ]\n";
    /* DEBUG STUFF END*/

    return blk;
}
void Board::NewGameBoard() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            board[j][i] = j+1;
        }
    }
}
bool Board::isValidPos(int x, int y, int value) {
    return isValidRow(x, y, value) && isValidColoumn(x, y, value) && isValidBlock(x, y, value);
}
bool Board::isValidRow(int x, int y, int value) {
    auto row = getRow(x, y);
    for(int i = 0; i < 9; i++) {
        if(value == row[i]) {
            return false;
        }
    }
    return true;
}
bool Board::isValidColoumn(int x, int y, int value) {
    auto col = getCol(x, y);
    for(int i = 0; i < 9; i++) {
        if(value == col[i]) {
            return false;
        }
    }
    return true;
}
bool Board::isValidBlock(int x, int y, int value) {
    auto blk = getBlock(x, y);
    for(int i = 0; i < 9; i++) {
        if(value == blk[i]) {
            return false;
        }
    }
    return true;
}
bool Board::isBoardFull() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == 0)
                return false;
        }
    }
    return true;
}
void Board::randomize(int b[9][9]) {
    // TODO: LOGIC STILL BROKEN
    /* create initial random number */
    time(0);
    int r = std::rand() % 9;
    int x, y;
    /* loop through each cell/square */
    for(int i = 0; i < 81; i++) {
        x = i % 9;
        y = i / 9;
        /* if current cell is empty */
        if(b[x][y] == 0) {
            int tmp = r;
            /* fill with random number until it is a valid number */
            for(int n = 1; n <= 9; n++) {
                /* is value valid */
                if(isValidPos(x, y, r)) {
                    b[x][y] = r;
                    break;
                }
                /* value is not valid */
                r = rand() % 9;
                for(int k = 0; k < 9; k++) {
                    if(r == tmp) {
                        break;
                    }
                    r = rand() % 9;
                }
            }
        }
    }
    std::cout << "\n";
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << b[i][j] << " ";
        }
    }
    std::cout << "\n";
    auto tmpblk = getBlock(0,0);
    for(int i = 0; i < tmpblk.size(); i++) {
        std::cout << tmpblk[i] << " ";
    }
    std::cout << "\n";
}
void Board::fillBoardWithInput(std::array<int, 81>& values) {
    for(int i = 0; i < 81; i++) {
        board[i % 9][i / 9] = values[i];
    }
}
void Board::removeCells() {
    time(0);
    int n = rand() % 10;
    for(int i = 0; i < 81; i++) {
        if(n >= 3) {
            board[i % 9][i / 9] = 0;
        }
        n = rand() % 10;
    }
}
bool Board::checkInput(int x, int y, int value) {
    if(x < 9 && x > -1 && y < 9 && y > -1 && value <= 9) {
        return isValidPos(x, y, value);
    }
    return false;
}
void Board::inputValue(int x, int y, int value) {
    if(!checkInput(x, y, value)) {
        printf("\n%s [%d][%d][%d] - row[%s] col[%s] pos[%s}].\t", ">>> Invalid input.", x, y, value, isValidRow(x,y,value) ? "true" : "false", isValidColoumn(x,y,value) ? "true" : "false", isValidPos(x,y,value) ? "true" : "false");
    } else {
        printf("Valid input [%d][%d][%d]", x, y, value);
        board[x][y] = value;
    }
}



