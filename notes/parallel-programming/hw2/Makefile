CUDA_PATH := /usr/local/cuda
NVCC := $(CUDA_PATH)/bin/nvcc

# Add /usr/local/cuda/bin to PATH
export PATH := $(CUDA_PATH)/bin:$(PATH)

TARGET := poly_mul
SRC := poly_mul.cu
# Object files
OBJ := $(SRC:.cu=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(NVCC) -g -o $@ $^

%.o: %.cu
	$(NVCC) -c -g -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
