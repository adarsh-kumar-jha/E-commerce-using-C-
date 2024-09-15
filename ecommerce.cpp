#include<bits/stdc++.h> 
#include <vector> 
#include <unordered_map> 
#include <iomanip> 
#include <conio.h>   
#include <windows.h>   
#include <limits> 
using namespace std; 
class Product { 
public: 
string id; 
string name; 
f
 loat price; 
string category; 
Product(string pid, string pname, float pprice, string pcategory) 
: id(pid), name(pname), price(pprice), category(pcategory) {} 
}; 
 
class CartItem { 
public: 
    Product product; 
    int quantity; 
 
    CartItem(Product p, int q) : product(p), quantity(q) {} 
 
    float getTotalCost() const { 
        return product.price * quantity; 
    } 
}; 
 
class Cart { 
private: 
    unordered_map<string, CartItem> items; 
    bool referralDiscount = false; 
 
public: 
    void addItem(Product product, int quantity) { 
        auto it = items.find(product.id); 
        if (it != items.end()) { 
            it->second.quantity += quantity;   
        } else { 
            items.emplace(product.id, CartItem(product, quantity));   
        } 
        cout << quantity << " " << product.name << "(s) added to the cart.\n"; 
    } 
 
    void removeItem(string productID, int quantity) { 
        auto it = items.find(productID); 
        if (it != items.end()) { 
            it->second.quantity -= quantity; 
            if (it->second.quantity <= 0) { 
                items.erase(it);   
                cout << "Product removed from the cart.\n"; 
            } else { 
                cout << quantity << " item(s) removed. Remaining quantity: " << it->second.quantity << endl; 
            } 
        } else { 
            cout << "Product not found in cart.\n"; 
        } 
    } 
 
    void viewCart() { 
        float total = 0; 
        if (items.empty()) { 
            cout << "Your cart is empty.\n"; 
            return; 
        } 
 
        cout << "\nYour Cart:\n"; 
        for (const auto& pair : items) { 
            const CartItem& item = pair.second; 
            float itemTotal = item.getTotalCost(); 
            total += itemTotal; 
            cout << item.product.name << " - Quantity: " << item.quantity 
                 << ", Price: $" << fixed << setprecision(2) << item.product.price 
                 << ", Total: $" << itemTotal << endl; 
        } 
        cout << "Total (before discounts): $" << total << endl; 
    } 
 
    void checkout() { 
        float total = 0, discount = 0; 
        for (const auto& pair : items) { 
            const CartItem& item = pair.second; 
            total += item.getTotalCost(); 
 
            if (item.product.category == "Fashion" && item.quantity >= 2) { 
                discount += (item.quantity / 2) * item.product.price; 
            } 
            else if (item.product.category == "Electronics") { 
                discount += item.getTotalCost() * 0.10; 
            } 
        } 
 
        if (referralDiscount) { 
            discount += total * 0.15; 
            cout << "Applying referral discount of 15%...\n"; 
        } 
 
        cout << "\nApplying discounts...\n"; 
        total -= discount; 
        cout << "Final Total in USD: $" << fixed << setprecision(2) << total << endl; 
 
        string choice; 
        cout << "\nWould you like to view it in a different currency? (yes/no): "; 
        cin >> choice; 
        if (choice == "yes") { 
            string currency; 
            cout << "Available Currencies: EUR, GBP, INR\n"; 
            cout << "Enter currency: "; 
            cin >> currency; 
 
            if (currency == "EUR") { 
                cout << "Final Total in EUR: €" << fixed << setprecision(2) << total * 0.85 << endl; 
            } else if (currency == "GBP") { 
                cout << "Final Total in GBP: £" << fixed << setprecision(2) << total * 0.75 << endl; 
            } else if (currency == "INR") { 
                cout << "Final Total in INR: ₹" << fixed << setprecision(2) << total * 80 << endl; 
            } else { 
                cout << "Currency not supported!\n"; 
            } 
        } 
    } 
 
    void applyReferralDiscount(int referrals) { 
        if (referrals >= 10) { 
            referralDiscount = true; 
            cout << "\nCongratulations! You've referred 10 people and earned a 15% discount.\n"; 
        } else { 
            cout << "\nYou have referred only " << referrals << " people. Refer "  
                 << 10 - referrals << " more people to earn a 15% discount.\n"; 
        } 
    } 
 
