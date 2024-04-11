CXXFLAGS=-IHeaders -std=c++11 -g

all : mmt test/testMenu

OBJS = MakeMyTrip.o \
	Entities/Accomodation.o \
	Entities/Place.o \
	Interfaces/HotelInterface.o \
	Repositories/HotelRepository.o \
	Repositories/UserRepository.o \
	Entities/Hotel.o \
	Entities/Room.o \
	Entities/Booking.o

mmt: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $? $(LDFLAGS)
test/testMenu: test/testMenu.cpp


clean:
	$(RM) mmt test/testMenu test/*.o $(OBJS)
