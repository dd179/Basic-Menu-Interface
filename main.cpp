#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>
using namespace std;



//Function Prototypes >>
void display_menu();
char get_char();
void print_list(vector<int>&);
void add_to_list(vector<int>&);
void mean_of_list(vector<int>&);
void smallest_num(vector<int>&);
void largest_num(vector<int>&);
void quit();


//Main

int main() {
    vector<int> my_list{};

    while(true) {
        display_menu();
        char selection = ::toupper(get_char());

        if (selection == 'P') {
            print_list(my_list);
        } else if (selection == 'A') {
            add_to_list(my_list);
        } else if (selection == 'M') {
            mean_of_list(my_list);
        } else if (selection == 'S') {
            smallest_num(my_list);
        } else if (selection == 'L') {
            largest_num(my_list);
        } else if (selection == 'Q') {
            quit();
            break;
        }
        else{
            cout<<"Unknown selection!"<<endl;
        }

    }
    return 0;
}

//Function Definitions >>

void display_menu(){

    cout<<"\nP - Print numbers"<<endl;
    cout<<"A - Add a number"<<endl;
    cout<<"M - Display mean of the numbers"<<endl;
    cout<<"S - Display the smallest number"<<endl;
    cout<<"L - Display the largest number"<<endl;
    cout<<"Q - Quit"<<endl;
}


char get_char(){
    char user_input {};
    cout<<"Please, make your decision:";
    cin>>user_input;
    return user_input;
}
void print_list(vector<int> &list){
    if(list.size() ==0){
        cout<<"\n[] the list is empty."<<endl;
    }
    else{
        cout<<"[ ";
        for(auto vector:list){
            cout<<vector<<" ";

        }
        cout<<"]"<<endl;
    }
}
void add_to_list(vector<int> &list){
    int num;
    cout<<"Add a number to your list:";
    cin>>num;
    list.push_back(num);
    cout<<num<<" added"<<endl;
}
void mean_of_list(vector<int> &list){
    double sum {};
    if(list.size()==0){
        cout<<"The list is empty. Please add numbers to find the mean of the list!!"<<endl;
    }
    else{
        for(auto vector:list){
        sum+=vector;
        }
        double mean = sum/list.size();
        cout<<fixed<<setprecision(2)<<"The mean is "<<mean<<endl;
}
}
void smallest_num(vector<int> &list){
    int smallest= list[0];
    if(list.size()==0){
        cout<<"The list is empty. Please add numbers to find the smallest number of the list!!"<<endl;
    }
    else{
    for(int i{0};i<list.size();++i){
        if(smallest>list[i]){
            smallest=list[i];
        }
    }
    cout<<"The smallest number is "<<smallest<<endl;
}}
void largest_num(vector<int> &list){
    if(list.size()==0){
        cout<<"The list is empty. Please add numbers to find the largest number of the list!!"<<endl;
    }
    else{
    int largest =list[0];
    for(int i {0};i<list.size();++i){
        if(largest<list[i]){
            largest=list[i];
        }
    }
    cout<<"The largest number is "<<largest<<endl;

}}
void quit(){
    cout<<"Good Bye!!"<<endl;
}