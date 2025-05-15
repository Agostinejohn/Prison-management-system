# Prison Management System

A terminal-based Prison Management System built in C. This project allows administrators to manage prisoner records with core functionalities like adding, searching, updating, and deleting inmate data.

## 🔧 Features

- Add new prisoner records
- Display all prisoners
- Search prisoner by ID or name
- Update prisoner information
- Delete prisoner records
- Password-protected admin access (basic)
- Simple file-based data persistence

## 🖥️ Tech Stack

- Language: C
- IDE: Any C compiler (e.g., GCC, Code::Blocks)
- Platform: Windows/Linux (terminal)

## 📦 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/Agostinejohn/Prison-management-system.git
cd Prison-management-system
2. Compile the Code
On Linux/macOS:
bash
Copy
Edit
gcc main.c -o prison_management
./prison_management
On Windows (MinGW):
bash
Copy
Edit
gcc main.c -o prison_management.exe
prison_management.exe
📝 File Structure
perl
Copy
Edit
Prison-management-system/
├── main.c          # Main source code
├── guide.txt       # Project usage guide (optional)
├── .gitattributes  # Git config (default)
└── README.md       # Project documentation (this file)
🛡️ Access Control
Admin login is implemented through hardcoded credentials.

Add more robust security for real-world applications.

🧾 To-Do / Improvements
 Migrate from file-based storage to SQLite or MySQL

 Add role-based access (e.g., admin vs. guard)

 Implement unit tests

 GUI version using C++/Qt or Python/Tkinter

 Encrypt stored data for privacy

📄 License
This project is licensed under the MIT License.

🙋‍♂️ Author
John Maubi
GitHub Profile
LinkedIn
