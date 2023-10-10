#ifndef VECTOR2_H
#define VECTOR2_H

/*
*	Création de vecteur à deux dimensions
*/

/*class Vector2
{
public:

	Vector2(double x, double y);//Constructor
	Vector2();//Create a vector x=0 y=0


	double getx();//return double x component
	double gety();//return double y component
	double magnitude();//return the length of this vector


	void Set(double newX, double newY);//Set x and y component of an existing Vector2
	void Normalized();//return this vector normalized

	bool Equals(Vector2 vec);//return true if the given vector is exactly equals to this vector;



private:
	double x; //x component
	double y; //y component

};*/

struct Vector2
{
	/*
*	(0,0)
*		O----------> x			
*		|
*		|
*		|
*		|
*	  y v
*/
	double x; //x component
	double y; //y component

	Vector2(double xComp, double yComp)//Constructor
	{
		x = xComp;
		y = yComp;
	}

	Vector2()
	{
		x=0; y=0;
	}


	double getx()//return double x component
	{
		return x;
	}

	double gety()//return double y component
	{
		return y;
	}

	double magnitude()//return the length of this vector
	{
		return sqrt(x*x + y*y);
	}


	void Set(double newX, double newY)//Set x and y component of an existing Vector2
	{
		x = newX;
		y = newY;
	}
	void Set(Vector2 v)//Set x and y component of an existing Vector2
	{
		x = v.getx();
		y = v.gety();
	}

	void Normalized()//return this vector normalized
	{
		double mag = magnitude();
		Set(x/mag,y/mag);
	}

	bool Equals(Vector2 vec)//return true if the given vector is exactly equals to this vector
	{
		if(vec.getx()!=x || vec.gety()!=y)return false;
		else return true;
	}

	Vector2 plus(Vector2 v1, Vector2 v2)
	{
		double xres = v1.getx() + v2.getx();
		double yres = v1.gety() + v2.gety();
		Vector2 res(xres,yres);
		return res;
	}
	Vector2 minus(Vector2 v1, Vector2 v2)
	{
		double xres = v1.getx() - v2.getx();
		double yres = v1.gety() - v2.gety();
		Vector2 res(xres,yres);
		return res;
	}


};

#endif
