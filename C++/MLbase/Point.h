#pragma once
class Point
{
protected:
	float x1;
	float x2;

    //sets the class of point
    int group;
public:
    float getX1() const;
    float getX2() const;
    int getGroup() const;

    void setX1(float xVal);
    void setX2(float yVal);
    void setGroup(int group);
};

