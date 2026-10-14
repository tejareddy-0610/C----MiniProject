<p align="center">
  <img width="3200" height="760" alt="banner_pro" src="https://github.com/user-attachments/assets/ab0c63ff-d040-47a4-bd4f-c842d96e8791" />

</p>

A Menu based phone book written in **C** using a **singly linked list**, **file handling** and a **Makefile**.
Your contacts are saved in a file, so they are still there when you open the program again.

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Language C">
  <img src="https://img.shields.io/badge/Compiler-GCC-A42E2B?style=for-the-badge&logo=gnu&logoColor=white" alt="Compiler GCC">
  <img src="https://img.shields.io/badge/Build-Makefile-2E7D32?style=for-the-badge" alt="Build Makefile">
  <br>
  <img src="https://img.shields.io/badge/Data%20Structure-Linked%20List-F57C00?style=for-the-badge" alt="Data Structure Linked List">
  <img src="https://img.shields.io/badge/Storage-File%20Handling-00897B?style=for-the-badge" alt="Storage File Handling">
  <img src="https://img.shields.io/badge/Platform-Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Platform Linux">
</p>

## 📖 About the Project
This is a console **Phone Book App** that works like the contact list on a phone, but runs in the terminal. You can add people with several phone numbers, an email and an address, then find, edit, sort or delete them.

Everything is written to a file called `phonebook.dat`. The next time you start the program, the contacts are loaded back, so nothing is lost. Quitting with `q` **saves automatically**.

The project is built the way real C projects are organised: one function per source file, one shared header file, and a `Makefile` to compile everything.

### 🎯 Why this project?
- Shows how a **linked list** works in a real program, not just on paper
- Practises **pointers and dynamic memory** with `malloc` and `free`
- Shows how data can **stay saved** between runs using **file handling**
- Shows how to **sort a linked list** by relinking nodes instead of copying data
- Teaches how to **split a program into several files** and build it with `make`

### 📊 At a Glance
| | |
|---|---|
| 💻 **Language** | C |
| 🔗 **Data structure** | Singly linked list |
| 💾 **Storage** | Plain text file (`phonebook.dat`) |
| 📞 **Numbers per contact** | Up to 5 |
| 🔍 **Search** | Part of a name or phone number, ignores upper/lower case |
| 🔤 **Sort** | By name, A to Z, ignores upper/lower case |
| 🧩 **Structure** | 10 source files and 1 header file |
| 🛠️ **Build tool** | `make` with `gcc` |

## ⚡ Quick Start
```bash
make            # compile
./phonebook     # run
```

<p align="center">
  <img width="2400" height="1080" alt="terminal_demo" src="https://github.com/user-attachments/assets/f1869d70-eeda-4e24-bfa4-581a9e9c259b" />

</p>

## ✨ Features
- ➕ Add a contact with up to **5 phone numbers**, email and address
- 📋 Show all contacts
- 🔍 **Find** a contact by full name, **part of a name** or **phone number**. Upper/lower case does not matter, and every match is shown with a count
- ✏️ Edit any detail of a contact
- 🗑️ Delete a contact
- 🔤 **Sort** all contacts by name (A to Z)
- 💾 Save to a file and **load automatically** next time
- ✅ **Auto save on quit**
- 🚫 Two contacts cannot have the same name

## 🕹️ Menu
```
c/C : Create a new contact
p/P : Print all contacts
d/D : Delete a contact
f/F : Find a contact (name, letters or phone number)
e/E : Edit a contact
o/O : Sort contacts by name
s/S : Save contacts to file
q/Q : Save automatically and quit
```
> 💡 Pressing `q` saves your contacts before the program exits. Use `s` any time you want to save without quitting.

## 🔄 Program Flow
<p align="center">
  <img width="2480" height="1460" alt="flowchart" src="https://github.com/user-attachments/assets/823c5a18-fc08-4767-b9d0-7a212f0e6eaa" />

</p>

The program loads the saved contacts, then shows the menu again and again. Every action returns to the menu, except `q`, which saves, frees the list and exits.
Orange boxes were **updated** and the green box is **new** in this version.

## 🧠 How It Works
Every contact is stored in one structure, and the structures are joined together like a chain. This is a **singly linked list**.

<p align="center">
  <img width="2480" height="750" alt="linked_list" src="https://github.com/user-attachments/assets/24e19af4-37da-497f-8799-f77995fea758" />

</p>

