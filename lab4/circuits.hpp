#ifndef CIRCUITS_H
#define CIRCUITS_H
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <initializer_list>

struct Connection
{
  double Volt;
  bool can_change;
  Connection()
  {
    Volt = 0;
    can_change = true;
  }
};

class Component
{
protected:
  std::string Name;
  Connection *V_P;
  Connection *V_N;

public:
  Component(const std::string &name, Connection *P, Connection *N);
  virtual ~Component() = default;
  virtual double returnCurr()
  {
    return 0.0;
  }
  virtual void changeVolt(double time_step)
  {
    std::cout << "Wrong Call" << std::endl;
  }
  std::string returnName();
  double getVolt() const;
  void checkNP();
};

class Battery : public Component
{
private:
  double Volt;

public:
  Battery(std::string const &name, double volt, Connection *P, Connection *N);
  ~Battery() override;
  void setVolt();
  void changeVolt(double time_step) override;
};

class Resistor : public Component
{
private:
  double Ohm;

public:
  Resistor(std::string const &name, double ohm, Connection *P, Connection *N);
  ~Resistor() override;
  double returnCurr() override;
  void changeVolt(double time_step) override;
};

class Capacitor : public Component
{
private:
  double Fahrad;
  double Charge;

public:
  Capacitor(std::string const &name, double fahrad, Connection *P, Connection *N);
  ~Capacitor() override;
  double returnCurr() override;
  void changeVolt(double time_step) override;
};

/*class Circuits : public Component
{
private:
  std::vector<Component *> net;

public:
  Circuits(std::initializer_list<int> list);
  ~Circuits();
};*/
#endif