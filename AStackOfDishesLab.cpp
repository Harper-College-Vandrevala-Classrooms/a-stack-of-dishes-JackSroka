#include <iostream>
#include <array>
#include <string>

using namespace std;

class Dish {
private:
    string description;

public:
    Dish(string description = "") : description(description) {}

    string get_description() const {
        return description;
    }
};

class DishStack {
private:
    static const int MAX_SIZE = 5;
    array<Dish, MAX_SIZE> stack;
    int top;

public:
    DishStack() : top(-1) {}

    void push(const Dish& dish) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack is full! Cannot push " << dish.get_description() << "." << endl;
        }
        else {
            stack[++top] = dish;
        }
    }

    Dish pop() {
        if (top < 0) {
            cout << "Stack is empty! Cannot pop." << endl;
            return Dish("Empty Dish");
        }
        return stack[top--];
    }

    Dish peek() const {
        if (top < 0) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return Dish("Empty Dish");
        }
        return stack[top];
    }

    int size() const {
        return top + 1;
    }
};

int main() {
    DishStack stack;

    Dish fish_dish = Dish("fish");
    Dish frog_dish = Dish("frog");
    Dish dog_dish = Dish("dog");
    Dish cat_dish = Dish("cat");

    int stack_size = stack.size();
    cout << "Initial stack size: " << stack_size << endl;

    stack.push(fish_dish);
    stack.push(frog_dish);
    stack.push(dog_dish);
    stack.push(cat_dish);

    int size_after_pushes = stack.size();
    cout << "Size after pushes: " << size_after_pushes << endl;

    Dish peeked_dish = stack.peek();
    cout << "Peeked dish description: " << peeked_dish.get_description() << endl;

    Dish popped_dish = stack.pop();
    cout << "Popped dish description: " << popped_dish.get_description() << endl;

    Dish another_popped_dish = stack.pop();
    cout << "Another popped dish description: " << another_popped_dish.get_description() << endl;

    int final_size = stack.size();
    cout << "Final stack size: " << final_size << endl;

    return 0;
}
