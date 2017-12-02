#include <stdbool.h>
#include <stdio.h>
#include "car.h"

#define MAX_ACCERATION_RATE_AIXAM 1.0
#define MAX_ACCERATION_RATE_FIAT 2.26
#define MAX_ACCERATION_RATE_JEEP 3.14
#define MIN_ACCERATION_RATE -8

#define MAX_SPEED_AIXAM 45
#define MAX_SPEED_FIAT 170
#define MAX_SPEED_JEEP 196


struct CarType{
  enum Type type;
  enum Color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool isRented;
};

static struct CarType aixam = {AIXAM, RED,  16.0, 0.0 , 0, false};
static struct CarType fiat_multiplay1 = {FIAT_MULTIPLA, GREEN, 65, 0, 0, false};
static struct CarType fiat_multiplay2  = {FIAT_MULTIPLA, BLUE, 65, 0, 0, false};
static struct CarType fiat_multiplay3  = {FIAT_MULTIPLA, ORANGE, 65, 0 ,0, false};
static struct CarType jeep1 = {JEEP, SILVER, 80, 0, 0, false};
static struct CarType jeep2 = {JEEP, BLACK, 80, 0, 0, false};

void init(){

  aixam.fill_level = 16;
  aixam.acceleration_rate = 0;
  aixam.speed = 0;
  aixam.isRented = false;

  fiat_multiplay1.fill_level = 65;
  fiat_multiplay1.acceleration_rate = 0;
  fiat_multiplay1.speed = 0;
  fiat_multiplay1.isRented = false;

  fiat_multiplay2.fill_level = 65;
  fiat_multiplay2.acceleration_rate = 0;
  fiat_multiplay2.speed = 0;
  fiat_multiplay2.isRented = false;

  fiat_multiplay3.fill_level = 65;
  fiat_multiplay3.acceleration_rate = 0;
  fiat_multiplay3.speed = 0;
  fiat_multiplay3.isRented = false;

  jeep1.fill_level = 80;
  jeep1.acceleration_rate = 0;
  jeep1.speed = 0;
  jeep1.isRented = false;

  jeep2.fill_level = 80;
  jeep2.acceleration_rate = 0;
  jeep2.speed = 0;
  jeep2.isRented = false;
}

Car get_car(enum Type type)
{
  Car car;
  if(type == AIXAM){
    if (aixam.isRented == false)
    {
      aixam.isRented = true;
      car = &aixam;
    }
    else
    {
      car = 0;
    }
    return car;
  }
  if(type == FIAT_MULTIPLA){
    if (fiat_multiplay1.isRented == false)
    {
      fiat_multiplay1.isRented = true;
      car = &fiat_multiplay1;
    }
    else if(fiat_multiplay2.isRented == false)
    {
      fiat_multiplay2.isRented = true;
      car = &fiat_multiplay2;
    }
    else if (fiat_multiplay3.isRented == false)
    {
      fiat_multiplay3.isRented = true;
      car = &fiat_multiplay3;
    }
    else
    {
      car = 0;
    }
    return car;
  }
  if(type == JEEP){
    if (jeep1.isRented == false)
    {
      jeep1.isRented = true;
      car = &jeep1;
    }
    else if (jeep2.isRented == false)
    {
      jeep2.isRented = true;
      car = &jeep2;
    }
    else
    {
      car = 0;
    }
    return car;
  }
}
Type get_type(Car car)
{
  return car->type;
}
Color get_color(Car car)
{
  return car->color;
}
float get_fill_level(Car car)
{
  return car->fill_level;
}
float get_acceleration_rate(Car car)
{
  return car->acceleration_rate;
}
void set_acceleration_rate(Car car,double acceleration_rate)
{
  if(car->type == AIXAM){
    if(acceleration_rate < MIN_ACCERATION_RATE)
    {
      car->acceleration_rate = MIN_ACCERATION_RATE;
    }
    else if (acceleration_rate > MAX_ACCERATION_RATE_AIXAM)
    {
      car->acceleration_rate = MAX_ACCERATION_RATE_AIXAM;
    }
    else
    {
      car->acceleration_rate = acceleration_rate;
    }
  }
  if(car->type == FIAT_MULTIPLA){
    if(acceleration_rate < MIN_ACCERATION_RATE)
    {
      car->acceleration_rate = MIN_ACCERATION_RATE;
    }
    else if (acceleration_rate > MAX_ACCERATION_RATE_FIAT)
    {
      car->acceleration_rate = MAX_ACCERATION_RATE_FIAT;
    }
    else
    {
      car->acceleration_rate = acceleration_rate;
    }
  }
  if(car->type == JEEP){
    if(acceleration_rate < MIN_ACCERATION_RATE)
    {
      car->acceleration_rate = MIN_ACCERATION_RATE;
    }
    else if (acceleration_rate > MAX_ACCERATION_RATE_JEEP)
    {
       car->acceleration_rate = MAX_ACCERATION_RATE_JEEP;
    }
    else
    {
      car->acceleration_rate = acceleration_rate;
    }
  }
}
int get_speed(Car car)
{
  int rounds = car->speed + 0.5;
  int speed = rounds;
  return speed;
}
void accelerate(Car car)
{
  if(car->type == AIXAM){
    if (car->speed + 3.6 * car->acceleration_rate <= MAX_SPEED_AIXAM)
    {
      car->speed = car->speed + 3.6 * car->acceleration_rate;
    }
    else
    {
      car->speed = MAX_SPEED_AIXAM;
    }
  }
  if(car->type == FIAT_MULTIPLA){
    if (car->speed + 3.6 * car->acceleration_rate <= MAX_SPEED_FIAT)
    {
    car->speed = car->speed + 3.6 * car->acceleration_rate;
    }
    else
    {
      car->speed = MAX_SPEED_FIAT;
    }
  }
  if(car->type == JEEP){
    if (car->speed + 3.6 * car->acceleration_rate <= MAX_SPEED_JEEP)
    {
      car->speed = car->speed + 3.6 * car->acceleration_rate;
    }
    else
    {
      car->speed = MAX_SPEED_JEEP;
    }
  }
}
