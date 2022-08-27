
//#pragma once

 #ifndef _Vehicle_h
 #define _Vehicle_h

 #define _CRT_SECURE_NO_WARNINGS

 #include <cstring>
 #include <iostream>

 using namespace::std;

 class Vehicle {
 protected:
         char* model;

         int passengers; //승객의 수
        int fuelCap; //연료의 용량(리터)
         int kpl; //연료 소비량(km/리터)

public:
         Vehicle(const char* m, int p, int f, int k);
         ~Vehicle();

         int Range() const { return kpl * fuelCap; }

         char* GetModel() const { return model; }
         int GetPassengers() const { return passengers; }
         int GetFuelCap() const { return fuelCap; }
         int GetKpL() const { return kpl; }
 };

 class Truck : public Vehicle {
 private:
         int cargoCap; //적재용량

public:
         Truck(int c, const char* m, int p, int f, int k);
         ~Truck();

         int GetCargoCap() const { return cargoCap; }

         int TGetRange() const { return Range(); }
         char* TGetModel() const { return GetModel(); }
         int TGetPassengers() const { return GetPassengers(); }
         int TGetFuelCap() const { return GetFuelCap(); }
         int TGetKpL() const { return GetKpL(); }
 };

 class OffRoad : public Vehicle{
 private:
         int groundClearance; //지상고(차량의 가장 낮은 부분의 높이)

public:
         OffRoad(int g, const char* m, int p, int f, int k);
         ~OffRoad();

         int GetGroundClearance() const { return groundClearance; }

         int OGetRange() const { return Range(); }
         char* OGetModel() const { return GetModel(); }
         int OGetPassengers() const { return GetPassengers(); }
         int OTGetFuelCap() const { return GetFuelCap(); }
         int OTGetKpL() const { return GetKpL(); }
 };

 Vehicle::Vehicle(const char* m = "Vehicle", int p = 0, int f = 0, int k = 0) {
         int len = strlen(m);
         model = new char[len+1];
         strcpy(model, m);

         passengers = p; //승객의 수
        fuelCap = f; //연료의 용량(리터)
         kpl= k; //연료 소비량(km/리터)

         cout << endl;
         cout << model << " ";
         cout << "의 생성자 Vehicle" << endl;
 }
 Vehicle::~Vehicle() {
         cout << model << " ";
         cout << "의 소멸자 Vehicle" << endl << endl;
         delete[] model;
 }

 Truck::Truck(int c = 0, const char* m = "Truck", int p = 0, int f = 0, int k = 0) : Vehicle(m, p, f, k) {
         cargoCap = c;
         cout << model << " ";
         cout << "의 생성자 Truck" << endl;
 }
 Truck::~Truck(){
         cout << model << " ";
         cout << "의 소멸자 Truck" << endl;
 }

 OffRoad::OffRoad(int g = 0, const char* m = "OffRoad", int p = 0, int f = 0, int k = 0) : Vehicle(m, p, f, k) {
         groundClearance = g;
         cout << model << " ";
         cout << "의 생성자 OffRoad" << endl;
 }
 OffRoad::~OffRoad() {
         cout << model << " ";
         cout << "의 소멸자 OffRoad" << endl;
 }

 #endif // _Vehicle_h

 *********************************************************************************************

 #include "Vehicle.h"

 int main() {
         Vehicle vhc0;
         Vehicle vhc1("vhc1", 1, 1, 1);
         Truck trk0;
         Truck trk1(1, "trk1", 1, 1, 1);
         OffRoad off0;
         OffRoad off1(1, "off1", 1, 1, 1);

         cout << "-------------------------" << endl;
 } 