#pragma once
#include <cmath>


namespace Math {
	//�~����
	static float PI = 3.141592653589793238462643383279502884197f;
	//�p�x�ϊ�
	inline float ToDegree(float radian);
	inline float ToRadian(float degree) {
		return (degree / 180.0f)*PI;
	}
	//�d��
	inline float Gravity(int onemeter) {
		return ((9.8f / 60) / 60)*onemeter;
	}


	//�x�N�g���N���X
	//�f�t�H���g������z=0.0f�Ȃ̂�2�����ł��g����ˁI
	class Vec {
	public:
		float x, y, z;		//���W

		Vec(float x = 0.0f, float y = 0.0f, float z = 0.0f) :
			x(x),
			y(y),
			z(z)
		{}
		~Vec() {};


		//�x�N�g���𐳋K��
		Vec Normalize() {
			float len = GetVecLen(*this);
			if (len == 0) return *this;
			return Vec(x /= len, y /= len);
		}
		//�x�N�g����x���@�ŉ�]����
		Vec RotateVecDegree(Vec v, float deg) {
			float rad = (deg / 180) * Math::PI;
			float tempX = v.x;
			float tempY = v.y;
			v.x = float(tempX*cos(rad) - tempY*sin(rad));
			v.y = float(tempX*sin(rad) + tempY*cos(rad));
			return v;
		}		
		//�x�N�g�����ʓx�@�ŉ�]����
		Vec RotateVecRadian(Vec v, float rad) {
			float tempX = v.x;
			float tempY = v.y;
			v.x = float(tempX*cos(rad) - tempY*sin(rad));
			v.y = float(tempX*sin(rad) + tempY*cos(rad));
			return v;
		}
		//2�̃x�N�g���̓��ς�Ԃ�
		static float GetDotVec(Vec v1, Vec v2) {
			return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
		}
		//2�̃x�N�g���̊O�ς�Ԃ�(2����)
		static float GetCrossVec2(Vec v1, Vec v2) {
			return (v1.x*v2.y) - (v1.y*v2.x);
		}
		//2�̃x�N�g���̊O�ς�Ԃ�(3����)
		Vec GetCrossVec3(Vec v1, Vec v2) {
			Vec Result;
			Result.x = v1.y*v2.z - v1.z*v2.y;
			Result.y = v1.z*v2.x - v1.x*v2.z;
			Result.z = v1.x*v2.y - v1.y*v2.x;
			return Result;
		}
		//�x�N�g���̒����𓾂�
		float GetVecLen(Vec v) {
			return std::pow(v.x*v.x + v.y*v.y + v.z*v.z, 0.5f);
		}
		//���K�����ꂽ�x�N�g���𓾂�
		Vec GetUnitVec(Vec v) {
			float len = GetVecLen(v);
			Vec Result = v;
			Result.x /= len;
			Result.y /= len;
			Result.z /= len;
			return Result;
		}
		//�x�N�g����n�{����
		Vec VecScale(Vec v, float n) {
			Vec Result;
			Result.x *= n;
			Result.y *= n;
			Result.z *= n;
			return Result;
		}
		//2�����x�N�g���̒P�ʖ@���x�N�g���𓾂� v1�~v2 �x�N�g���̍����̕� (��:���w�̍��W�n)
		Vec GetUnitNormVec2Left(Vec v) {	//������90�x��]���Ă邾����Ł�
			Vec Result = v;
			float tmpx = Result.x;
			Result.x = Result.y;
			Result.y = (-1)*tmpx;
			Result = GetUnitVec(Result);
			return Result;
		}
		//2�����x�N�g���̒P�ʖ@���x�N�g���𓾂� v1�~v2 �x�N�g���̉E���̕� (��:���w�̍��W�n)
		Vec GetUnitNormVec2Right(Vec v) {	//�������͉E����Ł�
			Vec Result = v;
			float tmpx = Result.x;
			Result.x = (-1)*Result.y;
			Result.y = tmpx;
			Result = GetUnitVec(Result);
			return Result;
		}
		//3�������ʂ̒P�ʖ@���x�N�g���𓾂�(��:���w�̍��W�n) v1,v2�͕��ʏ�ɑ��݂���x�N�g��
		Vec GetUnitNormVec3(Vec v1, Vec v2) {
			Vec Result = GetCrossVec3(v1, v2);
			Result = GetUnitVec(Result);
			return Result;
		}