    void listDiscounts() { 
        cout << "\nAvailable Discounts:\n"; 
        cout << "1. Buy 1 Get 1 Free on Fashion items\n"; 
        cout << "2. 10% Off on Electronics\n"; 
        cout << "3. 15% Referral Discount after 10 successful referrals\n"; 
    } 
}; 
 
 
bool gameOver; 
const int width = 20; 
const int height = 17; 
int x, y, fruitX, fruitY, score; 
int tailX[100], tailY[100]; 
int nTail; 
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; 
eDirection dir; 
 
void setup() { 
    gameOver = false; 
    dir = STOP; 
    x = width / 2; 
    y = height / 2; 
    fruitX = rand() % width; 
    fruitY = rand() % height; 
    score = 0; 
} 
 
void draw() { 
    system("cls");   
    for (int i = 0; i < width + 2; i++) cout << "#"; 
    cout << endl; 
 
    for (int i = 0; i < height; i++) { 
        for (int j = 0; j < width; j++) { 
            if (j == 0) cout << "#"; 
            if (i == y && j == x) 
                cout << "       ";   
            else if (i == fruitY && j == fruitX) 
                cout << "F";   
            else { 
                bool print = false; 
                for (int k = 0; k < nTail; k++) { 
                    if (tailX[k] == j && tailY[k] == i) { 
                        cout << "o";   
                        print = true; 
                    } 
                } 
                if (!print) cout << " "; 
            } 
            if (j == width - 1) cout << "#"; 
        } 
        cout << endl; 
    } 
 
    for (int i = 0; i < width + 2; i++) cout << "#"; 
    cout << endl; 
    cout << "Score: " << score << endl; 
} 
 
void input() { 
    if (_kbhit()) { 
        switch (_getch()) { 
        case 'a': 
            dir = LEFT; 
            break; 
        case 'd': 
            dir = RIGHT; 
            break; 
        case 'w': 
            dir = UP; 
            break; 
        case 's': 
            dir = DOWN; 
            break; 
        case 'x': 
            gameOver = true;   
            break; 
        } 
    } 
} 
 
void logic() { 
    int prevX = tailX[0]; 
    int prevY = tailY[0]; 
    int prev2X, prev2Y; 
    tailX[0] = x; 
    tailY[0] = y; 
    for (int i = 1; i < nTail; i++) { 
        prev2X = tailX[i]; 
        prev2Y = tailY[i]; 
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
    Product p1("1", "Shirt", 25.99, "Fashion"); 
    Product p2("2", "Laptop", 999.99, "Electronics"); 
    Product p3("3", "Shoes", 49.99, "Fashion"); 
 
    int choice, quantity, referrals; 
    string productID; 
    bool exit = false; 
 
    while (!exit) { 
        cout << "\nShopping Cart Menu:\n"; 
        cout << "1. Add Item\n"; 
        cout << "2. Remove Item\n"; 
        cout << "3. View Cart\n"; 
        cout << "4. Apply Referral Discount\n"; 
        cout << "5. Checkout\n"; 
        cout << "6. List Available Discounts\n"; 
        cout << "7. Play Snake Game\n"; 
        cout << "8. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
        case 1: 
            cout << "Available Products:\n"; 
            cout << "1. Shirt (Fashion) - $25.99\n"; 
            cout << "2. Laptop (Electronics) - $999.99\n"; 
            cout << "3. Shoes (Fashion) - $49.99\n"; 
            cout << "Enter product ID to add: "; 
            cin >> productID; 
            cout << "Enter quantity: "; 
            cin >> quantity; 
            if (productID == "1") cart.addItem(p1, quantity); 
            else if (productID == "2") cart.addItem(p2, quantity); 
            else if (productID == "3") cart.addItem(p3, quantity); 
            else cout << "Invalid product ID.\n"; 
            break; 
        case 2: 
            cout << "Enter product ID to remove: "; 
            cin >> productID; 
            cout << "Enter quantity: "; 
            cin >> quantity; 
            cart.removeItem(productID, quantity); 
            break; 
        case 3: 
            cart.viewCart(); 
            break; 
        case 4: 
            cout << "Enter the number of referrals: "; 
            cin >> referrals; 
            cart.applyReferralDiscount(referrals); 
            break; 
        case 5: 
            cart.checkout(); 
            break; 
        case 6: 
            cart.listDiscounts(); 
            break; 
        case 7: 
            playSnakeGame(); 
            break; 
        case 8: 
            exit = true; 
            break; 
        default: 
            cout << "Invalid choice! Try again.\n"; 
        } 
    } 
 
    return 0; 
} 
