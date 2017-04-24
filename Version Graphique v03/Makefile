
OBJ_FILES = Zone.cpp  sdlJeu.cpp Personnage.cpp Etat.cpp Action.cpp Combat.cpp


SRCS_SDL = $(OBJ_FILES) main.cpp
FINAL_TARGET_SDL = P8_Fighter_sdl
#DEFINE_SDL = -DJEU_SDL


ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw/SDL2-2.0.3/include \
						-Iextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/include/SDL2
	LIBS_SDL = 	-Lextern \
			-Lextern/SDL2_mingw/SDL2-2.0.3/i686-w64-mingw32/lib \
			-Lextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/lib \
			-Lextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll
else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image
endif

CC					= g++
LD 					= g++
LDFLAGS  			=
CPPFLAGS 			= -Wall -ggdb   #-O2   # pour optimiser
OBJ_DIR 			= obj
SRC_DIR 			= src
BIN_DIR 			= bin
INCLUDE_DIR			= -Isrc

default: make_dir $(BIN_DIR)/$(FINAL_TARGET_SDL)

make_dir:
ifeq ($(OS),Windows_NT)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR) $(OBJ_DIR)\src 
else
	mkdir -p $(OBJ_DIR) $(OBJ_DIR)/src
endif

$(BIN_DIR)/$(FINAL_TARGET_SDL): $(SRCS_SDL:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SDL)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_SDL) $(INCLUDE_DIR) $< -o $@


clean:
ifeq ($(OS),Windows_NT)
	del /f $(OBJ_DIR)*.o $(BIN_DIR)\$(FINAL_TARGET_SDL).exe
else
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(FINAL_TARGET_SDL)
endif

