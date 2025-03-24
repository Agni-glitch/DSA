#include <iostream>
using namespace std;
void tower_of_hanoi(int n, char source, char destination, char auxiliary, int &moveCount) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        moveCount++;
        return;
    }
    tower_of_hanoi(n - 1, source, auxiliary, destination,moveCount);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    moveCount++;
    tower_of_hanoi(n - 1, auxiliary, destination, source,moveCount);
}

int main() {
    int n = 3;  
    int moveCount =0;
    tower_of_hanoi(n, 'A', 'C', 'B',moveCount); 
    cout << "Total number of moves: " << moveCount << endl;
    return 0;
}
