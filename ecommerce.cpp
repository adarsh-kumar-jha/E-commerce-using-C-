#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <limits>
using namespace std;

class User {
public:
    string username;
    string password;

    bool signIn(string uname, string pwd) {
        if (username == uname && password == pwd) {
            cout << "Login Successful! Welcome " << username << endl;
            return true;
        } else {
            cout << "Invalid Credentials. Please try again.\n";
            return false;
        }
    }

    void signUp(string uname, string pwd) {
        username = uname;
        password = pwd;
        cout << "Account created successfully!\n";
    }
};

class Product {
public:
    string id;
    string name;
    float price;
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
    bool otherDiscount = false;

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
            } else if (item.product.category == "Electronics") {
                discount += item.getTotalCost() * 0.10;
            }
        }

        if (referralDiscount) {
            discount += total * 0.15;
            cout << "Applying referral discount of 15%...\n";
        }

        if (otherDiscount) {
            discount += total * 0.10;
            cout << "Applying additional discount of 10%...\n";
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

    void applyOtherDiscount() {
        otherDiscount = true;
        cout << "An additional 10% discount has been applied!\n";
    }

    void listDiscounts() {
        cout << "\nAvailable Discounts:\n";
        cout << "1. Buy 1 Get 1 Free on Fashion items\n";
        cout << "2. 10% Off on Electronics\n";
        cout << "3. 15% Referral Discount after 10 successful referrals\n";
        cout << "4. 10% Special Discount\n";
    }
};

// Add simple game feature
void playGame() {
    string choice;
    cout << "Do you want to play a game while your product is being prepared? (yes/no): ";
    cin >> choice;
    
    if (choice == "yes") {
        cout << "Playing a simple guessing game...\n";
        int number = rand() % 10 + 1;
        int guess;
        cout << "Guess a number between 1 and 10: ";
        cin >> guess;

        if (guess == number) {
            cout << "Congratulations! You guessed the right number!\n";
        } else {
            cout << "Sorry! The correct number was " << number << ".\n";
        }

        string continuePlaying;
        cout << "Do you want to play again or quit? (play/quit): ";
        cin >> continuePlaying;

        if (continuePlaying == "quit") {
            cout << "Returning to the main menu...\n";
            return;
        } else {
            playGame();  // Recursive call to replay
        }
    } else {
        cout << "Skipping game. Returning to main menu...\n";
    }
}

// Main application
int main() {
    Cart cart;
    Product p1("1", "Shirt", 25.99, "Fashion");
    Product p2("2", "Laptop", 999.99, "Electronics");
    Product p3("3", "Shoes", 49.99, "Fashion");

    User user;
    string username, password;
    int signChoice;

    cout << "Welcome! Please choose an option:\n";
    cout << "1. Sign Up\n2. Sign In\n";
    cin >> signChoice;

    if (signChoice == 1) {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        user.signUp(username, password);
    } else {
        bool loggedIn = false;
        while (!loggedIn) {
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            loggedIn = user.signIn(username, password);
        }
    }

    // Main shopping menu
    int choice, quantity, referrals;
    string productID;
    bool exit = false;

    while (!exit) {
        cout << "\nShopping Cart Menu:\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. View Cart\n";
        cout << "4. Apply Referral Discount\n";
        cout << "5. Apply Other Discounts\n";
        cout << "6. Checkout\n";
        cout << "7. List Available Discounts\n";
        cout << "8. Play Game During Checkout\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Available Products:\n";
            cout << "1. Shirt (Fashion) - $25.99\n";
            cout << "2. Laptop (Electronics) - $999.99\n";
            cout << "3. Shoes (Fashion) - $49.99\n";
            cout << "Enter product ID: ";
            cin >> productID;
            cout << "Enter quantity: ";
            cin >> quantity;

            if (productID == "1") cart.addItem(p1, quantity);
            else if (productID == "2") cart.addItem(p2, quantity);
            else if (productID == "3") cart.addItem(p3, quantity);
            else cout << "Invalid product ID!\n";
            break;

        case 2:
            cout << "Enter product ID to remove: ";
            cin >> productID;
            cout << "Enter quantity to remove: ";
            cin >> quantity;
            cart.removeItem(productID, quantity);
            break;

        case 3:
            cart.viewCart();
            break;

        case 4:
            cout << "Enter number of successful referrals: ";
            cin >> referrals;
            cart.applyReferralDiscount(referrals);
            break;

        case 5:
            cart.applyOtherDiscount();
            break;

        case 6:
            cart.checkout();
            playGame();
            break;

        case 7:
            cart.listDiscounts();
            break;

        case 8:
            playGame();
            break;

        case 9:
            exit = true;
            cout << "Exiting... Thank you for shopping with us!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
