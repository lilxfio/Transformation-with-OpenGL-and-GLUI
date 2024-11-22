
# Setting Up OpenGL, GLUT, and GLUI Libraries

This guide provides instructions to set up the OpenGL, GLUT, and GLUI libraries for developing graphics applications on different platforms.

## Table of Contents
- [Linux](#linux)
- [Windows](#windows)
- [MacOS](#macos)
- [Verifying Installation](#verifying-installation)

---

## Linux

### Install OpenGL and GLUT
1. Update your package list:
   ```bash
   sudo apt update
   ```
2. Install the required packages:
   ```bash
   sudo apt install freeglut3-dev libglew-dev
   ```

### Install GLUI
1. Clone the GLUI repository:
   ```bash
   git clone https://github.com/libglui/glui.git
   cd glui
   ```
2. Build and install GLUI:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   sudo make install
   ```

---

## Windows

### Install OpenGL and GLUT
1. **Download GLUT**: Download the GLUT library from [GLUT for Windows](https://www.opengl.org/resources/libraries/glut/).
2. Extract the files and copy them as follows:
   - `glut.h` to `C:\Program Files\Microsoft Visual Studio\VC\include\GL`.
   - `glut32.lib` to `C:\Program Files\Microsoft Visual Studio\VC\lib`.
   - `glut32.dll` to `C:\Windows\System32`.

### Install GLUI
1. **Download GLUI**: Download GLUI from [GLUI GitHub Repository](https://github.com/libglui/glui).
2. Build the library using Visual Studio or MinGW:
   - Open the provided Visual Studio solution file in the `glui` repository and build the project.
   - Alternatively, use MinGW with the following commands:
     ```bash
     mkdir build
     cd build
     cmake ..
     mingw32-make
     ```
3. Place the compiled `.dll` and `.lib` files in appropriate directories.

---

## MacOS

### Install OpenGL and GLUT
1. OpenGL and GLUT come pre-installed on macOS. Install additional development tools if necessary:
   ```bash
   xcode-select --install
   ```

### Install GLUI
1. Install Homebrew if not already installed:
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```
2. Install GLUI:
   ```bash
   brew install glui
   ```

---

## Verifying Installation
1. Create a test file (`test.cpp`) with the following content:
   ```cpp
   #include <GL/glut.h>
   #include <GL/glui.h>
   #include <iostream>

   int main(int argc, char** argv) {
       glutInit(&argc, argv);
       std::cout << "OpenGL and GLUI are properly set up!" << std::endl;
       return 0;
   }
   ```
2. Compile the program:
   ```bash
   g++ test.cpp -o test -lGL -lGLU -lglut -lglui
   ```
3. Run the program:
   ```bash
   ./test
   ```
   If you see the message, "OpenGL and GLUI are properly set up!", the libraries have been installed correctly.
