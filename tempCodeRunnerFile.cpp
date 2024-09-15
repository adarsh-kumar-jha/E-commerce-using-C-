        tailX[i] = prevX; 
        tailY[i] = prevY; 
        prevX = prev2X; 
        prevY = prev2Y; 
    } 
    switch (dir) { 
    case LEFT: 
        x--; 
        break; 
    case RIGHT: 
        x++; 
        break; 
    case UP: 
        y--; 
        break; 
    case DOWN: 
        y++; 
        break; 
    default: 
        break; 
    } 
 
    if (x >= width) x = 0; else if (x < 0) x = width - 1; 
    if (y >= height) y = 0; else if (y < 0) y = height - 1; 
 
    for (int i = 0; i < nTail; i++) 
        if (tailX[i] == x && tailY[i] == y) 
            gameOver = true; 
 
    if (x == fruitX && y == fruitY) { 
        score += 10; 
        fruitX = rand() % width; 
        fruitY = rand() % height; 
        nTail++; 
    } 
} 
 
void playSnakeGame() { 
    setup(); 
    while (!gameOver) { 
        draw(); 
        input(); 
        logic(); 
        Sleep(100); 
    } 
    cout << "Game Over! Your final score: " << score << endl; 
} 
 
// Main application 
int main() { 
    Cart cart; 