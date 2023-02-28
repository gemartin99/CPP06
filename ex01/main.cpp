#include <iostream>
#include <cstdint> // Para usar uintptr_t

struct Data {
  int a;
  char b;
  void* c;
};

uintptr_t serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

int main() 
{
  Data data;
  data.a = 42;
  data.b = 'X';
  data.c = nullptr;


  std::cout << "Original " << &data << std::endl;

  // Serializamos la estructura Data
  uintptr_t serialized = serialize(&data);
  std::cout << "S: " << serialized << std::endl;
  //(void)serialized;
  //Data* deserialized = deserialize(11281323);

  // Deserializamos el valor y lo comparamos con el original
  Data* deserialized = deserialize(serialized);
  std::cout << "D: " << deserialized << std::endl;
  
  if (deserialized == &data)
  {
    std::cout << "Los punteros son iguales" << std::endl;
    std::cout << data.a << std::endl;
    std::cout << data.b << std::endl;
    std::cout << data.c << std::endl;
  }
  else 
    std::cout << "Los punteros son diferentes" << std::endl;
  return 0;
}