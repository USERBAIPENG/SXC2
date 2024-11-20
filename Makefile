CPPCPATH	  = D:\GREESmartDeveloper\GREESmartDeveloper\compiler\arm-linux-gnueabihf\bin
#LIB           = -L D:\Mycode\libmodbus-3.0.8\install\lib   -lmodbus -lpthread 
#CPPCPATH	  = D:\GREESmartDeveloper\GREESmartDeveloper\Dompiler\arm-linux-gnueabihf\bin
#LIB           = -L C:\Users\Administrator.DESKTOP-84A32CD\Desktop\UbuntuShare\project\libmodbus\libmodbus-3.0.8\install\lib   -lmodbus -lpthread 
LIB           = -L D:\vsc\libmodbus-3.0.8\install\lib -lmodbus -lpthread


CROSS_COMPILER= arm-linux-gnueabihf-
CC            = $(CPPCPATH)\$(CROSS_COMPILER)g++ -std=c++17
CFLAGS = -I ./include
OUTPUT = ./bin/GMVFCCGW

.PHONY :all clean

SRCS = $(wildcard ./src/*.cpp)

FCCgateway:.\src\main.cpp
	$(CC) $(SRCS) -o $(OUTPUT) $(LIB) $(CFLAGS)



#CPPCPATH	  = D:\GREESmartDeveloper\GREESmartDeveloper\Dompiler\arm-linux-gnueabihf\bin
#LIB           = -L C:\Users\Administrator.DESKTOP-84A32CD\Desktop\UbuntuShare\project\libmodbus\libmodbus-3.0.8\install\lib   -lmodbus -lpthread 
#CROSS_COMPILER= arm-linux-gnueabihf-
#CC            = $(CPPCPATH)\$(CROSS_COMPILER)g++ -std=c++17
#CFLAGS = -I ./include -I ./include/bmodbus -I 
#OUTPUT = ./bin/GMVFCCGW
#.PHONY :all clean 
#SRCS = $(wildcard ./src/*.cpp)  
#FCCgateway:.\src\main.cpp	
#	$(CC) $(SRCS) -o $(OUTPUT) $(LIB) $(CFLAGS)