# LUA_Parser

A lightweight Lua tokenizer and parser, designed to convert Lua source code into tokens and parse them into an abstract syntax tree (AST). This project serves as a foundational component for building interpreters, compilers, or static analyzers for Lua code.

---

## 🧠 Features

- Custom tokenizer (lexer) written from scratch
- Parses identifiers, numbers, strings, operators, and keywords
- Handles escape sequences in string literals
- Framework for future AST and LLVM IR generation

---

## 📂 Project Structure

LUA_Parser/
├── src/
│ ├── Main.cpp # Entry point
│ ├── Tokenizer.cpp # Tokenizer logic (lexical analysis)
│ ├── Tokenizer.hpp
│ ├── Parser.cpp # AST parser stub
│ ├── Parser.hpp
├── test.lua # Sample Lua file
├── CMakeLists.txt
└── README.md


---

## ⚙️ Building

```bash
mkdir build
cd build
cmake ..
cmake --build .

🚀 Running
After building, run the binary like this:

bash
Copy
Edit
./LuaToLLVM

Make sure test.lua is located at the project root.