```c
typedef struct contact
{
    char name[MAX_NAME];
    char phone[MAX_NUMBERS][MAX_PHONE];
    int  phone_count;
    char email[MAX_EMAIL];
    char address[MAX_ADDRESS];
    struct contact *next;     // points to the next contact
} CONTACT;
```

### 🔍 Searching
`search_contact()` asks for a name, some letters or a phone number. A contact matches if the text appears **anywhere** in its name or in **any** of its phone numbers, ignoring upper/lower case. For example, `ra` finds `Ravi` and `Sravan`, and `9876` finds every number containing `9876`. All matches are printed, followed by how many were found.

### 🔤 Sorting
`sort_contacts()` uses insertion sort. Each node is taken from the old list and linked into its correct place in a new sorted list.

<p align="center">
  <img width="1800" height="700" alt="sort_relink" src="https://github.com/user-attachments/assets/584ec690-8851-4877-a16a-535f96ef1dc3" />

</p>

- Names are compared with `compare_names()`, which ignores upper/lower case
- Only `next` pointers change, no contact data is copied
- Equal names keep their original order (stable sort)
- `CONTACT **head` is needed because the first node can change

### 💾 Saving and Loading
<p align="center">
  <img width="2480" height="800" alt="save_load" src="https://github.com/user-attachments/assets/496386c4-2d5e-4f8a-aa39-bead2ae3a085" />

</p>

- **Saving:** pressing `s` writes every contact to `phonebook.dat`. Pressing `q` does the same automatically before exit.
- **Loading:** when the program starts, it reads `phonebook.dat` and builds the list again. On the first run there is no file, so the phone book starts empty.

The saved file is plain text, so you can open it and read it:
```
===============CONTACT 1===============
Name    :Ravi
Count   :2
Phone number[1] :9876543210
Phone number[2] :9123456780
Email    :ravi@gmail.com
Address  :Not Available
```

## 📁 Project Files
| File | What it does |
|------|--------------|
| `main.c` | Loads contacts, shows the menu and calls the functions |
| `create.c` | `create_contact()` adds a contact |
| `display.c` | `display_contact()` shows all contacts |
| `search.c` | `search_contact()` finds contacts by part of a name or number |
| `edit.c` | `edit_contact()` changes a contact |
| `delete.c` | `delete_contact()` removes a contact |
| `sort.c` | `sort_contacts()` sorts the list by name 🆕 |
| `save.c` | `save_contacts()` writes contacts to the file |
| `file.c` | `load_contacts()` reads contacts from the file |
| `free.c` | `free_contacts()` frees memory when the program ends |
| `phonebook.h` | Structure, limits and function names |
| `Makefile` | Compiles the project |
| `images/` | Diagrams used in this readme |

## 🔧 Build Commands
| Command | What it does |
|---------|--------------|
| `make` | Compile the project |
| `make run` | Compile and run |
| `make clean` | Delete compiled files |

- **Add a file:** copy the new `.c` file into the folder and run `make`. The Makefile picks up every `.c` file automatically.
- **Remove a file:** delete it, then run `make clean` and `make`.
- **Needs:** `gcc` and `make` (`sudo apt install gcc make`).

## 💡 Design Highlights
- **Linked list:** no fixed contact limit, and deleting a contact only changes pointers.
- **`CONTACT **head`** is used in create, delete, load, sort and free because they can change the first node.
- **Sort by relinking:** fast to write and no data is copied between nodes.
- **Case-insensitive helpers:** `search.c` and `sort.c` use `tolower()` so `ravi` and `Ravi` are treated alike.
- **Text file:** easy to read and debug.
- **One function per file:** easy to understand and change.
- **Memory:** every `malloc` has a matching `free`, and the list is freed on quit.

## ⚠️ Known Limitations
- A phone number can have up to 10 characters.
- Creating, editing and deleting still compare names **exactly**, so `ravi` and `Ravi` are different contacts. Only search and sort ignore case.
- Very long input can overflow a field in create, edit and delete. Using `fgets` or width limits like `%49[^\n]` (already used in search) would fix this.
- Sorting is insertion sort, which is fine for a phone book but slow for very large lists.

## 🚀 Future Improvements
- Check phone number and email format
- Make the duplicate-name check ignore upper/lower case
- Sort by other fields such as phone number

## 👤 Author
**Name:** `Balaji Pidikiti`  
**ID:** `V25HE11B5`
