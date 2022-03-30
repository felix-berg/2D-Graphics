rm a.out

echo "Lines of code: " $(wc -l *.cpp Graphics_Lib/*.cpp Graphics_Lib/Shapes/*.cpp Graphics_Lib/*.hpp Graphics_Lib/Shapes/*.hpp Graphics_Lib/Shapes/drawing_algorithms/*.cpp Graphics_Lib/Shapes/drawing_algorithms/*.hpp Graphics_Lib/Shapes/BMP/*.cpp Graphics_Lib/Shapes/BMP/*.hpp) "
"
echo "Compiling: " main.cpp Graphics_Lib/*.cpp Graphics_Lib/Shapes/*.cpp Graphics_Lib/Shapes/drawing_algorithms/*.cpp Graphics_Lib/Shapes/BMP/*.cpp"
"

g++ -std=c++20 *.cpp Graphics_Lib/*.cpp Graphics_Lib/Shapes/*.cpp Graphics_Lib/Shapes/drawing_algorithms/*.cpp Graphics_Lib/Shapes/BMP/*.cpp -lSDL2 -mavx2 -pthread -O3

echo "Finished.
"