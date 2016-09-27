#### Objectives:

- [x] Create a Windows application. It should have in middle following text: "Done with Pride and Prejudice by student name". Replace student name with your name.
- [x] On windows resize, text should reflow and be in window's middle (vertically and horizontally)
- [x] Limit minimal window width and height in order to keep text visible always(_doesn't work with wine_)
- [x] Change behavior of different window actions
  - [x] On close button additional message window will appear
  - [x] On pressing right mouse button message window will appear

for cross-compiling on linux:
    `i686-w64-mingw32-g++ -mwindows main.cpp -o main.exe`

