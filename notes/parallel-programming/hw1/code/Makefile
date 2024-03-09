CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

SRCS_q1 = main_q1.cpp SquareMatrix.cpp SquareMatrixView.cpp lower_triangular_inverse.cpp
HEADERS_q1 = SquareMatrix.hpp SquareMatrixView.hpp
OBJS_q1 = $(SRCS_q1:.cpp=.o)
BIN_q1 = q1

SRCS_q2 = main_q2.cpp SquareMatrix.cpp SquareMatrixView.cpp
HEADERS_q2 = SquareMatrix.hpp SquareMatrixView.hpp
OBJS_q2 = $(SRCS_q2:.cpp=.o)
BIN_q2 = q2

# Default target to build both binaries
all: $(BIN_q1) $(BIN_q2)

$(BIN_q1): $(OBJS_q1)
	$(CXX) $(CXXFLAGS) $(OBJS_q1) -o $(BIN_q1)

$(BIN_q2): $(OBJS_q2)
	$(CXX) $(CXXFLAGS) $(OBJS_q2) -o $(BIN_q2)

%.o: %.cpp $(HEADERS_q1) $(HEADERS_q2)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_q1) $(BIN_q1) $(OBJS_q2) $(BIN_q2)
