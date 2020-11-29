#pragma once
#ifndef OBJECT_H
#define OBJECT_H

class Object {
private:
	int id;
	double x;
	double y;

public:
	Object(int id);
	virtual ~Object();
	void SetX(double x);
	void SetY(double y);
	double GetX() const;
	double GetY() const;
	int GetId() const;
};
#endif // !OBJECT_H
