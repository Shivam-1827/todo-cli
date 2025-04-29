#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;


struct Task{
    int id;
    string description;
    bool completed;
};

vector<Task>tasks;

void showMenu(){
    cout<<"\n===== TODO APP ====="<<endl;
    cout<<"1. Add Task"<<endl;
    cout<<"2. View Task"<<endl;
    cout<<"3. Mark task as completed."<<endl;
    cout<<"4. Delete task."<<endl;
    cout<<"5. Save and Exit"<<endl;
    cout<<"Enter your choice: ";
}                   

void addTask(){
    Task newTask;
    cout<<"Enter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.id = tasks.size()+1;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout<<"Task added successfully."<<endl;
}

void viewTask(){
    if(tasks.empty()){
        cout<<"No task found!"<<endl;
    }

    for(auto &task: tasks){
        cout<<task.id<<". "<<(task.completed ? "[X] " : "[] ")<< task.description<<endl;
    }
}

void markTaskCompleted(){
    int id;
    cout<<"Enter Task ID to mark as completed: ";
    cin>>id;

    if(id>0 && id <= tasks.size()){
        tasks[id-1].completed = true;
        cout<<"Task marked as completed."<<endl;
    }else{
        cout<<"Invalid task ID."<<endl;
    }
}

void deleteTask(){
    int id;
    cout<<"Enter task ID to delete: ";
    cin>>id;

    if(id>0 && id <=tasks.size()){
        tasks.erase(tasks.begin() + (id-1));
        cout<<"Task deleted successfully."<<endl;

        for(int i = 0; i<tasks.size(); i++){
            tasks[i].id = i+1;
        }
    }else{
        cout<<"Invalid task ID"<<endl;
    }
}

void saveTasks(){
    ofstream file("tasks.txt");
    if(!file) return;

    for(auto &task: tasks){
        file<<task.id<<"|"<<task.description<<"|"<<task.completed<<endl;
    }

    file.close();
    cout<<"Task saved"<<endl;
}

void loadTask(){
    ifstream file("tasks.txt");
    if(!file) return;

    Task task;
    string line;

    while(getline(cin, line)){
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1+1);
        task.id = stoi(line.substr(0, pos1));
        task.description = line.substr(pos1+1, pos2-pos1-1);
        task.completed = stoi(line.substr(pos2+1));
        tasks.push_back(task);
    }

    file.close();
}

int main(){
    loadTask();
    int choice;

    do{
        showMenu();
        cin>>choice;

        switch(choice){
            case 1: addTask();
                    break;;
            
            case 2: viewTask();
                    break;

            case 3: markTaskCompleted();
                    break;

            case 4: deleteTask();
                    break;

            case 5: saveTasks();
                    cout<<"Exiting....."<<endl;
                    break;

            default: cout<<"Invalid choice! Try Again."<<endl;
        }
    }while(choice != 5);

    return 0;
}