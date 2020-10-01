debug:
	g++ -c source/*.cpp -std=c++14 -g -Wall -m64 -I include -I D:/Libraries/SDL2/include && g++ *.o -o bin/debug/main -L D:/Libraries/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

clean:
	del *.o