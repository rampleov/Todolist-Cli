#include <iostream>
#include <string>
#include <vector>

struct Task{
private:
    std::string Desc;
public:
   Task(const std::string&desc)
   :Desc(desc)
   {}

 std::string description(){
    return Desc;
   }

   void setDescription(const std::string& desc){
      Desc = desc;
   }

};

class Todolist{
     std::vector<Task> todolist;
public:

     void addTask(const std::string& desc){
       todolist.emplace_back(desc);
      std::cout << "Task sucessfully added\n";

     }


     void displayTasks(){
      for(int i = 0; i < todolist.size(); ++i){
        std::cout << i + 1 << "." 
        <<  todolist[i].description() << "\n";
      }
     }

     void editTask(){
      displayTasks();
      std::cout << "Enter a task to edit: ";
      int tasknumber;
      std::cin >> tasknumber;
      std::cin.ignore();
      if(tasknumber > 0 && tasknumber <= todolist.size()){
          std::cout << "Enter new task: ";
          std::string taskname;
          std::getline(std::cin , taskname);
          todolist[tasknumber - 1].setDescription(taskname);
           std::cout << "Task has been edited\n";
      }
     }

     void deleteTask(){
      displayTasks();
      std::cout << "Enter task number to delete: ";
      int number;
      std::cin >> number;
      todolist.erase(todolist.begin() + number - 1);
      std::cout << "Task sucessfully deleted\n";
     }
};

class Todo{
  Todolist list;
public:
  void todolist(){
    char a;
    do{
    std::cout << "1.Add tasks\n";
    std::cout << "2.Display tasks\n";
    std::cout << "3.Edit tasks\n";
    std::cout << "4.Delete task\n";
    std::cout << "Enter a tasknumber: ";
    int num;
    std::cin >> num;
    std::cin.ignore();
    switch(num){
      case 1:{
      std::cout << "Enter a task to add: ";
      std::string task;
      std::getline(std::cin , task);
      list.addTask(task);
      }
      break;
      case 2:{
      list.displayTasks();
      break;
      }
      case 3:{
      list.editTask();
      break;
      }
      case 4:{
        list.deleteTask();
      }

    }
     std::cout << "Run again(Y/N): ";
      std::cin >> a;
      std::cin.ignore();
  } while(a == 'Y' && "y");
  std::cout << "\nGoodbye";
};
};
int main(){
  Todo todo;
  todo.todolist();
}
