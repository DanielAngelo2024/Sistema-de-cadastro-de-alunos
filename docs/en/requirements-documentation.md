# 📘 Student Registration System Documentation

## 1. General Description
The **Student Registration System** is an academic project developed as a challenge during the second semester of the Software Engineering degree.  
Its main objective is to apply fundamental concepts of algorithms, data structures, dynamic memory allocation, and modularization in the **C++** programming language.  

The system will evolve progressively, following the course content, incorporating new concepts and techniques as required.

---

## 2. Functional Requirements (FR)

- **FR01** – The system must allow the registration of new students.  
- **FR02** – The system must require the registration of subjects linked to the teacher.  
- **FR03** – The system must record grades for each student in their respective subjects.  
- **FR04** – The system must allow the modification of previously recorded grades.  
- **FR05** – The system must display the data of the currently selected student.  
- **FR06** – The system must allow the selection of a student in the list.  
- **FR07** – The system must display the complete list of registered students.  
- **FR08** – The system must display an appropriate message if there are no registered students.  
- **FR09** – The system must allow the removal of students from the list.  
- **FR10** – The system must allow the user to terminate the execution at any time.  
- **FR11** – The system must require the registration of the teacher.  
- **FR12** – The system must display a termination message when exiting.  

---

## 3. Non-Functional Requirements (NFR)

- **NFR01** – The system must be implemented in the **C++** programming language.  
- **NFR02** – The system must use **structs** to model students and subjects.  
- **NFR03** – The system must implement student registration using a **list**.  
- **NFR04** – The system must use **pointers** to handle dynamic memory allocation.  
- **NFR05** – The code must be modularized into prototype functions, ensuring clarity and reusability.  
- **NFR06** – The system must provide a simple and intuitive **text-based interface**, executed in the **console/terminal**.  
- **NFR07** – The system must optimize memory usage through dynamic allocation.  

---

## 4. Monolithic Architecture

### 4.1. Interface Layer
- The system must provide interactive menus in the terminal for user navigation.  
- The system must capture user input (name, ID, subject, grade, and menu options).  
- The system must present informational, error, or confirmation messages regarding operations performed.  

### 4.2. Business Layer
- The system must contain the rules for registering students and subjects.  
- The system must control the registration and modification of grades.  
- The system must validate student selection operations.  
- The system must prevent operations when the list is empty.  
- The system must implement rules for adding and removing students from the list.  

### 4.3. Data Layer
- The system must include the following fundamental data structures:  
  - **Student**: name, ID, list of subjects.  
  - **Subject**: subject name and corresponding grade.  
- The system must manage the list of students.  
- The system must provide functions for inserting, deleting, searching, and modifying data in memory.  

---

## 5. Main Components

1. **Main Menu**  
   - Responsible for displaying available options and guiding the application flow.  

2. **Student Registration Component**  
   - Responsible for creating a new student and inserting them into the list.  

3. **Subject and Grade Registration Component**  
   - Responsible for recording subjects and their respective grades for students.  

4. **Grade Modification Component**  
   - Responsible for locating a student and updating their grades.  

5. **Student Selection Component**  
   - Responsible for selecting a student by index (array) or position in the list.  

6. **Student Display Component**  
   - Responsible for displaying data of the currently selected student or all registered students.  
   - Must display an appropriate message when no records exist.  

7. **Student Removal Component** *(under development)*  
   - Responsible for removing a student from the list.  

8. **List Manager**  
   - Responsible for handling the student list (insertion, removal, search, and navigation).  
