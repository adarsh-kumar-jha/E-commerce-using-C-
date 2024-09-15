# **Mini E-Commerce Cart System**

Welcome to the **Mini E-Commerce Cart System**! This command-line application allows users to manage their shopping cart, apply discounts, and complete transactions while enjoying interactive features. Whether you're adding items to your cart, applying discounts, or just playing a game, this system is designed to be user-friendly and engaging.

## **Features**

1. **Add Items to Cart**: Add products to your shopping cart by specifying the product ID and quantity.
2. **Remove Items from Cart**: Remove items from your cart based on product ID and quantity.
3. **View Cart**: View current items in the cart along with the total price.
4. **Apply Discounts**:
   - **Referral Discount**: Earn a discount after successfully referring 10 users.
   - **Available Discounts**: Includes Buy 1 Get 1 Free for fashion items and 10% off on electronics.
5. **Multi-Currency Checkout**: Checkout with support for multiple currencies (USD, EUR, GBP, INR).
6. **Integrated Mini Game**: Enjoy a simple number guessing game during checkout. You can quit at any time.
7. **Sign-In Feature**: Secure sign-in functionality to manage your account.
8. **Interactive Command-Line Interface**: Navigate through a fully interactive, menu-based interface for a seamless experience.

## **Getting Started**

### **Prerequisites**

- A C++ compiler (e.g., g++, clang++)

### **Installation**

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/mini-ecommerce-cart-system.git
   cd mini-ecommerce-cart-system
   ```

2. **Compile the Code**:
   ```bash
   g++ -o ecommerce ecommerce.cpp
   ```

3. **Run the Application**:
   ```bash
   ./ecommerce
   ```

## **Usage**

### **Main Menu**

Upon running the application, you will be presented with the following options:

1. **Add Item**: Add a product to your cart.
2. **Remove Item**: Remove a product from your cart.
3. **View Cart**: View the items in your cart and their total cost.
4. **Apply Referral Discount**: Apply a referral discount if eligible.
5. **Apply Other Discounts**: Apply available discounts.
6. **Checkout**: Complete your purchase with multi-currency support.
7. **Play Game**: Play a simple number guessing game during checkout.
8. **Sign In**: Sign in to manage your account.
9. **Exit**: Exit the application.

### **Example Commands**

- **Add Item**:
  ```bash
  Enter product ID: 1
  Enter quantity: 2
  ```

- **Remove Item**:
  ```bash
  Enter product ID to remove: 1
  Enter quantity to remove: 1
  ```

- **View Cart**:
  ```bash
  Your Cart:
  Shirt - Quantity: 1, Price: $25.99, Total: $25.99
  Total (before discounts): $25.99
  ```

- **Checkout**:
  ```bash
  Applying referral discount of 15%...
  Final Total in USD: $22.09
  ```

- **Play Game**:
  ```bash
  Do you want to play a game while your product is being prepared? (yes/no): yes
  Guess a number between 1 and 10: 5
  ```


## **Contributing**

Feel free to fork this repository and contribute to its development. Create a pull request with your changes and enhancements!

## **License**

This project is licensed under the MIT License.

## **Contact**

For any questions or feedback, please contact [jhaadarsh234@gmail.com](mailto:jhaadarsh234@gmail.com).
