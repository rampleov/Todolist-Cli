#include <iostream>
#include <vector>
#include <string>

class Task{
private:
    std::string description;
    bool completed;
public:
   Task(const std::string& desc)
     :description(desc)
     ,completed(false)
     {}

    std::string getDescription(){
        return description;
    }
};

class Todolist{
private:
     std::vector<Task> todolist;
public:
   void addTask(const std::string& desc){
      todolist.emplace_back(desc);
      std::cout << "Task succesfully added\n";
}

void displayTask(){
    for(int i = 0; i < todolist.size(); ++i){
        std::cout << i + 1 << "."
        << todolist[i].getDescription() << std::endl;

    }
}

};

class Todo{
private:
   Todolist todo;
public:
    void addtask(){
        std::cout << "Enter a Task to add: ";
        std::string task;
        std::getline(std::cin , task);
        todo.addTask(task);
        }
    void displayTasks(){
        todo.displayTask();
    }
    void displayMenu(){
        char input;
        do{
        std::cout << "1.Add Tasks\n";
        std::cout << "2.Display Tasks\n";
        std::cout << "Enter a number:";
        int num;
        std::cin >> num;
        std::cin.ignore();


        switch(num){
            case 1:
            addtask();
            break;
            case 2:
            displayTasks();
            break;

        }
        std::cout << "Run again(Y/N): ";
        std::cin >> input;
        std::cin.ignore();
       } while(input == 'Y');
        std::cout << "\nGoodbye\n";




    }
};
int main(){
Todo todo;
todo.displayMenu();
}
