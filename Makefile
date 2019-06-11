all:
	g++ src/main.cpp src/libraries/* src/sources/* -std=c++17 -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl -o out

