#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <map>

using namespace std;

void arrayExample(){
    //Array Initialization
    array<string,7> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  
    //Print Size
    cout << "Days: " << days.size() << endl;
  
    //Print Days
    for(auto d : days)
        cout << d << endl;
    cout << endl;
}

void vectorExample(){
    //Vector Initialization
    vector<int> numbers = {10, 20, 30, 40, 50};
  
    //Add Elements
    numbers.push_back(60);
    numbers.push_back(70);
  
    //Remove Last
    numbers.pop_back();
  
    //Print
    cout << "Vector:" << endl;
    for(auto n : numbers)
        cout << n << " ";
    cout << endl << endl;
}

void listExample(){
    //List Initialization
    list<string> fruits = {"Orange","Black Berry","Strawberry"};
  
    //Add To Front And Back
    fruits.push_front("Apple");
    fruits.push_back("Tomato");
  
    //Remove Element
    fruits.remove("Strawberry");
  
    //Print
    cout << "List:" << endl;
    for(auto it = fruits.begin(); it != fruits.end(); ++it)
        cout << *it << endl;
    cout << endl;
}

void mapExample(){
    //Map Initialization
    map<string,int> stock;
    stock.insert({"Apples",12});
    stock.insert({"Tomatos",7});
    stock.insert({"Oranges",12});
  
    //Update Count
    stock["Tomatos"] = 2;
  
    //Print
    cout << "Map:" << endl;
    for(auto item : stock)
        cout << item.first << "->" << item.second << endl;
    cout << endl;
}

int main(){
    //Array
    cout << "Array Example:" << endl;
    arrayExample();
  
    //Vector
    cout << "Vector Example:" << endl;
    vectorExample();
  
    //List
    cout << "List Example:" << endl;
    listExample();
  
    //Map
    cout << "Map Example:" << endl;
    mapExample();
    return 0;
}
