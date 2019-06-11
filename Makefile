all:
	g++ src/libraries/glad.c src/main.cpp src/libraries/stb_image.cpp -std=c++17 -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -o out

