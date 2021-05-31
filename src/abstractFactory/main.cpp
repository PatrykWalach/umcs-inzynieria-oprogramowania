#include <iostream>
#include <string>

class Car {
 public:
  virtual std::string type() = 0;
};
class Truck {
 public:
  virtual std::string type() = 0;
};
class DeliveryTruck {
 public:
  virtual std::string type() = 0;
};

class Factory {
 public:
  virtual Car *car() = 0;
  virtual Truck *truck() = 0;
  virtual DeliveryTruck *deliveryTruck() = 0;
};

class ElectricEngineCar : public Car {
 public:
  std::string type() { return "ElectricEngineCar"; }
};
class ElectricEngineTruck : public Truck {
 public:
  std::string type() { return "ElectricEngineTruck"; }
};
class ElectricEngineDeliveryTruck : public DeliveryTruck {
 public:
  std::string type() { return "ElectricEngineDeliveryTruck"; }
};

class CombustionEngineCar : public Car {
 public:
  std::string type() { return "CombustionEngineCar"; }
};
class CombustionEngineTruck : public Truck {
 public:
  std::string type() { return "CombustionEngineTruck"; }
};
class CombustionEngineDeliveryTruck : public DeliveryTruck {
 public:
  std::string type() { return "CombustionEngineDeliveryTruck"; }
};

class HybridEngineCar : public Car {
 public:
  std::string type() { return "HybridEngineCar"; }
};
class HybridEngineTruck : public Truck {
 public:
  std::string type() { return "HybridEngineTruck"; }
};
class HybridEngineDeliveryTruck : public DeliveryTruck {
 public:
  std::string type() { return "HybridEngineDeliveryTruck"; }
};

class ElectricFactory : Factory {
 public:
  Car *car() { return new ElectricEngineCar(); }
  Truck *truck() { return new ElectricEngineTruck(); }
  DeliveryTruck *deliveryTruck() { return new ElectricEngineDeliveryTruck(); }
};
class CombustionFactory : Factory {
 public:
  Car *car() { return new CombustionEngineCar(); }
  Truck *truck() { return new CombustionEngineTruck(); }
  DeliveryTruck *deliveryTruck() { return new CombustionEngineDeliveryTruck(); }
};

class HybridFactory : Factory {
 public:
  Car *car() { return new HybridEngineCar(); }
  Truck *truck() { return new HybridEngineTruck(); }
  DeliveryTruck *deliveryTruck() { return new HybridEngineDeliveryTruck(); }
};

int main() {
  auto electric_factory = new ElectricFactory();
  auto car = electric_factory->car();
  std::cout << car->type() << std::endl;
  auto truck = electric_factory->truck();
  std::cout << truck->type() << std::endl << std::endl;

  auto combustionFactory = new CombustionFactory();
  auto combustionDeliveryTruck = combustionFactory->deliveryTruck();
  std::cout << combustionDeliveryTruck->type() << std::endl;
  auto combustionTruck = combustionFactory->truck();
  std::cout << combustionTruck->type() << std::endl << std::endl;

  auto hybridFactory = new HybridFactory();
  auto hybridCar = hybridFactory->car();
  std::cout << hybridCar->type() << std::endl;
}