CXXFLAGS=-IHeaders -std=c++11 -g

all : mmt test/testMenu

mmt: MakeMyTrip.o Entities/Accomodation.o Entities/Place.o Interfaces/HotelInterface.o Repositories/HotelRepository.o Repositories/UserRepository.o Entities/Hotel.o
	$(CXX) $(CXXFLAGS) -o $@ $? $(LDFLAGS)
test/testMenu: test/testMenu.cpp


clean:
	$(RM) mmt test/testMenu test/*.o *.o Entities/*.o Endpoints/*.o
