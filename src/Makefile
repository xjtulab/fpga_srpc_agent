SRC = main.cc proto/protogen/fpgaServiceTest1.pb.cc \
	service/FpgaServiceTest1.cc

SERVER = ../fpga_agent 
CLIENT = ../fpga_client
LDFLAGS=-lsrpc
CC=g++

OBJ = $(patsubst %.cc, %.o, $(SRC))

all:$(SERVER) $(CLIENT) 

$(SERVER):$(OBJ)
	$(CC)  $^ $(LDFLAGS) -o $@

$(CLIENT):client/client.cc proto/protogen/fpgaServiceTest1.pb.cc
	$(CC) -o $(CLIENT) $^ -I. -lsrpc

%.o:%.c
	$(CC) $(CFLGAS) -I. -c  $< -o $@


.PHONY: clean
clean:
	@echo "clean all!"
	rm -rf $(OBJ) 
	rm -rf $(TARGET)