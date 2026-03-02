# CPP Module 05 (42 School)

## 📋 Description
This module focuses on **Exceptions** in C++. Through the metaphor of a heavy bureaucracy, it teaches how to handle error conditions gracefully using `try`, `throw`, and `catch` blocks, while respecting the Orthodox Canonical Form.

## 🧠 Implementation Logic (Score: 100/100)
The project revolves around Bureaucrats (the actors) and Forms (the tasks), with a strict hierarchy of grades ranging from 1 (highest) to 150 (lowest).

- **Exception Handling**: Instead of returning error codes, I implemented custom nested exception classes (inheriting from `std::exception`) like `GradeTooHighException` and `GradeTooLowException`.
- **Bureaucrat & Grade Management**: Implementation of increment/decrement methods with immediate safety checks. If a grade goes out of bounds, an exception is thrown and caught by the caller.
- **Form Progression**:
  - **Ex01**: Introduction of the `Form` class. A bureaucrat can only sign a form if their grade is high enough.
  - **Ex02 (AForm)**: Refactored `Form` into an abstract class (`AForm`) with specific derived forms:
    - `ShrubberyCreationForm`: Required grades (145/137), creates a file with ASCII trees.
    - `RobotomyRequestForm`: Required grades (72/45), has a 50% chance of "robotomizing" a target.
    - `PresidentialPardonForm`: Required grades (25/5), grants a pardon from Zaphod Beeblebrox.
- **The Intern (Ex03)**: Implementation of an `Intern` class that uses a "factory" pattern to create forms based on a string name, avoiding massive `if/else` blocks by using an array of pointers to member functions or a similar dispatch logic.



## 📂 Project Structure
- `ex00/`: First step (Bureaucrat class and basic exceptions).
- `ex01/`: Form class (Interactions between Bureaucrats and Forms).
- `ex02/`: Concrete forms (Shrubbery, Robotomy, and Presidential Pardon).
- `ex03/`: At least the intern creates forms (Factory pattern).

## 🛠️ Usage & Compilation

### Compilation
All exercises are compiled with `c++ -Wall -Wextra -Werror -std=c++98`.
```bash
make
```
