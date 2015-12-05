#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
#include <vector>
using namespace std;
/*
class Buzzer{
	private:
		string RedButtonMsg;
		string GreenButtonMsg;
	public:
		
		void setRedButtonMsg(string redButtonMsg);
		void setGreenButtonMsg(string greenButtonMsg);

		void displayRedButton();
		void displayGreenButton();
};
///////////////////////////////////////////////////////////////////////////////////

void Buzzer::setRedButtonMsg(string redButtonMsg){
	if(redButtonMsg !="fail" && redButtonMsg !="hate" 
	   && redButtonMsg != "dislike")
		RedButtonMsg = redButtonMsg;
}
void Buzzer::displayRedButton(){
	cout << RedButtonMsg << endl;
}

//////////////////////////////////////////////////////////////////////////////////

int main(){

	Buzzer button;
	button.setRedButtonMsg("good");
	button.displayRedButton();
}
*/

class Laptop{
	private:
		//char* ModelNumber;
		string ModelNumber;
		int ProcessorSpeed;
		int MemoryCapacity;

	public:
		void displayModelNumber();
		void displayProcessorSpeed();
		void displayMemoryCapacity();

		//void setModelNumber(char);
		void setProcessorSpeed(int processorSpeed);
		void setMemoryCapacity(int memoryCapacity);
		//void setModelNumber(char* modelNumber);
		void setModelNumber(string modelNumber);
};

void Laptop::setProcessorSpeed(int processorSpeed){
	ProcessorSpeed = processorSpeed;
}
void Laptop::setMemoryCapacity(int memoryCapacity){
	MemoryCapacity = memoryCapacity;
}
//void Laptop::setModelNumber(char* modelNumber){
void Laptop::setModelNumber(string modelNumber){
	ModelNumber = modelNumber;
}
void Laptop::displayProcessorSpeed(){
	cout << ProcessorSpeed << endl;
}
void Laptop::displayMemoryCapacity(){
	cout << MemoryCapacity << endl;
}
void Laptop::displayModelNumber(){
	cout << ModelNumber << endl;
}
int main(){
	Laptop laptop1;
	laptop1.setProcessorSpeed(10);
	laptop1.setMemoryCapacity(20);
	laptop1.setModelNumber("njhldn");
	cout << "The processor speed is: ";
	laptop1.displayProcessorSpeed();
	cout << "The memory capacity is: ";
	laptop1.displayMemoryCapacity();
	cout << "The model number is: ";
	laptop1.displayModelNumber();
}





