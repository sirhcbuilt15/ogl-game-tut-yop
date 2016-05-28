# Detect OS
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGET=mijuego

CPPFLAGS= -Wall -Wextra

ifeq ($(uname_S),Darwin)
# OSX uses OpenGL as a framework
GLFW3_FLAGS := `pkg-config --cflags --libs glfw3` -framework OpenGL
else
# otherwise pkg-config finds OpenGL
GLFW3_FLAGS := `pkg-config --cflags --libs glfw3 glu gl`
endif

.PHONY: all
all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $<

$(TARGET): $(OBJECTS)
	$(LINK.cpp) $^ $(GLFW3_FLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS) *~


