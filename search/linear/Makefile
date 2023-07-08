PROJECTNAME=main
BIN=build/$(PROJECTNAME)
CC=g++

EXT=cpp
INCDIRS=include

DEPFLAGS=-MP -MD
FLAGS=-Wall -Wextra $(foreach F,$(INCDIRS),-I$(F)) $(OPT) $(DEPFLAGS)

SRC=$(shell find . -name "*.$(EXT)" -path "./src/*")
OBJ=$(subst ./src/,./build/,$(SRC:.$(EXT)=.o))
DEP=$(OBJ:.o=.d)
TEST=$(shell find . -name "*.$(EXT)" -path "./test/*")

$(shell mkdir -p build)

#all : $(BIN)
#
#$(BIN) : $(OBJ)
#	$(CC) $(FLAGS) -o $@ $^
#
#-include $(DEP)
#
#build/%.o : src/%.$(EXT)
#	@mkdir -p $(@D)
#	$(CC) $(FLAGS) -o $@ -c $<

run : all
	./$(BIN) $(input)

clean :
	rm -rf build/*

# make test file=testGenID.cpp
test : $(OBJ)
	$(CC) $(FLAGS) -o build/$(file:.$(EXT)=) test/$(file)
	./build/$(file:.$(EXT)=)

alltest :
	@for f in $(subst ./test/,,$(TEST)); do make -s test file=$$f; done

check :
	cppcheck --enable=all --suppress=missingIncludeSystem $(foreach I,$(INCDIRS),-I$(I)) .
	flawfinder .

# unzip : mkdir exemple && tar -xvf exemple.tgz -C exemple
dist : clean
	$(info /!\ project folder has to be named $(PROJECTNAME) /!\ )
	cd .. && tar zcvf $(PROJECTNAME)/build/$(PROJECTNAME).tgz $(PROJECTNAME) >/dev/null

.PHONY : all run clean test alltest check dist
