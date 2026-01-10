//missing many functionality and uncompleted

#include <iostream>
#include <vector>
#include <string>

struct Task{
std::string description;
   Task(const std::string& desc)
     :description(desc)
     {}

    std::string getDescription(){
        return description;
    }
    void setDescription(const std::string& desc){
          description = desc;
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
void editTask(){
    if (todolist.empty()){
        std::cout << "No tasks to edit\n";
    }

    std::cout << "Tasks:\n";
    for(int i = 0; i < todolist.size(); ++i){
        std::cout << i + 1 << "." << todolist[i].getDescription()
        << "\n";

    }
    std::cout << "Enter a task to edit:";
    int tasknumber;
    std::cin >> tasknumber;
    if(tasknumber >=0 && tasknumber <= todolist.size()){

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
