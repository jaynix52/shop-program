#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Item // struct for shoppingcart
 {
  string name;
  double price;
};

class ShoppingCart {
private:
  stack<Item> cart; //stack= the command, <item>= the list, cart= name;

public:
  void addItem()
  {
  	string name;
  	double price;
  	cout << "Enter item name: ";
  	cin >> name;
  	cout << "Enter item price: ";
  	cin >> price;
  	Item newItem;
  	newItem.name = name;
  	newItem.price = price;
  	cart.push(newItem);
  	cout << "Item added to cart." << endl;
}

  void editItem()
  {
  		if (cart.empty()) 
		{
    		cout << "Cart is empty." << endl;
    		return;
  		}
  			stack<Item> tempStack;
  			string name;
  			cout << "Enter item name to edit: ";
  			cin >> name;
 		while(!cart.empty()) 
		{
    	Item item = cart.top();
    	cart.pop();
    	if (item.name == name) 
		{
      		cout << "Enter new name: ";
      		cin >> item.name;
      		cout << "Enter new price: ";
     		cin >> item.price;
    	}
    	tempStack.push(item);
  	}
  		while(!tempStack.empty()) 
		{
    		cart.push(tempStack.top());
    		tempStack.pop();
  		}
  		cout << "Item edited." << endl;
}

 void searchItem() {
  string name;
  cout << "Enter the name of the item to search: ";
  cin >> name;
  bool found = false;
  stack<Item> temp;
  while (!cart.empty()) {
    if (cart.top().name == name) {
      cout << "Item found in the cart: " << name << " with price RM" << cart.top().price << endl;
      found = true;
      break;
    }
    temp.push(cart.top());
    cart.pop();
  }
  while (!temp.empty()) {
    cart.push(temp.top());
    temp.pop();
  }
  if (!found) {
    cout << "Item not found in the cart." << endl;
  }
}

  void removeItem()
  {
  		if (cart.empty()) 
		  {
    		cout << "Cart is empty." << endl;
    		return;
			}
  		cart.pop();
  		cout << "Item removed." << endl;
	}
	
  	void displayCart()
  	{
  		stack<Item> tempStack = cart;
  		cout << "--- Cart Contents ---" << endl;
  			while (!tempStack.empty()) 
			{
    			Item item = tempStack.top();
    			cout << item.name << ": RM" << item.price << endl;
    			tempStack.pop();
  			}
  		cout << "---------------------" << endl;
	}
  		
	
	double calculateTotal()
	{
  		double total = 0.0;
  		stack<Item> tempStack = cart;
  		while (!tempStack.empty()) 
  		{
    		Item item = tempStack.top();
    		total += item.price;
    		tempStack.pop();
  		}
  		return total;
	} 
};



int main() {
  ShoppingCart myCart;
  int choice;
  cout << "\t\tWelcome to the stationery shop\t\t\n";
  
  do 
  {
    cout<<"\tChoice list"<<endl;
    cout << "1. Add item" << endl;
    cout << "2. Edit item" << endl;
    cout << "3. Search item" << endl;
    cout << "4. Remove item" << endl;
    cout << "5. Display cart" << endl;
    cout << "6. Calculate total" << endl;
    cout << "7. Quit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    
    switch (choice) 
	{
      case 1:
        myCart.addItem();
        break;
      case 2:
        myCart.displayCart();
        myCart.editItem();
      case 3:
        myCart.searchItem();
        break;
      case 4:
        myCart.displayCart();
        myCart.removeItem();
        myCart.displayCart();
        break;
      case 5:
        myCart.displayCart();
        break;
      case 6:
        cout << "Total: RM" << myCart.calculateTotal() << endl;
        break;
      case 7:
      cout<<endl<<"Thank you"<<endl;
        break;
      default:
        cout << "Invalid choice." << endl;
    }
  }while (choice != 7);
  
  return 0;
}
