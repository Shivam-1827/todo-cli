# Todo CLI Application

A simple command-line interface (CLI) Todo list application written in C++. This application allows users to manage their tasks efficiently with basic CRUD operations.

## Features

- **Add Tasks**: Create new tasks with descriptions
- **View Tasks**: List all tasks with their completion status
- **Mark Completed**: Mark tasks as completed
- **Delete Tasks**: Remove tasks from the list
- **Auto-Save**: Tasks are automatically saved to a file when exiting the program
- **Persistence**: Tasks are loaded from storage when the application starts

## Installation

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- Basic command line knowledge

### Compiling the application

```bash
# Compile the application
g++ -o todo_app todo.cpp

# Run the application
./todo_app
```

## Usage

The application presents a simple menu interface:

```
===== TODO APP =====
1. Add Task
2. View Task
3. Mark task as completed.
4. Delete task.
5. Save and Exit
Enter your choice:
```

### Adding a task
Select option 1 and enter the task description.

### Viewing tasks
Select option 2 to see all tasks. Tasks display with their ID, completion status, and description.

### Marking a task as completed
Select option 3 and enter the ID of the task you want to mark as completed.

### Deleting a task
Select option 4 and enter the ID of the task you want to delete.

### Saving and exiting
Select option 5 to save all changes and exit the application.

## File Structure

- `todo.cpp`: The main source code file
- `tasks.txt`: Data file where tasks are stored

## Data Format

Tasks are stored in `tasks.txt` in the following format:
```
ID|Description|CompletionStatus
```

For example:
```
1|need to do DSA|0
2|need to do javascript|1
```

## Future Improvements

- Add task categories
- Set priorities for tasks
- Add due dates
- Implement search functionality
- Add a user-friendly interface

