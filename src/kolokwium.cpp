
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ICamera {
 public:
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
  virtual string takePhoto() = 0;
};

class TCamera : ICamera {
  bool isOn = false;

 public:
  void turnOn() { isOn = true; };
  void turnOff() { isOn = false; }
  string takePhoto() { return "some photo"; };
};

class TRoom {
  int size;

 public:
  TRoom(int size) { this->size = size; }
};
class THospitalRoom : TRoom {
  vector<TCamera> cameras;

 public:
  THospitalRoom(int size, int numberOfCameras) : TRoom(size) {
    cameras.resize(numberOfCameras);
  }
  string triggerCamera(int index) {
    auto &camera = cameras[index];
    camera.turnOn();
    auto photo = camera.takePhoto();
    camera.turnOff();
    return string("Camera[") + ((char)((int)'0' + index)) + "]: " + photo;
  }
};

int main() {
  auto room = new THospitalRoom(2, 3);

  std::cout << room->triggerCamera(2) << std::endl;
  std::cout << room->triggerCamera(1) << std::endl;
}