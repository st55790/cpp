#pragma once
struct Triangle {

	public:

		Triangle() {};

		Triangle(double a, double b, double c) {
			this->a = a;
			this->b = b;
			this->c = c;
		}

		bool canBeConstructed(Triangle t);
		bool canBeConstructed(Triangle* t);

		void setA(double s) {
			a = s;
		}
		void setB(double s) {
			b = s;
		}
		void setC(double s) {
			c = s;
		}

	protected:

	private:
		double a, b, c;
};