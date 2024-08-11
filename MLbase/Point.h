#pragma once
class Point
{
private:
	float x;
	float y;

    //sets the class of point
    int group;
public:
    float getX() const;
    float getY() const;
    int getGroup() const;

    void setX(float xVal);
    void setY(float yVal);
    void setGroup(int group);
};

