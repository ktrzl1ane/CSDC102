#include <iostream> 

int main () {
    char pixel_art[5][5] = {
        {' ', '*', '*', '*', ' '},  // only fill the visible part
        {'*', ' ', ' ', ' ', '*'},
        {'*', ' ', ' ', ' ', '*'},
        {' ', '*', ' ', '*', ' '},
        {' ', ' ', '*', ' ', ' '}
    };

     for(int i = 0; i <= 4; i++){
        for(int j = 0; j <= 4; j++){
            std::cout << pixel_art[i][j];
        }
        std::cout << std::endl;
    }
  
    return 0;
}

