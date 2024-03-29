CC        := g++
LD        := g++
CXXFLAGS = -O -Wall -std=c++11 -g
GL_LIBS = -lglut -lGLU -lGL -lm

MODULES   := Main Shape
SRC_DIR   := $(addprefix src/,$(MODULES))
BUILD_DIR := $(addprefix build/,$(MODULES))

SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ       := $(patsubst src/%.cpp,build/%.o,$(SRC))
INCLUDES  := $(addprefix -I,$(SRC_DIR))

vpath %.cpp $(SRC_DIR)

define make-goal
$1/%.o: %.cpp
	$(CC) $(INCLUDES) -c $$< -o $$@ $(CXXFLAGS)
endef

.PHONY: all checkdirs clean

all: checkdirs build/Solar

build/Solar: $(OBJ)
	$(LD) $^ -o $@ $(GL_LIBS) $(CXXFLAGS)


checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))