		//�I�y���[�^��`
		Vec& operator = (const Vec& v) { x = v.x; y = v.y; z = v.z; return *this; }
		const Vec operator + (const Vec& v) const { return Vec(x + v.x, y + v.y, z + v.z); }
		const Vec operator - (const Vec& v) const { return Vec(x - v.x, y - v.y, z - v.z); }
		const Vec operator * (const float n) const { return Vec(x*n, y*n, z*n); }
		const Vec operator / (const float n) const { return Vec(x / n, y / n, z / n); }
		Vec& operator += (const Vec& v) { x += v.x; y += v.y; z += v.z; return *this; }
		Vec& operator -= (const Vec& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
		Vec& operator *= (const float n) { x *= n; y *= n; z *= n; return *this; }
		Vec& operator /= (const float n) { x /= n; y /= n; z /= n; return *this; }

	};




	struct Box2D {				//�l�p�`�\����
		float	x, y, w, h;		//����̍��W�A���A����

		Box2D() :x(0.0f), y(0.0f), w(0.0f), h(0.0f) {}
		Box2D(float x, float y, float w, float h) :x(x), y(y), w(w), h(h) {}
		~Box2D() {}
		void Offset(Vec v) {							//�������x�N�g��
			x += v.x;
			y += v.y;
		}
		void Offset(float vx, float vy) {			//������x,y
			x += vx;
			y += vy;
		}
		Box2D OffsetCopy(float vx, float vy) const {	//x,y�������ɂ���Box2D��Ԃ�
			return Box2D(x + vx, y + vy, w, h);
		}
		Box2D OffsetCopy(const Vec& v)const {
			return Box2D(x + v.x, y + v.y, w, h);
		}
		bool Hit(const Box2D& b) const {		//��`���m�̓����蔻��
			if (x < b.x + b.w	&&
				b.x < x + w &&
				y < b.y + b.h	&&
				b.h < y + h) {
				return true;
			}
			return false;
		}
		bool Hit(const Vec& b) const {		//��`�ƃx�N�g���̓����蔻��
			if (x < b.x	&&
				b.x < x + w &&
				y < b.y	&&
				b.y < y + h) {
				return true;
			}
			return false;
		}
	};

	struct Circle {
		float x, y, z;		//���S���W
		float r;			//���a

		Circle() :x(0.0f), y(0.0f), z(0.0f), r(0.0f) {};
		Circle(float x, float y, float z, float r) :x(x), y(y), z(z), r(r) {};
		~Circle() {};

		void Offset(Vec v) {							//�������x�N�g��
			x += v.x;
			y += v.y;
			z += v.z;
		}
		void Offset(float vx, float vy, float vz = 0.0f) {			//������x,y,z
			x += vx;
			y += vy;
			z = vz;
		}
		Circle OffsetCopy(float vx, float vy, float vz = 0.0f) const {	//x,y�������ɂ���Circle��Ԃ�
			return Circle(x + vx, y + vy, z + vz, r);
		}
		Circle OffsetCopy(const Vec& v)const {
			return Circle(x + v.x, y + v.y, z + v.z, r);
		}
		bool Hit(const Circle& c) const {
			//���S�Ԃ̋�������̔��a�̘a��菬����������true
			float mx = powf(x - c.x, 2.0f);
			float my = powf(y - c.y, 2.0f);
			float mz = powf(z - c.z, 2.0f);
			if (powf(mx + my + mz, 0.5f) <= (r + c.r)) return true;
			return false;
		}
		bool Hit(const Vec& v) const {
			float mx = powf(x - v.x, 2.0f);
			float my = powf(y - v.y, 2.0f);
			float mz = powf(z - v.z, 2.0f);
			if (powf(mx + my + mz, 0.5f) <= r) return true;
			return false;
		}

	};

	struct Triangle {
		Vec v1, v2, v3;		//3���_

		Triangle(Vec v1, Vec v2, Vec v3) :
			v1(v1), v2(v2), v3(v3)
		{}

	};

	struct Orval {
		float x, y;		//���S���W
		float lr, sr;	//�����A�Z��	 long radius,shot radius
		float angle;	//������x������̌X��

		Orval(float x, float y, float lr, float sr, float ang) :
			x(x), y(y),
			lr(lr), sr(sr),
			angle(ang)
		{}
	};

}