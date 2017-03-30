#ifndef mapGeneration
#define mapGeneration

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

class map {
private:
	int doorCount;
	int discoveredRoomCount;
	int remainingRoomCount;
	//int [][] activeRoomLocation;
	int mainMap [4][4] = {{0}}; 
	char playerMap [4][4] = {""};
	int placeHolderX;
	int placeHolderY;
	
public:
	void MakeMap();
	void PlayerMapPrint();
	void MakePlayerMap();
	bool MapVerification();
	// int [][] RandomSetRoom();
	void PrintMap();
	void UpdatePlayerMap();
	void DoorConnection();
	// void UpdateRoomLocation()
	void TravelRoom();
};

void map::MakeMap(){
	mt19937 engine(time(0)); 
	uniform_int_distribution<int> startRoom(0,3);
	int currentRoomX = startRoom(engine);
	placeHolderX = currentRoomX; 
	int currentRoomY = 3; 
	mainMap[currentRoomY][currentRoomX] = 1; 
	uniform_int_distribution<int> direction(0,2);
	
	uniform_int_distribution<int> roomType(2,6);
	
	bool finalMove = false;
	bool badMove = true; 
	
	while(!finalMove){
		//cout << "first while" << endl;
		badMove = true; 
		while(badMove){
			//cout << "second while" << endl;
			int nextRoom = direction(engine); 
			
			if(nextRoom == 0){
				if(currentRoomX - 1 < 0 ) {
					break;
				} 
				else{
					currentRoomX--; 
					if(mainMap[currentRoomY][currentRoomX] != 0){
						break;
					}
					else{
					mainMap[currentRoomY][currentRoomX] = roomType(engine); 
					badMove = false;
					}
				}	
			}
			else if(nextRoom == 1){
				if(currentRoomY - 1 < 0 ){
					finalMove = true; 
					//Change last room to boss room. 
					mainMap[currentRoomY][currentRoomX] = 7;
					placeHolderY = currentRoomX;
				}
				else {
					currentRoomY--;
					if(mainMap[currentRoomY][currentRoomX] != 0){
						break;
					}
					else{
					mainMap[currentRoomY][currentRoomX] = roomType(engine);
					badMove = false;
					}
				}
			}
			else{
				if(currentRoomX + 1 > 3){
					break;
				}
				else {
					currentRoomX ++; 
					if(mainMap[currentRoomY][currentRoomX] != 0){
						break;
					}
					else{
					mainMap[currentRoomY][currentRoomX] = roomType(engine);
					badMove = false;
					}
				}
			}
		}
	}
}

void map::PrintMap(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << mainMap[i][j];
			cout << "\t"; 
		}
		cout << endl;
	}
};

void map::PlayerMapPrint(){
	cout<< "DUNGUEN FLOOR MAP" << endl;
	cout<< "O is start room." << endl;
	cout<< "X is boss room." << endl;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << playerMap[i][j];
			cout << "\t"; 
		}
		cout << endl;
	}
};

void map::MakePlayerMap(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			playerMap[i][j] = '#';
		}
	}
};

void map::UpdatePlayerMap(){
	playerMap[3][placeHolderX] = 'O'; 
	playerMap[0][placeHolderY] = 'X'; 
	
};


#endif
