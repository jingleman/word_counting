
# word_counting with google test and google benchmark

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

See also the following template from which this repo was adapted:
https://github.com/jingleman/cmake-gtest-gbench-starter
The README there explains the submodules, organizations, usage, etc.


# Debugging in VS Code

Finally got this working by simplifying like in

https://medium.com/@divyendu.narayan/visual-studio-code-setup-in-mac-os-to-build-and-debug-c-cmake-projects-45a78b29e49

You may need to disable the CMake Tools (and other) plugin(s) besides the C/C++ one.
Then modify the now-added .vscode launch.json to point to the desired target in the
workspace directory. (No need to Add Folder to Workspace. Just OpenFolder.)
And add args there if applicable. Then launch using Run --> Start Debugging or
correponding buttons (top left and bottom left). This works when you run
cmake -DCMAKE_BUILD_TYPE=Debug and make from outside of VS Code, and hopefully
will from within too. May want to add preBuild command back into this .json but
it's ommitted for now.


# Word Counting

The purpose of this particular repository is to experiment with basic word counting
functionality and a simple combinatoric optimization problem inspired by a toy.

The toy is a set of five consonant-vowel-consonant (CVC) words made out of wooden
blocks that spin to combine four beginning consonants with four ending consonants (for
each vowel).

See also https://docs.google.com/spreadsheets/d/1QRt20rpTCyJyiO0vnKrDAx5-xznL2l8qVX4qDVxbEyg/edit?usp=sharing (not public).


# License

[MIT](http://opensource.org/licenses/MIT)

