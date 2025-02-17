#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
The Observer pattern is a design pattern that allows an object to notify other objects about changes to its state. Here's an explanation of the Observer pattern with an example:

Subject
The Subject is the object that is being observed. It maintains a list of Observer objects and notifies them when its state changes.

Observer
The Observer is the object that is interested in the state of the Subject. It implements the Observer interface, which defines the update() method that is called by the Subject when its state changes.
*/


class observer
{
public:
	virtual void update(const std::string& message) = 0;
};


class subject
{
	std::vector<observer*> m_observer;

public:
	void addObserver(observer* observer)
	{
		m_observer.push_back(observer);
	}

	void removeObserver(observer* observer)
	{
		//m_observer.erase(observer)
	}

	void notifyObserver(const std::string& message)
	{
		for (observer* observer : m_observer)
		{
			observer->update(message);
		}
	}


};


class concreteObserver : public observer
{
public:
	void update(const std::string& message)
	{
		std::cout << "Recieved message: " << message <<std:: endl;
	}
};


int start()
{
	subject sub;
	concreteObserver ob1;
	concreteObserver ob2;
	sub.addObserver(&ob1);
	sub.addObserver(&ob2);

	sub.notifyObserver("Hello world");
	return 0;

}





//Example 2


// Observer interface
class Observer {
public:
    virtual void update(const std::string& temperature, const std::string& humidity, const std::string& windSpeed) = 0;
};

// Subject interface
class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const std::string& temperature, const std::string& humidity, const std::string& windSpeed) = 0;
};

// WeatherStation class (Subject)
class WeatherStation : public Subject {
public:
    void registerObserver(Observer* observer) override {
        observers_.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        // Remove observer from the list
    }

    void notifyObservers(const std::string& temperature, const std::string& humidity, const std::string& windSpeed) override {
        for (Observer* observer : observers_) {
            observer->update(temperature, humidity, windSpeed);
        }
    }

    void setMeasurements(const std::string& temperature, const std::string& humidity, const std::string& windSpeed) {
        temperature_ = temperature;
        humidity_ = humidity;
        windSpeed_ = windSpeed;
        notifyObservers(temperature_, humidity_, windSpeed_);
    }

private:
    std::vector<Observer*> observers_;
    std::string temperature_;
    std::string humidity_;
    std::string windSpeed_;
};

// TemperatureDisplay class (Observer)
class TemperatureDisplay : public Observer {
public:
    void update(const std::string& temperature, const std::string& humidity, const std::string& windSpeed) override {
        std::cout << "Temperature: " << temperature << std::endl;
    }
};

// HumidityDisplay class (Observer)
class HumidityDisplay : public Observer {
public:
    void update(const std::string& temperature, const std::string& humidity, const std::string& windSpeed) override {
        std::cout << "Humidity: " << humidity << std::endl;
    }
};

// WindSpeedDisplay class (Observer)
class WindSpeedDisplay : public Observer {
public:
    void update(const std::string& temperature, const std::string& humidity, const std::string& windSpeed) override {
        std::cout << "Wind Speed: " << windSpeed << std::endl;
    }
};

int main() {
    WeatherStation weatherStation;

    TemperatureDisplay temperatureDisplay;
    HumidityDisplay humidityDisplay;
    WindSpeedDisplay windSpeedDisplay;

    weatherStation.registerObserver(&temperatureDisplay);
    weatherStation.registerObserver(&humidityDisplay);
    weatherStation.registerObserver(&windSpeedDisplay);

    weatherStation.setMeasurements("25°C", "60%", "10 km/h");
    weatherStation.setMeasurements("30°C", "50%", "15 km/h");

    return 0;
}